#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

int main(){
    mpz_class a("12493161794204943211"),b("14932613808869647427"),n,q,e,d,m,c,de;
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

    cout<<"Enter the message(integer): ";
    cin>>m;

    //encryption
    mpz_powm(c.get_mpz_t(),m.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
    cout<<"the cipher text: "<<c<<endl;
    //decryption
    mpz_powm(de.get_mpz_t(),c.get_mpz_t(),d.get_mpz_t(),n.get_mpz_t());
    cout<<"the decrypted text: "<<de<<endl;


    

    
}