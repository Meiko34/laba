#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    string input;
    int index, start, end, choice;
    cout << "Введите строку: ";
    getline(cin, input);

    vector<char> digits;

    // Ищем числа в строке
    for (char c : input) {
        if (isdigit(c)) {
            digits.push_back(c); // Сохраняем цифры
        }
    }

    cout << "Количество цифр в строке: " << digits.size() << endl;

    cout << "Выберите действие:\n1. Вывести одну цифру\n2. Вывести диапазон цифр\n";
    cout << "Введите номер действия (1 или 2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "Введите номер цифры для вывода (от 1 до " << digits.size() << "): ";
        cin >> index;

        // Проверяем, что введенный номер корректен
        if (index >= 1 && index <= digits.size()) {
            cout << "Введённая цифра под номером " << index << ": " << digits[index - 1] << endl; // Индексация с 0
        } else {
            cout << "Ошибка: неверный номер. Пожалуйста, введите номер от 1 до " << digits.size() << "." << endl;
        }
    } else if (choice == 2) {
        cout << "Введите начальный номер (от 1 до " << digits.size() << "): ";
        cin >> start;
        cout << "Введите конечный номер (от 1 до " << digits.size() << "): ";
        cin >> end;

        // Проверяем, что введенные номера корректны
        if (start >= 1 && end <= digits.size() && start <= end) {
            cout << "Цифры в диапазоне с " << start << " по " << end << ":" << endl;
            for (int i = start - 1; i < end; ++i) {  // Индексация начинается с 0
                cout << digits[i] << " ";
            }
            cout << endl; // Переход на новую строку после вывода
        } else {
            cout << "Ошибка: пожалуйста, введите корректные номера для диапазона." << endl;
        }
    } else if (choice != 1 && choice != 2) {
        cout << "Ошибка: неверный выбор. Пожалуйста, введите 1 для одной цифры или 2 для диапазона." << endl;
    }

    if (digits.empty()) {
        cout << "В строке нет цифр." << endl;
    }

    return 0;
}
