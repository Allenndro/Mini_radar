#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;

long duracion;
int distancia;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  Serial.begin(9600);        
  myServo.attach(12);        
  pinMode(5, OUTPUT);    
}

void loop() {
  for (int i = 15; i <= 180; i++) {
    myServo.write(i);        
    delay(30);              
    distancia = calculardistancia();  

    Serial.print(i);  
    Serial.print(",");        
    Serial.print(distancia);  
    Serial.print(".");      

    if (distancia < 10) {
      tone(5, 500, 100);  
    } else if (distancia > 20 && distancia < 40) {
      tone(5, 200, 100);
    }
  }
  for (int i = 180; i > 15; i--) {
    myServo.write(i);          
    delay(30);                
    distancia = calculardistancia();  

    Serial.print(i);  
    Serial.print(",");        
    Serial.print(distancia);  
    Serial.print(".");      

    if (distancia < 10) {
      tone(5, 500, 100);
    } else if (distancia > 20 && distancia < 40) {
      tone(5, 200, 100);  
    }
  }
}

int calculardistancia() {
  digitalWrite(trigPin, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trigPin, HIGH);      
  delayMicroseconds(10);            
  digitalWrite(trigPin, LOW);        
  duracion = pulseIn(echoPin, HIGH);

  distancia = duracion * 0.034 / 2;
  return distancia;
}
