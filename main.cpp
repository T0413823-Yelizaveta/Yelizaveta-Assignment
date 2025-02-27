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
    void addItem(const string& item) {
        items.push_back(item);
        cout << "You added to inventory: " << item << endl;
    }

    // Remove
    void removeItem(const string& item) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == item) {
                items.erase(it);
                cout<<"You removed from inventory: "<<item<<endl;
                return;
            }
        }
        cout << "Item " << item << "' is not found in inventory\n";
    }

    // Check availability
    bool hasItem(const string& item) const {
        for (const string& i : items) {
            if (i == item) {
                return true;
            }
        }
        return false;
    }

    // output list items
    void showItems() const {
        if (items.empty()) {
            cout << "Inventory is empty\n";
            return;
        }

        cout << "Your Inventory:\n";
        for (const string& item : items) {
            cout << "- " << item << endl;
        }
    }
};

class Player {
private:
    string name;
    int survivalRate;
    int mentalHealth;

    bool isAlive;
    Inventory inventory;

public:
    Player(string PlayerName) {
        name = PlayerName;
        survivalRate = 100;
    }

    string getName() {
        return name;
    }
    int getmentalHealth() {
        return mentalHealth;
    }
    int getSurvivalRate() {
        return survivalRate;
    }

    void sayHello() {
        cout << "Hello my name is" << name<<"!"<< endl;
    }
    //Methods for managing mental health
    void increaseMentalHealth(int amount) {
        mentalHealth += amount;
        if (mentalHealth > 100) {
            mentalHealth = 100;
        }
        cout << "Your mental health " << mentalHealth << "%" << endl;
    }

    // Decrease mental health (if < 10%, playues failed)
    void decreaseMentalHealth(int damage) {
        mentalHealth -= damage;
        if (mentalHealth < 10) {
            cout << "Mental health is critical. You failed..." << endl;
        } else {
            cout << "Mental health is descreased: " << mentalHealth << "%" << endl;
        }
    }
    // Methods for managing SurvivalRate
    void increaseSurvivalRate(int amount) {
        survivalRate += amount;
        if (survivalRate > 100) {
            survivalRate = 100;
        }
        cout<<"Survival Rate: "<<survivalRate<<"%"<<endl;
    }


    void decreaseSurvivalRate(int amount) {
        survivalRate -= amount;
        if (survivalRate < 0) {
            survivalRate = 0;
        }
        cout<<"Survival Rate: "<<survivalRate<<"%"<<endl;
    }

    // Check status
    void showStatus() {
        cout<<"Player state: "<<isAlive<<endl;
        cout<<"\nSurvival Rate: "<<survivalRate<<"%";
    }

    // Direct access to `inventory`
    Inventory& getInventory() {
        return inventory;
    }

};


class Game {

};

class Choice {

};

class Event {

};


class Scene {
private:


public:
    Scene(string desc);
    string description;


};


class CombatScene : public Scene {
private:
    int damage;
    int mentalHealth;

public:
    CombatScene(string desc, int dmg, int mentalHealth);

    void play(Player& player) {
        cout << "\n" << description << endl;
        cout << "Your attempt ...\n";

        int attempt = 1;
        if (attempt==1) {
            cout << "You succesfully dodged. No damage\n";
        }
        cout << "You didn't have time to dodge - " << damage << "% Mental health.\n";
        player.decreaseMentalHealth(damage);
        }
};



class PuzzleScene : public Scene {
private:
    string question;
    string correctAnswer;
    int survivalBonus;

public:
    PuzzleScene(string desc, string q, string answer, int bonus);
    void play(Player& player) {
        cout << "\n" << description << endl;
        cout << "Quiz: " << question << "\nYour answer: ";

        string userAnswer;
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Right! + " << survivalBonus << "% to chance to survival rate.\n";
            player.increaseSurvivalRate(survivalBonus);
        } else {
            cout << "Wrong answer.No bonuses.\n";
        }
    }
};


int main() {

    string inputName;
    cout << "Enter your character name: ";
    cin >> inputName;

    Player player1(inputName);//Create an object with name
    cout<<"The player saved as: "<<player1.getName()<<endl;

    player1.sayHello();//Show the greetings
    player1.showStatus();





    return 0;




}

