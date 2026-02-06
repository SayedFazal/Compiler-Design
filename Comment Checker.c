#include <stdio.h>
#include <string.h>

int main() {
    char line[200];

    printf("Enter a line of code:\n");
    fgets(line, sizeof(line), stdin);

    // Check for single-line comment
    if (line[0] == '/' && line[1] == '/') {
        printf("The given line is a SINGLE-LINE COMMENT.\n");
    }

    // Check for multi-line comment
    else if (line[0] == '/' && line[1] == '*' && strstr(line, "*/") != NULL) {
        printf("The given line is a MULTI-LINE COMMENT.\n");
    }

    else {
        printf("The given line is NOT A COMMENT.\n");
    }

    return 0;
}
