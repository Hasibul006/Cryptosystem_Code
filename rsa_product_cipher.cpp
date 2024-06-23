#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

int main(){
    mpz_class a("12493161794204943211"),b("14932613808869647427"),n,q,e,d,m1,m2,m,c1,c2,c,de1,de2,de;
    n = a*b;
    q = (a-1)*(b-1);
    e = a+b;

    //finding e (encrytion key)
    while(true){
        mpz_class gcd_r;
        mpz_gcd(gcd_r.get_mpz_t(),q.get_mpz_t(),e.get_mpz_t());
        if(gcd_r==1)break;
        e=e+1;
    }

    //finding d (decryption key)
    mpz_invert(d.get_mpz_t(),e.get_mpz_t(),q.get_mpz_t());

    cout<<"prime-1(p): "<<a<<endl<<"prime-2(q): "<<b<<endl<<"n=p*q: "<<n<<endl<<"q=(p-1)*(q-1): "<<q<<endl<<"encryption key: "<<e<<endl<<"decryption key :"<<d<<endl;

    cout<<"Enter the message1(integer): ";
    cin>>m1;
    cout<<"Enter the message2(integer): ";
    cin>>m2;
    cout<<"The product of the messages: "<<m1*m2<<endl;

    //encryption
    mpz_powm(c1.get_mpz_t(),m1.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
    mpz_powm(c2.get_mpz_t(),m2.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
    m=m1*m2;
    mpz_powm(c.get_mpz_t(),m.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());

    cout<<"the cipher text c1: "<<c1<<endl;
    cout<<"the cipher text c2: "<<c2<<endl;
    cout<<"the cipher text c: "<<c<<endl;

    //decryption
    mpz_powm(de1.get_mpz_t(),c1.get_mpz_t(),d.get_mpz_t(),n.get_mpz_t());
    mpz_powm(de2.get_mpz_t(),c2.get_mpz_t(),d.get_mpz_t(),n.get_mpz_t());
    mpz_powm(de.get_mpz_t(),c.get_mpz_t(),d.get_mpz_t(),n.get_mpz_t());

    cout<<"the decrypted text for m1: "<<de1<<endl;
    cout<<"the decrypted text for m2: "<<de2<<endl;
    cout<<"the decrypted text for m: "<<de1*de2<<endl;
    
}