// Blink an 8-bit port's worth of LEDs.

#include <CSCI_LED.h>     // Library routines
#include <CSCI_Timers.h>

// Port-related definitions.

const uint8_t *PortDirPtr = &DDRL;    // Ptr to port direction control.
const uint8_t *PortDataPtr = &PORTL;  // Ptr to port data.

// State-related definitions

const int LedOnState = LOW;   // State which turns LED on.
const int LedOffState = HIGH; // State which turns LED off.

const int LedOnTime = 400;    // LED on time (in milliseconds).
const int LedOffTime = 600;   // LED off time (in milliseconds).

// This routine called once at program start.

void setup()
{
  SetupLEDPort(PortDirPtr); // Set port direction bits

  // Turn all LED's off
  
  SetLEDPortBits(PortDataPtr, 0b11111111, LedOffState);
}

// This routine called repeatedly until a "reset" is performed.

const int LoopDelay = 1000;   // Loop repeat delay (in milliseconds).

void loop ()
{
  uint8_t ledByte = 0b00000001;

  SweepLSBToMSB(ledByte, PortDataPtr, LedOnState, LedOnTime, LedOffTime);

  ledByte = 0b10000000;
  
  SweepMSBToLSB(ledByte, PortDataPtr, LedOnState, LedOnTime, LedOffTime);
  
  ledByte = 0b11110000;

  for ( int times = 1; times <= 8; times++ )
  {
    CompPattern(ledByte, PortDataPtr, LedOnState, LedOnTime, LedOffTime);
  }
  
  ledByte = 0b10101010;

  for ( int times = 1; times <= 8; times++ )
  {
    CompPattern(ledByte, PortDataPtr, LedOnState, LedOnTime, LedOffTime);
  }

  ledByte = 0b00000000;

  IncToZero(ledByte, PortDataPtr, LedOnState, LedOnTime / 10);
  
  // Wait a little before repeating.

  WaitMillis(LoopDelay);
}

// Routine to display bit pattern passed in "ledByte", hold it for
// "patTime", then display the complement of the bit pattern and hold
// it for "compTime".

void CompPattern(uint8_t ledByte, uint8_t *portDataPtr,
                 int onState, int patTime, int compTime)
{
  // offState is opposite onState.
  
  int offState = ( onState == HIGH ) ? LOW : HIGH;
    
  SetLEDPortBits(portDataPtr, ledByte, onState);
  WaitMillis(patTime);

  SetLEDPortBits(portDataPtr, ledByte, offState);
  
  ledByte = ~ledByte;     // Complement bits

  SetLEDPortBits(portDataPtr, ledByte, onState);
  WaitMillis(compTime);

  SetLEDPortBits(portDataPtr, ledByte, offState);
}

// Routine to sweep bit pattern passed in "ledByte" from LSB to MSB,
// holding each LED on/off for the specified times (in milliseconds).

void SweepLSBToMSB(uint8_t ledByte, uint8_t *portDataPtr,
                   int onState, int onTime, int offTime)
{
  // offState is opposite onState.
  
  int offState = ( onState == HIGH ) ? LOW : HIGH;
  
  for ( uint8_t bit = 0; bit < 8; bit++ )
  {
    SetLEDPortBits(portDataPtr, ledByte, onState);
    WaitMillis(onTime);
    SetLEDPortBits(portDataPtr, ledByte, offState);
    WaitMillis(offTime);

    ledByte = ledByte << 1;
  }  
}

// Routine to sweep bit pattern passed in "ledByte" from MSB to LSB,
// holding each LED on/off for the specified times (in milliseconds).

void SweepMSBToLSB(uint8_t ledByte, uint8_t *portDataPtr,
                   int onState, int onTime, int offTime)
{
  // offState is opposite onState.
  
  int offState = ( onState == HIGH ) ? LOW : HIGH;
    
  for ( uint8_t bit = 0; bit < 8; bit++ )
  {
    SetLEDPortBits(portDataPtr, ledByte, onState);
    WaitMillis(onTime);
    SetLEDPortBits(portDataPtr, ledByte, offState);
    WaitMillis(offTime);

    ledByte = ledByte >> 1;
  }  
}

// Routine to increment pattern until it reaches zero, holding each
// value on for the specified time (in milliseconds).

void IncToZero(uint8_t ledByte, uint8_t *portDataPtr, int onState, int onTime)
{
  // offState is opposite onState.
  
  int offState = ( onState == HIGH ) ? LOW : HIGH;
    
  do
  {
    SetLEDPortBits(portDataPtr, ledByte, onState);
    WaitMillis(onTime);
    SetLEDPortBits(portDataPtr, ledByte, offState);

    ledByte++;
  }
  while ( ledByte != 0 );
}
