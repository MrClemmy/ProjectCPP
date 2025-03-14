#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ifstream racers("raceTimes.txt");
    if (!racers){
        cerr << "Error: File not found!" << endl;
        return 1;
    }

    vector<string> names(5);
    vector<int> times(5);

    for (int i = 0; i < 5; i++){
        racers >> names[i];
    }

    for (int i = 0; i < 5; i++){
        racers >> times[i];
    }

    for (int i = 0; i < 5; i++){
        cout << names[i] << " " << times[i] << endl;
    }
    
}