#include <Servo.h>
#define S1_PIN 2
#define S2_PIN 3
#define S3_PIN 4

#define STD_DELAY 1500
#define DELAY 30

Servo DownServo;
Servo MiddleServo;
Servo UpperServo;

int servo_position = 0;
const int moving_height = 50;

int this_down_angle;
int this_middle_angle;
int this_upper_angle;

void write_angles(const int down_angle, const int middle_angle, const int upper_angle) {
  MiddleServo.write(moving_height);
  delay(STD_DELAY);
  DownServo.write(down_angle);
  delay(STD_DELAY);
  UpperServo.write(upper_angle);
  MiddleServo.write(middle_angle);  
}

void move_to_pos_0() {

  const int down_angle = 25;
  const int middle_angle = 50;
  const int upper_angle = 40;

  write_angles(down_angle, middle_angle, upper_angle);
}

void move_to_pos_8() {

  const int down_angle = 75;
  const int middle_angle = 29;
  const int upper_angle = 24;
  write_angles(down_angle, middle_angle, upper_angle);
}

void move_to_pos_9() {

  const int down_angle = 40;
  const int middle_angle = 40;
  const int upper_angle = 33;
  write_angles(down_angle, middle_angle, upper_angle);
}

void move_to_home_pos() {
  MiddleServo.write(moving_height);
  delay(STD_DELAY);
  move_to_pos_0();
}

void setup() {
  DownServo.attach(S1_PIN);
  MiddleServo.attach(S2_PIN);
  UpperServo.attach(S3_PIN);

  move_to_pos_0();
  delay(STD_DELAY);
  Serial.begin(9600);
}


void loop() {
  //delay(STD_DELAY);
  //move_to_pos_9();
  
  delay(STD_DELAY);
  move_to_pos_8();

  delay(STD_DELAY);
  move_to_home_pos();
  /*for (; servo_position <= 90; ++servo_position) {
    DownServo.write(servo_position);
    delay(DELAY);

    MiddleServo.write(servo_position);
    delay(DELAY);

    UpperServo.write(servo_position);
    delay(DELAY);
    }

    for (servo_position = 90; servo_position > 0; --servo_position) {
    DownServo.write(servo_position);
    delay(DELAY);

    MiddleServo.write(servo_position);
    delay(DELAY);

    UpperServo.write(servo_position);
    delay(DELAY);
    }*/
}
