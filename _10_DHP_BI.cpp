#include <iostream>
#include <conio.h>
#include "..\@lib\BigInteger\BigInteger.cpp"
#include "..\@lib\Resource.hpp"

#define aMAX 100
#define nMAX 400
#define kMAX 1000

using namespace std;

BigInteger bigPow(BigInteger a,BigInteger b)
{
    BigInteger wynik = 1;

    for (BigInteger i = 0; i<b; i++)
        wynik*=a;

    return wynik;
}

int main()
{
    int randC=0;
    string t;
    string in;
    while(1)
    {
    srand(time(NULL));
    char chose;
    cout<<"0 - ALLICE"<<endl<<"1 - BOB"<<endl; chose=getch();
    if(chose=='0')
    {
        BigInteger a = rGenPrime(0,aMAX,randC);
        BigInteger n = rGen(0,nMAX,randC);
        if(n<4 || n==a)
            n = rGen(0,nMAX,randC);
        BigInteger KA=rGen(0,kMAX,randC);   //klucz prywatny ALICE
        if(KA==1 || KA==a)
            KA=rGen(0,kMAX,randC);
        BigInteger KpA=bigPow(a,KA)%n;  //klusz publiczny ALICE
        if(KpA==1)
        {
            KA=rGen(0,kMAX,randC);
            KpA=bigPow(a,KA)%n;
        }
        cout<<"a mod n"<<endl;
                t=a;
        cout<<"a= "<<t<<endl;
                t=n;
        cout<<"n= "<<t<<endl;
                t=KA;
        cout<<"("<<t<<")"<<endl;
                t=KpA;
        cout<<"Klucz publiczny ALICE: "<<t<<endl;
                t=a;
        cout<<"power("<<t;
                t=KA;
        cout<<","<<t;
                t=n;
        cout<<")%"<<t;
                t=KpA;
        cout<<"="<<t<<endl<<endl;
        cout<<"Podaj klucz publiczny BOBa: "; cin>>in;
        BigInteger KpB = in;
         //  x=pow(KpB,KA);
        BigInteger Key=bigPow(KpB,KA)%n;
        //cout<<"power("<<KpB<<","<<KA<<")%"<<n<<"="<<Key<<endl;
                t=KpB;
        cout<<"power("<<t;
                t=KA;
        cout<<","<<t;
                t=n;
        cout<<")%"<<t;
                t=Key;
        cout<<"="<<t<<endl<<endl;
                t=Key;
        cout<<"Wspolny klocz = ("<<t<<")";
    }else
    {

        cout<<"a mod n:"<<endl;
        cout<<"Podaj a: "; cin>>in;
        BigInteger a=in;
        cout<<"Podaj n: "; cin>>in;
        BigInteger n=in;
        cout<<"Podaj klucz publiczny ALICE: "; cin>>in;
        BigInteger KpA=in;
        BigInteger KB=rGen(0,kMAX,randC);   //klucz prywatny BOBa
        if(KB==1)
            KB=rGen(0,kMAX,randC);
        BigInteger KpB=bigPow(a,KB)%n;  //klusz publiczny ALICE
                t=KB;
        cout<<"("<<t<<")";
                t=KpB;
        cout<<endl<<"Klucz publiczny BOBa: "<<t<<endl;
       //     <<"power("<<a<<","<<KB<<")%"<<n<<"="<<KpB<<endl;
                t=a;
        cout<<"power("<<t;
                t=KB;
        cout<<","<<t;
                t=n;
        cout<<")%"<<t;
                t=KpB;
        cout<<"="<<t<<endl<<endl;
        BigInteger Key=bigPow(KpA,KB)%n;
        //cout<<"power("<<KpA<<","<<KB<<")%"<<n<<"="<<Key<<endl;
                t=KpA;
        cout<<"power("<<t;
                t=KB;
        cout<<","<<t;
                t=n;
        cout<<")%"<<t;
                t=Key;
        cout<<"="<<t<<endl<<endl;
        t=Key;
        cout<<"Wspolny klocz = ("<<t<<")";
    }
    getch();
    cout<<endl
        <<"<---------------------------------------------->"
        <<endl;
    }
    return 0;
}
