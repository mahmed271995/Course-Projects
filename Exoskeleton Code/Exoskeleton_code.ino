int delays[8] = {3000, 3000, 2500, 2500, 2500, 2500, 2500, 2500}; 

//MOTOR 1 
#define m1Pin1 11 
#define m1Pin2 12 
#define m1PWMPin 13 

//MOTOR 2 
#define m2Pin1 8 
#define m2Pin2 9 
#define m2PWMPin 10 

//MOTOR 3 
#define m3Pin1 5 
#define m3Pin2 6 
#define m3PWMPin 7 

//MOTOR 4 
#define m4Pin1 2 
#define m4Pin2 3 
#define m4PWMPin 4 

//PWM Values for Motors 
#define m1PWM 255 
#define m2PWM 255 
#define m3PWM 255 
#define m4PWM 255 
#define MOTOR_1 0 

int pins[8] = {A0, A1, A2, A3, A4, A5, A6, A7}; 
short usSpeed = 150; //default motor speed 

void setup() 
{ 
  pinMode(m1Pin1, OUTPUT); 
  pinMode(m1Pin2, OUTPUT); 
  pinMode(m1PWMPin, OUTPUT); 
  pinMode(m2Pin1, OUTPUT); 
  pinMode(m2Pin2, OUTPUT); 
  pinMode(m2PWMPin, OUTPUT); 
  pinMode(m3Pin1, OUTPUT); 
  pinMode(m3Pin2, OUTPUT); 
  pinMode(m3PWMPin, OUTPUT); 
  pinMode(m4Pin1, OUTPUT); 
  pinMode(m4Pin2, OUTPUT); 
  pinMode(m4PWMPin, OUTPUT); 

  for (int i = 0 ; i < 8; i++) 
    pinMode(pins[i], OUTPUT); 
  
  digitalWrite(pins[0], HIGH); 
  digitalWrite(pins[1], HIGH); 
  digitalWrite(pins[2], HIGH); 
  digitalWrite(pins[3], HIGH); 

  Serial.begin(9600); // Initiates the serial to do the monitoring 
  Serial.println("Begin motor control"); 
  Serial.println(); //Print function list for user selection 
  Serial.println("Enter number for control option:"); 
  Serial.println("1. ForeArm Up"); 
  Serial.println("2. ForeArm Down"); 
  Serial.println("3. Shoulder Right"); 
  Serial.println("4. Shoulder Left"); 
  Serial.println("5. Shoulder In"); 
  Serial.println("6. Shoulder Out"); 
  Serial.println("7. Shoulder Up"); 
  Serial.println("8. Shoulder Down"); 
  Serial.println(); 
} 

void loop() 
{ 
  char user_input; 
  while (Serial.available()) 
  { 
    user_input = Serial.read(); 
    if (user_input == '1' ) 
    { 
      m1Control(1); 
      delay(delays[0]); 
      m1Control(0); 
    } 
    else if (user_input == '2') 
    { 
      m1Control(-1); 
      delay(delays[1]); 
      m1Control(0); 
    } 
    else if (user_input == '3' ) 
    { 
      m2Control(1); 
      delay(delays[2]); 
      m2Control(0); 
      delay(50); 
    } 
    else if (user_input == '4') 
    { 
      m2Control(-1); 
      delay(delays[3]); 
      m2Control(0); 
      delay(50); 
    } 
    else if (user_input == '5' ) 
    { 
      m3Control(1); 
      delay(delays[4]); 
      m3Control(0); 
      delay(50); 
    } 
    else if (user_input == '6') 
    { 
      m3Control(-1); 
      delay(delays[5]); 
      m3Control(0); 
      delay(50);
    } 
    else if (user_input == '7' ) 
    { 
      m4Control(1); 
      delay(delays[6]); 
      m4Control(0); 
      delay(50); 
    } 
    else if (user_input == '8') 
    { 
      m4Control(-1); 
      delay(delays[7]); 
      m4Control(0); 
      delay(50); 
    } 
    else 
    { 
      Serial.println("Invalid option entered."); 
    } 
  } 
} 

void m1Control(int x) 
{ 
  if (x == 1) 
  { 
    digitalWrite(m1Pin1, LOW); 
    digitalWrite(m1Pin2, HIGH); 
  } 
  else if (x == -1) 
  { 
    digitalWrite(m1Pin1, HIGH); 
    digitalWrite(m1Pin2, LOW); 
  } 
  else 
  { 
    digitalWrite(m1Pin1, LOW); 
    digitalWrite(m1Pin2, LOW); 
  } 
  analogWrite(m1PWMPin, m1PWM); 
} 

void m2Control(int x) 
{ 
  if (x == 1) 
  { 
    digitalWrite(m2Pin1, LOW); 
    digitalWrite(m2Pin2, HIGH); 
  } 
  else if (x == -1) 
  { 
    digitalWrite(m2Pin1, HIGH); 
    digitalWrite(m2Pin2, LOW); 
  } 
  else 
  { 
    digitalWrite(m2Pin1, LOW); 
    digitalWrite(m2Pin2, LOW); 
  } 
  analogWrite(m2PWMPin, m2PWM); 
} 

void m3Control(int x) 
{ 
  if (x == 1) 
  { 
    digitalWrite(m3Pin1, LOW); 
    digitalWrite(m3Pin2, HIGH); 
  } 
  else if (x == -1) 
  { 
    digitalWrite(m3Pin1, HIGH); 
    digitalWrite(m3Pin2, LOW); 
  } 
  else 
  { 
    digitalWrite(m3Pin1, LOW); 
    digitalWrite(m3Pin2, LOW); 
  } 
  analogWrite(m3PWMPin, m3PWM); 
} 

void m4Control(int x) 
{ 
  if (x == 1) 
  { 
    digitalWrite(m4Pin1, LOW); 
    digitalWrite(m4Pin2, HIGH); 
  } 
  else if (x == -1) 
  { 
    digitalWrite(m4Pin1, HIGH); 
    digitalWrite(m4Pin2, LOW); 
  } 
  else 
  { 
    digitalWrite(m4Pin1, LOW); 
    digitalWrite(m4Pin2, LOW); 
  } 
  analogWrite(m4PWMPin, m4PWM); 
}
