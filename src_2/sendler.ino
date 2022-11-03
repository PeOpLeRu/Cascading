#include <SoftwareSerial.h>

#define LACTH_PIN 8
#define CLOCK_PIN 12
#define DATA_PIN 11

#define RX_PIN 2
#define TX_PIN 3

SoftwareSerial Slave(RX_PIN, TX_PIN);	  // rx, tx
bool mess_input = true;
long num = 0;
#define SIZE_ARR_NUM 10
uint8_t arr_num[SIZE_ARR_NUM];

uint8_t nums[] = { 0b11101110, 0b10000010, 0b11011100, 0b11010110, 0b10110010, 0b01110110, 0b01111110, 0b11000010, 0b11111110, 0b11110110 };

void setup()
{
  pinMode(LACTH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);

  pinMode(RX_PIN, INPUT);
  pinMode(TX_PIN, OUTPUT);
  
  Serial.begin(9600);
  Slave.begin(9600);
}

void loop()
{
  if (mess_input)
  {
    Serial.print("Enter num: ");
    mess_input = false;
  }

  if (Serial.available())
  {
    num = Serial.parseInt();
    Serial.println(num);
    
    int iterator = num_decomposition(num, arr_num, SIZE_ARR_NUM);
    
    for (; iterator < SIZE_ARR_NUM; iterator += 2)	// Итератор всегда будет четным (из-за функции num_decomposition)
    {
    	Slave.print(arr_num[iterator + 1] % 10);
      	show_digit(arr_num[iterator] % 10);
      	while(!Slave.available()){}	// Ждем пока вторая ардуино напечатает и ответит нам
      	Slave.read();
      	delay(800);	// Чтобы успеть увидеть выввод
    }
    
    mess_input = true;
  }
}

void show_digit(int8_t digit)
{
    if (digit < 0 || digit > 9)
        return;

  	digitalWrite(LACTH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, (255 - nums[digit]));
	  digitalWrite(LACTH_PIN, HIGH);

    return;
}

int num_decomposition(long num, uint8_t* arr_num, const int& size_arr)
{
  int iterator = size_arr;
  while (num > 0)	// число в массив в обратном порядке
  {
    --iterator;
    arr_num[iterator] = num % 10;
    num /= 10;
  }
  
  if (iterator == 10)	// Если был 0 и мы не зашли в цикл - обнуляем
  {
    --iterator;
    arr_num[iterator] = 0;
  }
  
  if (iterator % 2 != 0)	// Если нечетное кол-во цифр, то добавляем незначащий ноль
  {
    --iterator;
    arr_num[iterator] = 0;
  }
  
  return iterator;
}