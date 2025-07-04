# include<stdio.h>
# include<stdarg.h>

int sum_them_all(const unsigned int n,...)
{
    va_list args;
    va_start(args, n);
    int sum =0 ;
    for (int i=0 ; i < n ; i++ )
    {
        sum = va_arg(args,int)+sum;
    }
    printf("the sum of the arguments is = %d \n",sum);
    va_end(args);
    return sum ;    
}

int main()
{
    sum_them_all(2,2,3);
    sum_them_all(5,2,3,2,2,3);
    return 0 ;
}

