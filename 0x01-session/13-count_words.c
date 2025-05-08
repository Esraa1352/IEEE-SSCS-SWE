int counter(char *mystring)
{
int count = 0 , in_word = 0;
while (*mystring)
{
if (*mystring == ' ')
{
in_word = 0;
}
else if (!in_word) {
in_word = 1;
count++;
}
mystring++;
}

return count;
}


