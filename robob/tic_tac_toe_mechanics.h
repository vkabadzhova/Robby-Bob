
#ifndef TIC_TAC_TOE_MECHANICS_H
#define TIC_TAC_TOE_MECHANICS_H

#include "./robob_movement.h"

const int tic_tac_toe_size = sizeof(positions) / sizeof(positions[0]) - 1;

// TIC-TAC-TOE MECHANICS
int boardState[3][3];

#define PLAYER_BOARD_MARK 1
#define COMPUTER_BOARD_MARK 2
#define NOTHING_MARK 0

#define MAGIC_NUM_RIGHT 500
#define MAGIC_NUM_MIDDLE 920
#define MAGIC_NUM_LEFT 1000

int totalGameMoves = 0;
bool playerLed = true;

#define ROWS_NUM 3
#define COLS_NUM 3

void move_to_position(const int row, const int col) {
  Serial.println("Moving to position...");
  positions[row * 3 + col + 1]();
  delay(BTW_POS_DELAY);
  
  boardState[row][col] = 2;

  move_to_home_pos();
  delay(STD_DELAY);
}

bool BlockPlayerWin()
{
  bool done = false;

  //down diag
  if ((boardState[0][0] == PLAYER_BOARD_MARK) && (boardState[1][1] == PLAYER_BOARD_MARK) && (boardState[2][2] == 0))
  {
    boardState[2][2] = 2;
    done = true;
  }
  else if ((boardState[2][2] == PLAYER_BOARD_MARK) && (boardState[1][1] == PLAYER_BOARD_MARK) && (boardState[0][0] == 0))
  {
    boardState[0][0] = 2;
    done = true;
  }

  //up diag
  if (!done)
  {
    if ((boardState[0][2] == PLAYER_BOARD_MARK) && (boardState[1][1] == PLAYER_BOARD_MARK) && (boardState[2][0] == 0))
    {
      boardState[2][0] = 2;
      done = true;
    }
    else if ((boardState[2][0] == PLAYER_BOARD_MARK) && (boardState[1][1] == PLAYER_BOARD_MARK) && (boardState[0][2] == 0))
    {
      boardState[0][2] = 2;
      done = true;
    }
  }
  if (done) return done;

  //rows
  for (int row = 0; row < 3; row++)
  {
    if ((boardState[row][0] == PLAYER_BOARD_MARK) && (boardState[row][1] == PLAYER_BOARD_MARK) && (boardState[row][2] == 0))
    {
      move_to_position(row, 2);
      done = true;
      break;
    }
    else if ((boardState[row][0] == PLAYER_BOARD_MARK) && (boardState[row][1] == 0) && (boardState[row][2] == PLAYER_BOARD_MARK))
    {
      move_to_position(row, 1);
      done = true;
      break;
    }
    else if ((boardState[row][0] == 0) && (boardState[row][1] == PLAYER_BOARD_MARK) && (boardState[row][2] == PLAYER_BOARD_MARK))
    {
      move_to_position(row, 0);
      done = true;
      break;
    }
  }
  if (done) return done;

  //cols
  for (int col = 0; col < 3; col++)
  {
    if ((boardState[0][col] == PLAYER_BOARD_MARK) && (boardState[1][col] == PLAYER_BOARD_MARK) && (boardState[2][col] == 0))
    {
      move_to_position(2, col);
      done = true;
      break;
    }
    else if ((boardState[0][col] == PLAYER_BOARD_MARK) && (boardState[1][col] == 0) && (boardState[2][col] == PLAYER_BOARD_MARK))
    {
      move_to_position(1, col);
      done = true;
      break;
    }
    else if ((boardState[0][col] == 0) && (boardState[1][col] == PLAYER_BOARD_MARK) && (boardState[2][col] == PLAYER_BOARD_MARK))
    {
      move_to_position(0, col);
      done = true;
      break;
    }
  }
  return done;
}

bool FindComputerWin()
{
  bool done = false;

  //down diag
  if ((boardState[0][0] == 2) && (boardState[1][1] == 2) && (boardState[2][2] == 0))
  {
    move_to_position(2, 2);
    done = true;
  }
  else if ((boardState[2][2] == 2) && (boardState[1][1] == 2) && (boardState[0][0] == 0))
  {
    move_to_position(0, 0);
    done = true;
  }

  //up diag
  if (!done)
  {
    if ((boardState[0][2] == 2) && (boardState[1][1] == 2) && (boardState[2][0] == 0))
    {
      move_to_position(2, 0);
      done = true;
    }
    else if ((boardState[2][0] == 2) && (boardState[1][1] == 2) && (boardState[0][2] == 0))
    {
      move_to_position(0, 2);
      done = true;
    }
  }
  if (done) return done;

  //rows
  for (int row = 0; row < 3; row++)
  {
    if ((boardState[row][0] == 2) && (boardState[row][1] == 2) && (boardState[row][2] == 0))
    {
      move_to_position(row, 2);
      done = true;
      break;
    }
    else if ((boardState[row][0] == 2) && (boardState[row][1] == 0) && (boardState[row][2] == 2))
    {
      move_to_position(row, 1);
      done = true;
      break;
    }
    else if ((boardState[row][0] == 0) && (boardState[row][1] == 2) && (boardState[row][2] == 2))
    {
      move_to_position(row, 0);
      done = true;
      break;
    }
  }
  if (done) return done;

  //cols
  for (int col = 0; col < 3; col++)
  {
    if ((boardState[0][col] == 2) && (boardState[1][col] == 2) && (boardState[2][col] == 0))
    {
      move_to_position(2, col);
      done = true;
      break;
    }
    else if ((boardState[0][col] == 2) && (boardState[1][col] == 0) && (boardState[2][col] == 2))
    {
      move_to_position(1, col);
      done = true;
      break;
    }
    else if ((boardState[0][col] == 0) && (boardState[1][col] == 2) && (boardState[2][col] == 2))
    {
      move_to_position(0, col);
      done = true;
      break;
    }
  }
  return done;
}

