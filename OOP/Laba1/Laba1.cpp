// Laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h> 
#include <stdlib.h> 

using namespace std;

float mins;
float maxs;
float s;
float i;
float MAX;
float N;
float S;
float Sn;

int main()
{
    setlocale(LC_ALL, "Russian");
    cin >> mins;
    s = ((4 - mins) / 9);
    while (mins < 4)
    {
        cout << "Точка - " << mins << ", Значение функции - " << sin(mins) / mins << "\n";
        mins = mins + s;
    }
    cout << "Точка - " << mins << ", Значение функции - " << sin(mins) / mins << "\n";

    cin >> MAX;
    S = 2;
    Sn = 1;
    N = 3;
    while (S < MAX)
    {
        i = S;
        S = S + Sn;
        Sn = i;
        N = N + 1;
    }
    cout << "Искомое число - " << S << ", Его номер - " << N;
}