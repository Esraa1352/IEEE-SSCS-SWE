#include <stdlib.h>
#include "polynomial-solver.h" 
#include <stdio.h>


Term *A = NULL, *B = NULL, *C = NULL, *R = NULL;

//free old polynomial
void freePolynomial(Term **poly) {
    Term *current = *poly;
    while (current != NULL) {
        Term *next = current->next;
        free(current);
        current = next;
    }
    *poly = NULL;
}

void setPolynomial(char poly, int terms[][2], int size) {
    Term **target;

    // Choose the target polynomial
    if (poly == 'A') target = &A;
    else if (poly == 'B') target = &B;
    else if (poly == 'C') target = &C;
    else return;

    // Free old polynomial if any
    freePolynomial(target);

    Term *head = NULL, *tail = NULL;

    // Build the linked list
    for (int i = 0; i < size; i++) {
        Term *new_term = malloc(sizeof(Term));
        if (!new_term) return; // Memory allocation failed

        new_term->coeff = terms[i][0];
        new_term->exp = terms[i][1];
        new_term->next = NULL;

        if (head == NULL) {
            head = tail = new_term;
        } else {
            tail->next = new_term;
            tail = new_term;
        }
    }

    *target = head;
}

void print(char poly) {
    Term *current = NULL;

    if (poly == 'A') current = A;
    else if (poly == 'B') current = B;
    else if (poly == 'C') current = C;
    else if (poly == 'R') current = R;
    else {
        printf("Invalid polynomial name.\n");
        return;
    }

    if (current == NULL) {
        printf("0\n");
        return;
    }

    while (current != NULL) {
        int coeff = current->coeff;
        int exp = current->exp;

        if (coeff == 0) {
            current = current->next;
            continue; // Skip zero terms
        }

        // Print sign for middle terms
        if (current != A && coeff > 0) {
            printf(" + ");
        } else if (coeff < 0) {
            printf(" - ");
            coeff = -coeff; // Make it positive for printing
        }

        // Print coefficient
        if (exp == 0) {
            printf("%d", coeff);
        } else if (exp == 1) {
            if (coeff != 1) printf("%d", coeff);
            printf("x");
        } else {
            if (coeff != 1) printf("%d", coeff);
            printf("x^%d", exp);
        }

        current = current->next;
    }

    printf("\n");
}

void clearPolynomial(char poly) {
    Term **target;

    if (poly == 'A') target = &A;
    else if (poly == 'B') target = &B;
    else if (poly == 'C') target = &C;
    else if (poly == 'R') target = &R;
    else return;

    Term *current = *target;
    while (current) {
        Term *next = current->next;
        free(current);
        current = next;
    }

    *target = NULL;
}

#include <math.h>

float evaluatePolynomial(char poly, float x) {
    Term *p = NULL;

    if (poly == 'A') p = A;
    else if (poly == 'B') p = B;
    else if (poly == 'C') p = C;
    else if (poly == 'R') p = R;
    else return 0;

    float result = 0;

    while (p != NULL) {
        result += p->coeff * powf(x, p->exp);
        p = p->next;
    }

    return result;
}
void add(char poly1, char poly2) {
    clearPolynomial('R');

    Term *p1 = (poly1 == 'A') ? A : (poly1 == 'B') ? B : C;
    Term *p2 = (poly2 == 'A') ? A : (poly2 == 'B') ? B : C;

    Term *head = NULL, *tail = NULL;

    while (p1 || p2) {
        Term *new_term = malloc(sizeof(Term));
        new_term->next = NULL;

        if (p1 && (!p2 || p1->exp > p2->exp)) {
            new_term->coeff = p1->coeff;
            new_term->exp = p1->exp;
            p1 = p1->next;
        } else if (p2 && (!p1 || p2->exp > p1->exp)) {
            new_term->coeff = p2->coeff;
            new_term->exp = p2->exp;
            p2 = p2->next;
        } else { // equal exponents
            new_term->coeff = p1->coeff + p2->coeff;
            new_term->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (new_term->coeff != 0) {
            if (!head) head = tail = new_term;
            else tail = tail->next = new_term;
        } else {
            free(new_term);
        }
    }

    R = head;
}
void subtract(char poly1, char poly2) {
    clearPolynomial('R');

    Term *p1 = (poly1 == 'A') ? A : (poly1 == 'B') ? B : C;
    Term *p2 = (poly2 == 'A') ? A : (poly2 == 'B') ? B : C;

    Term *head = NULL, *tail = NULL;

    while (p1 || p2) {
        Term *new_term = malloc(sizeof(Term));
        new_term->next = NULL;

        if (p1 && (!p2 || p1->exp > p2->exp)) {
            new_term->coeff = p1->coeff;
            new_term->exp = p1->exp;
            p1 = p1->next;
        } else if (p2 && (!p1 || p2->exp > p1->exp)) {
            new_term->coeff = -p2->coeff;
            new_term->exp = p2->exp;
            p2 = p2->next;
        } else { // equal exponents
            new_term->coeff = p1->coeff - p2->coeff;
            new_term->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (new_term->coeff != 0) {
            if (!head) head = tail = new_term;
            else tail = tail->next = new_term;
        } else {
            free(new_term);
        }
    }

    R = head;
}
void multiply(char poly1, char poly2) {
    clearPolynomial('R');

    Term *p1 = (poly1 == 'A') ? A : (poly1 == 'B') ? B : C;
    Term *p2 = (poly2 == 'A') ? A : (poly2 == 'B') ? B : C;

    Term *result = NULL;

    for (Term *t1 = p1; t1 != NULL; t1 = t1->next) {
        for (Term *t2 = p2; t2 != NULL; t2 = t2->next) {
            int coeff = t1->coeff * t2->coeff;
            int exp = t1->exp + t2->exp;

            // Add to result (combine like terms)
            Term *curr = result, *prev = NULL;
            while (curr && curr->exp > exp) {
                prev = curr;
                curr = curr->next;
            }

            if (curr && curr->exp == exp) {
                curr->coeff += coeff;
                if (curr->coeff == 0) { // Remove zero term
                    if (prev) prev->next = curr->next;
                    else result = curr->next;
                    free(curr);
                }
            } else if (coeff != 0) {
                Term *new_term = malloc(sizeof(Term));
                new_term->coeff = coeff;
                new_term->exp = exp;
                new_term->next = curr;
                if (prev) prev->next = new_term;
                else result = new_term;
            }
        }
    }

    R = result;
}




