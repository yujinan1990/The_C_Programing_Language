/* read lines of arbitrary length, print the length
 * Page 31 of The C Programing Language
 * by Jean 20170702\
 */

#include <stdio.h>

#define MAXLINE 20

int get_line( char s[], int lim );
void copy( char to[], char from[] );

int main( void )
{	/* read lines of arbitray length, print its lenght */
	char line[ MAXLINE ];
	char longest[MAXLINE];
	char temp[MAXLINE];
	int len, max, premax, getmore;

	max = premax = getmore = 0;

	while( ( len = get_line(line, MAXLINE) ) > 0 ){
		if( line[ len - 1 ] != '\n' ){
			if( getmore == 0 ){
				copy( temp , line );
			}  //fi
			premax += len;
			if( max < premax ){
				max = premax;
			}	
			getmore = 1;
		}else{
			if(getmore == 1){
				if( max < premax + len ){
					max = premax + len;
					copy(longest, temp);
					longest[ MAXLINE - 2 ] = '\n';
				} //fi
				getmore = 0;
			}else if( max < len ) {
				max = len;	
				copy( longest, line);	
			
			}
			premax = 0;
		}
	} //while

	if( max > 0 ){
		printf( " %s " , longest );
		printf( " leng = %d \n " , max);
	} //fi
	return 0;
} //main

int get_line( char s[], int lim )
{
	int c, i;

	for( i = 0; i < lim -1 && ( (c = getchar() ) != EOF && c != '\n' ); ++i ){
		s[i] = c;
	} //for
	if( c == '\n' ){
		s[i] = c;
		++i;
	}else if( c == EOF && i > 0){
		s[i] = '\n';
		++i;
	} //fi
	s[i] = '\0';
	return i;
} //get_line

void copy( char to[], char from[] )
{
	int i;

	i = 0;
	while( to[i] = from[i] != '\0' )
		++i;
} //copy
