#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <windows.h>
#include "Bohater.h"
#include "przeciwnik.h"

void intro();
void menu();
void wczytaj();
void zapis(string imie);

using namespace std;

int top10[10];
int score=0;
int progress=0;
int hp_bar;
int hp_bar2;

string nick[10];

float a=89;

int main(int argc, char *argv[])
{
    wczytaj();
    /*a=89/10;
    cout<<"\n"<<a<<"\n\n";
    cout<<round(8.9)<<endl;
    system("pause");*/

    srand( time( NULL ) );

    intro();

    Bohater b1;
    b1.nadajImie();
    b1.hp=1000;

    Przeciwnik p1;
    p1.hp=1000;

    menu();
    system("cls");
    while(true)
    {
        hp_bar=b1.hp/100;
        hp_bar2=p1.hp/100;
        cout<<"                         \nScore: "<<score<<"\n\nTwoje hp: "<<b1.hp<<"                                       "<<p1.hp<<":hp przeciwnika\n";

        for(int z=hp_bar; z>=0; z--)
        {
            cout<<"|";
        }

        for(int z=61-(hp_bar+hp_bar2); z>=0; z--)
        {
            cout<<" ";
        }

        for(int z=hp_bar2; z>=0; z--)
        {
            cout<<"|";
        }


        /*
        Score: xyz
        Twoje hp: x                    z :hp przeciwnika
        |||||||                            |||||||||||||
        x        +         y           +        z     = 65



        */

        //cout<<
        if(p1.hp<=0)
        {
            p1.hp=1000;
            score+=100+progress;
            progress+=50;
            b1.progress2+=0.1;
        }

        if((b1.atak())&&(p1.hp>0))
        {
            p1.hp-=(150+rand()%100+30);
        }
        if(p1.atak())
        {
            b1.hp-=(150+rand()%100+30);
        }
        Sleep(2000);
        system("cls");

        if(b1.hp<=0)
        {
            break;
        }
    }

    system("cls");
    cout<<"Nie zyjesz!\n";
    Sleep(1000);
    system("pause");
    system("cls");

    wczytaj();
    zapis(b1.imie);

    cout<<"RANKING\n";
    for(int c=0;c>10; c++)
    {
        cout<<c<<". "<<nick[c]<<" "<<top10[c]<<"\n";
    }

    return 0;
}

void intro()
{
    cout<<"By Adam Czwordon - ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"www.teampelikan.pl/adach/index.html";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout<<"\n\n\nLoading...\n 0%   ";
    Sleep(1000);
    for(int i=0;i<40; i++)
    {
        cout<<"|";
        Sleep(20);
        if((i==30)||(i==35))
        {
            Sleep(500);
        }
        else if(i==38)
        {
            Sleep(800);
        }
    }
    cout<<"   100%";
    Sleep(1700);
    cout<<"\n\n:)))";
    Sleep(300);
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void menu()
{
    cout<<"Nastepny przeciwnik\n";
    system("pause");
}

void wczytaj()
{
    fstream plik;
    plik.open("ranking.txt", ios::in | ios::app);

    if(!plik.good())
    {
        cout<<"\nNie udalo sie wyswietlic rankingu! Plik nie istnieje!";
    }

    int nr_lini=1;
    int aktualny_nr=1;
    string linia;

    while(getline(plik,linia))
    {
       /* if(aktualny_nr==nr_lini) nick[aktualny_nr-1]=linia;
        if(aktualny_nr==nr_lini+1) top10[aktualny_nr-1]=atoi(linia.c_str());*/

        aktualny_nr++;

    }


    /*string linia;
    int nr_linii=1;
    while(getline(plik, linia))
    {
        switch(nr_linii)
        {
        case 1: nick[0]     =linia;               break;
        }
        nr_linii++;

        (nr_linii)

             if(nr_linii-1>10) {nick[nr_linii-1] =linia;}
             top10[nr_linii-1] =atoi(linia.c_str());               break;


        nr_linii++;
    }*/
    cout<<"RANKING\n";
    for(int c=0;c<10; c++)
    {
        cout<<c+1<<". "<<nick[c]<<" "<<top10[c]<<"\n";
    }
    system("pause");
    plik.close();
}

void zapis(string imie)
{
    fstream plik;
    plik.open("ranking.txt", ios::out | ios::app);

    plik<<" "<<imie<<" "<<score<<endl;


    plik.close();
}

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}








