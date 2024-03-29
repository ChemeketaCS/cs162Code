#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

struct BingoCell {
  int num = 0;
  bool marked = false;
};

struct BingoBoard {
  // 25 items representing 5x5 grid 0-4 are row 1, 5-9 are row 2...
  // 0  1  2  3  4
  // 5  6  7  8  9
  // 10 11 12 13 14...
  vector<BingoCell> squares = vector<BingoCell>(25);

  // Debug helper
  string toString() {
    stringstream s;
    int count = 0;
    for (const BingoCell& cell : squares) {
      s << cell.num;
      if (cell.marked)
        s << 'X';

      if (count++ % 5 == 4)
        s << endl;
      else
        s << '\t';
    }
    return s.str();
  }
};

BingoBoard readBoard(istream& in) {
  BingoBoard b;
  for_each(b.squares.begin(), b.squares.end(),
           [&in](BingoCell& c) { in >> c.num; });
  return b;
}

// See if given board has won
bool isWinner(const BingoBoard& board) {
  for (int i = 0; i < 5; i++) {
    // Check row i
    // Rows are 5 contiguous items starting at 0, 5, 10...
    auto rowStart = board.squares.begin() + i * 5;
    bool win = all_of(rowStart, rowStart + 5,
                      [](const BingoCell& c) { return c.marked; });
    if (win)
      return true;

    // Check col i
    // Columns are not contiguous - can't use all_of on them, must loop through
    // rows
    win = true;
    for (int r = 0; r < 5; r++) {
      if (!board.squares[r * 5 + i].marked) {
        win = false;
        break;
      }
    }
    if (win)
      return true;
  }
  return false;
}

// Mark given number on given board
void markBoard(BingoBoard& board, int num) {
  // Look for given value on board, if present, mark that square
  auto square = find_if(board.squares.begin(), board.squares.end(),
                        [num](const BingoCell& c) { return c.num == num; });
  // Last parameter is a lambda function - an anonymous function
  //[num] - capture num from the context of this lambda. Means we can talk about
  //"num" inside the lambda (const BingoCell& c) - the parameter that find_if
  //will pass is each single cell. It will be called c and be passed by
  //reference { return c.num == num; } - body of the function, needs to return
  //true if find_if should select this item

  if (square != board.squares.end()) {
    square->marked = true;
  }
}

// Find total of all unmarked squares on given board
int getSumOfUnmarked(const BingoBoard& board) {
  // Use std::accumulate to add all the unmarked
  BingoCell sum = accumulate(board.squares.begin(), board.squares.end(),
                             BingoCell(), // start with empty cell
                             [](BingoCell& total, const BingoCell& c) {
                               if (!c.marked)
                                 total.num += c.num;
                               return total;
                             });
  // accumulate will take the empty BingoCell with num of 0 and keep passing it
  // to the lambda
  //[] - capture no variables
  //(BingoCell& total, const BingoCell& c) - first param is what we are building
  //up, second is current value body updates total's num if current cell was not
  // marked

  return sum.num;
}

int main() {
  ifstream in("input.txt");
  if (!in)
    cout << "Error opening file - Check working directory";

  // Get first line into stringstream so we can parse it using getline later
  string firstLine;
  getline(in, firstLine);
  stringstream firstStream(firstLine);

  // Read in all boards
  vector<BingoBoard> boards;
  while (!in.eof()) {
    BingoBoard b = readBoard(in);
    boards.push_back(b);
  }

  // Winner will eventually be set to the board that wins
  auto winner = boards.end();
  while (winner == boards.end()) {
    int curNum;
    firstStream >> curNum;

    for (auto& b : boards)
      markBoard(b, curNum);

    winner = find_if(boards.begin(), boards.end(), isWinner);
  }

  cout << winner->toString();
  cout << "-------------" << endl;

  int sum = getSumOfUnmarked(*winner);
  cout << sum << endl;
}
