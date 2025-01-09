#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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
            int colorIndex = color - 'A'; // Получаем индекс цвета
            cout << COLOR_CODES[colorIndex] << color <<"" << RESET_COLOR; // Выводим букву с ее цветом
            } cout << endl;} 
            return 0;}