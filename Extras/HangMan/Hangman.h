#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

/**
 * @class Hangman
 * @brief Manages the state and rules for a simple Hangman game.
 */
class Hangman {
 public:
  /**
   * @brief Creates a new Hangman game for the given word.
   * @param word The word the player must guess.
   */
  explicit Hangman(const std::string& word);

  /**
   * @brief Applies a guessed letter to the current game state.
   * @param guess The guessed character.
   */
  void makeGuess(char guess);

  /**
   * @brief Checks whether the game has ended.
   * @return True if the player has won or used all allowed wrong guesses.
   */
  bool isDone() const;

  /**
   * @brief Checks whether the player has guessed the entire word.
   * @return True if the board matches the word.
   */
  bool isWin() const;

  /**
   * @brief Gets the current board display.
   * @return The board string with guessed letters revealed.
   */
  std::string getBoard() const;

  /**
   * @brief Gets the secret word.
   * @return The full word for this game.
   */
  std::string getWord() const;

  /**
   * @brief Gets the list of guessed letters as a printable string.
   * @return A space-separated string of guessed letters.
   */
  std::string getGuessedLetters() const;

  /**
   * @brief Gets the number of incorrect guesses made.
   * @return The wrong guess count.
   */
  int getWrongGuesses() const;

 private:
  std::string m_word;
  std::string m_board;
  std::vector<char> m_guessedLetters;
  int m_wrongGuesses;
};

#endif