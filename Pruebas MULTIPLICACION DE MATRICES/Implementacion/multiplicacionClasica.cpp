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
	cout << "\n"<<endl;
}
void multiplicacion_clasica(int m1[MAX][MAX], int m2[MAX][MAX], int m3[MAX][MAX])
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			m3[i][j] = 0;
			for (int k = 0; k < MAX; k++)
			{
				m3[i][j] = m3[i][j] + m1[i][k] * m2[k][j];
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
			A[i][j] = rand() % 100;
			B[i][j] = rand() % 100;
		}
	}
	//imprimirmatriz(A);
	//imprimirmatriz(B);
	auto begin = std::chrono::high_resolution_clock::now();
	//Multiplicacion Clasica
	multiplicacion_clasica(A, B, R);
	//imprimirmatriz(R);
	auto end = std::chrono::high_resolution_clock::now();
	auto rslt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cout << "Tiempo: " << rslt.count() << endl;
	cout << "TERMINE Multiplicacion Clasica" << endl;

	return 0;
}