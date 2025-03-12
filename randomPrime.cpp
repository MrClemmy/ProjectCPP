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
    if (apow != 1 && apow != p - 1){
        cout << p << " is a composite." << endl;
        return false;
    }


    cout << p << " is prime!" << endl;
    return true;

}

int main(){
    srand(time(0));
    mpz_class input0("561192545511605501847804031458486579170180721885050519341523637380951060985753413015561149180502147007767345472030");
    mpz_class input1("23634908516275441156240008234049257120333838151961212516763037798280869291669715873080558171002412980");
    mpz_class input2("99547112415950368609749926939128915172296448132305911481928232723544730974932209270079373824255543569278143012");
    mpz_class input3("700000000000000007000000222222000000000022222222220000000222000002222000000000000022220000000000000222200000000000002222000000000000222200000000000022220000000000000222222222222000000222222222222000700000000000000004");
    mpz_class input4("67989163763861225811000877783661019311779979416004714189288006719437081612046600466103755303097540113804746346430");
    mpz_class input5("1277361782154249992295763514822082698951936680331825288693984964651058209392398294887933203625094431173012381970684162");
    mpz_class input6("100127631001285310012921100129311001299910013141100132871001347310013287100131411001299910012931100129211001285310012764");
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