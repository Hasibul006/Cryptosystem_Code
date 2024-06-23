#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

int main(){
    mpz_class p("12493161794204943211"),g("2"),x,y,k,c1,c2,m,s,d;

    //get the private key
    cout<<"Enter the private key: ";
    cin>>x;

    //calculating the public key
    mpz_powm(y.get_mpz_t(),g.get_mpz_t(),x.get_mpz_t(),p.get_mpz_t());

    cout<<"Enter a message(integer): ";
    cin>>m;

    //encryption
    cout<<"Enter a random integer for encryption: ";
    cin>>k;
    mpz_powm(c1.get_mpz_t(),g.get_mpz_t(),k.get_mpz_t(),p.get_mpz_t());
    mpz_class temp1,temp2,temp;
    mpz_powm(temp1.get_mpz_t(),y.get_mpz_t(),k.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp2.get_mpz_t(),m.get_mpz_t(),p.get_mpz_t());
    temp = temp1* temp2;
    mpz_mod(c2.get_mpz_t(),temp.get_mpz_t(),p.get_mpz_t());
    cout<<"Cipher text: "<<endl<<"c1: "<<c1<<endl<<"c2: "<<c2<<endl;

    //decryption
    mpz_powm(s.get_mpz_t(),c1.get_mpz_t(),x.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp1.get_mpz_t(),c2.get_mpz_t(),p.get_mpz_t());
    mpz_invert(temp2.get_mpz_t(),s.get_mpz_t(),p.get_mpz_t());
    temp = temp1* temp2;
    mpz_mod(d.get_mpz_t(),temp.get_mpz_t(),p.get_mpz_t());
    cout<<"the decrypted text: "<<d<<endl;
}