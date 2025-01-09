#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include <iomanip> // Для std::setw


using namespace std;


// Функция для печати матрицы с форматированием
void printMatrix(const vector<vector<int>>& matrix) {
int maxWidth = 3; // Ширина для выравнивания



for (const auto& row : matrix) {
    for (const auto& elem : row) {
        std::cout << std::setw(maxWidth) << elem <<" "; // Печатает элемент с установленной шириной
        } cout << endl; // Переход на новую строку
        }}

// Функция для обмена столбцов матрицы
void swapColumns(vector<vector<int>>& matrix) {
int n = matrix[0].size(); // Количество столбцов
int m = matrix.size();    // Количество строк


vector<int> newOrder; // Вектор для нового порядка столбцов
for (int i = 0; i < (n + 1) / 2; ++i) {
    newOrder.push_back(i); // Первый столбец
    if (n - 1 - i!= i) {
        newOrder.push_back(n - 1 - i); // Последний столбец, если он не равен первому
        } }

vector<vector<int>> newMatrix(m, vector<int>(n)); // Новая матрица для хранения измененных столбцов
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < newOrder.size(); ++j) {
        newMatrix[i][j] = matrix[i][newOrder[j]]; // Заполнение новой матрицы
        } }

matrix = newMatrix; // Замена старой матрицы на новую
}
 
 int main() {

int rows, cols;


// Запрос количества строк и столбцов у пользователя
cout <<"Введите количество строк:"; cin >> rows;
cout <<"Введите количество столбцов:"; cin >> cols;


// Инициализация генератора случайных чисел
srand(static_cast<unsigned int>(time(nullptr))); // Используем текущее время для инициализации


// Создание матрицы
vector<vector<int>> matrix(rows, vector<int>(cols));


// Заполнение матрицы случайными числами
for (int i = 0; i < rows; ++i) {
for (int j = 0; j < cols; ++j) {
matrix[i][j] = rand() % 100; // Случайные числа от 0 до 99
} }


// Печать исходной матрицы
cout <<"Исходная матрица:" << endl;
printMatrix(matrix);


    // Обмен столбцов
    swapColumns(matrix); 

    // Печать измененной матрицы
    cout <<"Матрица после изменения столбцов:" << endl;
    printMatrix(matrix); 

    return 0;}
