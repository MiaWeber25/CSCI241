// Display using a single 8-segment LED module

const int SegAPin = 22;  // Output pin associated with the "A" (top) segment
const int SegBPin = 23;  // Output pin associated with the "B" (top right) segment
const int SegCPin = 24;  // Output pin associated with the "C" (bottom right) segment
const int SegDPin = 25;  // Output pin associated with the "D" (bottom) segment
const int SegEPin = 26;  // Output pin associated with the "E" (bottom left) segment
const int SegFPin = 27;  // Output pin associated with the "F" (top left) segment
const int SegGPin = 28;  // Output pin associated with the "G" (middle) segment
const int SegDPPin = 29; // Output pin associated with the "DP" (decimal point)

// Called once at start up

void setup()
{
  // Initialize the led ports for output.
  
  pinMode(SegAPin, OUTPUT);
  pinMode(SegBPin, OUTPUT);
  pinMode(SegCPin, OUTPUT);
  pinMode(SegDPin, OUTPUT);
  pinMode(SegEPin, OUTPUT);
  pinMode(SegFPin, OUTPUT);
  pinMode(SegGPin, OUTPUT);
  pinMode(SegDPPin, OUTPUT);
  
  FlashAllSegments(250);
}

static const int waitTime = 1000;   // Basic wait time (in milliseconds).

// Called repeatedly until the reset button is pressed

void loop()
{
  DisplayZero();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplayOne();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplayTwo();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplayThree();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplayFour();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplayFive();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplaySix();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplaySeven();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplayEight();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);

  DisplayNine();
  delay(waitTime);
  DisplayOff();
  delay(waitTime);
}

// Flash all segments with a delay between segments.

void FlashAllSegments(int waitInMilliseconds)
{
  FlashSegment(SegAPin, waitInMilliseconds);
  FlashSegment(SegBPin, waitInMilliseconds);
  FlashSegment(SegCPin, waitInMilliseconds);
  FlashSegment(SegDPin, waitInMilliseconds);
  FlashSegment(SegEPin, waitInMilliseconds);
  FlashSegment(SegFPin, waitInMilliseconds);
  FlashSegment(SegGPin, waitInMilliseconds);
  FlashSegment(SegDPPin, waitInMilliseconds);
}

// Flash a segment for the specified on/off time.

void FlashSegment(int segPin, int waitInMilliseconds)
{
  SegmentOn(segPin);
  delay(waitInMilliseconds);
  SegmentOff(segPin);
  delay(waitInMilliseconds);
}

// Display the numeral "0"

void DisplayZero()
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOn(SegFPin);
  SegmentOff(SegGPin);
  SegmentOff(SegDPPin);  
}

// Display the numeral "1"

void DisplayOne()
{
  SegmentOff(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOff(SegDPin);
  SegmentOff(SegEPin);
  SegmentOff(SegFPin);
  SegmentOff(SegGPin);
  SegmentOff(SegDPPin);  
}

// Display the numeral "2"

void DisplayTwo()
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOff(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOff(SegFPin);
  SegmentOn(SegGPin);
  SegmentOff(SegDPPin);  
}

// Display the numeral "3"

void DisplayThree()
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOff(SegEPin);
  SegmentOff(SegFPin);
  SegmentOn(SegGPin);
  SegmentOff(SegDPPin);  
}

// Display the numeral "4"

void DisplayFour()
{
  SegmentOff(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOff(SegDPin);
  SegmentOff(SegEPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  SegmentOff(SegDPPin);
}

// Display the numeral "5"

void DisplayFive()
{
  SegmentOn(SegAPin);
  SegmentOff(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOff(SegEPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  SegmentOff(SegDPPin);
}

// Display the numeral "6"

void DisplaySix()
{
  SegmentOn(SegAPin);
  SegmentOff(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  SegmentOff(SegDPPin);
}

// Display the numeral "7"

void DisplaySeven()
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOff(SegDPin);
  SegmentOff(SegEPin);
  SegmentOff(SegFPin);
  SegmentOff(SegGPin);
  SegmentOff(SegDPPin);
}

// Display the numeral "8"

void DisplayEight()
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOn(SegEPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  SegmentOff(SegDPPin);  
}

// Display the numeral "9"

void DisplayNine()
{
  SegmentOn(SegAPin);
  SegmentOn(SegBPin);
  SegmentOn(SegCPin);
  SegmentOn(SegDPin);
  SegmentOff(SegEPin);
  SegmentOn(SegFPin);
  SegmentOn(SegGPin);
  SegmentOff(SegDPPin);  
}

// Turn the display off.

void DisplayOff()
{
  SegmentOff(SegAPin);
  SegmentOff(SegBPin);
  SegmentOff(SegCPin);
  SegmentOff(SegDPin);
  SegmentOff(SegEPin);
  SegmentOff(SegFPin);
  SegmentOff(SegGPin);
  SegmentOff(SegDPPin);  
}

// Turn a segment on.

void SegmentOn(int segPin)
{
  digitalWrite(segPin, HIGH);
}

// Turn a segment off.

void SegmentOff(int segPin)
{
  digitalWrite(segPin, LOW);
}
