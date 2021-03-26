#include <iostream>
#include <chrono> 
#include <cmath>

using namespace std;
#define MAX 10

int main ()
{
	
	double A[MAX][MAX], x[MAX], y[MAX];
	//llenar matricez
	//y = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			A[i][j] = rand() % MAX;
		}
	}
	for (int j = 0; j < MAX; j++)
	{
		x[j] = rand() % MAX;
	}
	for (int j = 0; j < MAX; j++)
	{
		y[j] = 0;
	}

	//Primer par de bucles
	auto begin = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			y[i] += A[i][j] * x[j];
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto rslt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cout << "Tiempo: " << rslt.count() << endl;
	cout << "TERMINE 1" << endl;
	
	for (int j = 0; j < MAX; j++)
	{
		y[j] = 0;
	}
	cout << "VACIO" << endl;

	//y = 0;
	//Segundo par de bucles
	begin = std::chrono::high_resolution_clock::now();
	for (int j = 0; j < MAX; j++)
	{
		for (int i = 0; i < MAX; i++)
		{
			y[i] += A[i][j] * x[j];
		}
	}
	end = std::chrono::high_resolution_clock::now();
	rslt = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	cout << "Tiempo: " << rslt.count() << endl;
	cout << "TERMINE 2" << endl;
	return 0;
}