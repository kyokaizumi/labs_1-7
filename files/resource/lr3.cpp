#include "lr3.h"
#include <cstdlib> // Для malloc и free

namespace lr3 {
    // Конструктор
    DynamicArray::DynamicArray(int N) {
        size = N;
        arr = new int[size]; // Выделение памяти
    }

    // Деструктор
    DynamicArray::~DynamicArray() {
        delete[] arr; // Освобождение памяти
        arr = nullptr; // Обнуление указателя
    }

    // Метод для ввода элементов
    void DynamicArray::inputElements() {
        cout << "Введите элементы массива:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    // Метод для замены дубликатов
    void DynamicArray::replaceDuplicates(bool byModulo, bool replaceWithMax) {
        int extremeElement = replaceWithMax ? arr[0] : std::numeric_limits<int>::max();

        // Поиск максимального или минимального элемента
        for (int i = 0; i < size; ++i) {
            if (replaceWithMax) {
                if (arr[i] > extremeElement) {
                    extremeElement = arr[i];
                }
            }
            else {
                if (arr[i] < extremeElement) {
                    extremeElement = arr[i];
                }
            }
        }

        // Замена совпадающих значений
        for (int i = 0; i < size; ++i) {
            int k = 0;
            for (int j = 0; j < size; ++j) {
                if (i != j) {
                    bool isDuplicate = byModulo ? (abs(arr[i]) == abs(arr[j])) : (arr[i] == arr[j]);
                    if (isDuplicate) {
                        arr[j] = extremeElement; // Замена дубликата
                        k += 1;
                    }
                }
            }
            if (k > 0) arr[i] = extremeElement;
        }
    }

    // Метод для вывода массива
    void DynamicArray::display() const {
        cout << "Массив:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}