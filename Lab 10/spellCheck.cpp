#include <iostream>
#include <fstream>
#include <string>
#include "spellCheck.h"

using namespace std;

int main() {
    spellChecker checker;
    checker.loadDictionary("dictionary.txt");

    string input;

    while (true) {
        cout << "Enter a word to check (or 0 to quit): ";
        cin >> input;

        if (input == "0") {
            break;
        }

        if (checker.isSpelledCorrectly(input)) {
            cout << "The word " << input << " is spelled correctly!" << endl;
        } else {
            cout << "WHOA! " << input << " isn't a word! Bad human!" << endl;
            checker.suggestWords(input);
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}