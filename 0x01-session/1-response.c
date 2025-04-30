#include<stdio.h>

int is_response_detected(int strength)
{
if (strength>50)
return 1;
else
return 0;
}

int main()
{
int strength_values[]={10,20,50,80};
for (int i=0 ; i<=3;i++)
{
int detected=is_response_detected(strength_values[i]);
if (detected)
printf("Strength %d: Response detected.\n", strength_values[i]);
else
printf("Strength %d: No response detected.\n", strength_values[i]);
}
return 0;
}
