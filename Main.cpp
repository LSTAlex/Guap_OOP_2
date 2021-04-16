#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <exception>

using namespace std;

class MyError
{
private:
	char* msgs;
public:
	MyError(const char* msg);
	char* What();
};
MyError::MyError(const char* msg)
{
	this->msgs = const_cast<char*> (msg);
}
char* MyError::What()
{
	return msgs;
}

class MyClass
{
private:
	static const int N = 12;
	int arr[N] = {};
public:
	MyClass();
	~MyClass();
	void printarr();
	int minelem();
	int sumnegnum();
	void sortmodul();
};

void MyClass::printarr()
{
	for (size_t i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}

int MyClass::minelem()
{
	int min = arr[0];
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int MyClass::sumnegnum()
{
	int state = 0, sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (arr[i] < 0)
		{
			state++;
		}
		if (state == 2)
		{
			break;
		}
		if (arr[i] >= 0 && state == 1)
		{
			sum += arr[i];
		}
	}
	if (state == 0)
	{
		//throw "No negative elements";
		throw MyError("No negative elements");
	}
	if (state == 1)
	{
		//throw "Only one negative elevent";
		throw MyError("Only one negative elevent");
	}
	return sum;
}

void MyClass::sortmodul()
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (abs(arr[i]) <= 1)
		{
			for (int j = i; j > k; j--)
				swap(arr[j], arr[j - 1]);
			k++;
		}
	}
}

MyClass::MyClass()
{
	/*
	srand(time(NULL));
	for (size_t i = 0; i < N; i++)
	{
	arr[i] = rand() % 40 +(-20);
	}*/
	//для ручного ввода
	int value = 0;
	string str;
	for (size_t i = 0; i < N; i++)
	{
		cin >> str;
		try
		{
			value = stoi(str);
			arr[i] = value;
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
			return;
		}
	}
}

MyClass::~MyClass()
{
}

int main()
{
	setlocale(LC_ALL, "Russian");
	MyClass a;
	a.printarr();
	cout << endl;
	int z = a.minelem();
	cout << "Минимальное чило: " << z << endl;
	try
	{
		int x = a.sumnegnum();
		cout << "Сумма элементов между первым и вторым отрицательным числом: " << x << endl;
	}
	catch (MyError& e)
	{
		cout << "Error: " << e.What() << endl;
	}
	a.sortmodul();
	a.printarr();
	system("pause");
	return 0;
}