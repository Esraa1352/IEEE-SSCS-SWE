#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include "sms.h"
int i=0;
void hash_password(const char *password,char *dest)
{
  unsigned char hash[32];
  SHA256((const unsigned char *)password, strlen(password), hash);
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
  {
    sprintf( dest+ (i * 2), "%02x", hash[i]); //convert each byte in hash[i] to 2 hex decimal in dest[i]and dest[i++]  
  }
  dest[64]='\0'; //null terminator
}
void get_data ()
{
    char password[50];
    Data user ;
    printf("Hello , To sign in please enter your name");
    scanf ("%s",user.name);
    printf("please enter your password");
    scanf("%s",password);
    hash_password(password,user.hashed_password);
    printf("please enter your Email");
    scanf("%s",user.email);
    int option;
    printf("Are you a/an : 1-ADMIN 2-MODERATOR 3-USER");
    scanf("%d",&option);
    user.role=option-1;
    const char *role_str[] = {"ADMIN", "MODERATOR", "USER"};
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        perror("Sorry , Failed to save your data ");
        return;
    }
    fprintf(file,"-------------------------------------------------------------------------------------------------------------------\n");
    fprintf(file, "Name: %s\nEmail: %s\nPassword: %s\nRole: %s\n" ,user.name, user.email, user.hashed_password, role_str[user.role]);
    fclose(file);
}

int main ()
{
    get_data();
    
}