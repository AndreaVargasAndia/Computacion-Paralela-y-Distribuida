#include <iostream>
#include <chrono> 
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define F1 500
#define C1 1000

#define F2 1000
#define C2 100

#define F3 500
#define C3 100

/*#define F1 1000
#define C1 2000

#define F2 2000
#define C2 3000

#define F3 1000
#define C3 3000
*/
void imprimirmatriz(int m[F1][C1])
{
	for (int i = 0; i < F1; i++)
	{
		for (int j = 0; j < C1; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n" << endl;
}
void multiplicacion_bloques(int m1[F1][C1], int m2[F2][C2], int m3[F3][C3])
{
	int i, j, k, ii, jj, kk;
	int blq = 100; // tamaño del bloque 
	for (ii = 0; ii < F1 ; ii += blq)
	{
		for (jj = 0; jj < C1; jj += blq)
		{
			for (kk = 0; kk < C2; kk += blq)
			{
				for (i = ii; i < ii + blq; i++)
				{
					for (j = jj; j < jj + blq; j++)
					{
						for (k = kk; k < kk + blq; k++)
						{
							m3[i][j] += m1[i][k] * m2[k][j];
						}
					}
				}
			}
		}
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int A[F1][C1], B[F2][C2], R[F3][C3];
	//llenar matricez
	for (int i = 0; i < F1; i++)
	{
		for (int j = 0; j < C1; j++)
		{
			int t = rand() % 1000;
			A[i][j] = t;
		}
	}
	for (int i = 0; i < F2; i++)
	{
		for (int j = 0; j < C2; j++)
		{
			int t = rand() % 1000;
			B[i][j] = t;
		}
	}
	for (int i = 0; i < F3; i++)
	{
		for (int j = 0; j < C3; j++)
		{
			R[i][j] = 0;
		}
	}
	//imprimirmatriz(A);
	//imprimirmatriz(B);
	auto begin = std::chrono::high_resolution_clock::now();
	//Multiplicacion por bloques
	multiplicacion_bloques(A, B, R);
	//imprimirmatriz(R);
	auto end = std::chrono::high_resolution_clock::now();
	auto rslt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cout << "Tiempo: " << rslt.count() << endl;
	cout << "TERMINE MULTIPLICACION POR BLOQUES" << endl;
	return 0;

}