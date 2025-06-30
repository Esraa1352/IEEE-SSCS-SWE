int main (int argc , char *argv)
{
    int truth = 0;
    if (argc==1)
    {
        printf("Silence. Nothing came through.\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
    if (truth==0 && strcmp(argv[i], "revelation") == 0)
    {
        printf("A truth revealed: You are not alone");
        truth=1;

    }

    
}
}