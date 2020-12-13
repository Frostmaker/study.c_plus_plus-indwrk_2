#include <climits>
#include "defs.h"


/// <summary>
/// Функция проверяет, что в массиве только положительные элементы
/// </summary>
/// <param name="arr">— целочисленный массив</param>
/// <param name="len">— длина массива</param>
/// <returns>
/// true — в массиве только положительные элементы;
/// false — в массиве есть отрицательный элемент или ноль
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
/// Функция удаляет первую пару подряд идущих одинаковых элементов
/// </summary>
/// <param name="arr">— целочисленный массив</param>
/// <param name="len">— длина массива</param>
void delete_elements(int*& arr, size_t &len)
{
	// Находим индекс первого числа из пары
	int index;
	bool no_couple{ true };
	for (int i = 0; i < len - 1; ++i) {
		if (arr[i] == arr[i + 1]) {
			index = i;
			no_couple = false;
			break;
		}
	}

	if (no_couple) return;  // В матрице нет подряд идущих элементов

	// Создаём массив без первой пары цифр
	int* arr2 = new int[len - 2];

	for (int i = 0; i < index; ++i) {
		arr2[i] = arr[i];
	}

	for (int i = index + 2; i < len; ++i) {
		arr2[i - 2] = arr[i];
	}

	// Перезаписываем исходный массив
	delete[] arr;
	len -= 2;
	arr = new int[len];

	for (int i = 0; i < len; ++i) {
		arr[i] = arr2[i];
	}

	// Подчищаем динамическую память
	delete[] arr2;

	return;
}

/// <summary>
/// Функция заменяет все отрицательные элементы массива на нули (рекурсивно)
/// </summary>
/// <param name="arr">— целочисленный массив</param>
/// <param name="len">— длина массива</param>
void remove_negative_rec(int*& arr, size_t len)
{
	if (arr[len - 1] < 0) arr[len - 1] = 0;
		
	if (len == 1) return;

	return remove_negative_rec(arr, len - 1);
}

/// <summary>
/// Функция находит наименьшее число в верхней четверти матрицы большее заданного значения
/// </summary>
/// <param name="m">— квадратная целочисленная матрица</param>
/// <param name="size">— размер матрицы</param>
/// <param name="value">— заданное значение</param>
/// <returns></returns>
int find_elem(int m[MAX_ROWS][MAX_COLS], size_t size, int value)
{
	// Проверяем верхнюю четверть матрицы
	// С каждой новой строкой "обрезаем" по одному элементу в начале и в конце
	// С помощью <temp>
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

	if (res == INT_MAX) throw - 2;  // В верхней четверти матрицы нет чисел > заданного значения

	return res;
}

/// <summary>
/// Функция создаётв вектор каждый элемент которого равен среднему
/// арифметическому отрицательных элементов соответствующей строки
/// матрицы
/// </summary>
/// <param name="m">— целочисленная матрица</param>
/// <param name="rows">— кол-во строк в матрице</param>
/// <param name="cols">— кол-во столбов в матрице</param>
/// <returns>vec — массив значений (средних арифметических каждой строки)</returns>
double* create_vector(int m[MAX_ROWS][MAX_COLS], size_t rows, size_t cols)
{
	double* vec = new double[rows];
	int sum, k;  // Сумма и кол-во отрицательных чисел в строке

	// В каждой строке ищем отрицательные числа и записываем их в <sum> и <k>.
	// После этого находим среднее арифметическое для каждой строки и записываем его в вектор
	for (int i = 0; i < rows; ++i) {
		sum = 0;
		k = 0;
		for (int j = 0; j < cols; ++j) {
			if (m[i][j] < 0) {
				++k;
				sum += m[i][j];
			}
		}

		// Если в строке нету отрицательных чисел, генерируем исключение
		if (k == 0) {
			delete[] vec;
			throw i;  // Нужно выводить сообщение, что в <(i + 1)>-ой строке нет отрицательных чисел
		}

		vec[i] = 1.0 * sum / k;
	}

	return vec;
}