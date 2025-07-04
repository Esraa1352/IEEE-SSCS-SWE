#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* create_node(int value) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return NULL;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_node_end(Node** head, int value) {
    Node* new_node = create_node(value);
    if (!*head) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = new_node;
}

void print_list(Node* head) {
    while (head) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    add_node_end(&head, 1);
    add_node_end(&head, 2);
    add_node_end(&head, 3);
    print_list(head);
    return 0;
}
