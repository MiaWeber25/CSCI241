// Display using an 8-segment LED module. (Homework)

#include <CSCI_LED.h>    // Library routines
#include <CSCI_Timers.h>

const int SegAPin = 22;  // Output pin associated with the "A" (top) segment
const int SegBPin = 23;  // Output pin associated with the "B" (top right) segment
const int SegCPin = 24;  // Output pin associated with the "C" (bottom right) segment
const int SegDPin = 25;  // Output pin associated with the "D" (bottom) segment
const int SegEPin = 26;  // Output pin associated with the "E" (bottom left) segment
const int SegFPin = 27;  // Output pin associated with the "F" (top left) segment
const int SegGPin = 28;  // Output pin associated with the "G" (middle) segment
const int SegDPPin = 29; // Output pin associated with the "DP" (decimal point)

// IMPORTANT: The pin numbers above were purposely chosen to correspond to the 8 GPIO pins
//            associated with Arduino Mega PORTA.  Therefore, the following port address
//            pointers can be used to access all 8-bits at one time.

const uint8_t *PortDirPtr = &DDRA;    // Ptr to port input/output direction control bits.
const uint8_t *PortDataPtr = &PORTA;  // Ptr to port data bits.

// State-related definitions

const int LedOnState = HIGH;  // State which turns LED segment on.
const int LedOffState = LOW;  // State which turns LED segment off.

// In order to display a numeric digit (0,1,2,...,9), it's necessary to light one
// or more appropriate LED segments.  Which segments to light will be represented
// by 1 bits in an eight bit byte.  Here are the bit positions (MSB on left, LSB on right)
// representing each segment.  (A binary 1 in that position means that segment is
// to be lit, a binary 0 means that segment is NOT to be lit.)
//
// DP G F E D C B A   ("DP" is a single bit representing the decimal point segment)
//
// Example: The numeric digit "1" is displayed by lighting segments "B" and "C", so
// the bits in the byte should be:
//
// 0 0 0 0 0 1 1 0

// Each element in the following array holds the segment sequence pattern
// corresponding to each numeric digit (0,1,2,3,4,5,6,7,8,9).

const uint8_t DigitToSegSequence[] =
{
  0b00111111,   // "0"
  0b00000110,   // "1"

  // [*** Add array elements representing segments for digits 2 through 8 *** ]

  0b01101111    // "9"
};

// Note: The bit corresponding to the decimal point (DP segment) is always 0.  Whether or not
//       to set it to 0 or 1 is determined by special logic.

// Called once at start up

void setup()
{
  // Set port direction bits.

  // [*** Replace with your code ***]

  // Flash each segment so we know circuitry is working.

  // [*** Replace with your code ***]
}

// Called repeatedly until the reset button is pressed

void loop()
{
  static const int digitHoldTime = 1000;	// Time in milliseconds
  
  // For each decimal digit (0,1,2,...,9), display the digit on for "digitHoldTime",
  // then nothing for "digitHoldTime".  If the digit is odd (1,3,5,7,9), then also
  // display the decimal point.

  // [*** Replace with your code ***]  
}
