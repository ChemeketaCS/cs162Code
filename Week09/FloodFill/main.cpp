#include <iostream>
#include <vector>
using namespace std;

void printMaze(const vector<vector<char>>& curMaze) {
  size_t rows = curMaze.size();
  size_t cols = curMaze.at(0).size();
  for (size_t r = 0; r < rows; r++) {
    for (size_t c = 0; c < cols; c++) {
      cout << curMaze.at(r).at(c);
    }
    cout << endl;
  }
  cout << endl << endl;
}

void floodFill(vector<vector<char>>& picture, size_t curRow, size_t curCol) {
  size_t rows = picture.size();
  size_t cols = picture.at(0).size();

  // if using int's for curRow/curCol, check for negative here too
  if (curRow >= rows || curCol >= cols) {
    return; // went out of bounds - done
  }

  if (picture.at(curRow).at(curCol) != ' ') {
    return; // hit a filled square - done
  }

  // mark the current square
  picture.at(curRow).at(curCol) = '.';
  printMaze(picture); // show what it looks like now

  floodFill(picture, curRow, curCol - 1); // left
  floodFill(picture, curRow, curCol + 1); // right
  floodFill(picture, curRow - 1, curCol); // up
  floodFill(picture, curRow + 1, curCol); // down
}

int main() {
    vector<vector<char>> picture = {
        {'#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', '#', ' ', ' ', '#', ' ', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {'#', '#', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
        {' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#'}};

    printMaze(picture);

    int row = 7;
    int col = 6;

    floodFill(picture, row, col);
}