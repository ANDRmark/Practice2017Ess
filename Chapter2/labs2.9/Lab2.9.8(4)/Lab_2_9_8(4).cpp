#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double vector[] = { 1., 2., 3., 4., 5. };
	int n = sizeof(vector) / sizeof(vector[0]);
	double ArithmeticMean;
	double HarmonicMean;
	double GeometricMean;
	double RootMeanSquare;
	ArithmeticMean = 0;
	for (int i = 0; i < n; i++)
	{
		ArithmeticMean += vector[i];
	}
	ArithmeticMean /= n;
	HarmonicMean = 0;
	for (int i = 0; i < n; i++)
	{
		HarmonicMean += 1.0 / vector[i];
	}
	HarmonicMean = n / HarmonicMean;
	GeometricMean = 1;
	for (int i = 0; i < n; i++)
	{
		GeometricMean *= vector[i];
	}
	GeometricMean = pow(GeometricMean, 1.0 / n);
	RootMeanSquare = 0;
	for (int i = 0; i < n; i++)
	{
		RootMeanSquare += vector[i] * vector[i];
	}
	RootMeanSquare = sqrtf(RootMeanSquare * 1.0 / n);
	cout << "Arithmetic Mean = " << ArithmeticMean << endl;
	cout << "Harmonic Mean = " << HarmonicMean << endl;
	cout << "Geometric Mean = " << GeometricMean << endl;
	cout << "RootMean Square = " << RootMeanSquare << endl;
	cout << endl;
	system("pause");
	return 0;
}