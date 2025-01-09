#include <iostream>
#include <sstream>
#include <string>
#include <vector> //  для работы с векторами
#include <climits> // дял INT_MAX

using namespace std;

int main() {
    string input, word;
    
    vector<string> longest_words; // Вектор для самых длинных слов
    vector<string> shortest_words; // Вектор для самых коротких слов
    
    int max_length = 0; // Максимальная длина
    int min_length = INT_MAX; // Минимальная длина (максимально возможное значение)   
    
    cout <<"Введите фразу:";   
    getline(cin, input);    
    istringstream iss (input);    //разбиваем на слова

    while (iss >> word) { // Цикл пока некончатся слова
        int length = word.length(); // Длина текущего слова

        // Проверяем, является ли текущее слово самым длинным
        if (length > max_length) {
            max_length = length; // Обновляем максимальную длину
            longest_words.clear(); // Очищаем вектор для длинных слов
            longest_words.push_back(word); // Добавляем текущее слово
            
            } else if (length == max_length) { // Если длины совпадают
            longest_words.push_back(word); // Добавляем слово в вектор длинных слов
            }
            // Проверяем, является ли текущее слово самым коротким
        if (length < min_length) {
            min_length = length; // Обновляем минимальную длину
            shortest_words.clear(); // Очищаем вектор для коротких слов
            shortest_words.push_back(word); // Добавляем текущее слово
            
            } else if (length == min_length) { // Если длины совпадают
            shortest_words.push_back(word); // Добавляем слово в вектор коротких слов
                
            } }

    // Выводим результаты для самых длинных слов
    cout <<"Самые длинные слова:"; 
    for (const auto& lw : longest_words) {
    cout << "'" << lw <<"'";
        }
    cout <<"из " << max_length <<" символов." << endl; 
    
    // Выводим результаты для самых коротких слов
    cout <<"Самые короткие слова:"; 
    for (const auto& sw : shortest_words) {
    cout << "'" << sw <<"'";
    }
    cout <<"из " << min_length <<" символов." << endl;

    return 0;
            
        }