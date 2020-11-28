

float acuan=2.5;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(9,OUTPUT);
 pinMode(8,INPUT);
pinMode(7,INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  int limit = digitalRead(8); 
  int limit2 = digitalRead(7);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  Serial.println(limit);
  
 if(voltage >= acuan  && limit == 0 && limit2 == 1){
  digitalWrite(9, LOW);
  }else if(voltage <  acuan  && limit == 0 && limit2 == 1){
    digitalWrite(9, HIGH);
    }
  else if(voltage <  acuan  && limit == 0 && limit2 == 0){
    digitalWrite(9, HIGH);
    }
    else if(voltage <  acuan  && limit == 1 && limit2 == 0){
    digitalWrite(9, LOW);
    }
     else if(voltage >=  acuan  && limit == 1 && limit2 == 0){
    digitalWrite(9, HIGH);
    }
    else if(voltage >=  acuan  && limit == 0 && limit2 == 0){
    digitalWrite(9, HIGH);
    }
  else{
  digitalWrite(9, LOW);
  }

}
