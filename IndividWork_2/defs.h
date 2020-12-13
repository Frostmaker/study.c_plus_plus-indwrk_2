#pragma once
#ifndef MAX_ROWS, MAX_COLS

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

#endif // !MAX_ROWS, MAX_COLS

bool check_positivity(int* arr, size_t len);
void delete_elements(int*& arr, size_t& len);
void remove_negative_rec(int*& arr, size_t len);
int find_elem(int m[MAX_ROWS][MAX_COLS], size_t size, int value);
double* create_vector(int m[MAX_ROWS][MAX_COLS], size_t rows, size_t cols);