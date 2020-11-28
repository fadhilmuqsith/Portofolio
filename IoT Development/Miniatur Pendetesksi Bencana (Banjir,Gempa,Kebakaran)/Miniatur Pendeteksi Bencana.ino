const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
int vibra;
int pinAout = A0;
int EP = 6;


void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(pinAout,INPUT);

Serial.begin(9600); // Starts the serial communication
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor

int asap = analogRead(pinAout);

long measurement =TP_init();
  delay(50);
  int tinggiAir = 9 - distance;
  long kekuatanGempa = measurement/10000;
Serial.print("Ketinggian Air: ");
Serial.print(tinggiAir);
Serial.print(" cm");
Serial.print(" Kekuatan Gempa : ");
Serial.print(kekuatanGempa);
Serial.print(" skr Deteksi Asap : ");
Serial.println(asap);

if (tinggiAir > 0){
  Serial.println("Terjadi Banjir");
}
if (kekuatanGempa > 0){
  Serial.println("Terjadi Gempa");
}
if (asap > 100){
  Serial.println("Terdeteksi Adanya Asap");
}
}

long TP_init(){
  delay(10);
  long measurement=pulseIn (EP, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
}
