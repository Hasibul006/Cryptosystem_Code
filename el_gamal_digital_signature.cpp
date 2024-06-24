#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

int main(){
    mpz_class p("14932613808869647427"),g("2"),x,y,k,r,s,v1,v2,m;

    //key generation
    cout<<"Enter the private key: ";cin>>x;
    mpz_powm(y.get_mpz_t(),g.get_mpz_t(),x.get_mpz_t(),p.get_mpz_t());

    //signature generation
    cout<<"Enter the message(integer): ";cin>>m;
    cout<<"Enter a random integer k(1<=k<=p-2): ";cin>>k;
    mpz_powm(r.get_mpz_t(),g.get_mpz_t(),k.get_mpz_t(),p.get_mpz_t());
    mpz_class temp1,temp2,temp3,temp4;
    temp3 = m - x*r;
    temp4 = p-1;
    mpz_invert(temp2.get_mpz_t(),k.get_mpz_t(),temp4.get_mpz_t());
    s = temp3 * temp2;
    cout<<"The signature r: "<<r<<endl<<"The signature s: "<<s<<endl;

    //signature verification
    mpz_powm(temp1.get_mpz_t(),y.get_mpz_t(),r.get_mpz_t(),p.get_mpz_t());
    mpz_powm(temp2.get_mpz_t(),r.get_mpz_t(),s.get_mpz_t(),p.get_mpz_t());
    temp3 = temp1 * temp2;
    mpz_mod(v1.get_mpz_t(),temp3.get_mpz_t(),p.get_mpz_t());
    mpz_powm(v2.get_mpz_t(),g.get_mpz_t(),m.get_mpz_t(),p.get_mpz_t());
    cout<<"Signature varification: "<<endl<<"v1: "<<v1<<endl<<"v2: "<<v2<<endl;
    if(v1==v2)cout<<"Signature is varified"<<endl;
    else cout<<"Signature is not valid"<<endl;

}