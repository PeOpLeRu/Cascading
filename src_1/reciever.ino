int num = 0;

void setup()
{
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
    if (Serial.available())
    {
        num = Serial.parseInt();
        show_digit(num % 10);
    }
}

void show_digit(int8_t digit)
{
    if (digit < 0 || digit > 9)
        return;

    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);

    switch (digit)
    {
        case 0:
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
            break;

        case 1:
            digitalWrite(7, HIGH);
            digitalWrite(13, HIGH);
            break;
        
        case 2:
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
            break;
        
        case 3:
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
            break;
        
        case 4:
            digitalWrite(7, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(13, HIGH);
            break;
                
        case 5:
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            break;
        
        case 6:
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            break;
        
        case 7:
            digitalWrite(7, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
            break;
        
        case 8:
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
            break;
        
        case 9:
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, HIGH);
            digitalWrite(12, HIGH);
            digitalWrite(13, HIGH);
            break;
    
        default:
            break;
    }
  
  	for (int i = 6; i < 14; ++i)
    {
      digitalWrite(i, !digitalRead(i));
    }

    return;
}