/* print a histogram of the lengths of words in its input, vertical orientation histogram is more challenging than horizontal
 * page 25 of The C Programing Language
 * by Jean 20170624
 */
#include <stdio.h>
#define MAXLENGTH  10


int maxvalue( int A[], int n );

int main()
{	/* read stdin, calculate every word length, census the accounts of each length, and draw a histogram, 
	* the x coordinate is the words' length like 1,2,3... 10; the y coordinate is the statistic accounts */
	typedef long Y_axis;
	typedef int X_axis;

	Y_axis wd_freq[ MAXLENGTH ];	
	X_axis wd_length;	// the range of wd_length should be within 0 to MAXLENGTH
	int inspace;
	int wd_bg;
	int c;
	int i;
	for( i = 0; i < MAXLENGTH + 1 ; ++i) wd_freq[i] = 0;
	wd_length = 0;
	inspace = 0; wd_bg = 0;

	while( (c = getchar() ) != EOF  ){
		/* read char */
		if( c == ' ' || c == '\n' || c == '\t' ){
			++wd_freq[0];
			wd_bg = 0;
			if( inspace == 0 ){
				inspace = 1;
				if(wd_length >0) ++wd_freq[wd_length];
				wd_length = 0;
			}else{
				;	

			}//if
		}else{
			inspace = 0;
			if( wd_bg == 0 ){
				wd_bg = 1;
				++wd_length;

			}else{
				++wd_length;
			}//if
			if( wd_length >= MAXLENGTH ) wd_length = MAXLENGTH;
		}//if


	}//while
	

	/* draw the histogram, x: words length, y: appearance frequency */
	int xvalue, yvalue;

	for( yvalue = maxvalue( wd_freq, MAXLENGTH ); yvalue > 0; yvalue--){	
		printf("%8d |", yvalue);
		for( xvalue = 0; xvalue <= MAXLENGTH; xvalue++){
			if( yvalue > wd_freq[ xvalue ] ){
				printf("  ");
			}else{
				printf(" *");
			}
		}//for	
		printf("\n");
	}//for	
	printf("         +");
	for( xvalue = 0; xvalue <= MAXLENGTH; xvalue++ ){
		printf("--");
	} //for
	printf("\n          ");
	for( xvalue = 0; xvalue <= MAXLENGTH; xvalue++ ){
		printf("%2d",xvalue);
	} //for
	printf("\n");


} //main

/* calculate the max number of an array */
int maxvalue( int A[], int n ){
	int  i, a = 0;
	//int max_colums = sizeof( A[] ) / sizeof( int );
	for( i=0; i <= n; i++){
		if( a < *(A+i)){
			a = *(A+i);
		} //if
	printf( "%d\t%d\n", i, A[i]);
	} //for 
	return a;
} //maxvalue
