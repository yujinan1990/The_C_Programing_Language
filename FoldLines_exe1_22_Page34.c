/* "fold " long input lines into shorter lines after non-blank character that occurs befor the n-th column of input
 * Exe1_22 Page 34 Of The C
 * by Jean 20170707
 */

#include <stdio.h>

#define MAXLINE 1000

char line[ MAXLINE ];
int get_line(void);

int
main()
{
	int t, len;
	int location, spaceholder;

	const int FOLDLENGTH = 70;

	while( (len = get_line()) > 0){
		if( len < FOLDLENGTH ){
		}else{
			t = 0;
			location = 0;
			while( t < len ){
				if( line[t] == ' ' ){
					spaceholder = t;
				} //fi
				if( location == FOLDLENGTH ){
					line[spaceholder] = '\n';
					location = 0;
				} //fi
				location ++;
				t ++;
			} //while
		}
		printf("%s", line);
	} //while
	return 0;
} //main

int get_line(void)
{
	int c, i;
	extern char line[];
	for( i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; i++){
		line[i] = c;
	} //for
	if( c == '\n' ){
		line[i] = c;
		i++;
	} //fi
	line[i] = '\0' ;
	return i;
} //get_line
