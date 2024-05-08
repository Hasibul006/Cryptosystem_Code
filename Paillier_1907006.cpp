#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

int main() {
    //key generation:
    //selecting 2 prime numbers
    mpz_class p("10882836538747368499");
    mpz_class q("13178193455209031311");
    cout<<"enter the message: ";
    mpz_class message;
    cin>>message;
    //p = "10882836538747368499";
    //q = "13178193455209031311";
    mpz_class p1 = p - 1;
    mpz_class q1 = q - 1;
    mpz_class n = p * q;
    mpz_class lamda = lcm(p1, q1);
    mpz_class random_g;
    cout<<"Enter a random number for key generation:";
    cin>>random_g;
    mpz_class n1 = n*n;
    mpz_class x;
    //x = g^Lamda mod n^2
    mpz_powm(x.get_mpz_t(), random_g.get_mpz_t(), lamda.get_mpz_t(), n1.get_mpz_t());
    mpz_class l;
    l = ((x-1)/n);
    mpz_class m;
    mpz_invert(m.get_mpz_t(), l.get_mpz_t(), n.get_mpz_t());
    //cout << n << endl << lamda<<endl<<random_g<<endl<<x<<endl<<l<<endl<<m<<endl;
    cout<<"public key : ( "<<n<<", "<<random_g<<" )"<<endl;
    cout<<"private key : "<<lamda<<endl;

    //encryption
    mpz_class r;
    while(true){
        cout<<"Enter a random number for encryption: ";
        cin>>r;
        mpz_class check = gcd(r,n);
        if(check==1)break;
        cout<<"the random number is not valid. Pick again"<<endl;
    }
    
    mpz_class g_m;
    mpz_powm(g_m.get_mpz_t(), random_g.get_mpz_t(), message.get_mpz_t(), n1.get_mpz_t());
    mpz_class r_n;
    mpz_powm(r_n.get_mpz_t(), r.get_mpz_t(), n.get_mpz_t(), n1.get_mpz_t());
    mpz_class result;
    mpz_mul(result.get_mpz_t(), g_m.get_mpz_t(), r_n.get_mpz_t());
    mpz_class cipherText;
    mpz_mod(cipherText.get_mpz_t(),result.get_mpz_t(),n1.get_mpz_t());
    cout<<"Message: "<<message<<endl;
    cout<<"CipherText: "<<cipherText<<endl;

    //decryption
    mpz_powm(result.get_mpz_t(), cipherText.get_mpz_t(), lamda .get_mpz_t(), n1.get_mpz_t());
    result = (result - 1)/n;
    mpz_mul(result.get_mpz_t(), result.get_mpz_t(), m.get_mpz_t());
    mpz_class plainText;
    mpz_mod(plainText.get_mpz_t(),result.get_mpz_t(),n.get_mpz_t());
    cout<<"PlainText: "<<plainText<<endl;
    return 0;
}
