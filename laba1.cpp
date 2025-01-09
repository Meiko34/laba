#include <iostream>
#include <cmath>
#include <limits> 
using namespace std;

double getPositiveDouble(const string& prompt) {
    double value;
    
    while (true) {
        cout << prompt;
        cin >> value;

        // Проверка на корректность ввода
        if (cin.fail() || value <= 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Игнорируем некорректный ввод
            cout << "Ошибка: введите положительное число." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Игнорируем лишние символы
            return value;
        }
    }
}

int main() {
    double roomLength = getPositiveDouble("Введите длину комнаты(м): ");
    double roomHeight = getPositiveDouble("Введите высоту комнаты(м): ");
    double roomWidth = getPositiveDouble("Введите ширину комнаты(м): ");

    double wallpaperLength = getPositiveDouble("Введите длину рулона обоев(м): ");
    
    // Обработка ошибки для высоты рулона
    double wallpaperWidth = getPositiveDouble("Введите ширину рулона обоев(м): ");
    
    // Проверка, что высота рулона больше или равна высоте стены
    while (wallpaperLength < roomHeight) {
        cout << "Ошибка: высота рулона обоев должна быть не меньше высоты стены." << endl;
        wallpaperLength = getPositiveDouble("Введите длину рулона обоев(м): ");
    }

    double wallLen = 2 * (roomLength + roomWidth); // общая длина стен 
    double rollArea = wallLen / wallpaperWidth; // (длину стен делим на ширину обоев) = сколько полосок надо
    int quantity = floor(wallpaperLength / roomHeight); // делим длину обоев на высоту стен = сколько полосок в рулоне
    int needRoll = ceil(rollArea / quantity); // кол-во полосок нужных делим на сколько полосок в рулоне = сколько рулонов нужно
    
    double totalRoll = needRoll *(wallpaperLength* wallpaperWidth); // площадь потраченных обоев 
    double wallArea = wallLen * roomHeight; // площадь комнаты
    double ost = totalRoll - wallArea; // площадь остатков
    double procent = (ost / totalRoll) * 100; // проценты остатков

    cout << "Необходимое количество рулонов: " << needRoll << endl;
    cout << "Процент остатков: " << procent << "%" << endl;

    return 0;
}
