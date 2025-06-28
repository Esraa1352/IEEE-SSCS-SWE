#include <stdio.h>
typedef struct
{
    int i;
    float f;
    char c;
} DataType;

DataType echo_data(void *data)
{
    DataType *input = (DataType *)data;
    return *input ;
}
int main ()
{
    DataType InputData={1,1.25,'c'};
    DataType Result = echo_data(&InputData);
    printf("%d \n %c\n %f \n ", Result.i,Result.c, Result.f );

}