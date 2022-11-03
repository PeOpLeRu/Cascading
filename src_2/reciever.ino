#define LACTH_PIN 8
#define CLOCK_PIN 12
#define DATA_PIN 11

uint8_t nums[] = { 0b11101110, 0b10000010, 0b11011100, 0b11010110, 0b10110010, 0b01110110, 0b01111110, 0b11000010, 0b11111110, 0b11110110 };

int num = 0;

void setup()
{
  pinMode(LACTH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
 
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    num = Serial.parseInt();
    show_digit(num % 10);
    
    Serial.write("1");
  }
}

void show_digit(int8_t digit)
{
    if (digit < 0 || digit > 9)
        return;

  	digitalWrite(LACTH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, (255 - nums[digit]));
	  digitalWrite(LACTH_PIN, HIGH);
    
    // for (int i = 7; i >= 0; --i)
    // {
    //   digitalWrite(LACTH_PIN, bool(nums[digit] >> i));
    //   shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, );
    // }

    return;
}