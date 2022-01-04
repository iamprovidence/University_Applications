#pragma once
#include <iostream>
#include <string>
class HashTable;
struct abonent;
struct Node;
typedef void(*funcptr)(abonent A);

const int PRIME_SIZE = 500;// ����������� ������ �����

using namespace std;

struct abonent // ���������� ��� ������
{
	string name;
	long long number;
	
	abonent();
	abonent(string name, long long number);
	friend bool operator!=(abonent left, abonent right);
};

class HashTable // ���-�������,����� ������
{
private:
	struct Node
	{
		abonent data;
		Node *next;

		Node();
		Node(string name, long long number, Node* next);
	};
	Node*table[PRIME_SIZE];
	// ���-�������
	// ���� ����� ASCII ���� + ���� ���� ������
	// � ���� ������ �� ������ �� ���������� ������ �����
public:
	int hash(abonent current);
public:
	HashTable();
	~HashTable();
	// �����
	Node* find(string name, long long number, bool need_previous);
	// �������� ��������
	bool is_present(abonent is_present);
	// ���������
	bool push(abonent abonent_push);
	//�����
	bool rechange(abonent &find_to_change, abonent change_to);
	//���������
	bool remove(abonent abonent_remove);
	//������
	void doeach(funcptr f);
	int print();
};