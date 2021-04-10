#include <Servo.h>
#define S1_PIN 2
#define S2_PIN 3
#define S3_PIN 4

#define STD_DELAY 1500
#define DELAY 15

Servo DownServo;
Servo MiddleServo;
Servo UpperServo;

int servo_position = 0;

const int floating_position = 40;

/*void move_to_pos_1() {
  UpperServo.write(20);
}*/

void move_to_pos_9() {
  const int down_angle = 58;
  const int middle_angle = 29;
  const int upper_angle = 18;

  MiddleServo.write(floating_position);
  delay(STD_DELAY);
  DownServo.write(down_angle);
  delay(STD_DELAY);
  UpperServo.write(upper_angle);
  delay(STD_DELAY);
  MiddleServo.write(middle_angle);
  
}

void move_to_setup_pos() {
  const int down_angle = 40;
  const int middle_angle = 29;
  const int upper_angle = 15;
  
  DownServo.write(down_angle);
  MiddleServo.write(middle_angle);
  UpperServo.write(upper_angle);
}

void setup() {
  DownServo.attach(S1_PIN);
  MiddleServo.attach(S2_PIN);
  UpperServo.attach(S3_PIN);
  
  move_to_setup_pos();
  delay(STD_DELAY);
  Serial.begin(9600);
}


void loop() {
  //Serial.println("Loop starts");
    delay(STD_DELAY);
    move_to_pos_9();
  
    delay(STD_DELAY);
    move_to_setup_pos();
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
