#include "phone_book.h"

void user_option(Contact a[], int n)
{
	int option;
	cout << "\n�������i �i�" << endl
		<< "1. �����" << endl
		<< "2. ������ �����" << endl
		<< "3. ���i���� �����" << endl
		<< "4. �����i���� �����i���" << endl
		<< "5. �������� �����" << endl
		<< "6. ���������" << endl
		<< "7. ������� �����" << endl
		<< "8. ���i�" << endl << endl;

	do
	{
		cin >> option;
	} while (option <1 && option >8);

	switch (option)
	{
		case 1: find(a,  n); break;
		case 2: add(a, n); break;
		case 3: replace(a, n); break;
		case 4: present(a, n); break;
		case 5: execute(a, n); break;
		case 6: sort(a, n); break;
		case 7: show(a,n); break;
		case 8: exit(1); break;
	}
}

ostream& operator<<(ostream& os, const Contact&c)
{
	os << c.number << ' ' << c.name << ' ' << c.fname << ' ' << c.age << ' ' << c.address << endl;
	return os;
}
bool operator==(const Contact&l, const Contact&r)
{
	return  l.number == r.number &&
		l.name == r.name &&
		l.fname == r.fname &&
		l.age == r.age &&
		l.address == r.address;
}

void show(Contact A[], int n)
{
	int find_option;
	cout << "�������" << endl
		<< "1. �� �������" << endl
		<< "2. �� ���������� �������" << endl
		<< "3. ��i ������" << endl
		<< "4. �������� ����" << endl
		<< "5. ���i�" << endl;


	do
	{
		cin >> find_option;
	} while (find_option <1 && find_option >5);

	switch (find_option)
	{
		case 1: show_by_number(A, n); break;
		case 2: show_by_index(A, n); break;
		case 3: show_all(A, n); break;
		case 4: user_option(A, n); break;
		case 5: exit(1); break;
	}
}
void show_by_number(Contact A[], int n)
{
	cout << "����i�� �����" << endl;
	long long show_number;
	cin >> show_number;
	for (size_t i = 0; i < n; i++)
	{
		if (A[i].number == show_number)
		{
			cout << i + 1 << ' ' << A[i];
		}
	}
}
void show_by_index(Contact A[], int n)
{
	cout << "����i�� ���������� �����" << endl;
	int show_index;
	Contact ZERO;
	cin >> show_index;
	if (show_index < 0 || show_index >1000)
	{
		cout << "������������ i�����";
	}
	else if ( A[show_index] == ZERO)
	{
		cout << "������� �i�����i�";
	}
	else
	{
		cout << A[show_index + 1];
	}
}
void show_all(Contact A[], int n)
{
	cout << "��i ������" << endl;
	for (size_t i = 0; i < n; i++)
	{
		if (A[i].number != 0)
		{
			cout << i + 1 << ' ' << A[i];
		}
		else
		{
			continue;
		}
	}
}

void find(Contact a[], int n)
{
	int find_option;
	cout << "�����" << endl
		<< "1. �� �������" << endl
		<< "2. �� i�\'��" << endl
		<< "3. �� ���i�i��" << endl
		<< "4. �� �i���" << endl
		<< "5. �� �������" << endl
		<< "6. �� ���" << endl
		<< "7. �������� ����" << endl
		<< "8. ���i�" << endl;
		

	do
	{
		cin >> find_option;
	} while (find_option <1 && find_option >8);

	switch (find_option)
	{
		case 1: find_by_number(a, n); break;
		case 2: find_by_name(a, n); break;
		case 3: find_by_fname(a, n); break;
		case 4: find_by_age(a, n); break;
		case 5: find_by_address(a, n); break;
		case 6: find(a, n); break;
		case 7: user_option(a, n); break;
		case 8: exit(1); break;
	}
}

