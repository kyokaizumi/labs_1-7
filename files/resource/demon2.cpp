#include "lr2.h"
#include <cstdlib> // Для malloc и free

namespace lr2 {
    // Демонстрационная функция
    void runDemo() {
        setlocale(LC_ALL, "ru");
        srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

        DoublyLinkedList list;
        string choice;
        int i = 1; // Счетчик элементов

        while (true) {
            cout << endl << i << " элемент\n";
            cout << "Хотите ли вы вводить данные вручную или автоматически?\n(введите 'y' - вручную или 'n' - автоматически, для завершения ввода введите 'end'): ";
            cin >> choice;

            if (choice == "end") {
                break; // Завершение ввода
            }

            if (choice == "y") {
                int height, weight, age;
                cout << "Рост: ";
                cin >> height;
                cout << "Вес: ";
                cin >> weight;
                cout << "Возраст: ";
                cin >> age;
                list.addFirst(height, weight, age);
            }
            else if (choice == "n") {
                int height = rand() % 51 + 160; // Рост от 160 до 210
                int weight = rand() % 61 + 40;   // Вес от 40 до 100
                int age = rand() % 57 + 14;      // Возраст от 14 до 70
                list.addFirst(height, weight, age);
                cout << "Автоматически добавлено: Рост = " << height << ", Вес = " << weight << ", Возраст = " << age << endl;
            }
            else {
                cout << "Неверный ввод. Пожалуйста, попробуйте снова." << endl;
                continue; // Возвращаемся к началу цикла
            }
            i += 1; // Увеличиваем счетчик элементов
        }

        cout << "\nДанные в исходном порядке:\n";
        list.showList();

        string crit;
        cout << "\nВведите критерий сортировки (hwa - рост + вес + возраст,\nhw - рост + вес, ha - рост + возраст, wa - вес + возраст,\nh - рост, w - вес, a - возраст): ";
        cin >> crit;
        list.sortingList(crit);

        cout << "\nДанные после сортировки по " << crit << ":\n";
        list.showList();
    }
}