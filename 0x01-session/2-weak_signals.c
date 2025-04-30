#include <stdio.h>


int is_strong_signal(int strength)
{
if (strength > 50)
return 1;
else
return 0;
}
void check_signal(int strength)
{
int detected=is_strong_signal(strength);
if (detected)
printf("Strong signal detected \n");
else
printf("No signal detected\n");
}
int main ()
{
int signal_strengths[]={10,50,80,90};
for (int i=0;i<=3;i++)
{
check_signal(signal_strengths[i]);
}
return 0;
}