void find_by_number(Contact a[], int n)
{
	cout << "����i�� �����" << endl;
	long long find_number;
	cin >> find_number;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].number == find_number)
		{
			cout << i + 1 << ' ' << a[i];
		}
	}
}
void find_by_name(Contact a[], int n)
{
	cout << "����i�� i�\'��" << endl;
	string find_name;
	cin >> find_name;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].name == find_name)
		{
			cout << i + 1 << ' ' << a[i];
		}
	}
}
void find_by_fname(Contact a[], int n)
{
	cout << "����i�� ���i�i�" << endl;
	string find_fname;
	cin >> find_fname;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].fname == find_fname)
		{
			cout << i + 1 << ' ' << a[i];
		}
	}
}
void find_by_age(Contact a[], int n)
{
	cout << "����i�� �i�" << endl;
	int find_age;
	cin >> find_age;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].age == find_age)
		{
			cout << i + 1 << ' ' << a[i];
		}
	}
}
void find_by_address(Contact a[], int n)
{
	cout << "����i�� �����" << endl;
	string find_address;
	cin >> find_address;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i].address == find_address)
		{
			cout << i + 1 << ' ' << a[i];
		}
	}
}

void add(Contact a[], int n)
{
	Contact ZERO;
	Contact add;
	cout << "����i�� �����, i�\'�, ���i�i�, �i�, �����" << endl;
	cin >> add.number >> add.name >> add.fname >> add.age >> add.address;
	
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] == ZERO)
		{
			a[i] = add;
			cout << "����� ������";
			break;
		}
	}
}

void replace(Contact a[], int n)
{
	cout << "����i�� �����, ����� ���� ����i��� ���i����" << endl;
	long long replace_number;
	cin >> replace_number;
	if (is_exist(a, n, replace_number))
	{
		Contact replaced;
		cout << "����i�� �����, i�\'�, ���i�i�, �i�, �����" << endl;
		cin >> replaced.number >> replaced.name >> replaced.fname >> replaced.age >> replaced.address;

		for (size_t i = 0; i < n; i++)
		{
			if (a[i].number == replace_number)
			{
				a[i] = replaced;
				break;
			}
		}
		cout << "����� ���i����\n";
	}
	else
	{
		cout << "������ �i�����i�\n";
	}

}

void execute(Contact a[], int n)
{
	cout << "����i�� �����" << endl;
	long long delete_number;
	cin >> delete_number;
	if (is_exist(a, n, delete_number)) 
	{
		for (size_t i = 0; i < n; i++)
		{
			if (a[i].number == delete_number)
			{
				Contact deleted;
				a[i] = deleted;
			}
		}
		cout << "����� ��������\n";
	}
	else
	{
		cout << "������ �i�����i�\n";
	}
	
}

void present(Contact a[], int n)
{
	cout << "����i�� �����" << endl;
	long long exit_number;
	cin >> exit_number;
	is_exist(a, n, exit_number) ? cout << "������ �������i�\n" : cout << "������ �i�����i�\n";
}

bool is_exist(Contact a[], int n, long long exit_number)
{
	for (size_t i = 0; i < n; i++)
	{
		if (exit_number == a[i].number)
		{
			return true;
		}
	}
	return false;
}

void sort(Contact a[], int n)
{
	int sort_option;
	cout << "���������" << endl
		<< "1. �� �������" << endl
		<< "2. �� i�\'��" << endl
		<< "3. �������� ����" << endl
		<< "4. ���i�" << endl;

	do
	{
		cin >> sort_option;
	} while (sort_option <1 && sort_option >4);

	switch (sort_option)
	{
		case 1: shell_sort_by_number(a,n); break;
		case 2: shell_sort_by_name(a,n); break;
		case 3: user_option(a, n); break;
		case 4: exit(1); break;
	}
}
void shell_sort_by_number(Contact a[], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			if (a[j].number > a[j + 1].number)
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}
void shell_sort_by_name(Contact a[], int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			if (a[j].name > a[j + 1].name)
			{
				swap(a[j], a[j + 1]);
			}
		}
	}
}