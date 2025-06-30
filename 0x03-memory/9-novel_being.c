typedef struct 
{
    char *name;
    int age;
    float energy_level;
} Being;

void print_being(Being *b)
{
    printf("Name: %s, Age: %d, Energy: %f \n", b->name, b->age, b->energy_level);
}