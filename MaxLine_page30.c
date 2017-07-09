/* prints the longest line from many input lines, 
 * on page 30 of The C Programing Language
 * by Jean 20170630
 */
#include <stdio.h>
#define MAXLINE 200

int get_line( char s[], int line_max );
void copy_line( char to[], char from[] );

/* read a set of text lines and prints the longest */
int main()
{
	char line[MAXLINE];
	char longest[MAXLINE];

	int max;
	int len; 

	max = 0;

	while( ( len = get_line(  line , MAXLINE ) ) > 0 ){ // NOT: get_line( char line[] ...). "char line[]" is permissible, not even "line[]"
		if( len > max){
			max = len;
			copy_line( longest , line );
		} //fi
	} //while

	if( max > 0 ){	//the input line exits
		printf( " %s \n" , longest );
		return 0;
	} //fi
}

int get_line( char s[], int line_max ){
	int  c, i;
	for( i = 0; i < line_max-1 && ( c = getchar() ) != EOF && c != '\n' ; ++i ){
		s[i] = c;
	
	} //for
	if( c == '\n' ){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
} //get_line

void copy_line( char to[], char from[] ){
	int i;
	i = 0;
	while( ( to[i] = from[i] ) != '\0'  )
		++i;

} //copy_line
