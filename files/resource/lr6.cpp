#include "lr6.h"

namespace lr6 {

    //  онструктор
    template <typename T>
    NumberArray<T>::NumberArray(T* arr, size_t size) : size(size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    // ƒеструктор
    template <typename T>
    NumberArray<T>::~NumberArray() {
        delete[] data; // ќсвобождаем пам€ть
    }

    // ћетод сортировки последовательностей
    template <typename T>
    void NumberArray<T>::Sort() {
        size_t start = 0;
        while (start < size) {
            size_t end = start;
            // Ќаходим последовательность, упор€доченную по возрастанию
            while (end < size - 1 && data[end] < data[end + 1]) {
                end++;
            }
            // ≈сли последовательность найдена, сортируем еЄ по убыванию
            if (end > start) {
                sort(data + start, data + end + 1, greater<T>());
            }
            start = end + 1; // ѕереходим к следующей последовательности
        }
    }

    // ћетод дл€ вывода массива
    template <typename T>
    void NumberArray<T>::print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // явна€ инстанциаци€ шаблона дл€ целых и вещественных чисел
    template class NumberArray<int>;
    template class NumberArray<double>;
}