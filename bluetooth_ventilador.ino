//bluetooth hc-06
const int LED=11;
int state = 0; // Variable lectura serial
 
void setup() {
    pinMode(LED, OUTPUT);   //Declara pin de Salida
    analogWrite(LED,0);
    Serial.begin(9600);
}
void loop() {
 //si el módulo a manda dato, guardarlo en estado.
  if(Serial.available() > 0){
       state = Serial.read();
  } // esta parte del código es para solo 1 Carácter o Unidad. 
 
 // si el estado es 0 ese sería Apagado “OFF”
 if (state == '0') {
    analogWrite(LED,0);
    Serial.println("LED: off");
 }
 // de lo contrario si el estado es 1 ese sería Encendido “ON”
 else
 if (state == '1') {
     for  (int i=1;i<100; i++){
analogWrite(LED,i);
delay(5);}
     Serial.println("LED: on");
 }
 else
 if (state == '2') {
     analogWrite(LED,155);
     Serial.println("LED: medio");
 }
 else
 if (state == '3') {
     analogWrite(LED,155);
     Serial.println("LED: medio");
 }
}
