/*
 * Semih Demir
 * No: 18120205005
 * main.cpp
 * 07.04.2019
 */
#include "sozluk.h"
#include <iostream>
#include <vector>
#include "kayit.h"
using namespace std;

int main()
{
    Kayit A("Baslik_1", "Aciklama1");
    Kayit B("Baslik1", "Aciklama2");
    
    vector <string> v;
    v.push_back("devam1");
    v.push_back("devam2");
    Kayit C("Baslik", v);

    Sozluk X(C);
    Sozluk Y(A);
    Sozluk Z(B);
    Sozluk D = Y+Z;
    // = , + operant kontrolü

    cout << X+Y;
    cout << "****************" << endl;
    
    D-= "cıkar";
    cout << D;
    cout << "****************\n" << endl;

    cout << X;
    cout << "****************\n" << endl;

     X+=Y;
    cout << X;
    cout << "****************\n" << endl;  
 
    X-=C;
    cout << X;
    cout << "****************\n" << endl;

    cout << "****************" << endl;    

    if(X>Y) cout << "'>' operatoru basarili bir sekilde calisti!" << endl;
    cout << "****************\n" << endl;
    if(!(X==Y)) cout << "'==' operatoru basarili bir sekilde calisti!" << endl;
    cout << "****************\n" << endl;
    if(!(X<Y)) cout << "'<' operatoru basarili bir sekilde calisti!" << endl;
    cout << "****************\n" << endl;
    if(X!=Y) cout << "'!=' operatoru basarili bir sekilde calisti!" << endl;
    cout << "****************\n" << endl;
    if(X>=Y) cout << "'>=' operatoru basarili bir sekilde calisti!" << endl;
    cout << "****************\n" << endl;
    if(!(X<=Y)) cout << "'>=' operatoru basarili bir sekilde calisti!" << endl;
    cout << "****************\n" << endl;

    return 0;

}