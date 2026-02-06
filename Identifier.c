#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 20

int isOperator(char ch) {
    char operators[] = "+-*/=<>";
    for (int i = 0; operators[i] != '\0'; i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[MAX_ID_LEN];
    int i;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        /* Ignore whitespaces */
        if (ch == ' ' || ch == '\n' || ch == '\t')
            continue;

        /* Ignore comments */
        if (ch == '/') {
            char next = fgetc(fp);
            if (next == '/') {          // single-line comment
                while ((ch = fgetc(fp)) != '\n');
            } else if (next == '*') {   // multi-line comment
                while (1) {
                    ch = fgetc(fp);
                    if (ch == '*' && fgetc(fp) == '/')
                        break;
                }
            } else {
                printf("Operator: /\n");
                ungetc(next, fp);
            }
        }

        /* Identifier */
        else if (isalpha(ch)) {
            i = 0;
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(fp)) && i < MAX_ID_LEN - 1)
                buffer[i++] = ch;
            buffer[i] = '\0';
            ungetc(ch, fp);
            printf("Identifier: %s\n", buffer);
        }

        /* Constant */
        else if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;
            while (isdigit(ch = fgetc(fp)))
                buffer[i++] = ch;
            buffer[i] = '\0';
            ungetc(ch, fp);
            printf("Constant: %s\n", buffer);
        }

        /* Operator */
        else if (isOperator(ch)) {
            printf("Operator: %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
