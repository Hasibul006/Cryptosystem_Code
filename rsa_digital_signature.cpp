#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

int main(){
    mpz_class a("12493161794204943211"),b("14932613808869647427"),n,q,e,d,m,s,h;
    n = a*b;
    q = (a-1)*(b-1);
    e = a+b;

    while(true){
        mpz_class res;
        mpz_gcd(res.get_mpz_t(),q.get_mpz_t(),e.get_mpz_t());
        if(res==1)break;
        e=e+1;
    }

    mpz_invert(d.get_mpz_t(),e.get_mpz_t(),q.get_mpz_t());

    cout<<"prime-1(p): "<<a<<endl<<"prime-2(q): "<<b<<endl<<"n=p*q: "<<n<<endl<<"q=(p-1)*(q-1): "<<q<<endl<<"encryption key: "<<e<<endl<<"decryption key :"<<d<<endl;

    cout<<"Enter the message(integer): ";
    cin>>m;

    //generating signature
    mpz_powm(s.get_mpz_t(),m.get_mpz_t(),d.get_mpz_t(),n.get_mpz_t());
    cout<<"the signature: "<<s<<endl;

    //varifying signature
    mpz_powm(h.get_mpz_t(),s.get_mpz_t(),e.get_mpz_t(),n.get_mpz_t());
    cout<<"valified signature: " <<h<<endl;





}