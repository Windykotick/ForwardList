#include<iostream>
using namespace std;

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//����� ���������� ��������
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class List;
};

class List
{
	Element* Head;	//����� ������ ������
public:
	List()
	{
		this->Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	void push_front(int Data)
	{
		//1)������� ����� �������:
		Element* New = new Element(Data);
		//2)"����������� ����� ������� � ������ (Head)":
		New->pNext = Head;
		//3)������ ��������� �� ����� �������.
		Head = New;
	}

	void print()
	{
		Element* Temp = Head;	//Temp - ��� ��������.
		//�������� - ��� ���������, ��� ������ ��������
		//����� �������� ������, � ��������� ��������� ������.
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ ������: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}