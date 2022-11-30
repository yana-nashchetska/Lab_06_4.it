#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

void Create(int* m, int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		m[i] = Low + rand() % (High - Low + 1);
}

void printCreate(int* m, int n)
{
	for (int i = 0; i < n; i++)
		cout << "  " << m[i] << "  ";
	cout << endl;
}


int Count(int* m, int n)
{
	int c = 0;
	for (int i = 0; i < n; i++)
		if (m[i] < 0)
			c++;
	return c;
}

int Min(int* m, int n)
{
	int min = abs(m[0]);
	int imin = 0;
		for (int i = 1; i < n; i++)
		{
			if (abs(m[i]) < min)
			{
				min = abs(m[i]);
				imin = i;
			}

		}
		return imin;
}


int Sum(int* m, int n)
{
	int imin = Min(m, n);

	int suma = 0;
	for (int i = imin + 1; i < n; i++)
	{
		suma = suma + abs(m[i]);
	}
	return suma;

}

void Replace(int* m, const int n)
{
	for (int i = 0; i < n; i++)
		if (m[i] < 0)
			m[i] = m[i] * m[i];

	cout << endl;
}

void Sort(int* m, const int n) // метод вставки
{
	for (int i = 1; i < n; i++) 
	{
		int tmp = m[i]; 
		int j = 0; 
		while (tmp > m[j])
			j++;
		for (int k = i - 1; k >= j; k--) 
			m[k + 1] = m[k];
		m[j] = tmp; 
	}
}
	

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	srand((unsigned)time(NULL));
	
	int Low = -100;
	int High = 100;

	cout << " Введіть кількість елементів масиву: ";
	cin >> n;
	cout << endl;

	int* m = new int[n];

	cout << " Масив: ";
	Create(m, n, Low, High); 
	printCreate(m, n);
	cout << endl;
	cout << "1.1 Кількість від'ємних елементів масиву: " << Count(m, n) << endl;
	cout << "    Індекс мінімального елемента по молулю " << Min(m, n) << endl;
	cout << "1.2 Сума модулів елементів масиву, котрі розташовані після мінімального по модулю елемента: " << Sum(m, n) << endl;
	cout << endl;
	cout << "2. " << endl;
	cout << "Масив, в котрому від'ємні елементи замінені квадратами цих елементів: ";
	Replace(m, n);
	printCreate(m, n);
	cout << endl;
	cout << "Посортований масив: ";
	Replace(m, n);
	Sort(m, n);
	printCreate(m, n);
	cout << endl;
}