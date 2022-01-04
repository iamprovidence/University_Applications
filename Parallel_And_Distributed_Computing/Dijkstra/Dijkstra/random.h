#pragma once
#include <stdlib.h>

namespace CUDA
{
	// ������� ��������� ����� �� �������� [min, max)
	template<int min, int max>
	int get_rand()
	{
		//������� rand() % (������ �� ���������) + ��� �������
		return rand() % (max - min) + min;
	}

	double get_double_rand(double min, double max)
	{
		return min + (double)rand() / RAND_MAX * (max - min);
	}
}