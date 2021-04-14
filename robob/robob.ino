#include "robob_movement.h"
#include "tic_tac_toe_mechanics.h"

void setup() {
  DownServo.attach(S1_PIN);
  MiddleServo.attach(S2_PIN);
  UpperServo.attach(S3_PIN);

  move_to_pos_0();
  delay(STD_DELAY);

  randomSeed(analogRead(5));

  for (int i = 0; i < ROWS_NUM; ++i) {
    for (int j = 0; j < COLS_NUM; ++j) {
      boardState[i][j] = 0;
    }
  }
  
  DrawTicTacToe();

  Serial.begin(9600);
}

void loop() {
  int button = 0;
  do
  {
    button = GetButton();
  }
  while (button == -1);

  int row = button / 3;
  int col = button % 3;
  boardState[row][col] = 1;
  totalGameMoves++;

  DrawTicTacToe();
  delay(STD_DELAY);

  if (HasWinner())
  {
    FlashWinner(1);
    ResetGame();
  }
  else if (totalGameMoves == 5)
  {
    FlashEqual();
    ResetGame();
  }
  else
  {
    ComputerMove();
    delay(STD_DELAY);
    DrawTicTacToe();
    delay(STD_DELAY);

    if (HasWinner())
    {
      FlashWinner(2);
      ResetGame();
    }
  }

  delay(200);

}
