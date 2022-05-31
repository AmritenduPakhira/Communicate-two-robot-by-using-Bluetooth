0// slave
//
//
//#define led 2
//
//void setup()
//{
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  pinMode(led, OUTPUT);
//}
//
//void loop()
//{
//  // put your main code here, to run repeatedly:
//  if(Serial.available())
//  {
//    char val = Serial.read();
//    if(val == 'A')
//    {
//      digitalWrite(led, HIGH);
//    }
//    else if(val == 'a')
//    {
//      digitalWrite(led, LOW);
//    }
//  }
//}

char t;

void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

  Serial.begin(9600);

}

void loop()
{

  if (Serial.available())
  {
    t = Serial.read();
    Serial.println(t);
    Serial.println('k');
  }

  if (t == 'F') {          //move forward(all motors rotate in forward direction)
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);

    Serial.println('f');
  }

  else if (t == 'B') {    //move reverse (all motors rotate in reverse direction)
    digitalWrite(12, HIGH);
    digitalWrite(10, HIGH);

       Serial.println('b');
  }

  else if (t == 'L') {
    Serial.println('l');
    digitalWrite(13, HIGH); //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  }

  else if (t == 'R') {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(11, HIGH);
    Serial.println('r');
  }

  else if (t == 'S') 
  {    //STOP (all motors stop)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  delay(100);




}
