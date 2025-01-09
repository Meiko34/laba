#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int menuChoice;

// Функция для сохранения ответов в файл
void saveAnswers(const vector<bool>& answers, const string& filename) {
    unsigned char byte = 0; // Создаем переменную для хранения ответов в виде одного байта
    for (int i = 0; i < 8; ++i) {
        if (answers[i]) {
            byte |= (1 << i); // Установка соответствующего бита
            } }
    ofstream outFile(filename, ios::binary); // Записываем байт в файл 
    outFile.write(reinterpret_cast<char*>(&byte), sizeof(byte));    
    outFile.close();}

// Функция для загрузки ответов из файла
void loadAnswers(vector<bool>& answers, const string& filename) {
    unsigned char byte = 0; // Переменная для хранения загруженных ответов
    ifstream inFile(filename, ios::binary); // Открываем файл для чтения в бинарном режиме 
    if (inFile) {
        inFile.read(reinterpret_cast<char*>(&byte), sizeof(byte)); // Читаем байт из файла     
        inFile.close(); // Закрываем файл
        // Преобразуем байт в отдельные булевы значения
        for (int i = 0; i < 8; ++i) {
            answers[i] = (byte & (1 << i)) != 0; // Проверяем, установлен ли соответствующий бит
            }        cout <<"Ответы успешно загружены из файла:" << filename << endl;} else {
        cout <<"Ошибка при загрузке файла:" << filename << endl;}}

        // Функция для отображения ответов
void displayAnswers(const vector<bool>& answers, const vector<string>& questions) {
    cout <<"Ваши ответы:\n";    
    for (int i = 0; i < 8; ++i) {
        cout << questions[i] << ":" << (answers[i] ?"Да" :"Нет") << endl;}}
        
        
    int main() {
    vector<bool> answers(8, false); // Вектор для хранения 8 ответов (по умолчанию все"Нет") 
    vector<string> questions = {"Вы любите программировать?","Вы занимаетесь спортом?","Вы предпочитаете читать книги?","Вы любите путешествовать?","Вы увлекаетесь музыкой?","Вы предпочитаете работать в команде?","Вы любите готовить?","Вы интересуетесь наукой?"    }; // Массив с вопросами
    
    string filename;
    char choice;

    cout <<"Хотите загрузить существующий файл? (y/n):";
    
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout <<"Введите имя файла для загрузки:"; 
        cin >> filename;
        loadAnswers(answers, filename); // Загружаем ответы из указанного файла
        } else {
        cout <<"Введите имя нового файла для сохранения:"; 
        cin >> filename; // Пользователь вводит имя нового файла
        cout <<"Создан новый файл:" << filename << endl;}
        
         
    do {
        cout <<"1. Ответить на вопросы\n";        
        cout <<"2. Изменить ответ\n";        
        cout <<"3. Показать все ответы\n";       
        cout <<"4. Сохранить ответы в файл\n";        
        cout <<"5. Выйти\n";        
        cout <<"Выберите опцию:";        
        
        cin >> menuChoice;

        switch (menuChoice) {
            case 1: { // Ответить на вопросы
                for (int i = 0; i < 8; ++i) {
                    int response;
                    cout << questions[i] <<": Ответьте 0 (Нет) или 1 (Да):";                    
                    cin >> response;
                    answers[i] = (response == 1);  // Сохраняем ответ
                    }                
                    cout <<"Ваши ответы сохранены в памяти!" << endl;
                break;}            
                
                case 2: { // Изменить ответ
                int question;
                cout <<"Введите номер вопроса (1-8), который хотите изменить:";                
                cin >> question;
                if (question < 1 || question > 8) {
                    cout <<"Некорректный номер вопроса!" << endl;
                    } else {
                    int response;
                    cout <<"Введите новый ответ для вопроса" << question <<" (0 - Нет, 1 - Да):";                    
                    cin >> response;
                    answers[question - 1] = (response == 1);                    
                    cout <<"Ответ изменен!" << endl;}                
                    break;}         

                case 3: { // Показать все ответы
                displayAnswers(answers, questions);  // Вызываем функцию для отображения ответов         
                break;}            
                
                case 4: { // Сохранить ответы в файл
                saveAnswers(answers, filename); // Сохраняем в выбранный файл
                cout <<"Ответы сохранены в файл:" << filename << endl;
                break;}            
                
                case 5: // Выйти
                cout <<"Выход из программы." << endl;

                break;
                default: // Если введен некорректный выбор
                cout <<"Некорректный выбор. Попробуйте еще раз." << endl;
                }    } while (menuChoice!=5);    
                
                return 0;}
        
        
        
        