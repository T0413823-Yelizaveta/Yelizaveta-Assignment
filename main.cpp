#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Inventory {
private:
    vector<string> items;  // list of items(only names)

public:
    //Methods
    // Add item
    void addItem(const string& itemName);

    // Remove
    void removeItem(const string& itemName);

    // Check availability
    bool hasItem(const string& itemName) const;

    // output list items
    void showItems() const;
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
    // Methods for managing mental health
    void increaseMentalHealth(int amount);
    void decreaseMentalHealth(int damage);

    // Methods for managing SurvivalRate
    void increaseSurvivalRate(int amount);
    void decreaseSurvivalRate(int amount);

    // Check status
    void checkStatus() const;
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

