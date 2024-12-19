#include "lr3.h"
#include <cstdlib> // ��� malloc � free

namespace lr3 {
    // �����������
    DynamicArray::DynamicArray(int N) {
        size = N;
        arr = new int[size]; // ��������� ������
    }

    // ����������
    DynamicArray::~DynamicArray() {
        delete[] arr; // ������������ ������
        arr = nullptr; // ��������� ���������
    }

    // ����� ��� ����� ���������
    void DynamicArray::inputElements() {
        cout << "������� �������� �������:" << endl;
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    // ����� ��� ������ ����������
    void DynamicArray::replaceDuplicates(bool byModulo, bool replaceWithMax) {
        int extremeElement = replaceWithMax ? arr[0] : std::numeric_limits<int>::max();

        // ����� ������������� ��� ������������ ��������
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

        // ������ ����������� ��������
        for (int i = 0; i < size; ++i) {
            int k = 0;
            for (int j = 0; j < size; ++j) {
                if (i != j) {
                    bool isDuplicate = byModulo ? (abs(arr[i]) == abs(arr[j])) : (arr[i] == arr[j]);
                    if (isDuplicate) {
                        arr[j] = extremeElement; // ������ ���������
                        k += 1;
                    }
                }
            }
            if (k > 0) arr[i] = extremeElement;
        }
    }

    // ����� ��� ������ �������
    void DynamicArray::display() const {
        cout << "������:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}