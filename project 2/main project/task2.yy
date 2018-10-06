/** Mkahnyisi Gamedze
*   CS 333 programming languages
*   project 2: lexical analysis
*    26 September 2017
*
* 	##  task 2
*/

	// intialize constants
	int num_rows=0;
	int num_characters=0;
	int num_a=0;   
	int num_e=0;   
	int num_i=0;   
	int num_o=0;   
	int num_u=0;   
			 
%%

a	num_a++;   // count for all vowels and their uppercases

e	num_e++;

i	num_i++;

o	num_o++;

u	num_u++;

A	num_a++;

E	num_e++;

I	num_i++;

O	num_o++;

U	num_u++;

.	{num_characters++;} // count any character except newline




\n	{num_rows++;}  // assuming new row is indicated by this paramenter in a given line of text

%%

int main ( int argc, char *argv[] ) {
 
 if (argc > 1)
 	yyin = fopen( argv[1], "r" ); //where yylex reads its input 
 
 yylex();
 
 printf("\n \n \n number of vowels a=%d e=%d i=%d o=%d u=%d  , total characters=%d   number of lines=%d  \n \n ",num_a, num_e, num_i, num_o, num_u, num_characters , num_rows );
 

}