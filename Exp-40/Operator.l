%{
#include <stdio.h>
%}

%%
"=="|"<="|">="|"!="|"<"|">"   { printf("Relational Operator: %s\n", yytext); }
[a-zA-Z]+                    { printf("Word (Identifier): %s\n", yytext); }
[ \t\n]+                     ;   /* ignore spaces */
.                             ;
%%

int main()
{
    printf("Enter input:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
