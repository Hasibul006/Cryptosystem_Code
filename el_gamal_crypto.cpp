#include <bits/stdc++.h>
#include <gmp.h>
using namespace std;

int main() {
    // prime p
    mpz_t p;
    mpz_init_set_str(p,"3076254225030127069205146053958616692729173275",10);

    // primitive element of p between 2 and p-1
    mpz_t g;
    mpz_init_set_str(g,"3",10);

    // private key x between 1 and p-2
    mpz_t x;
    mpz_init_set_str(x,"123456789012345678901234567890",10);

    // public key d = g^x mod p
    mpz_t d;
    mpz_init(d);
    mpz_powm(d,g,x,p);

    gmp_printf("Public key (p, g, d): %Zd, %Zd, %Zd\n", p, g, d);
    gmp_printf("Private key x: %Zd\n\n", x);

    mpz_t plain;
    mpz_init(plain);

    string input;
    cout << "Enter a message: ";
    cin >> input;

    mpz_set_str(plain, input.c_str(), 10);

    // randomly choosen value. (randomness)
    mpz_t r;
    mpz_init_set_str(r,"56789012345678901234567",10);

    // encryption 
    // calculate c1 = g^r mod p
    mpz_t c1;
    mpz_init(c1);
    mpz_powm(c1,g,r,p);

    // calculate c2 = (d^r * plain) mod p
    mpz_t temp1, temp2, temp3, c2;
    mpz_inits(temp1, temp2, temp3, c2, NULL);
    mpz_powm(temp1, d, r, p); // temp1 = d^r mod p
    mpz_mod(temp2, plain, p); //temp2 = plain mod p
    mpz_mul(temp3, temp1, temp2); //temp3 = temp1 * temp2
    mpz_mod(c2, temp3, p); // temp3 mod p

    gmp_printf("The ciphertext:\nc1: %Zd\nc2: %Zd\n\n", c1, c2);

    // decryption = (c1^-x * c2) mod p
    mpz_t decrypt_text,xneg;
    mpz_inits(decrypt_text, xneg,NULL);
    mpz_neg(xneg,x);
    mpz_powm(temp1,c1,xneg,p); //temp1 = c1^(-x) mod p
    mpz_mod(temp2,c2,p); // temp2 = c2 mod p
    mpz_mul(temp3,temp1,temp2); //temp3 = temp1 * temp2
    mpz_mod(decrypt_text,temp3,p); // result = temp3 mod p
    gmp_printf("The decrypted text is: %Zd\n", decrypt_text);

    mpz_clears(p, g, x, d, plain, r, c1, c2, temp1, temp2, temp3, decrypt_text, NULL);

    return 0;
}