void ComputerMove()
{
  bool done = false;
  delay(STD_DELAY);
  if (totalGameMoves == 1)
  {
    //if first player move isn't the center, take the center
    if (boardState[1][1] == 0)
    {
      move_to_position(1, 1);
    }
    else // take any corner.  A side could equal a loss later.
    {
      int row = random(0, 2) << 1;
      int col = random(0, 2) << 1;

      Serial.print("row:");
      Serial.println(row);
      Serial.print("col:");
      Serial.println(col);
      move_to_position(row, col);
    }
  }

  if (totalGameMoves == 2)
  {
    done = false;
    // if player has 2 in a row, block it
    done = BlockPlayerWin();

    // look for any doubling traps.
    if (!done)
    {
      // Corner-opposite corner.  Take any side.  Corner would lead to loss.
      if (((boardState[0][0] == PLAYER_BOARD_MARK) && (boardState[2][2] == PLAYER_BOARD_MARK)) ||
          ((boardState[0][2] == PLAYER_BOARD_MARK) && (boardState[2][0] == PLAYER_BOARD_MARK)))
      {
        int row = random(0, 3);
        int col = 1;
        if (row == 1) col = random(0, 2) << 1;
        move_to_position(row, col);
        done = true;
      }

      // Side-corner. Take inside corner.
      //top-center plus corner
      if (!done && (boardState[0][1] == PLAYER_BOARD_MARK))
      {
        if (boardState[2][0] == PLAYER_BOARD_MARK)
        {
          move_to_position(0, 0);
          done = true;
        }
        else if (boardState[2][2] == PLAYER_BOARD_MARK)
        {
          move_to_position(0, 2);
          done = true;
        }
      }

      //bottom -center plus corner
      if (!done && (boardState[2][1] == PLAYER_BOARD_MARK))
      {
        if (boardState[0][0] == PLAYER_BOARD_MARK)
        {
          move_to_position(2, 0);
          done = true;
        }
        else if (boardState[0][2] == PLAYER_BOARD_MARK)
        {
          move_to_position(2, 2);
          done = true;
        }
      }

      //center-left plus corner
      if (!done && (boardState[1][0] == PLAYER_BOARD_MARK))
      {
        if (boardState[0][2] == PLAYER_BOARD_MARK)
        {
          move_to_position(0, 0);
          done = true;
        }
        else if (boardState[2][2] == PLAYER_BOARD_MARK)
        {
          move_to_position(2, 0);
          done = true;
        }
      }

      //center-right plus corner
      if (!done && (boardState[1][2] == PLAYER_BOARD_MARK))
      {
        if (boardState[0][0] == PLAYER_BOARD_MARK)
        {
          move_to_position(0, 2);
          done = true;
        }
        else if (boardState[2][0] == PLAYER_BOARD_MARK)
        {
          move_to_position(2, 2);
          done = true;
        }
      }

      // Center-corner (if computer has opposite corner).  Take either remaining corner.
      if (!done)
      {
        if (boardState[1][1] == PLAYER_BOARD_MARK)
        {
          if (((boardState[0][0] == 2) && (boardState[2][2] == PLAYER_BOARD_MARK)) || ((boardState[0][0] == PLAYER_BOARD_MARK) && (boardState[2][2] == 2)))
          {
            if (random(0, 2) == 1)
              move_to_position(0, 2);
            else
              move_to_position(2, 0);
            done = true;
          }
          else if (((boardState[0][2] == 2) && (boardState[2][0] == PLAYER_BOARD_MARK)) || ((boardState[0][2] == PLAYER_BOARD_MARK) && (boardState[2][0] == 2)))
          {
            if (random(0, 2) == 1)
              move_to_position(0, 0);
            else
              move_to_position(2, 2);
            done = true;
          }
        }
      }

      // Otherwise take any random spot
      if (!done)
      {
        int row = 1;
        int col = 1;
        do
        {
          row = random(0, 3);
          col = random(0, 3);
        }
        while (boardState[row][col] > 0);

        move_to_position(row, col);
      }
    }
  }

  if (totalGameMoves >= 3)
  {
    done = false;
    //if we have 2 in a row and can get 3 to win, do it
    done = FindComputerWin();

    //if player has 2 in a row, block it
    if (!done) done = BlockPlayerWin();

    //else todo?

    // take any random spot
    if (!done)
    {
      int row = 1;
      int col = 1;
      do
      {
        row = random(0, 3);
        col = random(0, 3);
      }
      while (boardState[row][col] > 0);

      move_to_position(row, col);
    }
  }
}


