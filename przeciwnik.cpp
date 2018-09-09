#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "bohater.h"
#include "przeciwnik.h"

using namespace std;

clock_t start2,stop2;

char losuj_klawisz2(int x)
{
    if(x<4)
    {
        return 'A';
    }
    else if((x>=4)||(x<8))
    {
        return 'S';
    }
    else
    {
        return 'D';
    }

}

bool Przeciwnik::atak()
{
    start2=0;
    stop2=0;
    double czas2;
    int combo2;
    char klawisz_obrona=losuj_klawisz2(rand()%10);
    int ilosc_obrona=rand()%10+2;
    int czas_obrona=2+ilosc_obrona/5;

    start2 = clock();
    cout<<"\nNacisnij ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<ilosc_obrona;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<" razy ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout<<klawisz_obrona;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<" aby sie obronic";

    combo2=0;
    while(1)
    {
        if(toupper(getch())==klawisz_obrona)
        {
            combo2++;
            if(combo2>=ilosc_obrona)
            {
                break;
            }
        }
    }
    stop2 = clock();
    czas2 = (double)(stop2-start2) / CLOCKS_PER_SEC;

    if(czas2>czas_obrona)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout<<"  -  Za wolno!";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        return true;
        ///Odebranie zycia bohaterowi
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"  -  Udalo sie!";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

        return false;
        ///Obrona bohatera
    }
}
