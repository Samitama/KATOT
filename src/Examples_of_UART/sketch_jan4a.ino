int data_length=4;
int data_array[64];
// Motor 1 için hareket pinlerinin tanımı
#define PWM1 3
#define IN1 4 
#define IN2 5

// Motor 2 için hareket pinlerinin tanımı
#define PWM2 6
#define IN3 7
#define IN4 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (Serial.available()>0) {
  char incomingByte = Serial.read();
    if(incomingByte == '#'){
      for (int j=0; j<data_length; j++) {
      data_array[j] = Serial.parseInt();
      }
      if(data_array[0] == 10 && data_array[1] == 10){
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN4, HIGH);
          digitalWrite(IN3, LOW);
      }
      if (data_array[0]== 11 && data_array[1] ==11){
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN4, HIGH);
          digitalWrite(IN3, HIGH);
      }
      if (data_array[0] == 00 && data_array[1] == 00){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN4, LOW);
          digitalWrite(IN3, LOW);
      }
      if (data_array[0] == 01 && data_array[1] == 01){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN4, LOW);
          digitalWrite(IN3, HIGH);
      }
      if (data_array[0] == 01 && data_array[1] == 10){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN4, HIGH);
          digitalWrite(IN3, LOW);
      }
      if (data_array[0]== 10 && data_array[1] == 01){
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN4, LOW);
          digitalWrite(IN3, HIGH);
      }
      analogWrite(PWM1, data_array[2]);
      analogWrite(PWM2, data_array[3]);
    }
  }  
}
