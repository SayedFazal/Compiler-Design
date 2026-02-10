%{
#include <stdio.h>
%}

%%
^[AEIOUaeiou][a-zA-Z]*   { printf("Valid string: starts with a vowel\n"); }
.*                       { printf("Invalid string: does not start with a vowel\n"); }
%%

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
