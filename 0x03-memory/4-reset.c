#include <stdio.h>
int counter_3 = 0;
int access_one(void)
{
    static int counter_1=0;
    counter_1++;
    counter_3++;
    printf("access_one function has been called for  %d times \n",counter_1);
    return counter_1 ;
}
int access_two(void)
{
    static int counter_2=0;
    counter_3++;
    counter_2++;
    printf("access_two function has been called for  %d times \n",counter_2);
    return counter_2 ;
}
int main ()
{
    access_one();
    access_one();
    access_one();
    access_two();
    access_two();
    printf("both functions has been called for  %d times \n",counter_3);
    return 0;
}