bool HasWinner()
{
  for (int player = 1; player < 3; player++)
  {
    if (boardState[0][0] == player)
    {
      if ((boardState[1][1] == player) && (boardState[2][2] == player)) return true; // right-down diag
      if ((boardState[1][0] == player) && (boardState[2][0] == player)) return true; //col 1
      if ((boardState[0][1] == player) && (boardState[0][2] == player)) return true; // row 1
    }
    if ((boardState[1][0] == player) && (boardState[1][1] == player) && (boardState[1][2] == player)) return true; //row 2
    if ((boardState[2][0] == player) && (boardState[2][1] == player) && (boardState[2][2] == player)) return true; //row 3
    if ((boardState[0][1] == player) && (boardState[1][1] == player) && (boardState[2][1] == player)) return true; //col 2
    if ((boardState[0][2] == player) && (boardState[1][2] == player) && (boardState[2][2] == player)) return true; //col 3

    if ((boardState[2][0] == player) && (boardState[1][1] == player) && (boardState[0][2] == player)) return true; //right-up diag
  }
  return false;
}

void FlashEqual() {
  for (int i = 0; i < 5; ++i)
  {
    Serial.println("No winner - you're equal with Robob!");
  }
}

void FlashWinner(int playerOrComp)
{
  String who = (playerOrComp == PLAYER_BOARD_MARK) ? "PLAYER" : "ROBOB";
  for (int i = 0; i < 10; ++i)
  {
    Serial.print(who);
    Serial.println(" won!");
  }
}

void ResetGame()
{
  delay(500);
  totalGameMoves = 0;
  //FlashWinner erases the boardState array.  But there may have been a tie.  So erase anyway.
  for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
      boardState[row][col] = 0;
  Serial.println("\n\n\nGAME RESETED! Now it's your turn.");
}

bool UserInputValid(int button)
{
  int result = false;

  button--;
  int row = button / 3;
  int col = button % 3;

  if (boardState[row][col] == 0) result = true;

  return result;
}


int GetButton()
{
  int btnRow1 = analogRead(A0);
  int btnRow2 = analogRead(A1);
  int btnRow3 = analogRead(A2);

  const int buffer_range = 20;

  if (btnRow1 >= MAGIC_NUM_LEFT && btnRow1 <= MAGIC_NUM_LEFT + buffer_range) return 8;
  if (btnRow1 >= MAGIC_NUM_MIDDLE && btnRow1 <= MAGIC_NUM_MIDDLE + buffer_range) return 7;
  if (btnRow1 >= MAGIC_NUM_RIGHT && btnRow1 <= MAGIC_NUM_RIGHT + buffer_range) return 6;

  if (btnRow2 >= MAGIC_NUM_LEFT && btnRow2 <= MAGIC_NUM_LEFT + buffer_range) return 5;
  if (btnRow2 >= MAGIC_NUM_MIDDLE && btnRow2 <= MAGIC_NUM_MIDDLE + buffer_range) return 4;
  if (btnRow2 >= MAGIC_NUM_RIGHT && btnRow2 <= MAGIC_NUM_RIGHT + buffer_range) return 3;

  if (btnRow3 >= MAGIC_NUM_LEFT && btnRow3 <= MAGIC_NUM_LEFT + buffer_range) return 2;
  if (btnRow3 >= MAGIC_NUM_MIDDLE && btnRow3 <= MAGIC_NUM_MIDDLE + buffer_range) return 1;
  if (btnRow3 >= MAGIC_NUM_RIGHT && btnRow3 <= MAGIC_NUM_RIGHT + buffer_range) return 0;

  return -1;
}

void DrawTicTacToe() {
  for (short i = 0; i < 40; ++i) {
    Serial.println();
  }

  for (int i = 0; i < ROWS_NUM; ++i) {
    Serial.print("| ");
    String current_player_sign = " ";
    for (int j = 0; j < COLS_NUM; ++j) {
      if (boardState[i][j] == PLAYER_BOARD_MARK) {
        Serial.print("X | ");
      }
      else if (boardState[i][j] == 2) {
        Serial.print("O | ");
      }
      else {
        Serial.print("  | ");
      }

    }

    Serial.println("\n");
  }

  for (int i = 0; i < 10; ++i) {
    Serial.println();
  }
}

#endif //TIC_TAC_TOE_MECHANICS_H
