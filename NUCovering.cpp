#include "fragmentation.h"
#include <locale.h>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;
/// ��������� ��������� ������������� �������
const double g_l1_max = 12.0;
const double g_l2_max = g_l1_max;
const double g_l1_min = 8.0;
const double g_l2_min = g_l1_min;
const double g_l0 = 5.0;

/// �������� ������������� �������� ������������
const double g_precision = 0.25;


int main()
{
	setlocale(LC_ALL, "Rus");

	double a = -10, b = 0, c = 24, d = 16;

	high_resolution_clock::time_point start, end;
	start = high_resolution_clock::now(); //������� �����
	high_level_analysis main_object(a, b, c, d);

	main_object.GetSolution();
	end = high_resolution_clock::now();
	duration<double> duration = (end - start);

	cout << "����� ���������� ����: " << duration.count() << " ������" << std::endl;

	// ��������! ����� ���������� ���������� ���� �� �������� ������!
	const char* out_files[3] = {	"solution.txt", "nsolution.txt", "boundary.txt" };
	WriteResults( out_files );

	system("pause");
	return 0;
}