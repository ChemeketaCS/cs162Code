#include <iostream>
#include <string>
#include "PlayerList.h"
using namespace std;

PlayerList::PlayerList(int size) {
    if (size <= 0) {
        throw invalid_argument("Size must be positive");
    }
    m_size = size;
    m_players = new string[m_size]; // allocate memory for the array
}

PlayerList::~PlayerList() {
    delete[] m_players; // deallocate memory for the array
    cout << "**PlayerList destroyed and memory freed.**" << endl;
}

PlayerList::PlayerList(const PlayerList& other) {
    // Copy non-pointer members
    m_size = other.m_size;

    // Allocate own dynamic storage
    m_players = new string[m_size];

    // Copy the contents from the other PlayerList
    for (int i = 0; i < m_size; ++i) {
        m_players[i] = other.m_players[i];
    }
}

PlayerList& PlayerList::operator=(const PlayerList& other) {
    // Check for self-assignment
    if (this != &other) { 
        // Deallocate existing memory
        delete[] m_players;

        // Copy non-pointer members
        m_size = other.m_size;

        // Allocate own dynamic storage
        m_players = new string[m_size];

        // Copy the contents from the other PlayerList
        for (int i = 0; i < m_size; ++i) {
            m_players[i] = other.m_players[i];
        }
    }
    return *this;  // Return the current object
}

void PlayerList::setPlayerName(int index, const string& name) {
    if (index < 0 || index >= m_size) {
        throw out_of_range("Index out of range");
    }
    m_players[index] = name; // set the player name at the given index
}

void PlayerList::print() const {
    cout << "Player List: ";
    for (int i = 0; i < m_size; ++i) {
        cout << m_players[i] << " ";
    }
    cout << endl;
}

