#include<stdio.h>//*EOF(=^Z或F6),NULL
#include<math.h>
#include<stdarg.h>
#define OK 1
#define ERROR 0
#define MAX_ARRAY_DIM 8
typedef int ElemType;
typedef int Status;//Status是函数的类型，其值是函数结果状态代码，如OK等
typedef struct
{
    ElemType *base;//数组元素基址，由InitArray分配
    int dim;//数组维数
    int *bounds;//数组维界基址，由InitArray分配
    int *constants;//数组映像函数常量基址，由InitArray分配
}
Array;
//顺序存储数组的基本操作

Status InitArray(Array *A,int dim,...)
//若维数dim的各维长度合法，则构造相应的数组A，并返回OK
{
    int elemtotal = 1,i;//elemtotal是元素总值
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
            return UNDERFLOW;//在math。h中定义为4
        elemtotal*=(*A).bounds[i];
    }
    va_end(ap);
    (*A).base=(ElemType *)malloc(elemtotal*sizeof(ElemType));
    if(!(*A).base)
        exit(OVERFLOW);
    (*A).constants=(int *)malloc(dim*sizeof(int));
    if(!(*A).constants)
}
