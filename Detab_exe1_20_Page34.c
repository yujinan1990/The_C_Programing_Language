/* replace tabs in the input with proper number of blanks to space to the next tab stop
 * Page 34 of The C
 * by Jean 20170705
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define SPACE ' '
#define TAB '\t'

int CalculateNumberOfSpaces( int offset, int tabsize)
{
	return tabsize - ( offset % tabsize );
}

int get_line( char s[], int lim )
{
	int c, i;
	
	for(i = 0; i < lim -1 && ( (c=getchar()) != EOF ) && ( c != '\n' ); ++i  ){
		s[i] = c;
	} //for
	if( c = '\n' ){
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

int main(void)
{
	char buffer[ MAX_BUFFER ];
	int tabsize = 5;
	int i, j , k , l ;

	while( get_line( buffer, MAX_BUFFER ) > 0 ){
		for( i = 0, l = 0; buffer[i] != '\0'; i++ ){
			if( buffer[i] == TAB){
				j = CalculateNumberOfSpaces( 1, tabsize);
				for( k = 0; k < j; k++){
					putchar( SPACE );
					l++;
				} //for
			}else{
				putchar( buffer[i]);
				l++;
			}
			return 0;
		} //for
	} //while
} //main
