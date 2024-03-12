// mulmatr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <omp.h>
#include <Windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	float a[10][10], b[10][10], r[10][10];
	int x, n;

	n = 10;

	printf( "A\n" );
	for( int y = 0; y < n; y++ )
	{
		for( int x = 0; x < n; x++ )
		{
			a[x][y] = rand() % 100 / 50.0f - 1.0f;
			printf( "%.2f ", a[x][y] );
		}
		printf( "\n" );
	}

	printf( "B\n" );
	for( int y = 0; y < n; y++ )
	{
		for( int x = 0; x < n; x++ )
		{
			b[x][y] = rand() % 100 / 50.0f - 1.0f;
			printf( "%.2f ", b[x][y] );
		}
		printf( "\n" );
	}

#pragma omp parallel for
	for( int y = 0; y < n; y++ )
	{
		for( int x = 0; x < n; x++ )
		{
			float s = 0;

			for( int i = 0; i < n; i++ )
			{
				s += a[x][i] * b[i][y];
			}
			printf( "r%d, %d = %.2f (thread %d)\n", x, y, s, omp_get_thread_num() );
			r[x][y] = s;
		}
	}

	printf( "R\n" );
	for( int y = 0; y < n; y++ )
	{
		for( x = 0; x < n; x++ )
		{
			printf( "%.2f ", r[x][y] );
		}
		printf( "\n" );
	}

	getchar();

	return 0;
}

