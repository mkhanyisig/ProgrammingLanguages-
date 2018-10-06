/** Mkahnyisi Gamedze
*   CS 333 programming languages
*   project 2: lexical analysis
*    26 September 2017
*
* 	error in code
*/


	char c;   
			 
%%

[a-z]		{  printf("****   %d ", yytext[0]);
			if ((int)yytext[0]>96  && (int)yytext[0]< 123){ // unnnecessary
				c=yytext[0]; 	
				c=c +14;
				c=abs(c);
				//printf("  ****> %d   \n",c); 
		 	if(c<0){
		 		c=-1*c;
		 		//printf("converted %d  ",c);
		 	}
		 	
		 	if (c>=123){ // if it went over z, go back to a and add the remaining values. Ensuring boundary conditions are met 
		 		c=abs(c);
		 		c=c-122;
		 		//c=abs(c);
		 		c=96+c;
		 		//printf("   ---> %d   \n",c); 
		 	}
		 	
		 	yytext[0]=c; 	
		 	printf("final  %d \n",yytext[0] );}
		 	yytext[0]=c;  
		 }

%%

int main ( int argc, char *argv[] ) {
 
 yylex();

}