#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>
#include <Ultrasonic.h>

extern Ultrasonic ultrasonic1; // Capteur droit
extern Ultrasonic ultrasonic2; // Capteur gauche

extern int distance1;
extern int distance2;
extern int direction; // 0: Avant, 1: Gauche, 2: Droite

extern int obstacleCount;

const int pinMoteur1_reculer = 3; // Moteur droit
const int pinMoteur1_avancer = 2; // Moteur droit
const int pinMoteur2_avancer = 4; // Moteur gauche
const int pinMoteur2_reculer = 5; // Moteur gauche

void initRobot();
void detectAndAvoidObstacles();
void forward();
void stopMotors();
void turnRight();
void turnLeft();
void adjustLeft();
void adjustRight();
void advanceSlightly();

#endif
