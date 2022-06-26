#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
