#include <iostream>
#include <iomanip>
using namespace std;

int minimum, maximum, range, count, userInput;
float mean;


int main(){
    cout << "Enter an integer: ";
    cin >> userInput;

    if (userInput < 0){
        return 0;
    }
    else{
        maximum = minimum = mean = userInput;
        count = 1;
    }

    do{
        cout << "Enter an integer: ";
        cin >> userInput;

        if (userInput < 0) {
            break;
        }

        if (userInput < minimum){
            minimum = userInput;
        }

        if (userInput > maximum){
            maximum = userInput;
        }

        count += 1;
        mean += userInput;
    } while (userInput >= 0);

    mean = mean / count;
    range = maximum - minimum;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    cout << fixed << setprecision(2) << "Average: " << mean << endl;
    cout << "Range: " << range << endl;

    return 0;
}