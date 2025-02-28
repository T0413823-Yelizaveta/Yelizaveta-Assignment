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

    // Decrease mental health (if < 10%, player failed)
    void decreaseMentalHealth(int damage) {
        mentalHealth -= damage;
        if (mentalHealth < 10) {
            cout << "Mental health is critical. You failed..." << endl;
        } else {
            cout << "Mental health is decreased: " << mentalHealth << "%" << endl;
        }
    }


    void takeDamage(int amount) {
        damage += amount; // accumulated damage
        decreaseMentalHealth(amount); // Damage reduces mental health
        cout << "You got " << amount << " units of damage!\n";
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
    vector<Choice> choices;
    vector<string> availableItems;
    string specialItemReward;

public:
    // Constructor. Create a text for a scene
    Scene(const string& text) {
        description = text;
    }

    //add choices in the scene
    void addChoice( const string& text,int number) {
        choices.push_back(Choice(text,number));
    }
    //Add items which player can take
    void availableItem(const string& item) {
        availableItems.push_back(item);
    }

    void setSpecialItemReward(const string& item) {
        specialItemReward = item;
    }

    // Show the scene to player
    void showScene(const string& playerName) const {
        string modifiedText = description;
        size_t pos = modifiedText.find("[player]");
        while (pos != string::npos) {
            modifiedText.replace(pos,8,playerName);
            pos = modifiedText.find("[player]",pos+ playerName.length());
        }
        cout << "\n " << modifiedText<< endl;
        for (const Choice& choice: choices) {
            choice.showChoice();
        }

        if (!availableItems.empty()) {
            cout << "\nYou can take one of items:\n";
            for (const string& item : availableItems) {
                cout << "- " << item << endl;
            }
        }
    }
    int getPlayerChoice() const {
        int playerChoice;
        bool validChoice = false;

        //repeat the enter while it still continues to be wrong
        while (!validChoice) {
            cout<< "Enter player's choice: ";
            cin >> playerChoice;

            //Check, is entered choice exit in list of choices?
            for (const Choice& choice: choices) {
                if (choice.getChoiceNumber() == playerChoice) {
                    validChoice = true;
                    break;
                }
            }
            if (!validChoice) {
                cout << "Invalid choice!\n" << endl;
            }
        }
        return playerChoice;
    }

    string getPlayerItemChoice() const {
        if (availableItems.empty()) return ""; // If we dont have items dont do anything

        string chosenItem;
        bool validItem = false;

        while (!validItem) {
            cout << "\nEnter the name of item, which you would like to take: ";
            cin.ignore(); // clear the input buffer`getline`
            getline(cin, chosenItem);

            for (const string& item : availableItems) {
                if (item == chosenItem) {
                    validItem = true;
                    break;
                }
            }

            if (!validItem) {
                cout << "We dont have such item in list.\n";
            }
        }

        return chosenItem;
    }

    //
    string getSpecialItemReward() const {
        return specialItemReward;
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
    Scene introScene1("/Chapter 1. Getting Ready for the Party/ The clock on [player] phone read 18:45. There was just over an hour left before the party, and [player] had plenty of time to get ready. She stood in front of the mirror in her room, contemplating which look to choose. The atmosphere was calm, but thoughts about how the evening would go were already swirling in her mind. Her boyfriend would be there, her ex as well, and of course, her best friend. But for some reason, a slight unease was growing.She sifted through her wardrobe. A tight black dress or a loose shirt with jeans? The decision could influence how people perceived her at the party. She decides...");
    introScene1.addChoice("Wear the tight black dress, adding a touch of bright lipstick",1);
    introScene1.addChoice("Choose the loose shirt with jeans for a more casual look",2);

    //Show the full scene with choices and get a choice from player
    introScene1.showScene(player1.getName());
    int choice = introScene1.getPlayerChoice();


    if (choice ==1) {
        cout << "Now you look wonderful and you will get a lot of compliments\n";
    } else if (choice ==2) {
        cout << "You look as usual, but you don't care, the main thing is comfort\n";
    } else {
        cout << "Wrong answer!\n";
    }

    Scene introScene2("Her apartment was small but cozy. A narrow hallway led to the living room, which at night turned into a bedroom."
                      "\nThere was a comfortable couch covered with decorative pillows, a bookshelf with randomly arranged volumes, and a small desk by the window, where a desk lamp cast a soft, warm glow. "
                      "\nThe bathroom was small but tidy, with a mirror above the sink and a shelf filled with bottles of cosmetics."
                      "\nThe kitchen, located in the far corner of the apartment near the balcony, was adorned with string lights, creating a dim, almost magical atmosphere."
                      "\nShe approached the console table in the hallway, where a large mirror in a black frame hung. It was positioned so that a small part of it could be seen from the kitchen."
                      "\nShe ran her hand across its surface as if trying to catch the reflection of her thoughts and looked at herself."
                      "\nFinishing with her outfit, she moved on to her hair. Should she curl it for extra volume or leave it straight, fixing it lightly with hairspray? On the table in her room, there were:"
                      "\nHairspray (left on the console table in front of the mirror) "
                      "\nA small mirror (lying next to the hairspray)");
    introScene2.addChoice("Take the hairspray and fix her hairstyle",1);
    introScene2.addChoice("Take the small mirror and put it in her bag",2);
    introScene2.showScene(player1.getName());

    int choice2 = introScene2.getPlayerChoice();

    Scene introScene3("Running her fingers through her hair, she checked her appearance one last time."
                      "\nA message alert sounded on her phone. (It was from her boyfriend,whom she started dating on Valentine's day: "
                      "\n'Are you getting ready? I can't wait to see you.'"
                      "\nSomething in the message made her feel slightly uneasy. Was there too much eagerness in it? She decides...");
    introScene3.addChoice("Reply: 'Yes, I'll be there soon!' and continue getting ready",1);
    introScene3.addChoice("Not reply immediately, pretending to be busy",2);
    introScene3.showScene(player1.getName());

    int choice3 = introScene3.getPlayerChoice();




    return 0;

}

