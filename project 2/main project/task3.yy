/** Mkahnyisi Gamedze
*   CS 333 programming languages
*   project 2: lexical analysis
*    26 September 2017
*
* 	##  task 3
* 	 strips an html file of all its tags and comments
*/

	

			 
%%


\<p\>	printf("\n\n");	// all <P> tags to be replaced with a blank line

\<[^<>]+\>	printf("");  //  matches html tags without regard to to attributes

[ \t\n]+	printf(""); // skip white space

. printf("%s", yytext);	

%%

int main ( int argc, char *argv[] ) {
 
 if (argc > 1)
 yyin = fopen( argv[1], "r" ); //where yylex reads its input

 yylex(); // a function of flex that read input till it is exhausted
 
 return 0;
 


}
