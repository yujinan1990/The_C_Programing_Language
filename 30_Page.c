/* study the array and function 
 * 20170506 by Jean
 */
# include <stdio.h>
# define MAXIUM 10
int getline_( char line[], int maxline);
void copy( char to[], char from[] );

int main()
{
	int max, len;
	char line_max[MAXIUM], line_current[MAXIUM];
	max = 0;
	while( (len = getline_( line_current, MAXIUM )) > 0 ){
		if( len > max ){ 
			max = len;
			printf("max = %d \n ", max);
			copy( line_max, line_current );/*using line_max[],line_current[] causing erro expected expression befor '[' */
		}
	}
	if( max > 0 ){
		printf("max length of lne is %d \n", max);
	}
	return 0;
}

int getline_( char s[], int limit ){
	int i = 0;
	char c;
	for(i; i < limit-1 && (c = getchar()) != EOF && c != '\n'; ++i)/* ' is better than ", " causing a waring : comparion of poiter to integer */
		s[i] = c;
	if( c == '\n' ){
		s[i] = c;
	//	++i;
	}
	s[i] = '\0';
	return i;
}
void copy( char to[], char from[] ){
	int i;
	i = 0;
	while( to[i] = from[i] != '\0' )
	++i;
}
