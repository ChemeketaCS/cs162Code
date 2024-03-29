#include <cstring> //memcpy
#include <iostream>
using namespace std;

const int MAZE_SIZE = 10;
const int INVALID_PATH_SIZE = 100;

void printMaze(char curMaze[MAZE_SIZE][MAZE_SIZE]) {
  // column headers
  cout << " ";
  for (int c = 0; c < MAZE_SIZE; c++)
    cout << c;
  cout << endl;

  for (int r = 0; r < MAZE_SIZE; r++) {
    cout << r; // row header
    for (int c = 0; c < MAZE_SIZE; c++) {
      cout << curMaze[r][c];
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
}

void copyMaze(char source[MAZE_SIZE][MAZE_SIZE],
              char newCopy[MAZE_SIZE][MAZE_SIZE]) {
  for (int r = 0; r < MAZE_SIZE; r++) {
    for (int c = 0; c < MAZE_SIZE; c++) {
      newCopy[r][c] = source[r][c];
    }
  }
}

// returns the length of path to the goal
int findPath(char maze[MAZE_SIZE][MAZE_SIZE], int startRow, int startCol,
             int goalRow, int goalCol) {
  if (startRow < 0 || startCol < 0 || startRow >= MAZE_SIZE
      || startCol >= MAZE_SIZE) {
    return INVALID_PATH_SIZE; // went out of bounds - return a length that says
                              // "can't be done"
  }
  if (maze[startRow][startCol] != ' ') {
    return INVALID_PATH_SIZE; // hit wall/our path - return a length that says
                              // "can't be done"
  }
  if (startRow == goalRow && startCol == goalCol) {
    // found it
    // printMaze(maze);  //show the path first
    return 0; // return - 0 : no more cost to get to goal
  }

  // copy the maze
  char updatedMaze[MAZE_SIZE][MAZE_SIZE];
  copyMaze(maze, updatedMaze);

  // mark our copy with the move
  updatedMaze[startRow][startCol] = '.';

  // printMaze(updatedMaze);

  int cost1 =
      findPath(updatedMaze, startRow, startCol - 1, goalRow, goalCol); // left
  int cost2 =
      findPath(updatedMaze, startRow, startCol + 1, goalRow, goalCol); // right
  int cost3 =
      findPath(updatedMaze, startRow - 1, startCol, goalRow, goalCol); // up
  int cost4 =
      findPath(updatedMaze, startRow + 1, startCol, goalRow, goalCol); // down

  // return 1 (this move) + minimum of the 4 possible child moves
  int minChild = min(cost1, cost2);
  minChild = min(minChild, cost3);
  minChild = min(minChild, cost4);
  return 1 + minChild;
}

int main() {
  char maze[MAZE_SIZE][MAZE_SIZE] = {
      {'#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#'},
      {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
      {'#', ' ', ' ', '#', ' ', '#', '#', ' ', '#', '#'},
      {' ', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#'},
      {' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
      {' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#'},
      {' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
      {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
      {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#'}};

  printMaze(maze);

  cout << "Enter start row & col with space between:" << endl;
  int startrow = 0;
  int startcol = 0;
  cin >> startrow >> startcol;

  cout << "Enter destination row & col with space between:" << endl;
  int destrow = 0;
  int destcol = 0;
  cin >> destrow >> destcol;

  int length = findPath(maze, startrow, startcol, destrow, destcol);
  if (length < INVALID_PATH_SIZE)
    cout << "That takes " << length << " steps";
  else
    cout << "Can't get there from here";

  return 0;
}
