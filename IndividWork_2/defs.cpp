#include <climits>
#include "defs.h"


/// <summary>
/// ������� ���������, ��� � ������� ������ ������������� ��������
/// </summary>
/// <param name="arr">� ������������� ������</param>
/// <param name="len">� ����� �������</param>
/// <returns>
/// true � � ������� ������ ������������� ��������;
/// false � � ������� ���� ������������� ������� ��� ����
/// </returns>
bool check_positivity(int* arr, size_t len)
{
	bool only_positive = true;
	for (int i = 0; i < len; ++i) {
		if (arr[i] <= 0) {
			only_positive = false;
			break;
		}
	}

	return only_positive;
}

/// <summary>
/// ������� ������� ������ ���� ������ ������ ���������� ���������
/// </summary>
/// <param name="arr">� ������������� ������</param>
/// <param name="len">� ����� �������</param>
void delete_elements(int*& arr, size_t &len)
{
	// ������� ������ ������� ����� �� ����
	int index;
	bool no_couple{ true };
	for (int i = 0; i < len - 1; ++i) {
		if (arr[i] == arr[i + 1]) {
			index = i;
			no_couple = false;
			break;
		}
	}

	if (no_couple) return;  // � ������� ��� ������ ������ ���������

	// ������ ������ ��� ������ ���� ����
	int* arr2 = new int[len - 2];

	for (int i = 0; i < index; ++i) {
		arr2[i] = arr[i];
	}

	for (int i = index + 2; i < len; ++i) {
		arr2[i - 2] = arr[i];
	}

	// �������������� �������� ������
	delete[] arr;
	len -= 2;
	arr = new int[len];

	for (int i = 0; i < len; ++i) {
		arr[i] = arr2[i];
	}

	// ��������� ������������ ������
	delete[] arr2;

	return;
}

/// <summary>
/// ������� �������� ��� ������������� �������� ������� �� ���� (����������)
/// </summary>
/// <param name="arr">� ������������� ������</param>
/// <param name="len">� ����� �������</param>
void remove_negative_rec(int*& arr, size_t len)
{
	if (arr[len - 1] < 0) arr[len - 1] = 0;
		
	if (len == 1) return;

	return remove_negative_rec(arr, len - 1);
}

/// <summary>
/// ������� ������� ���������� ����� � ������� �������� ������� ������� ��������� ��������
/// </summary>
/// <param name="m">� ���������� ������������� �������</param>
/// <param name="size">� ������ �������</param>
/// <param name="value">� �������� ��������</param>
/// <returns></returns>
int find_elem(int m[MAX_ROWS][MAX_COLS], size_t size, int value)
{
	// ��������� ������� �������� �������
	// � ������ ����� ������� "��������" �� ������ �������� � ������ � � �����
	// � ������� <temp>
	int temp{ 0 };
	int res{ INT_MAX };
	int rows = size / 2 + size % 2;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0 + temp; j < size - temp; ++j) {
			if (m[i][j] > value && m[i][j] < res) 
				res = m[i][j];
		}
		++temp;
	}

	if (res == INT_MAX) throw - 2;  // � ������� �������� ������� ��� ����� > ��������� ��������

	return res;
}

/// <summary>
/// ������� ������� ������ ������ ������� �������� ����� ��������
/// ��������������� ������������� ��������� ��������������� ������
/// �������
/// </summary>
/// <param name="m">� ������������� �������</param>
/// <param name="rows">� ���-�� ����� � �������</param>
/// <param name="cols">� ���-�� ������� � �������</param>
/// <returns>vec � ������ �������� (������� �������������� ������ ������)</returns>
double* create_vector(int m[MAX_ROWS][MAX_COLS], size_t rows, size_t cols)
{
	double* vec = new double[rows];
	int sum, k;  // ����� � ���-�� ������������� ����� � ������

	// � ������ ������ ���� ������������� ����� � ���������� �� � <sum> � <k>.
	// ����� ����� ������� ������� �������������� ��� ������ ������ � ���������� ��� � ������
	for (int i = 0; i < rows; ++i) {
		sum = 0;
		k = 0;
		for (int j = 0; j < cols; ++j) {
			if (m[i][j] < 0) {
				++k;
				sum += m[i][j];
			}
		}

		// ���� � ������ ���� ������������� �����, ���������� ����������
		if (k == 0) {
			delete[] vec;
			throw i;  // ����� �������� ���������, ��� � <(i + 1)>-�� ������ ��� ������������� �����
		}

		vec[i] = 1.0 * sum / k;
	}

	return vec;
}