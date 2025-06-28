int manual_sizeof()
{
    int arr[2]={1,2};
    char *start=(char* ) &arr[0];
    char *end  =(char*)  &arr[1];
    int size=end-start;
    return (size)   ;
}
int main ()
{
    int size=manual_sizeof();
    printf ("size of integer in this system is %d\n",size);
        return 0;
}
