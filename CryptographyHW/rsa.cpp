#include <gmpxx.h>
#include "cryptography.h"

using namespace std;

int main(){

    mpz_class generate_prime(int bits) {
        gmp_randclass rng(gmp_randinit_mt);
        rng.seed(time(0));

        mpz_class candidate;
        do {
            candidate = rng.get_z_bits(bits);
            candidate |= 1;  
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

    // Encryption
    mpz_class encrypt(mpz_class message, mpz_class e, mpz_class n) {
        return power(message, e, n);
    }

    // Decryption
    mpz_class decrypt(mpz_class ciphertext, mpz_class d, mpz_class n) {
        return power(ciphertext, d, n);
    }


    return 0;
}