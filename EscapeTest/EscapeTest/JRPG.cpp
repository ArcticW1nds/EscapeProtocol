#include <iostream>
#include <string>
#include <cctype>
#include <random>


#include "LabRat.hpp"
#include "Scientist.hpp"
#include "Utilities.hpp"

using namespace std;
int turnOrder();//forward decleration

void Battle1v1(Combatant* c1, Combatant* c2) {
    int ogTurn = turnOrder();  // 1 = Rat, 2 = Scientist
    int turnNum = 1;
    Combatant* attacker = (ogTurn == 1) ? c1 : c2;
    Combatant* defender = (ogTurn == 1) ? c2 : c1;

    std::cout << "\n=== Battle Start! ===\n";
    std::cout << c1->getName() << " vs " << c2->getName() << "\n";
    std::cout << "First attacker: " << attacker->getName() << "\n\n";

    while (attacker->getHealth() > 0 && defender->getHealth() > 0) {
        std::cout << "-----------------------------\n";
        std::cout << "Turn Number: " << turnNum << "\n";
        std::cout << attacker->getName() << "'s turn!\n";
        std::cout << attacker->getName() << " HP: " << attacker->getHealth() << " | ";
        std::cout << defender->getName() << " HP: " << defender->getHealth() << "\n";

        attacker->takeTurn(defender);

        std::cout << defender->getName() << "'s HP after attack: " << defender->getHealth() << "\n";
        std::cout << "-----------------------------\n\n";
        turnNum++;
        std::swap(attacker, defender);
    }

    Combatant* winner = (c1->getHealth() > 0) ? c1 : c2;
    std::cout << "\n=== Battle Over! ===\n";
    std::cout << winner->getName() << " wins the battle!\n";
}



int turnOrder() {
    int turnOrder = 0;
    cout << "Decide turn order." << endl;
    cout << "(1) Rat first" << endl;
    cout << "(2) Scientist first" << endl;
    cout << "(3) Random" << endl;
    int c1 = getValidatedInput(1, 3);

    if (c1 == 1) {
        cout << "Rat goes first!" << endl;
        turnOrder = 1;
    }
    else if (c1 == 2) {
        cout << "Scientist goes first!" << endl;
        turnOrder = 2;
    }
    else {
        int c2 = ranNumGen(1, 2);
        if (c2 == 1) {
            cout << "Rat goes first!" << endl;
            turnOrder = 1;
        }
        else {
            cout << "Scientist goes first!" << endl;
            turnOrder = 2;
        }
    }

    return turnOrder;
}