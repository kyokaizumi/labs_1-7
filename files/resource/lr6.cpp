#include "lr6.h"

namespace lr6 {

    // �����������
    template <typename T>
    NumberArray<T>::NumberArray(T* arr, size_t size) : size(size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    // ����������
    template <typename T>
    NumberArray<T>::~NumberArray() {
        delete[] data; // ����������� ������
    }

    // ����� ���������� �������������������
    template <typename T>
    void NumberArray<T>::Sort() {
        size_t start = 0;
        while (start < size) {
            size_t end = start;
            // ������� ������������������, ������������� �� �����������
            while (end < size - 1 && data[end] < data[end + 1]) {
                end++;
            }
            // ���� ������������������ �������, ��������� � �� ��������
            if (end > start) {
                sort(data + start, data + end + 1, greater<T>());
            }
            start = end + 1; // ��������� � ��������� ������������������
        }
    }

    // ����� ��� ������ �������
    template <typename T>
    void NumberArray<T>::print() const {
        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // ����� ������������ ������� ��� ����� � ������������ �����
    template class NumberArray<int>;
    template class NumberArray<double>;
}