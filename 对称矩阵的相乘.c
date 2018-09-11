#include<stdio.h>
#define N 3//N表示矩阵的阶数，若要改变阶数只需改动此处
#define M N*(N+1)/2//M表示存储压缩矩阵的一维数组的元素个数
//得到存储在一维数组中对应压缩矩阵的值

int getValue (int a[],int i,int j)
{
    if(i>=j)
    {
        return a[i*(i+1)/2+j];
    }
    else
    {
        return a[j*(j+1)/2+i];
    }
}
//对输入的两个压缩矩阵进行乘操作
void mult(int a[],int b[],int c[N][N])
{
    int i,j,k,s,x,y;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            s=0;
            for(k=0;k<N;k++)
            {
                x=getValue(a,i,k);
                y=getValue(b,k,j);
                printf("getValue(a,%d,%d)=%d\n",i,k,x);
                printf("getValue(b,%d,%d)=%d\n",k,j,y);
                s = s +x*y;
            }
            c[i][j]=s;
        }
    }
}
//程序入口
void main()
{
    //定义存储压缩矩阵的一维数组A，B
    //定义存储压缩矩阵相乘后的二维数组C
    int A[M],B[M],C[N][N];
    int i,j;
    printf("Please input array A:\n");
    //输入数组A
    for(i=0;i<M;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nPlease input array B:\n");
    //输入数组B
    for(i=0;i<M;i++)
    {
        scanf("%d",&B[i]);
    }
    //调用矩阵相乘函数
    mult(A,B,C);//A*B=c
    printf("\nThe result of A*B is:\n");
    //输出结果C
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d            ",C[i][j]);
        }
        printf("\n");
    }

    system("pause");
    return 0;
}
