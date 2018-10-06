/**
 * Read in from a specified file and
 * print out a list of all the integers in the file
 *
 * flex -o test.yy.c test.yy
 * gcc -o test test.yy.c -ll
 */



%%
[a-z] {if ((int)yytext[0]< 110):
		 printf("%c", (char)((int)yytext[0] +13))}

%%

int main( int argc, char *argv[] ) {

 if (argc > 1)
 yyin = fopen( argv[1], "r" ); //where yylex reads its input

 yylex(); // a function of flex that read input till it is exhausted
 printf("There are %d lines in the file.\n", count);
 return 0;
}