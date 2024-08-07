#include <bits/stdc++.h>

void FightProgress(int &a, int &b, int &saverF, int &saverS);

void numberOFChar(int &humans, int &skeletons);

using namespace std;

//Health
int static healthFC = 1000;
int static healthSC = 700;

int main() {
    // Character names
    string L1stChar = "Skeletons";
    string L2sChar = "Humans";

    // Game Logic

    // Number of characters
    int Skeletons, Humans;
    numberOFChar(Humans, Skeletons);

    // Initialize saverF and saverS
    int saverF = 0, saverS = 0;

    // Fight Progress
    FightProgress(Humans, Skeletons, saverF, saverS);

    // End fight
    cout << "\nCombat End!"<<endl;

    if(Humans==0){
        cout<<endl<<"Skeletons Win!"<<'\n';
    }
    else{
        cout<<"Humans Win!"<<endl;
    }
    cout << "Skeletons left: " << Skeletons << ", Humans left: " << Humans << endl;
    cout << "Skeletons defeated: " << saverF << ", Humans defeated: " << saverS << endl;

    return 0;
}

void numberOFChar(int &a, int &b) {
    cout << "Input the number of humans: ";
    cin >> a;
    cout<<"\n";
    cout << "Input the number of Skeletons: ";
    cin >> b;
    cout<<"\n";
}

void FightProgress(int &a, int &b, int &saverF, int &saverS) {
    default_random_engine Damage(time(0));
    uniform_real_distribution<float> attackDamage(0.0f, 1.0f);
    cout << " {COMBAT NOISES}\n";
    bool FIGHT = true;
    bool turn = true;

    while (FIGHT) {
        if (turn) { // First character's turn to attack
            if (attackDamage(Damage) >= 0.35) {
                healthFC -= 300; // Reduce health of first character by 300 if attack succeeds.
                turn = false; // Switch turn to the second character.
            }
        } else { // Second character's turn to attack
            if (attackDamage(Damage) >= 0.35) {
                healthSC -= 300; // Reduce health of second character by 300 if attack succeeds.
                turn = true; // Switch turn to the first character.
            }
        }

        // Check if the first character's health is depleted
        if (healthFC <= 0) {
            b -= 1;          // Decrease the count of the second character type.
            saverF += 1;      // Increment the count of defeated second characters.
            healthFC = 1000;  // Reset the health for the next round.
        }

        // Check if the second character's health is depleted
        if (healthSC <= 0) {
            a -= 1;          // Decrease the count of the first character type.
            saverS += 1;     // Increment the count of defeated first characters.
            healthSC = 700;  // Reset the health for the next round.
        }

        // End the fight if all characters of one type are defeated
        if (a == 0 || b == 0) {
            FIGHT = false;
        }
    }
}
