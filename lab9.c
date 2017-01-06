#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void swap_rec( int *, unsigned int );
char is_palindrome( int *, unsigned int );
char is_sorted( int *, unsigned int );
int max_sum_neighboors( int *, unsigned int );
int mymax( int, int );

void main()
{
	int a[] = { 1, 4, 9, 11, 13 };
	unsigned int size = sizeof( a ) / sizeof( int );
	swap_rec( a, size );
	if( is_palindrome( a, size ) )
		printf( "True.\n" );
	else
		printf( "False.\n" );
	if( is_sorted( a, size ) )
		printf( "True.\n" );
	else
		printf( "False.\n" );
	printf("4. max: %d\n", max_sum_neighboors( a, size ) );
	system( "pause" );
}

void swap_rec( int *list , unsigned int size )
{
	int temp, *opposide;
	opposide = list + size - 1;
	if( list < opposide )
	{
		temp = *list;
		*list = *opposide;
		*opposide = temp;
		swap_rec( list + 1, size - 2 );
	}
}

char is_palindrome( int *list , unsigned int size )
{
	int *opposide;
	opposide = list + size - 1;
	if( list < opposide )
	{
		if( *list != *opposide )
			return FALSE;
		swap_rec( list + 1, size - 2 );
	}
	return TRUE;
}

char is_sorted( int *list, unsigned int size )
{
	if( size > 1 )
	{
		if( *( list + size - 2 ) > *( list + size - 1 ) )
			return FALSE;
		else
			 return is_sorted( list, size - 1 );
	}
	return TRUE;
}

int max_sum_neighboors( int *list, unsigned int size )
{
	if( size > 2 )
	{
		return mymax( max_sum_neighboors( list, size - 1 ),
			        *( list + size - 2 ) + *( list + size - 1 ) );
	}
	return *list + *( list + 1 );
}

int mymax( int x, int y )
{
	return x > y ? x : y;
}