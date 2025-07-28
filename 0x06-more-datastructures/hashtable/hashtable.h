#ifndef HASHTABLE_H
#define HASHTABLE_H
#define TABLE_SIZE 5

typedef struct node 
{
 struct node *next ;
 int data ;  
 char *key; 
}node;

extern node *table[TABLE_SIZE]; 
unsigned int hash(const char *key);

void insert(const char *key, const char *value);
char *get(const char *key);
void _delete(const char *key);
int contains(const char *key);
int size(int index);
int isEmpty();

#endif