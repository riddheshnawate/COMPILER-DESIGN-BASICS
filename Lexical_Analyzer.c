#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* List of C keywords */
const char *keywords[] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void"
};
int keywordCount = 9;

/* Check if word is a keyword */
int isKeyword(char *word) {
    for (int i = 0; i < keywordCount; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[50];
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Cannot open file\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {

        /* Operator detection */
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>') {
            printf("Operator: %c\n", ch);
        }

        /* Identifier / Keyword detection */
        else if (isalpha(ch)) {
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(fp))) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;

            if (isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}
