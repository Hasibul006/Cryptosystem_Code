#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

int main(){
    mpz_class p("14932613808869647427"),g("2"),x,y,m1,m2,m,c11,c12,c21,c22,c1,c2,r1,r2,r,s1,d1,s2,d2,s,d;
    
    //key generation
    cout<<"Enter the private key: ";cin>>x;
    mpz_powm(y.get_mpz_t(),g.get_mpz_t(),x.get_mpz_t(),p.get_mpz_t());

    cout<<"Enter the messages(integer): "<<endl<<"m1: ";cin>>m1;
    cout<<"m2: ";cin>>m2;
    cout<<"m1*m2: "<<m1*m2<<endl;

    //encryption
    mpz_class temp1,temp2,temp3;
    cout<<"Enter a random integer to encrypt message-1: ";cin>>r1;
    mpz_powm(c11.get_mpz_t(),g.get_mpz_t(),r1.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp1.get_mpz_t(),m1.get_mpz_t(),p.get_mpz_t());
    mpz_powm(temp2.get_mpz_t(),y.get_mpz_t(),r1.get_mpz_t(),p.get_mpz_t());
    temp3 = temp1 * temp2;
    mpz_mod(c12.get_mpz_t(),temp3.get_mpz_t(),p.get_mpz_t());
    cout<<"c11: "<<c11<<endl<<"c12: "<<c12<<endl;

    cout<<"Enter a random integer to encrypt message-2: ";cin>>r2;
    mpz_powm(c21.get_mpz_t(),g.get_mpz_t(),r2.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp1.get_mpz_t(),m2.get_mpz_t(),p.get_mpz_t());
    mpz_powm(temp2.get_mpz_t(),y.get_mpz_t(),r2.get_mpz_t(),p.get_mpz_t());
    temp3 = temp1 * temp2;
    mpz_mod(c22.get_mpz_t(),temp3.get_mpz_t(),p.get_mpz_t());
    cout<<"c21: "<<c21<<endl<<"c22: "<<c22<<endl;

    r = r1 + r2;
    m = m1 * m2;
    mpz_powm(c1.get_mpz_t(),g.get_mpz_t(),r.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp1.get_mpz_t(),m.get_mpz_t(),p.get_mpz_t());
    mpz_powm(temp2.get_mpz_t(),y.get_mpz_t(),r.get_mpz_t(),p.get_mpz_t());
    temp3 = temp1 * temp2;
    mpz_mod(c2.get_mpz_t(),temp3.get_mpz_t(),p.get_mpz_t());
    cout<<"c1: "<<c1<<endl<<"c2: "<<c2<<endl;


    //decryption
    mpz_powm(s1.get_mpz_t(),c11.get_mpz_t(),x.get_mpz_t(),p.get_mpz_t());
    mpz_invert(temp1.get_mpz_t(),s1.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp2.get_mpz_t(),c12.get_mpz_t(),p.get_mpz_t());
    temp3 = temp1 * temp2;
    mpz_mod(d1.get_mpz_t(),temp3.get_mpz_t(),p.get_mpz_t());
    cout<<"Decrypted text for m1: "<<d1<<endl;

    mpz_powm(s2.get_mpz_t(),c21.get_mpz_t(),x.get_mpz_t(),p.get_mpz_t());
    mpz_invert(temp1.get_mpz_t(),s2.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp2.get_mpz_t(),c22.get_mpz_t(),p.get_mpz_t());
    temp3 = temp1 * temp2;
    mpz_mod(d2.get_mpz_t(),temp3.get_mpz_t(),p.get_mpz_t());
    cout<<"Decrypted text for m2: "<<d2<<endl;

    mpz_powm(s.get_mpz_t(),c1.get_mpz_t(),x.get_mpz_t(),p.get_mpz_t());
    mpz_invert(temp1.get_mpz_t(),s.get_mpz_t(),p.get_mpz_t());
    mpz_mod(temp2.get_mpz_t(),c2.get_mpz_t(),p.get_mpz_t());
    temp3 = temp1 * temp2;
    mpz_mod(d.get_mpz_t(),temp3.get_mpz_t(),p.get_mpz_t());
    cout<<"Decrypted text for m: "<<d<<endl;
    cout<<"m1*m2 form the decrypted texts: "<<d1*d2<<endl;


}