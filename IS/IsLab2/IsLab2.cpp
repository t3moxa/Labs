#include <iostream>
#include <iomanip>
#include <math.h>
#include <ctime>
using namespace std;
//точка пересечения функции f(x) = ln(x+1)-2,25 с осью x; x>-1
double mutationscale = 0.15, crossoverscale = 0.005, eps = 6, fgenconst = pow(10, (eps - 1) / 2), sgenconst = pow(10, eps - 1);
int const crossoveramount = 4, n=10, mutationprobability = 4, crossoverprobability = 3;
double func(double x)
{
	return log(x + 1) - 2.25;
}
double crossover(double par1, double par2) //BLX-a
{
	double cmin, cmax;
	if (par1 < par2)
	{
		cmin = par1;
		cmax = par2;
	}
	else
	{
		cmin = par2;
		cmax = par1;
	}
	double del = cmax - cmin;
	double low = cmin - crossoverscale * del, high = cmax + crossoverscale * del;
	return low + static_cast<double>(rand()) * static_cast<double>(high - low) / RAND_MAX;
}
double mutation(double gen)
{
	return gen += -mutationscale + static_cast<double>(rand()) * static_cast<double>(mutationscale * 2) / RAND_MAX;;
}
double firstchrom(double chel)
{
	return round(chel * 100) / 100;
}
double secchrom(double chel)
{
	return round(fmod(chel, 0.01) * 100000) / 100000;
}

int main()
{
	srand(time(NULL));
	int i, j;
	double pop[n];
	double fit[n];
	int ind[n];
	double sel[crossoveramount];
	double children[n];
	double g11, g12, g21, g22;
	int k = 0;
	bool FOUND = 0;
	int num = 0;
	while (not(FOUND))
	{
		num++;
		cout << endl << "Cycle number " << num << endl;
		cout << "Initial:" << endl;
		for (i = 0; i < n; i++)
		{
			pop[i] = (round(-1 + static_cast<double>(rand()) * static_cast<double>(8 + 1) / RAND_MAX * sgenconst)) / sgenconst;
			cout << setprecision(eps) << pop[i] << " ";
		}
		cout << endl << "Fitness:" << endl;
		for (i = 0; i < n; i++)
		{
			fit[i] = func(pop[i]);
			cout << fit[i] << " ";
		}
		cout << endl << "Sorted fitness:" << endl;

		for (i = 0; i < n; i++)
			ind[i] = i;
		for (i = 1; i < n; i++)
			for (j = i - 1; j >= 0 && abs(fit[ind[j]]) > abs(fit[ind[j + 1]]); j--)
				swap(ind[j], ind[j + 1]);
		for (i = 0; i < n; i++)
			cout << fit[ind[i]] << " ";
		cout << endl << "Selected for crossover:" << endl;
		for (i = 0; i < crossoveramount; i++)
		{
			sel[i] = pop[ind[i]];
			cout << sel[i] << " ";
		}
		i = 0; j = 0;

		while (k < n)
		{
			//while (i == j)
			{
				i = rand() % crossoveramount;
				j = rand() % crossoveramount;
			}
			if ((rand() % 10) < crossoverprobability)
			{
				g11 = firstchrom(sel[i]); g12 = secchrom(sel[i]); g21 = firstchrom(sel[j]); g22 = secchrom(sel[j]);
				children[k] = crossover(g11, g21) + crossover(g12, g22);
				children[k + 1] = crossover(g11, g21) + crossover(g12, g22);
				//cout << setprecision(eps) << g11 << " " << setprecision(eps) << g21 << " " << setprecision(eps) << children[k]<<endl;
				//cout << setprecision(eps) << g12 << " " << setprecision(eps) << g22 << " " << setprecision(eps) << children[k+1] << endl <<endl;
				k += 2;
			}
			else
			{
				children[k] = sel[i];
				children[k + 1] = sel[j];
				k += 2;
			}
		}
		cout << endl << "Children:" << endl;
		for (i = 0; i < n; i++)
		{
			cout << setprecision(eps) << children[i] << " ";
		}
		for (i = 0; i < n; i++)
		{
			if (rand() % 10< mutationprobability)
			{
				children[i] = mutation(firstchrom(children[i])) + secchrom(children[i]);
			}
			if (rand() % 10 < mutationprobability)
			{
				children[i] = firstchrom(children[i]) + mutation((secchrom(children[i])) * 1000) / 1000;
			}
		}
		cout << endl << setprecision(eps) << "Mutated children" << endl;
		for (i = 0; i < n; i++)
		{
			cout << children[i] << " ";
			pop[i] = children[i];
		}
		for (i = 0; i < n; i++)
		{
			fit[i] = func(pop[i]);
			if (abs(fit[i]) < 0.00001)
			{
				cout << "FOUND";
				FOUND = 1;
			}
		}
	}
}
