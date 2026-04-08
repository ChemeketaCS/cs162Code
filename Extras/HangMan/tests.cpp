#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using doctest::Approx;

#include "Hangman.h"

TEST_CASE("test basics")
{
  Hangman game("hello");

  CHECK(game.getWord() == "hello");
  CHECK(game.getBoard() == "_____");
  CHECK(game.getGuessedLetters() == "");
  CHECK(game.getWrongGuesses() == 0);
}
