
#include <iostream>
#include <string>
using namespace std;

char str_1[20];
char str_2[20];
void strings();
int main()
{
    setlocale(LC_ALL, "Russian");
    cin >> str_1;
    cin >> str_2;
    if (strcmp(str_1, str_2) > 0)
        cout << "Первая строка больше \n";
    else
        cout << "Вторая строка больше \n";
    cout << "Длина первой строки - " << strlen(str_1) << "\n";
    cout << "Длина второй строки - " << strlen(str_2) << "\n";
    cout << "Результат слияния строк - " << strcat(str_1, str_2) << "\n";
   strings();
}

void strings()
{
    string arr[20];
    int n, i;
    cout << "Введите количество слов (не больше 20): ";
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Чётные строки: \n";
    for (i = 0; i < n; ++i)
        if ((i % 2) != 0)
            cout << arr[i] << "\n";
}