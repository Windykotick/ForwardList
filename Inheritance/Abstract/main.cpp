#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound() = 0;	//����� ����������� �����
};

class Cat :public Animal
{
public:
	void sound()
	{
		cout << "���" << endl;
	}
};

class Dog :public Animal
{
public:
	void sound()
	{
		cout << "���" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Animal animal;	//���������� ������� ��������� ������������ ������.
	Animal* zoo[] =
	{
		new Cat(),
		new Cat(),
		new Dog(),
		new Cat(),
		new Dog()
	};
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
}