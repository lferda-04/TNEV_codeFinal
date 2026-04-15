#include <Ultrasonic.h>


Ultrasonic ultrasonic1(6, 7);
Ultrasonic ultrasonic2(8, 9);

const int pinMoteur1_reculer = 3; // Moteur droit
const int pinMoteur1_avancer = 2; // Moteur droit
const int pinMoteur2_avancer = 4; // Moteur gauche
const int pinMoteur2_reculer = 5; // Moteur gauche

int distance1 = 0;
int distance2 = 0;

int obstacleCount = 0;

//Functions==================================================================================

void initRobot() {
  Serial.begin(9600);
  pinMode(pinMoteur1_avancer, OUTPUT);
  pinMode(pinMoteur1_reculer, OUTPUT);
  pinMode(pinMoteur2_avancer, OUTPUT);
  pinMode(pinMoteur2_reculer, OUTPUT);
}
void forward() {
  digitalWrite(pinMoteur1_avancer, HIGH);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, HIGH);
  digitalWrite(pinMoteur2_reculer, LOW);
}

void stopMotors() {
  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, LOW);
}

void turnRight() {
  digitalWrite(pinMoteur1_avancer, HIGH);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, HIGH);
}

void turnLeft() {
  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, HIGH);
  digitalWrite(pinMoteur2_avancer, HIGH);
  digitalWrite(pinMoteur2_reculer, LOW);
}

void adjustLeft() {
  digitalWrite(pinMoteur1_avancer, LOW);
  digitalWrite(pinMoteur1_reculer, HIGH);
  digitalWrite(pinMoteur2_avancer, HIGH);
  digitalWrite(pinMoteur2_reculer, LOW);
  delay(200);
}

void adjustRight() {
  digitalWrite(pinMoteur1_avancer, HIGH);
  digitalWrite(pinMoteur1_reculer, LOW);
  digitalWrite(pinMoteur2_avancer, LOW);
  digitalWrite(pinMoteur2_reculer, HIGH);
  delay(200);
}

void advanceSlightly() {
  forward();
  delay(700); // Avancer pendant 300ms avant de tourner
  stopMotors();
}
// end functions ============================================================================

// main Function ============================================================================

void detectAndAvoidObstacles() {

  distance1 = ultrasonic1.read();
  distance2 = ultrasonic2.read();

  if (distance1 < 50 || distance2 < 50) {
    stopMotors();
    delay(500);
    long confirmRight = ultrasonic1.read();
    long confirmLeft = ultrasonic2.read();

    if (confirmRight < 50 || confirmLeft < 50) {
      advanceSlightly();
      if (distance1 < distance2) {
        turnLeft();
        delay(1000);
        adjustLeft();
      } else {
        turnRight();
        delay(700);
        adjustRight();
      }
      obstacleCount++;
    } else {
      forward();
    }
  } else {
    forward();
  }
  delay(100);
}

// end main Function=========================================================================

void setup() {
  initRobot();
}

void loop() {
  detectAndAvoidObstacles();
}
