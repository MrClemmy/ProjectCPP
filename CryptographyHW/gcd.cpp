#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0){
        cout << "The greatest common divisor is: " << a << endl;
        return a;
    }
    cout << "GCD(" << a << ", " << b << ")" << endl;
    cout << "Remainder: " << (a % b) << endl << endl;
    return gcd(b, (a % b));
}

int main(){
    int bigger, smaller;
    cout << "Welcome to the program, please select your numbers for GCD calculation." << endl;
    cout << "Enter the larger number: ";
    cin >> bigger;
    cout << endl << "Enter the lesser number: ";
    cin >> smaller;

    gcd(bigger, smaller);

    return 0;

}