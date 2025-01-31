Game

**Expanded Storyline & Gameplay Variants with Choices & Endings:**

1. **Prologue – The Party:**
   * **Choice 1.1:** Take **Mirror** → Later       allows glimpses of the stalker.
   * **Choice 1.2:** Take **Pepper Spray** →       Useful in a confrontation.
2. **Walking Home – The Suspicion      Begins:**
   * **Choice 2.1:** Use the mirror → Spot a       shadowy figure but don't know who it is.
   * **Choice 2.2:** Ignore it and keep walking →       May lead to being followed unnoticed.
3. **Home Intrusion – Unease Settles      In:**
   * **Choice 3.1:** Call the police → Delays any       immediate attack but changes how events unfold.
   * **Choice 3.2:** Enter cautiously (use  inventory item) → Might prepare her for an attack.
4. **Investigation – Pieces of the      Puzzle:**
   * **Choice 4.1:** Search the house for clues →       Might find signs of forced entry or misplaced objects.
   * **Choice 4.2:** Lock all doors and stay put →       Increases vulnerability to a surprise attack.
5. **Flashback – A Troubled Past:**
   * **Choice 5.1:** Confront the boyfriend about       past actions → He acts calm, making her suspicious.
   * **Choice 5.2:** Avoid discussing the past →       Leads to blind suspicion and increased paranoia.
6. **The Threat Escalates:**
   * **Choice 6.1:** Flee to a friend’s house →       Temporary safety but limits further investigation.
   * **Choice 6.2:** Stay and prepare for       self-defense (using collected items) → Leads to a fight later.
7. **The Confrontation – The True      Killer is Revealed:**
   * Throughout the game, the       protagonist believes her ex-lover is stalking her. However, in the final       confrontation, she discovers her boyfriend has known about her infidelity       all along and has been manipulating her fear to isolate and kill her.
   * **Choice 7.1:** Attempt to negotiate → Might       briefly delay the attack but is ultimately fatal.
   * **Choice 7.2:** Defend using a weapon (Knife,       Pepper Spray) → Can kill or wound the boyfriend and escape.
8. **Endings:**
   * **Ending 8.1:** She is caught and murdered by       her boyfriend.
   * **Ending 8.2:** She barely survives but       remains traumatized.
   * **Ending 8.3:** She successfully defends       herself and exposes the boyfriend as the killer.
   * **Ending 8.4:** She ignores all warning signs       and assumes she simply forgot to lock the door. After dismissing her       paranoia, she eats dinner, unaware that her boyfriend had previously       entered her apartment and poisoned the food. The screen fades to black       with the message: **"You died in your sleep from poisoning."**
   * **Ending 8.5:** The police arrive too late,       leaving the mystery unresolved.
   * **Ending 8.6:** She kills her boyfriend in       self-defense but is haunted by the event.

Scenario

Protagonist

Attributes:

·       Name

·        paranoia\_level,

·        inventory\_items,

·       current\_location

**Behaviors**:

pick\_up\_item(item)

check\_inventory()

make\_choice(option)

check\_surroundings()

defend\_self()

escape()

**Inventory**:

Attributes:

held\_items (Mirror, Pepper Spray, Knife, Phone, Keys)

Behaviors:

* use\_item(item)
* discard\_item(item)

**Environment**:

Attributes:

locations (Party, Street, Home, Friend’s House),

security\_status (doors\_locked, windows\_secure)

Behaviors:

* update\_security\_status()
* reveal\_clues()
* affect\_paranoia(level)

GameSystem

Attributes:

·       current\_scenario

·       available\_choices

·       game\_ending

Behaviors:

track\_game\_progress()

update\_scenario(choice)

check\_game\_ending()

Pseudocode

# Define a record for inventory items

RECORD Item

name : String
ENDRECORD

# Define a record for game state

RECORD GameState

choices : List  # Stores the player's choices

inventory : List  # Stores collected items

storyProgress : Integer  # Tracks the progress of the story

alive : Boolean  # Indicates if the protagonist is alive
ENDRECORD

# Initialize game state

game ← GameState([], [], 0, TRUE)

# Subroutine to advance the story based on player choices

SUBROUTINE ContinueStory(choice)

# Updates the game progress and modifies available choices

# Determines the next scenario based on the player's decision
ENDSUBROUTINE

# Subroutine to add an item to inventory

SUBROUTINE AddToInventory(item)

# Adds the specified item to the inventory list
ENDSUBROUTINE

# Subroutine to remove an item from inventory

SUBROUTINE RemoveFromInventory(item)

# Removes the specified item from the inventory list if it exists
ENDSUBROUTINE

# Subroutine to check and display the current inventory

SUBROUTINE CheckInventory()

# Outputs all collected items in the inventory
ENDSUBROUTINE

# Subroutine to process player choices

SUBROUTINE MakeChoice(choice)

# Ensures that the player's choice is valid

# Calls the ContinueStory subroutine to progress the game
ENDSUBROUTINE

# Subroutine to update the game state

SUBROUTINE UpdateGameState()

# Checks if the protagonist is still alive

# Determines if any endings have been reached

# Modifies available actions based on past choices
ENDSUBROUTINE

# Main game loop to handle player interactions

WHILE game.alive = TRUE

# Displays available choices to the player

# Takes player input and calls MakeChoice
ENDWHILE
