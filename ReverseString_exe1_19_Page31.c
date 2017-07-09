/* input characters to make a string, reverse it 
 * Page 31 of The C
 * by Jean 20170703
 */

#include <stdio.h>

#define MAX_LINE 1024

int get_line( char s[], int lim )
{
	int c , i;
	for( i = 0; i < lim -1 && ( (c=getchar()) != EOF ) && ( c != '\n' ); i++ ){
		s[i] = c;
	} //for
	if( c == '\n' ){
		s[i++] = '\n';
	}else if( c == EOF && i > 0 ){
		s[i++] = '\n';
	}
	s[i] = '\0';
	return i;
} //get_line()

void discardnewline( char s[] )
{ /* the string to be reversed should not include '\n' */
	int i;
	for( i = 0; s[i] != '\0'; i++){
		if( s[i] == '\n' )
			s[i] = '\0';
	} //for
} //discardnewline()

int reverse( char s[] )
{
	char ch;
	int i, j;
	
	for( j = 0; s[j] != '\0'; j++){
		;
	} //for
	--j;
	for( i = 0; i < j; i++){
		ch = s[i];
		s[i] = s[j];
		s[j] = ch;
		--j;
	} //for
	return 0;
} //reverse()

int main(void)
{
	char line[ MAX_LINE ];
	while( get_line( line, sizeof( line )) > 0 ){
		discardnewline( line );
		reverse( line );
		printf( "%s\n", line );
	} //while
	return 0;
} //main
