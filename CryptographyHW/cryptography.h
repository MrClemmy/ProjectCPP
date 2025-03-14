#include <gmpxx.h>

bool randPrime(mpz_class p){
    mpz_class a;
    gmp_randclass rng(gmp_randinit_mt);
    rng.seed(time(0));

    a = rng.get_z_range(p - 1) + 1;

    mpz_class gcd_result = gcd(p, a);

    if (gcd_result > 1){
        return false;
    }

    mpz_class aexp = (p - 1) / 2;

    mpz_class apow = power(a, aexp, p);

    // since we've already performed mod we can just check if its +/- 1
    if (apow != 1 && apow != p - 1){
        return false;
    }
}

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


mpz_class generate_prime(int bits) {
    gmp_randclass rng(gmp_randinit_mt);
    rng.seed(time(0));

    mpz_class candidate;
    do {
        candidate = rng.get_z_bits(bits);
        candidate |= 1;  // Ensure it's odd
    } while (!randPrime(candidate));
    
    return candidate;
}

// Function to compute the public key given a private key
mpz_class compute_public_key(mpz_class d, mpz_class phi) {
    return mod_inv(d, phi);
}

// RSA Key Generation
void generate_keys(mpz_class &n, mpz_class &e, mpz_class &d) {
    mpz_class p = generate_prime(512);  
    mpz_class q = generate_prime(512);
    n = p * q;
    mpz_class phi = (p - 1) * (q - 1);

    e = 65537;  
    while (egcd(e, phi, d, d) != 1) {
        e += 2;  // Find an e that is coprime with phi
    }

    d = mod_inv(e, phi);  // Compute private key
}

// RSA Encryption
mpz_class encrypt(mpz_class message, mpz_class e, mpz_class n) {
    return power(message, e, n);
}

// RSA Decryption
mpz_class decrypt(mpz_class ciphertext, mpz_class d, mpz_class n) {
    return power(ciphertext, d, n);
}