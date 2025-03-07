#include <iostream>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));
    int ding = rand() % 50 + 1;
    int userGuess;
    int numGuesses = 0;
    bool finished = false;

    cout << "Guess a number between 1 and 50." << endl;
    cout << "Or don't, but then don't just stand there and stare either." << endl;
    cout << "Try your luck: ";

    while (finished == false){
        cin >> userGuess;
        numGuesses += 1;

        if (userGuess == ding){
            cout << "You lucky son of a gun.. oh well." << endl;
            finished = true;
        }

        if (userGuess > ding){
            cout << "You really think I would choose such a big number? Please." << endl;
            cout << "Guess again pal: ";
        }

        if (userGuess < ding){
            cout << "Uhh, a little small don't you think? Nearly a reasonable guess. Nearly." << endl;
            cout << "Try again bucko, do better: " << endl;
       }


    }

    if (numGuesses == 1){
        cout << "Cheater. You took only " << numGuesses << " guesses." << endl;
        return 0;
    }

    if (1 < numGuesses && numGuesses <=4){
        cout << "Pretty decent stuff, only took you " << numGuesses << " tries." << endl;
        return 0;
    }
    if (numGuesses <= 6){
        cout << "Might want to try again, " << numGuesses << " guesses isn't great." << endl;
        return 0;
    }
    if (numGuesses <= 8){
        cout << "Are you even trying? " << numGuesses << " guesses? Really?" << endl;
        return 0;
    }
    if (numGuesses <= 10){
        cout << ".... " << numGuesses << " guesses is insane." << endl;
        return 0;
    }if (numGuesses > 10){
        cout << "Just exit the program already. " << numGuesses << " guesses is too many." << endl;
        return 0;
    }

    return 0;
}