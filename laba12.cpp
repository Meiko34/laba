#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

using namespace std;

const int COLORS = 7; // Количество цветов
const char COLOR_CHARS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; // Символы для цветов

// ANSI-коды для цветов
const string COLOR_CODES[] = {
"\033[31m", // Красный
"\033[32m", // Зеленый
"\033[33m", // Желтый
"\033[34m", // Синий
"\033[35m", // Магента
"\033[36m", // Циан
"\033[37m"  // Белый
};
const string RESET_COLOR ="\033[0m";

const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Функция для проверки границ матрицы
bool isValid(int x, int y, int N, int M) {
    return x >= 0 && x < N && y >= 0 && y < M;}

// Функция для поиска области одинакового цвета с использованием DFS
void dfs(const vector<vector<char>>& matrix, int x, int y, char color, vector<vector<bool>>& visited, int& count) {
    visited[x][y] = true; // Помечаю текущую ячейку как посещенную
    count++; // Увеличиваем счетчик текущей области

    for (auto dir : directions) { // Проходим по всем направлениям
        int newX = x + dir[0]; // Вычисляем новые координаты
        int newY = y + dir[1];        // Проверяем, валидны ли новые координаты и не посещена ли ячейка
        if (isValid(newX, newY, matrix.size(), matrix[0].size()) &&!visited[newX][newY] && matrix[newX][newY] == color) {
            // Рекурсивный вызов
            dfs(matrix, newX, newY, color, visited, count);} }}


int main() {
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    int N, M;
    cout <<"Введите размеры матрицы (N M):"; 
    cin >> N >> M;

    // Создание матрицы и заполнение цветами
    vector<vector<char>> matrix(N, vector<char>(M));    
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = COLOR_CHARS[rand() % COLORS]; // Заполнение случайными цветами
            } }

    // Вывод матрицы с цветами
         cout <<"Сгенерированная матрица:\n";  
    for (const auto& row : matrix) {
        for (char color : row) {
            cout << color <<" "; // Выводим букву цвета
            } cout << endl; // Переход на новую строку после каждой строки матрицы
            } 

    unordered_map<char, int> colorCount; // Счетчик для областей одинакового цвета
    vector<vector<bool>> visited(N, vector<bool>(M, false)); // Вектор для отслеживания посещенных ячеек

     char largestColor = '\0'; // Для хранения цвета самой большой области
    int largestArea = 0; // Для хранения размера самой большой области
    
    // Поиск областей
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                int count = 0;
                dfs(matrix, i, j, matrix[i][j], visited, count); // Поиск области
                colorCount[matrix[i][j]] = max(colorCount[matrix[i][j]], count); // Обновление счетчика
                 if (count > largestArea) {
                    largestArea = count; // Обновляем размер самой большой области
                    largestColor = matrix[i][j]; // Обновляем цвет самой большой области
                    } }} }

    // Вывод результата
   cout <<"Самая большая область цвета " << largestColor <<" с размером " << largestArea <<":\n";

// Визуализация самой большой области
for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        if (matrix[i][j] == largestColor) {
            cout << COLOR_CODES[largestColor - 'A'] << matrix[i][j] << RESET_COLOR<< " "; // Выводим цвет с ANSI-кодом
            } else {
            cout << matrix[i][j] << " "; // Выводим остальные цвета без изменений
            }}}
    return 0;}