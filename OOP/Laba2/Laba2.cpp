// Laba2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
using namespace std;
int z = 8;
int i;
int *w = &z;
int arr1[ 10 ];
int arr2[10];
int * arr3 = new int [10];
int * arr4 = new int[10];


struct list {
	int order;
	list* addr;
};

void notmain()
{
	list* p1,*p2;
	p1 = new list;
	p2 = p1;
	for (i = 0; i < 10; i++) 
	{
		p1->order = i + 1;
		p1->addr = new list;
		p1 = p1->addr;
		p1->addr = NULL;
	}
	p1 = p2;
	i = 1;
	while (p1->addr != NULL) {
		printf("Порядковый номер - %d, поле данных - %d\n", i, p1->order);
		p1 = p1->addr;
		i++;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i <= 9; ++i) // ++i --> i = i + 1
	{
		arr1[i] = rand();
		cout << arr1[i] << "\n";
	}
	cout << "\n";
	for (int i = 0; i <= 9; ++i) // ++i --> i = i + 1
	{
		*(arr2+i) = i*i;
	}
	for (int i = 0; i <= 9; ++i) // ++i --> i = i + 1
	{
		cout << *(arr2 + i) << "\n";
	}
	cout << "\n";
	for (int i = 0; i <= 9; ++i) // ++i --> i = i + 1
	{
		arr3[i] = rand();
		cout << arr3[i] << "\n";
	}
	cout << "\n";
	for (int i = 0; i <= 9; ++i) // ++i --> i = i + 1
	{
		*(arr4 + i) = i*i;
	}
	for (int i = 0; i <= 9; ++i) // ++i --> i = i + 1
	{
		cout << *(arr4 + i) << "\n";
	}
	delete[] arr3;
	delete[] arr4;
	notmain();
}

