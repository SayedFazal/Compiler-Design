%{
#include <stdio.h>
#include <string.h>
int max = 0;
%}
%%
[a-zA-Z]+   {
                int len = strlen(yytext);
                if (len > max)
                    max = len;
            }
[ \t\n]+    ;   /* ignore spaces, tabs, newlines */
%%
int main()
{
    printf("Enter a sentence:\n");
    yylex();
    printf("Length of the longest word = %d\n", max);
    return 0;
}
int yywrap()
{
    return 1;
}
