#include<stdio.h>//*EOF(=^Z��F6),NULL
#include<math.h>
#include<stdarg.h>
#define OK 1
#define ERROR 0
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef int Status;//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK��
typedef struct
{
    ElemType *base;//����Ԫ�ػ�ַ����InitArray����
    int dim;//����ά��
    int *bounds;//����ά���ַ����InitArray����
    int *constants;//����ӳ����������ַ����InitArray����
}
Array;
//˳��洢����Ļ�������

Status InitArray(Array *A,int dim,...)
//��ά��dim�ĸ�ά���ȺϷ���������Ӧ������A��������OK
{
    int elemtotal = 1,i;//elemtotal��Ԫ����ֵ
    va_list ap;
    if(dim<1||dim>MAX_ARRAY_DIM)
        return ERROR;
    (*A).dim=dim;
    (*A).bounds=(int *)malloc(dim*sizeof(int));
    if(!(*A).bounds)
        exit(OVERFLOW);
    va_start(ap,dim);
    for(i=0;i<dim;i++)
    {
        (*A).bounds[i]=va_arg(ap,int);
        if((*A).bounds[i]<0)
            return UNDERFLOW;//��math��h�ж���Ϊ4
        elemtotal*=(*A).bounds[i];
    }
    va_end(ap);
    (*A).base=(ElemType *)malloc(elemtotal*sizeof(ElemType));
    if(!(*A).base)
        exit(OVERFLOW);
    (*A).constants=(int *)malloc(dim*sizeof(int));
    if(!(*A).constants)
}
