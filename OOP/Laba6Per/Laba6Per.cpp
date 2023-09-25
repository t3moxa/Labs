#include <iostream>
using namespace std;

int n;
int P[10];
int R[10];
void per(int);

int main()
{
    cin >> n;
    int i;
    for (i=1; i <= n; ++i)
        R[i] = 0;
        per(1);
}

void per(int k)
{
    int i;
    for (i=1; i <= n; ++i)
        if (R[i] == 0)
        {
            P[k] = i;
            R[i] = 1;
            if (k == n)
                for (int g = 1; g <= n; ++g)
                    cout << P[g];
            else
                per(k + 1);
            R[i] = 0;
            cout << " ";
        }
}