#ifndef PLAYERLIST_H
#define PLAYERLIST_H

#include <string>

class PlayerList {
private:
  std::string* m_players; // pointer to the array of player names
  int m_size;             // number of players in the list
public:
  PlayerList(int size);

  // Rule of Three:
  ~PlayerList();                                  // Destructor
  PlayerList(const PlayerList& other);            // Copy constructor
  PlayerList& operator=(const PlayerList& other); // Assignment operator

  void setPlayerName(int index, const std::string& name);

  void print() const;
};

#endif // PLAYERLIST_H