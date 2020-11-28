  #include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
String perintah;
int relay1 = 6;

void setup() {
  BT.begin(9600);
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
 }
void loop() {
  while (BT.available()) {
  delay(10);
  char c = BT.read();
  perintah += c;
  Serial.println();
}
  if(perintah.length() > 0) {
  Serial.println(perintah);
      
  // perintah dibawah ini dapat anda sesuaikan dengan perintah anda gan :v
  if (perintah == "sekarang sudah malam")
 { digitalWrite(relay1, LOW); }
  else if(perintah == "sekarang sudah siang")
 { digitalWrite(relay1, HIGH); }
  
perintah="";}}
