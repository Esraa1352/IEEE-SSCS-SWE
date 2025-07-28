#include "hashtable.h"

void insert(const char *key, const char *value)
{
    unsigned int index = hash(key);
    node *new_node = malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->data= strdup(value);
    new_node->next = table[index];
    table[index] = new_node;
}
