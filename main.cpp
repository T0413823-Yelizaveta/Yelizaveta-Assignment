#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Inventory {
private:
    vector<string> items;  // list of items(only names)

public:
    void addItem(const string& itemName);   // Add item
    void removeItem(const string& itemName); // Remove
    bool hasItem(const string& itemName) const; // Check availability
    void showItems() const;                    // output list items
};

class Player {
private:
    string playerName;
    int mentalHealth;
    int survivalRate;
    bool isAlive;
    Inventory inventory;

public:
    Player(string name, int health, int survivalRate)
{
    cout << "Player Name: " << playerName << endl;
}
};


class Game {

};

class Choice {

};

class Event {

};



int main() {

    string playerName;
    cout << "Enter your name: ";
    cin >> playerName;
    cout << "Добро пожаловать в игру, " << playerName << "!";

}

