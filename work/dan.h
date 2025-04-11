#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SpellChecker {
private:
    string dictionary[201278]; // Array for word storing
    int wordCount; // Number of words are loaded 

public: 


    void loadDictionary(string filename){
        cout << "yes!";
        return;
    }
    bool isSpelledCorrectly(string word){
        cout << "true!";
        return true;
    }
    void suggestWords(string word){
        return;
    }
};

#endif
