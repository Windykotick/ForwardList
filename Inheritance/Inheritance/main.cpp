#include<iostream>
#include<string>
using namespace std;

//#define INHERITANCE
#define POLYMORPHISM

class Human
{
protected:
	string last_name;
	string first_name;
	unsigned int age;
public:
	const string& get_last_name() const
	{
		return this->last_name;
	}
	const string& get_first_name() const
	{
		return this->first_name;
	}
	unsigned int get_age() const
	{
		return this->age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	virtual void info()
	{
		cout << last_name << " " << first_name << ", " << age << " ���.\n";
	}
};

class Student :public Human
{
	string specialty;
	string group;
	unsigned int rating;
public:
	const string& get_specialty()const
	{
		return this->specialty;
	}
	const string& get_group()const
	{
		return this->group;
	}
	unsigned int get_rating()const
	{
		return this->rating;
	}
	/*
		TODO: set methods.
	*/

	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, unsigned int rating
	):Human(last_name, first_name, age)
	{
		this->specialty = specialty;
		this->group = group;
		this->rating = rating;
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	void info()
	{
		Human::info();
		cout << "�������������: " << specialty << endl;
		cout << "������: " << group << endl;
		cout << "������������: " << rating << endl;
	}
};

class Teacher :public Human
{
	string specialty;
	unsigned int evil;
public:
	const string& get_specialty()const
	{
		return this->specialty;
	}
	unsigned int get_evil()const
	{
		return this->evil;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_evil(unsigned int evil)
	{
		this->evil = evil;
	}

	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int evil
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_evil(evil);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	void info()
	{
		Human::info();
		cout << "�������������: " << specialty << endl;
		cout << "������:\t" << evil << endl;
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	Graduate
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, unsigned int rating,
		const string& diploma_theme
	) :Student(last_name, first_name, age, specialty, group, rating)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	void info()
	{
		Student::info();
		cout << "���� ���������� �������: " << diploma_theme << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	/*Human h("�������", "�������", 18);
h.info();*/

	Student s("�������", "�������", 18, "���", "�� �� �� 34", 50);
	s.info();
	cout << "\n----------------------------------------\n";
	Teacher albert("Einstein", "Albert", 150, "Astronomy", 5);
	albert.info();
	cout << "\n----------------------------------------\n";

	Human* ps = &s;		//pointer to student
	Human* pt = &albert;//pointer to teacher
	ps->info();
	pt->info();
#endif // INHERITANCE

	//UpCast
	Human* group[] = 
	{
		new Student("�����", "�������", 18, "���", "�� �� �� 34", 20),
		new Student("�������", "����", 18, "���", "�� �� �� 34", 12),
		new Student("��������", "�������", 18, "���", "�� �� �� 34", 25),
		new Teacher("�������", "�������", 50, "�++", 99),
		new Student("����������", "������", 16, "���", "�� �� �� 34", 33),
		new Teacher("�����", "������", 60, "����", 2),
		new Graduate("����������", "�����", 17, "���", "�� �� �� 34", 98, "���������� ������������� ����������")
	};

	cout << "\n--------------------------\n";
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->info();
		cout << "\n--------------------------\n";
	}

	//DownCast

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}