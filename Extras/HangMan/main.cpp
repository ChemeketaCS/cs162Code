#include <iostream>

#include "Hangman.h"

using namespace std;


int main () {
  Hangman game("hello");

  while(!game.isDone()) {
    cout << "Current board: " << game.getBoard() << endl;
    cout << "Guessed letters: " << game.getGuessedLetters() << endl;
    cout << "Wrong guesses: " << game.getWrongGuesses() << endl;

    cout << "Enter a letter to guess: ";
    char guess;
    cin >> guess;
    game.makeGuess(guess);
  }

  if ( game.isWin() ) {
    cout << "Congratulations! You've guessed the word: " << game.getWord() << endl;
  } else {
    cout << "Game over! The correct word was: " << game.getWord() << endl;
  }
}