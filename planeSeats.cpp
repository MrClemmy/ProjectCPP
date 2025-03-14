#include <iostream>
#include <vector>
#include <string>

using namespace std;

void seats(int a, int b)
{   
    vector<string> plane(b);
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j < b; j++){
            plane[j] = to_string(i) + char('A' + j) + " ";
        }

        for(int k = 0; k < plane.size(); k++){
            cout << plane[k];
        }

        cout << endl;
    }
}

int main(){
    seats(17, 5);
}