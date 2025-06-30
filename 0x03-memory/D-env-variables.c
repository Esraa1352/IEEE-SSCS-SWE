#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct env_var {
    char *key;
    char *value;
    struct env_var *next;
} env_var;

env_var* create_node(const char* key, const char* value) {
    env_var* node = malloc(sizeof(env_var));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

void add_env_var(env_var** head, const char* key, const char* value) {
    env_var* cur = *head;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            printf("Variable '%s' already exists. Use update_env_var.\n", key);
            return;
        }
        cur = cur->next;
    }
    env_var* node = create_node(key, value);
    node->next = *head;
    *head = node;
}


int update_env_var(env_var* head, const char* key, const char* value) {
    env_var* cur = head;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            free(cur->value);
            cur->value = strdup(value);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}


int delete_env_var(env_var** head, const char* key) {
    env_var *cur = *head, *prev = NULL;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            if (prev) prev->next = cur->next;
            else *head = cur->next;
            free(cur->key);
            free(cur->value);
            free(cur);
            return 1;
        }
        prev = cur;
        cur = cur->next;
    }
    return 0;
}


const char* get_env_var(env_var* head, const char* key) {
    env_var* cur = head;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            return cur->value;
        }
        cur = cur->next;
    }
    return NULL;
}


env_var* store_env(char **envp) {
    env_var* head = NULL;
    for (int i = 0; envp[i] != NULL; i++) {
        // envp[i] is "KEY=VALUE"
        char* sep = strchr(envp[i], '=');
        if (!sep) continue; 

        size_t key_len = sep - envp[i];
        char* key = malloc(key_len + 1);
        strncpy(key, envp[i], key_len);
        key[key_len] = '\0';

        char* value = strdup(sep + 1);

        add_env_var(&head, key, value);

        free(key);
        free(value);
    }
    return head;
}

void print_env_to_file(env_var* head, const char* filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        perror("fopen");
        return;
    }

    env_var* cur = head;
    while (cur) {
        fprintf(f, "%s=%s\n", cur->key, cur->value);
        cur = cur->next;
    }

    fclose(f);
}


void free_env_list(env_var* head) {
    env_var* cur = head;
    while (cur) {
        env_var* next = cur->next;
        free(cur->key);
        free(cur->value);
        free(cur);
        cur = next;
    }
}
