/* page 22-23 of The C Programing Language
 * read stdin, count the number of each digit, each white characters and others
 * by Jean 20170620
 */

#include <stdio.h>

int main()
{	/*read stdin, count number of characters of different types */
	int c;
	int nwhite, nother;
	int ndigit[10];
	int i;

	nwhite = nother = 0;
	for( i = 0; i < 10; ++i){
		ndigit[i] = 0;
	}//for

	while( ( c == getchar() ) != EOF ){
		if( c > '0' && c < '9' ){
			++ndigit[ c - '0' ];// c is char so c-'0'
		}else if( c == '\n' || c == '\t' || c == ' ') {
			++nwhite;		
		}else{
			++nother;
		}
	}//while

	for( i = 0; i < 10; ++i ){
		printf("%d  \t, ndigit[i] ");
	}
	
	printf(  "%d \t %d \t ", nwhite, ndigit);


}
