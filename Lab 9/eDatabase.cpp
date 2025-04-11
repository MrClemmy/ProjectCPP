#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void printEmployee(int idx, vector<string> &names, vector<string> &titles){
    cout << names[idx] << " (" << titles[idx] << ") " << endl;
}

int main(){
    int numLines = 0;
    ifstream data("employees.txt");
    if(!data.is_open()){
        cout << "Error! File did not open correctly";
        return 1;
    }
    string unused;
    while (getline(data, unused))
        ++numLines;

    data.clear();
    data.seekg(0);

    vector<string> names(numLines);
    vector<string> titles(numLines);
    vector<int> rev1(numLines);
    vector<int> rev2(numLines);
    vector<int> rev3(numLines);

    for(int i = 0; i < numLines; i++){
        data >> names[i];
        data >> titles[i];
        data >> rev1[i];
        data >> rev2[i];
        data >> rev3[i];
    
        if(data.eof()){
            data.close();
        }
    }

    int index = 0;

    cout << "Input employee index: ";
    cin >> index;
    printEmployee(index, names, titles);

}