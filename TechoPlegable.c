#include <Servo.h>

int servoPin = 9; // Pin digital donde está conectado el servomotor
Servo servo_9; // Objeto Servo que permite controlar el servomotor
float pos;



int ldrPin = A0; // Pin analógico donde está conectada la fotocelda
int thresholdValue = 560; // Umbral de luz

void setup() {
Serial.begin(9600);
  servo_9.attach(servoPin); // Inicializa el servomotor en el pin 9
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Lee el valor de la fotocelda
  Serial.println(ldrValue);
  delay(170);
  if (ldrValue < thresholdValue) { // Si el valor de la fotocelda es menor al umbral
    abrirTecho(); // Abre el techo
  } else { // Si el valor de la fotocelda es mayor o igual al umbral
    cerrarTecho(); // Cierra el techo
  }
}

void abrirTecho() {
  
  for (pos; pos <= 155; pos += 4) {
    // Mueve el servomotor desde el ángulo actual hasta 180 grados
    servo_9.write(pos);
    delay(30); // Espera en milisegundos para que el servomotor llegue a la posición
  }
}

void cerrarTecho() {
  
  for (pos; pos >= 0; pos -= 4) {
    // Mueve el servomotor desde el ángulo actual hasta 0 grados
    servo_9.write(pos);
    delay(30); // Espera en milisegundos para que el servomotor llegue a la posición
  }
}