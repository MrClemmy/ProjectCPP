#include <gmpxx.h>

mpz_class gcd(mpz_class a, mpz_class b){
    mpz_class temp;
    while (b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

mpz_class power(mpz_class x, mpz_class n, mpz_class mod){
    mpz_class result = 1;
    x = x % mod;

    while (n > 0){
        if (n % 2 == 1){
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        n /= 2;
    }

    return result;
}