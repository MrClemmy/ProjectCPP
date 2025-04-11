#include <iostream>
#include <string>
#include "dan.h"

using namespace std;

int main() {
    SpellChecker checker;
    checker.loadDictionary("largedictionary.txt");

    string word;
    cout << "Enter a word to check (or 0 to exit): ";
    
    while (cin >> word && word != "0") {
        if (checker.isSpelledCorrectly(word)) {
            cout << "The word '" << word << "' is spelled correctly!\n";
        } else {
            cout << "WHOA! '" << word << "' isn't a word! Bad human!\n";
        }
        cout << "Enter another word (or 0 to exit): ";
    }

    cout << "Spell checker terminated. Goodbye!\n";
    return 0;
  }
    