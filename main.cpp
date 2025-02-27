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

class Combat {
private:
    int damage;
    int mentalHealth;

public:
    Combat() {
        mentalHealth = 100;
        damage = 0;
    }


    int getMentalHealth() const {
        return mentalHealth;
    }
    int getDamage() const {
        return damage;
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


    void takeDamage(int amount) {
        damage += amount; // accumulated damage
        decreaseMentalHealth(amount); // Damage reduces mental health
        cout << "You got " << amount << " units of damae!\n";
    }


    bool isGameOver() const {
        return mentalHealth < 10;
    }

};

class Player {
private:
    string name;
    int survivalRate;
    bool isAlive;
    Inventory inventory;
    Combat combat;

public:
    Player(string PlayerName) {
        name = PlayerName;
        survivalRate = 100;
    }

    string getName() {
        return name;
    }

    int getSurvivalRate() {
        return survivalRate;
    }

    void sayHello() {
        cout << "Hello my name is" << name<<"!"<< endl;
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

    Combat& getCombat() {
        return combat;
    }

};


class Game {

};

class Event {

};

class Choice {
private:
    string choiceText;
    int choiceNumber;

public:
    Choice(const string& text, int number) {
        choiceText = text;
        choiceNumber = number;
    }
    void showChoice() const {
        cout<< choiceNumber<< "."<<choiceText<< endl;
    }
    int getChoiceNumber() const {
        return choiceNumber;
    }
};

class Scene {
private:
    string description;
public:
    // Constructor. Create a text for a scene
    Scene(const string& text) {
        description = text;
    }

    // Show the scene to player
    void showScene() const {
        cout << "\n " << description << endl;
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

    // Create scene 1
    Scene introScene("/Chapter 1. Getting Ready for the Party/ The clock on her phone read 18:45. There was just over an hour left before the party, and she had plenty of time to get ready. She stood in front of the mirror in her room, contemplating which look to choose. The atmosphere was calm, but thoughts about how the evening would go were already swirling in her mind. Her boyfriend would be there, her ex as well, and of course, her best friend. But for some reason, a slight unease was growing.She sifted through her wardrobe. A tight black dress or a loose shirt with jeans? The decision could influence how people perceived her at the party. She decides...");
    introScene.showScene();

    // create 2 choices
    Choice choice1("Wear the tight black dress, adding a touch of bright lipstick",1);
    Choice choice2("Choose the loose shirt with jeans for a more casual look",2);

    // Show choices
    choice1.showChoice();
    choice2.showChoice();


    int playerChoice;
    cout << "Choose the choice 1 or 2: ";
    cin >> playerChoice;

    if (playerChoice == choice1.getChoiceNumber()) {
        cout << "Now you look wonderful and you will get a lot of compliments\n";
    } else if (playerChoice == choice2.getChoiceNumber()) {
        cout << "You look as usual, but you don't care, the main thing is comfort\n";
    } else {
        cout << "Wrong answer!\n";
    }

    return 0;

}

