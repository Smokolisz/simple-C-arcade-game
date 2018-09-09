#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "bohater.h"
#include "przeciwnik.h"

using namespace std;

clock_t start,stop;

double czas;
int combo;

char losuj_klawisz(int x)
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

void Bohater::nadajImie()
{
    cout<<"Nadaj imie bohaterowi: ";
    cin>>Bohater::imie;
    system("cls");
}

bool Bohater::atak()
{
    combo=0;
    start=0;
    stop=0;
    char klawisz_atak=losuj_klawisz(rand()%10);
    int ilosc_atak=rand()%10+2;
    float progress2=0.1;
    float czas_atak=2+ilosc_atak/4-progress2;
    start = clock();
    cout<<"\nNacisnij ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<ilosc_atak;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<" razy ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout<<klawisz_atak;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout<<" aby zaatakowac";

    combo=0;
    while(1)
    {
        if(toupper(getch())==klawisz_atak)
        {
            combo++;
            if(combo>=ilosc_atak)
            {
                break;
            }
        }
    }
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;

    if(czas>czas_atak)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout<<"  -  Za wolno!";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return false;
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout<<"  -  Udalo sie";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return true;
    }
}
