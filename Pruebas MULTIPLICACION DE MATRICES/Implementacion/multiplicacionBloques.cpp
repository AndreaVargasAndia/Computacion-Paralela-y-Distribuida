#include <iostream>
#include <chrono> 
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MAX 1000

void imprimirmatriz(int m[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n" << endl;
}
void multiplicacion_bloques(int m1[MAX][MAX], int m2[MAX][MAX], int m3[MAX][MAX])
{
	int i, j, k, ii, jj, kk;
	int blq = 100; // tamaño del bloque 
	for (ii = 0; ii < MAX; ii += blq)
	{
		for (jj = 0; jj < MAX; jj += blq)
		{
			for (kk = 0; kk < MAX; kk += blq)
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
	srand(time(NULL));
	int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
	//llenar matricez
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			A[i][j] = rand() % MAX;
			B[i][j] = rand() % MAX;
			R[i][j] = 0;
		}
	}
	imprimirmatriz(A);
	imprimirmatriz(B);
	auto begin = std::chrono::high_resolution_clock::now();
	//Multiplicacion por bloques
	multiplicacion_bloques(A, B, R);
	imprimirmatriz(R);
	auto end = std::chrono::high_resolution_clock::now();
	auto rslt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cout << "Tiempo: " << rslt.count() << endl;
	cout << "TERMINE MULTIPLICACION POR BLOQUES" << endl;
	return 0;
}