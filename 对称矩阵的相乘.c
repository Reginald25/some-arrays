#include<stdio.h>
#define N 3//N��ʾ����Ľ�������Ҫ�ı����ֻ��Ķ��˴�
#define M N*(N+1)/2//M��ʾ�洢ѹ�������һά�����Ԫ�ظ���
//�õ��洢��һά�����ж�Ӧѹ�������ֵ

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
//�����������ѹ��������г˲���
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
//�������
void main()
{
    //����洢ѹ�������һά����A��B
    //����洢ѹ��������˺�Ķ�ά����C
    int A[M],B[M],C[N][N];
    int i,j;
    printf("Please input array A:\n");
    //��������A
    for(i=0;i<M;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nPlease input array B:\n");
    //��������B
    for(i=0;i<M;i++)
    {
        scanf("%d",&B[i]);
    }
    //���þ�����˺���
    mult(A,B,C);//A*B=c
    printf("\nThe result of A*B is:\n");
    //������C
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
