/* print all input lines that are longer than 80 characters
 * page 31 exercise 1.17
 * by Jean 20170702
 */

#include <stdio.h>

#define MINLENGTH 81

int readbuff( char *buffer)
{
	size_t i = 0;
	int c;
	while( i < MINLENGTH ){
		c = getchar();
		if( c == EOF )
			return -1;
		if( c == '\n' )
			return 0;
		buffer[i++] = c;
	} //while
	return 1;
} //readbuff

int copyline( char *buffer )
{
	size_t i;
	int c;
	int status = 1;
	for( i = 0; i < MINLENGTH; i++ ){
		putchar( buffer[i] );
	} //for
	while( status == 1 ){
		c = getchar();
		if( c == EOF )
			status == -1;
		else if( c == '\n' )
			status == 0;
		else 
			putchar( c );
	} //while
	putchar('\n');
	return status;

} //copyline

int main( void )
{
	char buffer[MINLENGTH];
	int status = 0;
	while( status != -1 ){
		status = readbuff( buffer );
		if( status == 1 ){
			status == copyline( buffer );
		} //fi
	} //while
	return 0;
}
