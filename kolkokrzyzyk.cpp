#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "kolkokrzyzyk.h"
void numeruj(int t[4][4])
{
    t[0][1]=1;
    t[0][2]=2;
    t[0][3]=3;
    t[1][0]=1;
    t[2][0]=2;
    t[3][0]=3;
}
struct gracze
{
    char nazwa[20];
    int znak;
    char znk;
};
int main()
{
    gracze gracz[2];
    gracz[0].znak=11;
    gracz[0].znk='X';
    gracz[1].znak=22;
    gracz[1].znk='O';
    start:
    system("cls");
    printf("Podaj nazwe gracza 1: ");
    scanf("%s",&gracz[0].nazwa);
    printf("Podaj nazwe gracza 2: ");
    scanf("%s",&gracz[1].nazwa);
    int gr=0;
    int rem;
    int x,y;
    int n=4;//ilosc rzedzow/kolumn tablicy
    int t[4][4]={0};
    numeruj(t);
    for(int i=1;i<=n-1;i++) //zerowanie planszy
    {
        for(int j=1;j<=n-1;j++)
        {
            t[i][j]=0;
        }
    }
    do{
        czyscPlansze();
        drukujPlansze(t);
        printf("Kolej gracza %s ( %c )\n",gracz[gr].nazwa,gracz[gr].znk);
        powtWyb:
        printf("Wybor [X/Y]: \n");
        do{
        //POSTAWIENIE ZNAKU
        scanf("%d",&x);
        scanf("%d",&y);
        if(x==0 || y==0 ||x>3 || y>3) printf("Pole poza plansza! Podaj inne [X/Y]\n");
        }while(x==0 || y==0 ||x>3 || y>3);

        if(t[y][x]==0)t[y][x]=gracz[gr].znak;
        else
        {
            printf("To pole jest juz zajete!\n");
            printf("Wybierz inne pole!\n");
            goto powtWyb;
        }

        //WARUNKI KONCA
        for(int i=1;i<=3;i++)
        {
            if((t[i][1]==t[i][2] && t[i][2]==t[i][3]) && (t[i][1]!=0 && t[i][2]!=0 && t[i][3]!=0)) goto wygrana;
            else if(t[1][i]==t[2][i] && t[2][i]==t[3][i] && t[1][i]!=0 &&t[2][i]!=0 && t[3][i]!=0) goto wygrana;
        }
        if(t[1][1]==t[2][2] && t[2][2]==t[3][3] &&t[1][1]!=0 && t[2][2]!=0 && t[3][3]!=0) goto wygrana;
        else if(t[1][3]==t[2][2] && t[2][2]==t[3][1] &&t[1][3]!=0 && t[2][2]!=0 && t[3][1]!= 0) goto wygrana;

        rem=0;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(t[i][j]==11 || t[i][j]==22) rem++;
            }
        }
        if(rem==9) goto remis;
        //WYGRANA
        while(0)
        {
            wygrana:
            czyscPlansze();
            drukujPlansze(t);
            printf("Koniec gry, gracz %s wygral!\n",gracz[gr].nazwa);
            int wybor=powtorzGre();
            if(wybor==1) goto start;
            else goto koniec;
        }
        //REMIS
        while(0)
        {
            remis:
            czyscPlansze();
            drukujPlansze(t);
            printf("Koniec gry, Remis!\n");
            int wybor=powtorzGre();
            if(wybor==1) goto start;
            else goto koniec;
        }
        gr=zmianaGracza(gr);
    }while(1);
    koniec:
    return 0;
}
