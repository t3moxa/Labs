#include <iostream>
#include <random>
using namespace std;
void vivod(int n);
int arr[100000];
int arr2[18];
int arr3[100000];
int main()
{ 
    int i,n;
    setlocale(LC_ALL, "Russian");
    cout << "Введите количество элементов массива\n";
    cin >> n;
    for (i = 1; i <= n; ++i)
    {
    arr[i] = rand() % (17 - 0 + 1) + 0;
}
    for (i = 0; i <= n; ++i)
    {
        arr2[arr[i]] = arr2[arr[i]] + 1;
    }
    cout << "Сокращенный массив: \n";
    for (i = 0; i <= 17; ++i)
    {
        cout << arr2[i] << " ";
    }
    vivod(n);
}

void vivod(int n)
{
    int i,j;
    j = 0;
    cout << "Исходный массив: \n";
    for (i = 0; i <= 17; ++i)
    {
        for (arr2[i]; arr2[i] >> 0; --arr2[i])
        {
            arr3[j] = i;
            ++j;
        }
    }
    for (i = 0; i <= n; ++i)
    {
        cout << arr3[i] << " ";
    }
}
