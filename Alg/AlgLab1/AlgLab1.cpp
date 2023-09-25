#include <iostream>

using namespace std;

class Sort
{
public:
    static int numofcomp;

    static void shell_sort(int** A_point, int n)
    {
        int i, j, h;
        for (h = 1; h <= n / 9; h = h * 3 + 1);
        while (h >= 1)
        {
            for (i = h; i < n; i++)
                for (j = i - h; j >= 0 && ++numofcomp && *A_point[j] > *A_point[j + h]; j -= h)
                {
                    swap(A_point[j], A_point[j + h]);
                }
            h = (h - 1) / 3;
        }
    }

    static void quick_sort(int** A_point, int b, int e)
    {
        double x; int i, j, c = b, d = e;
        while (c < d)
        {
            x = *A_point[(c + d) / 2]; i = c; j = d;
            while (i < j)
            {
                while ((++numofcomp) && (*A_point[i] < x))
                    i++;
                while ((++numofcomp) && (*A_point[j] > x))
                    j--;
                if (i <= j)
                {
                    swap(A_point[i], A_point[j]); i++; j--;
                }
            }
            if (j - c < d - i)
            {
                if (c < j)
                    quick_sort(A_point, c, j);
                c = i;
            }
            else
            {
                if (i < d)
                    quick_sort(A_point, i, d);
                d = j;
            }
        }
    }
    static bool check_sort(int** A, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (*A[i] > *A[i + 1])
            {
                return(0);
            }
        }
        return(1);
    }
};

int Sort::numofcomp = 0;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество элементов ";
    cin >> n;
    int* A = new int[n];
    int** A_point = new int* [n];
    cout << "\n--------------------------Сортировка Шелла----------------------------\n";

    cout << "\n\n Массив по возрастанию:\n";
    for (int i = 0; i < n; i++)
    {
        A[i] = i;
    }
    for (int i = 0; i < n; i++)
        A_point[i] = A + i;
    if (n <= 100)
    {
        cout << "\n Исходный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    Sort::shell_sort(A_point, n);
    if (n <= 100)
    {
        cout << "\n Отсортированный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    if (Sort::check_sort(A_point, n))
        cout << "\n Массив отсортирован";
    else
        cout << "\n Массив не отсортирован";
    cout << "\n Количество сравнений: " << Sort::numofcomp;
    Sort::numofcomp = 0;

    cout << "\n\n Массив по убыванию:\n";
    for (int i = 0; i < n; i++)
    {
        A[i] = n - i;
    }
    for (int i = 0; i < n; i++)
        A_point[i] = &A[i];
    if (n <= 100)
    {
        cout << "\n Исходный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    Sort::shell_sort(A_point, n);
    if (n <= 100)
    {
        cout << "\n Отсортированный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    if (Sort::check_sort(A_point, n))
        cout << "\n Массив отсортирован";
    else
        cout << "\n Массив не отсортирован";
    cout << "\n Количество сравнений: " << Sort::numofcomp;
    Sort::numofcomp = 0;

    cout << "\n\n Случайный массив:\n";
    for (int i = 0; i < n; i++)
    {
        A[i] = rand();
    }
    for (int i = 0; i < n; i++)
        A_point[i] = &A[i];
    if (n <= 100)
    {
        cout << "\n Исходный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    Sort::shell_sort(A_point, n);
    if (n <= 100)
    {
        cout << "\n Отсортированный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    if (Sort::check_sort(A_point, n))
        cout << "\n Массив отсортирован";
    else
        cout << "\n Массив не отсортирован";
    cout << "\n Количество сравнений: " << Sort::numofcomp;
    Sort::numofcomp = 0;

    cout << "\n--------------------------Быстрая сортировка с 1 рекурсивным вызовом----------------------------\n";

    cout << "\n\n Массив по возрастанию:\n";
    for (int i = 0; i < n; i++)
    {
        A[i] = i;
    }
    for (int i = 0; i < n; i++)
        A_point[i] = &A[i];
    if (n <= 100)
    {
        cout << "\n Исходный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    Sort::quick_sort(A_point, 0, n - 1);
    if (n <= 100)
    {
        cout << "\n Отсортированный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    if (Sort::check_sort(A_point, n))
        cout << "\n Массив отсортирован";
    else
        cout << "\n Массив не отсортирован";
    cout << "\n Количество сравнений: " << Sort::numofcomp;
    Sort::numofcomp = 0;

    cout << "\n\n Массив по убыванию:\n";
    for (int i = 0; i < n; i++)
    {
        A[i] = n - i;
    }
    for (int i = 0; i < n; i++)
        A_point[i] = &A[i];
    if (n <= 100)
    {
        cout << "\n Исходный массив по убыванию:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    Sort::quick_sort(A_point, 0, n - 1);
    if (n <= 100)
    {
        cout << "\n Отсортированный массив по убыванию:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    if (Sort::check_sort(A_point, n))
        cout << "\n Массив отсортирован";
    else
        cout << "\n Массив не отсортирован";
    cout << "\n Количество сравнений: " << Sort::numofcomp;
    Sort::numofcomp = 0;

    cout << "\n\n Случайный массив:\n";
    for (int i = 0; i < n; i++)
    {
        A[i] = rand();
    }
    for (int i = 0; i < n; i++)
        A_point[i] = &A[i];
    if (n <= 100)
    {
        cout << "\n Исходный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    Sort::quick_sort(A_point, 0, n - 1);
    if (n <= 100)
    {
        cout << "\n Отсортированный:\n";
        for (int i = 0; i < n; i++)
        {
            cout << *A_point[i] << " ";
        }
    }
    if (Sort::check_sort(A_point, n))
        cout << "\n Массив отсортирован";
    else
        cout << "\n Массив не отсортирован";
    cout << "\n Количество сравнений: " << Sort::numofcomp;
    Sort::numofcomp = 0;
}