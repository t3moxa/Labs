#include <iostream>
#include <cmath>
using namespace std;
struct network
{
public:
	double* weights;
	int amount;
	network(int n): amount(n)
	{
		weights = new double[amount];
		for (int i = 0; i < amount; i++)
			weights[i] = static_cast<double>(rand()) * static_cast<double>(0.1) / RAND_MAX;
	}
	double activate(double S)
	{
		return 1 / (1+exp(-S));
	}
	double predict(double* in, int n)
	{
		double out = 0;
		for (int i = 0; i < n; i++)
			out += in[i] * weights[i];
		return out;
	}
	void train(double** in, double* out, int rows/*количество штук входных данных*/, int columns/*количество чисел для сложения в штуке данных*/, int iterations)
	{
		double* output = new double[rows];
		double* error = new double[rows];
		for (int i = 0; i < iterations; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				output[j] = predict(in[j], columns);
				error[j] = out[j] - output[j];
			}
			for (int k = 0; k < rows; k++)
			{
				for (int z = 0; z < amount; z++)
				{
					weights[z] += 0.01*in[k][z]*error[k];
				}
			}
			if (iterations<200)
			{
			cout << i << " " << endl;
			cout << weights[0] << " " << weights[1] << " " << weights[2] << endl;
			for (int l = 0; l < rows; l++)
			{
				cout << in[l][0] << " " << in[l][1] << " " << in[l][2] << " " << output[l] << " " << error[l] << " " << endl;
			}
			}
		}
	}
};
int main()
{
	int n = 10;
	int nums_to_sum = 3;
	double** in = new double*[n];
	for (int i = 0; i < n; i++)
		in[i] = new double[nums_to_sum];
	double* out = new double[n];
	for (int i = 0; i<n;i++)
	{
	    out[i] = 0;
	    for (int j = 0; j<nums_to_sum;j++)
	    {
	        in[i][j] = static_cast<double>(rand()) * static_cast<double>(1.3) / RAND_MAX;
	        out[i]+=in[i][j];
	    }
	    cout << out[i] << " ";
	}
	network aboba(nums_to_sum);
	cout << endl;
	for (int i = 0; i < nums_to_sum; i++)
	    cout << aboba.weights[i] << " ";
	aboba.train(in, out, n, nums_to_sum, 199);
	double predict[nums_to_sum] = {1.1,0.2,0.3};
	cout << endl << aboba.predict(predict, nums_to_sum);
}