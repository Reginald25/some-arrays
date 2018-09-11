#include<stdio.h>
#define N 100
unsigned matrix[N][N];
void init(void);
void odd(unsigned startdigit,unsigned char startrow,unsigned char startcol,unsigned char rowcol);
void odd_even(unsigned char rowcol);
void even_even(unsigned char rowcol);
void print(unsigned char rowcol);
void verify(unsigned char rowcol);
int main()
{
    unsigned char number;
    printf("Please input a number:");
    scanf("%d",&number);
    init();
    if(number % 2)  odd(1,0,0,number);
    else if(number % 4)  odd_even(number);
    else even_even(number);
    print(number);
    verify(number);
    return 0;
}

void init(void)
{
    unsigned char i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        matrix[i][j]=0;

}
void odd(unsigned startdigit,unsigned char startrow,unsigned char startcol,unsigned char rowcol)
{
    unsigned char row,col,row0,col0;
    unsigned i;
    row0 = row = startrow;
    col = (rowcol-1)/2+startcol;
    matrix[row][col]=startdigit;
    for(i=startdigit+1;i<=startdigit+rowcol * rowcol-1;i++)
    {
        if(row-1<startrow)row=startrow+rowcol-1;
        else row--;
        if(col+1>startcol+rowcol-1) col = startcol;
        else col++;
        if(!matrix[row][col])
        {
            row0=row;
            col0=col;
            matrix[row][col]=i;
        }
        else
        {
            row=row0;
            if(row+1>startrow+rowcol-1)row=startrow;
            else row++;
            col = col0;
            matrix[row][col]=i;
        }
    }
}

void odd_even(unsigned char rowcol)
{
    unsigned char k=rowcol/2;
    unsigned char row,col;
    unsigned t,l;
    odd(1,0,0,k);
    odd(k*k+1,k,k,k);
    odd(2*k*k+1,0,k,k);
    odd(3*k*k+1,k,0,k);
    for(col=0;col<=k/2-1;col++)
        for(row=0;row<k;row++)
        if(!(col==0&&row+k==k/2+k))
    {
        t=matrix[row+k][col];
        matrix[row+k][col]=matrix[row][col];
        matrix[row][col]=t;
    }
    t=matrix[(k-1)/2+k][(k-1)/2];
    matrix[(k-1)/2+k][(k-1)/2]=matrix[(k-1)/2][(k-1)/2];
    matrix[(k-1)/2][(k-1)/2]=t;
    l=(k-1)/2;
    for(col=0;col<l-1;col++)
        for(row=k;row<rowcol;row++)
    {
        t=matrix[row][rowcol-col-l];
        matrix[row][rowcol-col-l]=matrix[row-k][rowcol-col-l];
        matrix[row-k][rowcol-col-l]=t;
    }
}

void even_even(unsigned char rowcol)
{
    unsigned order1=rowcol*rowcol,order2=1;
    unsigned char row,col,k;
    for(row=0;row<rowcol;row++)
        for(col=0;col<rowcol;col++)
        if((row%4)==(col%4)||((row%4)+(col%4)==3))
    {
        matrix[row][col]=order1--;
        order2++;
    }
    else
    {
        matrix[row][col]=order2++;
        order1--;
    }
}

void print(unsigned char rowcol)
{
    char *str ="\xc4\xc4\xc4\xc4";
    unsigned char i,j;
    for(i=0;i<rowcol;i++)
    {
        for(j=0;j<rowcol;j++)
        {
            if(i==0)
                if(j==0) printf("\xda");
                else printf("\xc2");
            else
                if(j==0) printf("\xc3");
                else printf("\xc5");
                printf("%s",str);
        }
        if(i==0) printf("\xbf\n");
        else     printf("\xb4\n");
        for(j=0;j<rowcol;j++) printf("\xb3%4b",matrix[i][j]);
        printf("\xb3\n");
    }
    printf("\xc0%s",str);
    for(j=1;j<rowcol;j++) printf("\xb3%4d",matrix[i][j]);
    printf("\xd9\n");
}

void verify(unsigned char rowcol)
{
    unsigned char i,j;
    unsigned sum=0,sum1=0;
    for(i=0;i<rowcol;i++)
    {
        sum1=0;
        for(j=0;j<rowcol;j++)
            sum1+=matrix[i][j];
        if(sum==0)sum=sum1;
        else if(sum1!=sum)
        {
            printf("Error!\n");
            return;
        }
    }
    for(i=0;i<rowcol;i++)
    {
        sum1=0;
        for(j=0;j<rowcol;j++)
            sum1+=matrix[j][i];
        if(sum==0) sum=sum1;
        else if(sum1 !=sum)
        {
            printf("Error!\n");
            return;
        }
    }
    printf("Verify OK!The sum is %d\n",sum);//sum=n*n*(n*n+1)/2
}

