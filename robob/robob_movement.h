#ifndef ROBOB_MOVEMENT_H
#define ROBOB_MOVEMENT_H

#include <Servo.h>
#define S1_PIN 2
#define S2_PIN 3
#define S3_PIN 4

#define STD_DELAY 1000
#define BTW_POS_DELAY 1500
#define DELAY 30

Servo DownServo;
Servo MiddleServo;
Servo UpperServo;

const int moving_height = 50;

void write_angles(const int down_servo_angle, const int middle_servo_angle, const int upper_servo_angle) {

  MiddleServo.write(moving_height);
  delay(BTW_POS_DELAY);
  DownServo.write(down_servo_angle);
  delay(BTW_POS_DELAY);
  UpperServo.write(upper_servo_angle);
  delay(BTW_POS_DELAY);
  MiddleServo.write(middle_servo_angle);
}

void move_to_pos_0() {

  const int down_servo_angle = 25;
  const int middle_servo_angle = 50;
  const int upper_servo_angle = 40;

  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_9() {
  const int down_servo_angle = 87;
  const int middle_servo_angle = 28;
  const int upper_servo_angle = 60;
  
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_8() {
  const int down_servo_angle = 70;
  const int middle_servo_angle = 28;
  const int upper_servo_angle = 60;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_7() {
  const int down_servo_angle = 55;
  const int middle_servo_angle = 28;
  const int upper_servo_angle = 66;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_6() {
  const int down_servo_angle = 96;
  const int middle_servo_angle = 29;
  const int upper_servo_angle = 40;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_5() {
  const int down_servo_angle = 73;
  const int middle_servo_angle = 30;
  const int upper_servo_angle = 37;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_4() {
  const int down_servo_angle = 51;
  const int middle_servo_angle = 29;
  const int upper_servo_angle = 42;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_3() {
  const int down_servo_angle = 110;
  const int middle_servo_angle = 29;
  const int upper_servo_angle = 23;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_2() {
  const int down_servo_angle = 80;
  const int middle_servo_angle = 29;
  const int upper_servo_angle = 21;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_pos_1() {
  const int down_servo_angle = 40;
  const int middle_servo_angle = 29;
  const int upper_servo_angle = 27;
  write_angles(down_servo_angle, middle_servo_angle, upper_servo_angle);
}

void move_to_home_pos() {
  MiddleServo.write(moving_height);
  delay(BTW_POS_DELAY);
  move_to_pos_0();
}

void (*positions[])() = {move_to_home_pos, move_to_pos_1, move_to_pos_2,
                               move_to_pos_3, move_to_pos_4,  move_to_pos_5, 
                               move_to_pos_6,  move_to_pos_7,  move_to_pos_8, move_to_pos_9 };


#endif //ROBOB_MOVEMENT_H
