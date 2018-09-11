#include<stdio.h>
#include<string.h>
void main()
{
    char a[15]="Hi Hillo Hi";
    char *p=a;
    char *q;
    char *temp="Hi";
    int i;
    i=strlen(temp);
    while((q=strstr(p,"Hi"))!=NULL)
    {
        strcpy(q,q+i);
    }
    puts(p);

    system("pause");
}
