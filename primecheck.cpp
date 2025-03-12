#include <iostream>
#include <cmath>
#include <gmp.h>
using namespace std;

bool primeCheck(int n){
    if (n <= 1){
        return false;
    }
    int root = ceil(sqrt(n));
    for(int i = 2; i <= root; i++){
        if(n % i == 0){
            cout << n << " is not prime." << endl;
            return false;
        }
    }
    cout << n << " is prime." << endl;
    return true;
}

int main(){
    int input = 0;
    cout << "Input a number to test for primality: ";
    cin >> input;

    primeCheck(input);

    return 0;
}