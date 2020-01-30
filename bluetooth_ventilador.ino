//bluetooth hc-06
//Se utiliza el pin 11 ya que tiene capacidad PWM (como los pines 3,5,6,9,10,11) permite modificar
//la cantidad de energía que se envía a una carga

const int FAN=11;
int state = 0; // Variable lectura serial
 
void setup() {
    pinMode(FAN, OUTPUT);   //Declara pin de salida
    analogWrite(FAN,0);
    Serial.begin(9600);
}
void loop() {
 //si el módulo manda un dato, guardarlo en estado.
  if(Serial.available() > 0){
       state = Serial.read();
  }
 
//si el estado es 0 sería Apagado “OFF” para el ventilador
 if (state == '0') {
    analogWrite(FAN,0);
    Serial.println("FAN: off");
 }
 //de lo contrario si el estado es 1 sería Encendido “ON” para el ventilador con una velocidad baja
 else
 if (state == '1') {
     for  (int i=1;i<100; i++){
analogWrite(FAN,i);
delay(5);}
     Serial.println("FAN: on");
 }
 //de lo contrario si el estado es 2 sería aumentar la velocidad a media para el ventilador
 else
 if (state == '2') {
     analogWrite(FAN,155);
     Serial.println("FAN: medio");
 }
//de lo contrario si el estado es 3 sería aumentar la velocidad alta para el ventilador
 else
 if (state == '3') {
     analogWrite(FAN,255);
     Serial.println("FAN: alta");
 }
}
