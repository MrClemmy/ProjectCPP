#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class spellChecker{
    private:
        string dictionary[201728];
        int wordCount;
    
    public:
        void loadDictionary(string filename){
            ifstream dict(filename);
            if (!dict.is_open()){
                cout << "File did not open correctly" << endl;
                return;
            }
    
            string word;
            while (dict >> word && wordCount < 201728) {
                dictionary[wordCount] = word;
                wordCount++;
            }
    
            dict.close();
            cout << "Dictionary loaded with " << wordCount << " words." << endl;
        }
    
        bool isSpelledCorrectly(string word){
            for(int i = 0; i < wordCount; i++){
                if (word == dictionary[i]){
                    cout << "That word is in our dictionary!" << endl;
                    return true;
                }
                if (word < dictionary[i]){
                    cout << "That word is not in our dictionary!" << endl;
                    return false;
                }
            }
            return false;
        }
    
        void suggestWords(string word){
            for(int i = 0; i < wordCount; i++){
                if (word < dictionary[i]){
                    cout << "We've found a few words you might have meant:" << endl;
                    if (i == 0 || i == 1){
                        for (int j = 0; j < 4; j++){
                            cout << dictionary[i + j] << endl;
                        }
                    }else {
                        cout << dictionary[i - 2] << endl;
                        cout << dictionary[i - 1] << endl;
                        cout << dictionary[i] << endl;
                        cout << dictionary[i + 1] << endl;
                        cout << dictionary[i + 2] << endl;
                    }
                }
            }
        }
    };