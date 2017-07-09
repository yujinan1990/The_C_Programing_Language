/* replace strings of blanks with the minimum number of tabs and blanks to achieving the same spacing
 * Page 34 exe 1_21 of The C
 * by Jean 20170706
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
#define TAB2SPACE 4

char line[ MAXLINE ];
int get_line(void);

int main()
{
	int i,t;
	int spacecount, len;

	while( (len = get_line()) > 0 ){
		spacecount = 0;
		for( i = 0; i < len; i++ ){
			if( line[i] == ' ')
				spacecount++;
			if( line[i] != ' ' )
				spacecount = 0;
			if( spacecount == TAB2SPACE ){
				i -= 3;
				len -= 3;
				line[i] = '\t';
			} //fi
			for( t = i+1; t < len; t++ ){
				line[t] = line[t+3];
			} //for
			spacecount = 0;
			line[len] = '\0';
		} //for
	} //while
	return 0;
} //main

int get_line()
{
	int c , i;
	extern char line[];

	for( i = 0; i < MAXLINE-1 && ( c = getchar() ) != EOF && c != '\n'; i++ ){
		line[i] = c;
	} //for
	if( c == '\n' ){
		line[i] = c; 
		++i;
	} //fi
	line[i] = '\0';
	return i;
} //get_line
