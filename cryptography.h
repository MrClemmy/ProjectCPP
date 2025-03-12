#include <gmpxx.h>

mpz_class egcd(mpz_class a, mpz_class m, mpz_class &x, mpz_class &y){
    if (m == 0){
        x = 1;
        y = 0;
        return a;
    }

    mpz_class x1, y1;
    mpz_class gcd = egcd(m, a % m, x1, y1);

    x = y1;
    y = x1 - (a / m) * y1;

    return gcd;
}

mpz_class mod_inv(mpz_class a, mpz_class m){
    mpz_class x, y;
    mpz_class g = egcd(a, m, x, y);
    
    if (g > 1){
        std::cout << "Modular inverse does not exist!" << std::endl;
        return g;
    }
    // brute force i guess
    // for(mpz_class x = 1; x < m; )
    mpz_class result = (x % m + m) % m;

    return result;

    
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