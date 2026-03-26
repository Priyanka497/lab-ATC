1.
 #include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *str) {
    char *keywords[] = {"int", "float", "char", "if", "else", "while"};
    for (int i = 0; i < 6; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter a statement: ");
    fgets(str, sizeof(str), stdin);

    char *token = strtok(str, " \t\n");

    while (token != NULL) {
        if (isKeyword(token))
            printf("Keyword: %s\n", token);
        else if (isdigit(token[0]))
            printf("Number: %s\n", token);
        else if (strlen(token) == 1 && strchr("+-*/=", token[0]))
            printf("Operator: %s\n", token);
        else
            printf("Identifier: %s\n", token);

        token = strtok(NULL, " \t\n");
    }

    return 

2.
    #include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int lines = 0, words = 0, chars = 0, inWord = 0;

    while ((ch = getchar()) != EOF) {
        chars++;
        if (ch == '\n') 
            lines++;

        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;
        }
    }

    printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, chars);
    return 0;
}

4.
#include <stdio.h>
#include <string.h>

int main() {
    char email[100];
    printf("Enter email: ");
    scanf("%s", email);

    int at = 0, dot = 0;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') at++;
        if (email[i] == '.') dot++;
    }

    if (at == 1 && dot >= 1)
        printf("Valid Email\n");
    else
        printf("Invalid Email\n");

    return 0;
}

5.
#include <stdio.h>

int main() {
    int a, b;
    char op;

    printf("Enter expression (e.g. 5 + 3): ");
    scanf("%d %c %d", &a, &op, &b);

    switch(op) {
        case '+': 
            printf("Result = %d", a + b); 
            break;
        case '-': 
            printf("Result = %d", a - b); 
            break;
        case '*': 
            printf("Result = %d", a * b); 
            break;
        case '/': 
            if (b != 0) 
                printf("Result = %d", a / b); 
            else 
                printf("Error: Division by zero!");
            break;
        default: 
            printf("Invalid operator!");
    }

    return 0;
}

6.
#include <stdio.h>
#include <string.h>

// Simple precedence check
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int main() {
    char expr[50];
    printf("Enter expression: ");
    scanf("%s", expr);

    int ambiguous = 0;

    for (int i = 0; i < strlen(expr) - 1; i++) {
        if (precedence(expr[i]) == precedence(expr[i + 1]) && precedence(expr[i]) != 0) {
            ambiguous = 1;
            break;
        }
    }

    if (ambiguous)
        printf("Possible ambiguity detected (same precedence operators)\n");
    else
        printf("No ambiguity detected (based on precedence rules)\n");

    return 0;
}

7.
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left, *right;
};

struct node* newNode(char data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int main() {
    struct node* root = newNode('+');
    root->left = newNode('a');
    root->right = newNode('*');
    root->right->left = newNode('b');
    root->right->right = newNode('c');

    printf("AST created for a + b * c\n");
    return 0;
}

8. 
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter statement:\n");
    fgets(str, 100, stdin);

    if (strstr(str, "if"))
        printf("IF statement found\n");
    else
        printf("No IF statement\n");

    return 0;
}


9.
#include <stdio.h>

int main() {
    printf("Input:\n");
    printf("a = b + c\n");
    printf("d = b + c\n");

    printf("\nOptimized:\n");
    printf("t1 = b + c\n");
    printf("a = t1\n");
    printf("d = t1\n");

    return 0;
}

10.
include <stdio.h>

int main() {
    printf("Expression: a = b + c\n");
    printf("Generated Code:\n");
    printf("MOV R1, b\n");
    printf("ADD R1, c\n");
    printf("MOV a, R1\n");

    return 0;
}

