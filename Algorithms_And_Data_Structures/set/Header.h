#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class set
{
public:
	set();
	set(char X);
	set(const char* X);
	set(__int32 N);
	set& operator=(set S);
	void show(ostream&os);
	friend ostream& operator<<(ostream&os, set A);
	friend bool operator==(set A, set B);

	bool is_present(char X)const;//��������� ��������
	set& insert(char X);//��������
	set& remove(char X);//��������
	set& toggle(char X);//�����������
	set U(set A, set B);//��'�������
	set U(set A);
	set �(set A, set B);//�������
	set �(set A);
	set l(set A, set B);//������
	set l(set A);
	set divide(char X);//���� �� ���������
	char find_the_smallest()const;//����� ����������
	
private:
	__int32 transform(char X)const;
	__int32 fullset;
	
};

