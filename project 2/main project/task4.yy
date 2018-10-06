/** Mkahnyisi Gamedze
*   CS 333 programming languages
*   project 2: lexical analysis
*    26 September 2017
*
* 	##  task 3
* 	 strips an html file of all its tags and comments
*/


			 
%%

[ \t\n]+	// whitespace do nothing

"main"	printf("Identifier-%s  \n",yytext);

[0-9]+	{printf("Integer-<%s> \n ",yytext);} // Signed decimal integer

[0-9]+"."[0-9]*		{printf("Float-<%s> \n",yytext);}	// Decimal floating point

if|else|while|for|int|float	  printf( "Keyword-%s \n", yytext );

=	{printf("Assignment \n");}

==|<|>|<=|>=	{printf("Comparison-%s\n",yytext);}

"+"|"-"|"*"|"/"   printf( "Operator-%s\n", yytext );

"{"	printf("Open-bracket \n");

"}"	printf("Close-bracket \n");


"("	printf("Open-paren \n");

")"	printf("Close-paren \n");

[a-zA-Z]	printf("Identifier-%s\n",yytext);

;	// pass

.	// pass



"/*"		printf("------- beginning of comment --------\n \n");

"*/"		printf("------- end of comment --------\n \n");

"//"	printf("-----------line comment---------------");








%%

int main ( int argc, char *argv[] ) {
 
 if (argc > 1)
 yyin = fopen( argv[1], "r" ); //where yylex reads its input

 yylex(); // a function of flex that read input till it is exhausted
 
 return 0;
 


}
