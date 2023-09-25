#include <iostream>
using namespace std;
//Метод Ньютона, уравнение 15 x(x + 1) = 1 или x*x + x - 1 = 0
float y(float x);
float py(float x);
float p2y(float x);
float xn(float x);
float xn2(float x, float x0init);
float xn3(float x, float x1);
float eps = 0.00000000000000001;
float a, b, step, i, x0, n, speed, x0init, x1, x05;
int numit1 = 0, numit2 = 0, numit3 = 0, numroots = 0, numprecision = 0, numrootsconst = 0;
int main()
{
    cout << "Enter initial and final borders and number of partitions: \n";
    cin >> a >> b >> n;
    step = ((abs(a) + abs(b)) / n);
    for (i = a; i <= b; i = i + step)
    {
        float lb = i, hb = i + step, m1, m2;
        if ((y(lb) * y(hb)) < 0)
        {
            numroots++;
            if (y(lb) * p2y(lb) > 0)
            {
                x0 = lb;
            }
            else if (y(hb) * p2y(hb) > 0)
            {
                x0 = hb;
            }
            else
                x0 = lb;
            if (py(lb) <= py(hb))
                m1 = py(lb);
            else
                m1 = py(hb);
            if (p2y(lb) >= p2y(hb))
                m2 = py(lb);
            else
                m2 = py(hb);
            while (((m2 / 2 * m1) * abs(xn(x0) - x0)) > eps)
            {
                x0 = xn(x0);
                numit1++;
            }
            cout << "Root - " << x0 << "\n";
            cout << "Verification - " << y(x0) << "\n";
            cout << "Number of iterations - " << numit1 << "\n \n";
            numit1 = 0;
        }
    }
    for (i = eps; i < 1; i = i * 10)
        numprecision++;
    float** A1 = new float* [numprecision];
    for (int i = 0; i < numprecision; i++) {
        A1[i] = new float[numprecision + 1];
    }
    float** A2 = new float* [numprecision];
    for (int i = 0; i < numprecision; i++) {
        A2[i] = new float[numprecision + 1];
    }
    float** A3 = new float* [numprecision];
    for (int i = 0; i < numprecision; i++) {
        A3[i] = new float[numprecision + 1];
    }
    numrootsconst = numroots;
    numroots = 0;
    numprecision = 0;
    for (speed = 0.1; speed >= eps; speed = speed * 0.1)
    {
        numprecision++;
        for (i = a; i <= b; i = i + step)
        {
            float lb = i, hb = i + step, m1, m2;
            if ((y(lb) * y(hb)) < 0)
            {
                numroots++;
                if (y(lb) * p2y(lb) > 0)
                {
                    x0 = lb;
                    x1 = x0 + (x0 / n);
                }
                else if (y(hb) * p2y(hb) > 0)
                {
                    x0 = hb;
                    x1 = x0 - (x0 / n);
                }
                else
                    x0 = lb;
                if (py(lb) <= py(hb))
                    m1 = py(lb);
                else
                    m1 = py(hb);
                if (p2y(lb) >= p2y(hb))
                    m2 = py(lb);
                else
                    m2 = py(hb);
                x0init = x0;
                while (((m2 / 2 * m1) * abs(xn(x0) - x0) * abs(xn(x0) - x0)) > speed)
                {
                    x0 = xn(x0);
                    numit1++;
                }
                x0 = x0init;
                while (((m2 / 2 * m1) * abs(xn2(x0, x0init) - x0) * abs(xn2(x0, x0init) - x0)) > speed)
                {
                    x0 = xn2(x0, x0init);
                    numit2++;
                }
                x0 = x0init;
                while (((m2 / 2 * m1) * abs(xn3(x0, x1) - x1) * abs(xn3(x0, x1) - x1)) > speed)
                {
                    x05 = x1;
                    x1 = xn3(x0, x1);
                    x0 = x05;
                    numit3++;
                }
                A1[numprecision][numroots] = numit1;
                A2[numprecision][numroots] = numit2;
                A3[numprecision][numroots] = numit3;
                numit1 = 0;
                numit2 = 0;
                numit3 = 0;
            }
        }
        numroots = 0;
    }
    for (int i = 1; i < numrootsconst + 1; i++)
    {
        cout << "\nRoot number " << i << "\n";
        printf("%8s ", "eps");
        for (int j = 1; j < numprecision + 1; j++)
        {
            printf("%4s%-2d ", "10^-", j);
        }
        cout << "\n";
        printf("%8s ", "Method 1");
        for (int j = 1; j < numprecision + 1; j++)
        {
            printf("%3.0f    ", A1[j][i]);
        }
        cout << "\n";
        printf("%8s ", "Method 2");
        for (int j = 1; j < numprecision + 1; j++)
        {
            printf("%3.0f    ", A2[j][i]);
        }
        cout << "\n";
        printf("%8s ", "Method 3");
        for (int j = 1; j < numprecision + 1; j++)
        {
            printf("%3.0f    ", A3[j][i]);
        }
        cout << "\n";
    }
    for (int i = 0; i < numprecision; i++)
    {
        delete[] A1[i];
    }
    for (int i = 0; i < numprecision; i++)
    {
        delete[] A2[i];
    }
    for (int i = 0; i < numprecision; i++)
    {
        delete[] A3[i];
    }
}
float xn3(float x0, float x1)
{
    return x1 - (((x1 - x0) * y(x1)) / (y(x1) - y(x0)));
}