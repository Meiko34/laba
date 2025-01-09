#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int num_of_rooms=0, i=0, num_of_rooms_phones=0, b=0, a=0, o=0, count=0, min_count=10000, komutator=0;
   
    cout << "Введите количество всех комнат\t";
    cin >> num_of_rooms;
    
      if (num_of_rooms <= 0) {
        cout << "введите положительное ЧИСЛО" << endl;
        return 1; 
    }
    
    int rooms[num_of_rooms] = {0};
    for(int i=0; i<num_of_rooms; i++){
        rooms[i] = i+1;
    }
    
    cout << "Введите количество комнат с телефонами ";
    cin >> num_of_rooms_phones;
    
    cout << "Введите номера " << num_of_rooms_phones << " комнат с телефонами в порядке возрастания ";
    int numbers_phones[num_of_rooms_phones] = {0};
    for(int b=0; b < num_of_rooms_phones; b++)
    {
        cin >> a;
        numbers_phones[b] = a;
    }

    for(int i = 0; i < num_of_rooms; i ++)
    {
        count=0;
        
        for(int o = 0; o < num_of_rooms_phones; o ++)
        {
            count += abs(rooms[i] - numbers_phones[o]);
        }

        if (count < min_count){
            min_count = count;
            komutator = rooms[i];
            count = 0;
        }
    }

    cout << "Номер комнаты = " << komutator << "\n"
         << "Минимальная длина = " << min_count;

    return 0;
}
