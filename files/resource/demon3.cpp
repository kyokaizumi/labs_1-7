#include "lr3.h"
namespace lr3 {
    // Функция для демонстрации
    void runDemo() {
        setlocale(LC_ALL, "ru");

        while (true) {
            int N;
            cout << "\nВведите количество элементов: ";
            cin >> N;
            DynamicArray dynamicArray(N); // Создание объекта класса
            dynamicArray.inputElements(); // Ввод элементов

            // Выбор параметров замены
            char choice;
            cout << "Выберите способ замены дубликатов (m - по модулю, v - по значению): ";
            cin >> choice;
            bool byModulo = (choice == 'm');

            cout << "Выберите замену на (M - максимум, m - минимум): ";
            cin >> choice;
            bool replaceWithMax = (choice == 'M');

            dynamicArray.replaceDuplicates(byModulo, replaceWithMax); // Замена дубликатов
            cout << "Полученный ";
            dynamicArray.display(); // Вывод измененного массива

            // Выбор продолжения или выхода
            char continueChoice;
            cout << "\nХотите продолжить? (y - да, n - нет): ";
            cin >> continueChoice;
            if (continueChoice != 'y') {
                break; // Выход из цикла и завершение программы
            }
        }
    }
}