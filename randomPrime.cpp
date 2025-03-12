#include <iostream>
#include <gmpxx.h>
#include <cmath>
#include <time.h>
#include "cryptography.h"

using namespace std;

bool randPrime(mpz_class p){
    mpz_class a;
    gmp_randclass rng(gmp_randinit_mt);
    rng.seed(time(0));

    a = rng.get_z_range(p - 1) + 1;

    mpz_class gcd_result = gcd(p, a);

    if (gcd_result > 1){
        cout << p << " is composite." << endl;
        return false;
    }

    mpz_class aexp = (p - 1) / 2;

    mpz_class apow = power(a, aexp, p);

    // since we've already performed mod we can just check if its +/- 1
    if (apow != 1 && apow != -1){
        cout << p << " is a composite." << endl;
        return false;
    }


    cout << p << " is prime!" << endl;
    return true;

}

int main(){
    srand(time(0));
    mpz_class input0("239");
    mpz_class input1("379");
    mpz_class input2("641");
    mpz_class input3("997");
    mpz_class input4("569");
    mpz_class input5("199");
    mpz_class input6("487");
    randPrime(input0);
    randPrime(input1);
    randPrime(input2);
    randPrime(input3);
    randPrime(input4);
    randPrime(input5);
    randPrime(input6);

    return 0;
}

// g++ -o randomPrime randomPrime.cpp -lgmpxx -lgmp <-- links gmp, does not run otherwise