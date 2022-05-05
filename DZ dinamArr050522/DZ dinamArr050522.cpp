#include <iostream>
#include <windows.h>
//#include <conio.h>
using namespace std;

//ДЗ  Создать 2 функции
//	add(ar, k, 10); // функция добавляет число 10 в конец массива
//	remove(ar, k, 3); // функция удаляет элемент из массива по индексу 3
	

void fillArray(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

void showArray(const int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << "\n";
}

void add(int* &arr, int &size,  int number)
{
	int* newArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	
	newArray[size] = number;
	size++;
	arr = newArray;
}
void remove(int*& arr, int& size, int number)
{
	
	int* newArray = new int[size - 1];
	for (int i = 0; i < number; i++)
	{
		newArray[i] = arr[i];
	}
	
	for (int i = number; i < size-1; i++)
	{
		newArray[i] = arr[i+1];
	}
	delete[] arr;
	arr = newArray;
	size--;
}
int main()
{
	int size = 5;
	int* arr = new int[size];
		
	fillArray(arr, size);
	showArray(arr, size);
	add(arr, size, 10);
	showArray(arr, size);
	cout << "__________________________________"<< "\n";
	size--;
	fillArray(arr, size);
	showArray(arr, size);
	remove(arr, size, 3);
	showArray(arr, size);
		
	delete[] arr;
}