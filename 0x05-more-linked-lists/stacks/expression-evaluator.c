#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

// Helper for operator precedence
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int isOperand(char ch) {
    return isdigit(ch) || isalpha(ch);
}
char* infixToPostfix(char* expression) {
    Stack opStack = {NULL, 0};
    char* postfix = malloc(strlen(expression) * 2 + 1);
    int j = 0;

    for (int i = 0; expression[i]; i++) {
        char ch = expression[i];

        if (ch == ' ') continue;

        if (isOperand(ch)) {
            postfix[j++] = ch;
            postfix[j++] = ' ';
        } else if (ch == '(') {
            push(&opStack, ch);
        } else if (ch == ')') {
            while (!isEmpty(&opStack) && (char)peek(&opStack) != '(') {
                postfix[j++] = (char)pop(&opStack);
                postfix[j++] = ' ';
            }
            pop(&opStack); // remove '('
        } else if (isOperator(ch)) {
            while (!isEmpty(&opStack) && precedence((char)peek(&opStack)) >= precedence(ch)) {
                postfix[j++] = (char)pop(&opStack);
                postfix[j++] = ' ';
            }
            push(&opStack, ch);
        }
    }

    while (!isEmpty(&opStack)) {
        postfix[j++] = (char)pop(&opStack);
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0';
    return postfix;
}
float applyOp(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

float evaluatePostfix(char* expression) {
    Stack stack = {NULL, 0};
    char* token = strtok(expression, " ");

    while (token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atof(token));
        } else if (strlen(token) == 1 && isOperator(token[0])) {
            float b = pop(&stack);
            float a = pop(&stack);
            float result = applyOp(a, b, token[0]);
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

