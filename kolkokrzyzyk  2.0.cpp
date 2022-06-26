#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>

using namespace std;
int zmianaGracza(int gr)
{
    if(gr==0) return 1;
    else if(gr==1) return 0;
}
void drukujPlansze(int t[4][4])
{
    for(int i=0;i<=3;i++) //drukowanie planszy
    {
        for(int j=0;j<=3;j++)
        {
            if(i==0 || j==0) printf("%d ",t[i][j]);
            else if(t[i][j]==0) {printf("%c ",32);}
            else if(t[i][j]==11) printf("%c ",'X');
            else if(t[i][j]==22) printf("%c ",'O');
        }
        printf("\n");
    }
}
void czyscPlansze()
{
    system("cls");
}
int powtorzGre()
{
    int wybor;
    printf("Powtorzyc gre?\n");
    printf("1. Tak :D\n");
    printf("2. Nie D:\n");
    printf("Wybor: ");
    scanf("%d",&wybor);
    return wybor;
}
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
    char nazwa[20]="PC";
    int znak;
    char znk;
    int ai=0;
};
int main()
{
    gracze gracz[2];
    gracz[0].znak=11;
    gracz[0].znk='X';
    gracz[1].znak=22;
    gracz[1].znk='O';
    int isai;
    start:
    system("cls");
    cout<<"1. 1 Player"<<endl;
    cout<<"2. 2 Players"<<endl;
    cin>>isai;
    if(isai==1)
    {
        gracz[1].ai=1;
    }
    printf("Podaj nazwe gracza 1: ");
    scanf("%s",&gracz[0].nazwa);
    if(isai!=1)
    {
        printf("Podaj nazwe gracza 2: ");
        scanf("%s",&gracz[1].nazwa);
    }
    //else {gracz[1].nazwa="PC";}
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
    int movve=0;
    do{
        movve++;
        czyscPlansze();
        drukujPlansze(t);
        printf("Kolej gracza %s ( %c )\n",gracz[gr].nazwa,gracz[gr].znk);
        powtWyb:
        printf("Wybor [X/Y]: \n");
        if(gracz[gr].ai==0)
        {
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
        }
        else if(gracz[gr].ai==1)
        {
            int zajete=0;
            int copyBoard[3][3];
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    copyBoard[i][j]=t[i+1][j+1];
                    if(copyBoard[i][j]==11 || copyBoard[i][j]==22)
                    {
                        zajete++;
                    }
                }
            }
            if(movve==1 || movve==2 )
            {
                int option;
                int a=5;
                int b=1;
                while(0)
                {
                reMove12:
                    a--;
                    b++;
                }
                option=(rand()%a)+b;
                if(option==1)
                {
                    if(copyBoard[0][0]==11 || copyBoard[0][0]==22) goto reMove12;
                    else copyBoard[0][0]=22;
                }
                else if(option==2)
                {
                    if(copyBoard[0][2]==11 || copyBoard[0][2]==22) goto reMove12;
                    else copyBoard[0][2]=22;
                }
                else if(option==3)
                {
                    if(copyBoard[2][0]==11 || copyBoard[2][0]==22) goto reMove12;
                    else copyBoard[2][0]=22;
                }
                else if(option==4)
                {
                    if(copyBoard[2][2]==11 || copyBoard[2][2]==22) goto reMove12;
                    else copyBoard[2][2]=22;
                }
                else if(option==5)
                {
                    if(copyBoard[1][1]==11 || copyBoard[1][1]==22) goto reMove12;
                    else copyBoard[1][1]=22;
                }
            }
            int placed=0;
            if(zajete>=3 && zajete<5)
            {
                //DEFF
                int crn=11;
                if(copyBoard[0][0]==crn && copyBoard[1][0]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][2]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                if(copyBoard[0][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                //ATT
                crn=22;
                if(copyBoard[0][0]==crn && copyBoard[1][0]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][2]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }

                if(placed==0)
                {
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(copyBoard[i][j]==0 && placed==0)
                            {
                                if(placed==0)
                                {
                                    copyBoard[i][j]=22;
                                    placed=1;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            if(zajete>=5)
            {
                //ATT
                int crn=22;
                if(copyBoard[0][0]==crn && copyBoard[1][0]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][2]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                if(copyBoard[0][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                //DEFF
                crn=11;
                if(copyBoard[0][0]==crn && copyBoard[1][0]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][2]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[2][2]==0 && placed==0)
                    {
                        copyBoard[2][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[0][0]==0 && placed==0)
                    {
                        copyBoard[0][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[1][1]==crn)
                {
                    if(copyBoard[0][2]==0 && placed==0)
                    {
                        copyBoard[0][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][1]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[2][0]==0 && placed==0)
                    {
                        copyBoard[2][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][0]==crn)
                {
                    if(copyBoard[1][0]==0 && placed==0)
                    {
                        copyBoard[1][0]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[0][1]==0 && placed==0)
                    {
                        copyBoard[0][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][2]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][2]==0 && placed==0)
                    {
                        copyBoard[1][2]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[2][1]==0 && placed==0)
                    {
                        copyBoard[2][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][0]==crn && copyBoard[2][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[2][0]==crn && copyBoard[0][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[0][1]==crn && copyBoard[2][1]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
                 if(copyBoard[1][0]==crn && copyBoard[1][2]==crn)
                {
                    if(copyBoard[1][1]==0 && placed==0)
                    {
                        copyBoard[1][1]=22;
                        placed=1;
                        goto endTurn;
                    }
                }
               if(placed==0)
                {
                    for(int i=0;i<3;i++)
                    {
                        for(int j=0;j<3;j++)
                        {
                            if(copyBoard[i][j]==0 && placed==0)
                            {
                                if(placed==0)
                                {
                                    copyBoard[i][j]=22;
                                    placed=1;
                                }
                                else
                                    break;
                            }
                        }
                    }
                }
            }
            //if(zajete>4)
            endTurn:
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    t[i+1][j+1]=copyBoard[i][j];
                }
            }
            Sleep(250);
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
