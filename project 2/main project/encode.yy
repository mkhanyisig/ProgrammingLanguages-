/** Mkahnyisi Gamedze
*   CS 333 programming languages
*   project 2: lexical analysis
*    26 September 2017
*
* 	##  task 1
*/


	char c;   
			 
%%

[a-z]		{  //printf("\n %c final  ", yytext[0]);  // uncomment to see initial and final
			if (((int)yytext[0])< 110){ 
				c=(int)yytext[0];
				c=c+13; 
					
		 	}
		 	else{
		 		//printf(">110  %d ",yytext[0] );
		 		c=(int)yytext[0];
				c=c-110; 
				c=97+c;	
				
		 	}
		 	
		 	yytext[0]=c; 	
		 	printf("%c ",yytext[0] );
		 	yytext[0]=c;  
		 }
		 
[A-Z]		{  //printf("\n %c final  ", yytext[0]);  // uncomment to see initial and final
			if (((int)yytext[0])< 77){
				c=(int)yytext[0];
				c=c+13; 
					
		 	}
		 	else{
		 		//printf(">77  %d ",yytext[0] );
		 		c=(int)yytext[0];
				c=c-77; 
				c=64+c;	
				
		 	}
		 	
		 	yytext[0]=c; 	
		 	printf("%c ",yytext[0] );
		 	yytext[0]=c;  
		 }

%%

int main ( int argc, char *argv[] ) {
 
 yylex();

}