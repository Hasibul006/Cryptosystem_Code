#include<bits/stdc++.h>
#include<gmpxx.h>
using namespace std;

int main(){
    cout<<"Enter the message: ";
    string m;cin>>m;
    cout<<"Enter the shift value: ";
    int x;cin>>x;

    //encryption
    for(int i=0;i<m.size();i++){
        if(m[i]>='a' && m[i]<='z'){
            m[i]='A'+m[i]-'a';
            m[i]='A'+(m[i]-'A'+x)%26;
        }
        else if(m[i]>='A' && m[i]<='Z'){
            m[i]='a'+m[i]-'A';
            m[i]='a'+(m[i]-'a'+x)%26;
        }
        
    }
    cout<<"Encrypted message: "<<m<<endl;

    //decryption
    for(int i=0;i<m.size();i++){
        if(m[i]>='a' && m[i]<='z'){
            m[i]='A'+m[i]-'a';
            m[i]='Z'-(('Z'-m[i]-x))%26;
            m[i]='A'+(m[i]-'A')%26;
        }
        else if(m[i]>='A' && m[i]<='Z'){
            m[i]='a'+m[i]-'A';
            m[i]='z'-(('z'-m[i]-x))%26;
            m[i]='a'+(m[i]-'a')%26;
        }
    }
    cout<<"Depcrypted message: "<<m<<endl;
}