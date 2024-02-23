int data_length=3;
int data_array[64];
int pins[6] = {3,4,5,6,10,11};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (int i=0; i<6; i++) {
  pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available()>0) {
  char incomingByte = Serial.read();
    if(incomingByte == '#'){
      for (int j=0; j<data_length; j++) {
      data_array[j] = Serial.parseInt();
      }
      if(data_array[0] == 1010){
        digitalWrite(pins[0], 1);
        digitalWrite(pins[1], 0);
        digitalWrite(pins[2], 1);
        digitalWrite(pins[3], 0);
      }
      if (data_array[0]== 1111) {
        digitalWrite(pins[0], 1);
        digitalWrite(pins[1], 1);
        digitalWrite(pins[2], 1);
        digitalWrite(pins[3], 1);
      }
      if (data_array[0] == 0000) {
        digitalWrite(pins[0], 0);
        digitalWrite(pins[1], 0);
        digitalWrite(pins[2], 0);
        digitalWrite(pins[3], 0);
      }
      if (data_array[0]== 101) {
        digitalWrite(pins[0], 0);
        digitalWrite(pins[1], 1);
        digitalWrite(pins[2], 0);
        digitalWrite(pins[3], 1);
      }
      if (data_array[0]== 110) {
        digitalWrite(pins[0], 0);
        digitalWrite(pins[1], 1);
        digitalWrite(pins[2], 1);
        digitalWrite(pins[3], 0);
      }
      if (data_array[0]== 1001) {
        digitalWrite(pins[0], 1);
        digitalWrite(pins[1], 0);
        digitalWrite(pins[2], 0);
        digitalWrite(pins[3], 1);
      }
      analogWrite(pins[4], data_array[1]);
      analogWrite(pins[5], data_array[2]);
    }
  }  
}
