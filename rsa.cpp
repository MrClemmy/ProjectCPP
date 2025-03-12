#include <gmpxx.h>
#include "cryptography.h"
#include <time.h>
#include <cmath>

using namespace std;

int main(){

/*
(1) It should be able to find a public key given a private key. 
(2). It has an efficient way to compute the exponential function. 
(3). It can select large two prime numbers. 
(4). It can do both encryption and decryption
*/
mpz_class generate_prime(int bits) {
    gmp_randclass rng(gmp_randinit_mt);
    rng.seed(time(0));

    mpz_class candidate;
    do {
        candidate = rng.get_z_bits(bits);
        candidate |= 1;  // Ensure it's odd
    } while (!is_prime(candidate));
    
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

    return 0;
}