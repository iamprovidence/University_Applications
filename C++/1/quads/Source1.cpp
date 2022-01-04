#include "Header.h"

void main()
{
	Figure *Fg[5] =
	{
		new Figure("Figure"),
		new Quadrilateral("Quadrilateral", 23, 40,18,45),
		new Parallelogram("Parallelogram", 30, 25),
		new Rhombus("Rhombus", 50),
		new Square("Square", 15)
	};

	Quadrilateral *Qd[4] =
	{
		new Quadrilateral("Quadrilateral", 23, 40,18,45),
		new Parallelogram("Parallelogram", 30, 25),
		new Rhombus("Rhombus", 50),
		(Rhombus*)new Square("Square", 15)
	};

	cout << endl << "----SHOW----" << endl;
	//* ���������������� ��������� �������� �� ������� ������ �ᒺ��� �������� �����
	for (size_t i = 0; i < 4; i++)
	{
		Qd[i]->show(cout);
	}
	
	for(size_t i = 0; i < 5; i++)
	{
		Fg[i]->show(cout);
	}

	for (size_t i = 0; i < 5; i++)
	{
		Fg[i]->print();
	}

	Figure** arr = new Figure*[2];
	arr[0] = (Parallelogram*)new Square("Parallelogram",15);
	arr[1] = new Rhombus("Rhombus", 60);

	cout << endl << "----USING----" << endl;
	//������������ ��������� using ��� ������� ������� �� ���� �������� �����
	Quadrilateral Q("Quadrilateral", 2, 5, 6, 9);
	Q.name = "Q";
	Q.show(cout);
	cout << endl;

	Rhombus R("Rhombus", 100);
	R.name = "Rh";
	R.show(cout);
	cout << endl;

	Parallelogram P("Parallelogram", 30, 25);
	P.name = "Pr";
	P.show(cout);
	cout << endl;

	Square S("Square", 15);
	S.name = "Sq";
	S.show(cout);
	cout << endl;

	cout << endl << "----FUNCTION----" << endl;
	//*���������������� �������� �������������� ������� ������� - ����� � ���������� ������� 
	//��� ����� ������� ��������� ���������� � ������ LandTransport �� SeaTransport ��� �ᒺ��� 
	//SuperVehicle.����������� using - ���������� ��� �������� �������������� ������� � ������� ��������
	//����� SuperVehicle.
	Square S1("Square", 25);
	cout << S1.S(25) << endl;
	cout << S1.S(25) << endl;
	//* ���������������� �������� �������������� ������� �������-����� � ���������� ����������� 
	//(���������� ����� �������, �� ���������, �� ���, ���� ������� �������) ���������� � ������ 
	//LandTransport �� SeaTransport ��� �ᒺ��� SuperVehicle.
	Square S2("Square", 20);
	cout << S2.Rhombus::P(20) << endl;
	cout << S2.Parallelogram::P(20) << endl;

	system("pause");
}