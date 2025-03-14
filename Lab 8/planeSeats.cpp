#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

// Vector implementation
/*void seats(int a, int b)
{   
    vector<string> plane(b);
    for (int i = 1; i <= a; i++)
    {
        for (int j = 0; j < b; j++){
            plane[j] = to_string(i) + char(A + j) + " ";
        }

        for(int k = 0; k < plane.size(); k++){
            cout << plane[k];
        }

        cout << endl;
    }
}*/

// Array implementation
void seats(int a, int b)
{   
    string plane[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++){
            plane[i][j] = to_string(i + 1) + char(65 + j);
            cout << plane[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    seats(14, 5);
}