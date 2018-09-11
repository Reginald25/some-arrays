#include<stdio.h>
int main()
{
    int i,j;
    int a[10][10];
    printf("Ñî»ÔÈý½Ç£¡£º\n");
    for(i=0;i<10;i++)
    {
        a[i][0]=1;
        a[i][i]=1;
    }
    for(i=2;i<10;i++)
        for(j=1;j<i;j++)
        a[i][j]=a[i-1][j-1]+a[i-1][j];
    for(i=0;i<10;i++)
    {
        printf("%*d",25-i*2,a[i][0]);
        for(j=1;j<=i;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    system("pause");

    return 0;
}
