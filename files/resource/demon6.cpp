#include "lr6.h"

namespace lr6 {

    // ������� ��� ���������� �������
    template <typename T>
    void fillArrayManually(T* arr, size_t size) {
        cout << "������� " << size << " �����:" << endl;
        for (size_t i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    void fillArrayRandomly(int* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = rand() % 100; // ���������� ��������� ����� �� 0 �� 99
        }
    }

    void fillDoubleArrayRandomly(double* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = static_cast<double>(rand()) / RAND_MAX * 100.0; // ���������� ��������� ����� �� 0.0 �� 100.0
        }
    }

    // ������� ��� �������� ���� ��������� �������
    template <typename T>
    bool validateArrayInput(T* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            if (cin.fail()) {
                cin.clear(); // ������� ��������� ������
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ���������� �������� ����
                return false; // ���������� false, ���� ���� �� ������������� ����
            }
        }
        return true; // ��� �������� ���������
    }
    // ������� ��� ������������
    void runDemo() {
        setlocale(LC_ALL, "ru");
        srand(static_cast<unsigned int>(time(0))); // ������������� ���������� ��������� �����
        while (true) {
            int choice;
            cout << "\n����:" << endl;
            cout << "1) ������� ������ ����� �����" << endl;
            cout << "2) ������� ������ ������������ �����" << endl;
            cout << "0) �����" << endl;
            cout << "�������� ����� (0, 1 ��� 2): ";
            cin >> choice;

            switch (choice) {
            case 1: {
                size_t intSize;
                cout << "������� ������ ������� ����� �����: ";
                cin >> intSize;

                int* intArray = new int[intSize];
                int fillChoice;

                cout << "�������� ������ ���������� �������:" << endl;
                cout << "1) �������" << endl;
                cout << "2) ��������" << endl;
                cin >> fillChoice;

                if (fillChoice == 1) {
                    while (true) {
                        fillArrayManually(intArray, intSize);
                        if (validateArrayInput(intArray, intSize)) {
                            break; // ���� ���������, ������� �� �����
                        }
                        else {
                            cout << "������������ ����. ����������, ������� ������ ������." << endl;
                        }
                    }
                }
                else {
                    fillArrayRandomly(intArray, intSize);
                }

                NumberArray<int> intNumbers(intArray, intSize);
                cout << "�������� ������ ����� �����: ";
                intNumbers.print();

                intNumbers.Sort();
                cout << "��������������� ������ ����� �����: ";
                intNumbers.print();

                delete[] intArray; // ����������� ������
                break;
            }
            case 2: {
                size_t doubleSize;
                cout << "������� ������ ������� ������������ �����: ";
                cin >> doubleSize;

                double* doubleArray = new double[doubleSize];
                int fillChoice;

                cout << "�������� ������ ���������� �������:" << endl;
                cout << "1) �������" << endl;
                cout << "2) ��������" << endl;
                cin >> fillChoice;

                if (fillChoice == 1) {
                    while (true) {
                        fillArrayManually(doubleArray, doubleSize);
                        if (validateArrayInput(doubleArray, doubleSize)) {
                            break; // ���� ���������, ������� �� �����
                        }
                        else {
                            cout << "������������ ����. ����������, ������� ������ ������." << endl;
                        }
                    }
                }
                else {
                    fillDoubleArrayRandomly(doubleArray, doubleSize);
                }

                NumberArray<double> doubleNumbers(doubleArray, doubleSize);
                cout << "�������� ������ ������������ �����: ";
                doubleNumbers.print();

                doubleNumbers.Sort();
                cout << "��������������� ������ ������������ �����: ";
                doubleNumbers.print();

                delete[] doubleArray; // ����������� ������
                break;
            }
            case 0:
                cout << "����� �� ���������." << endl;
                return; // ���������� ���������
            default:
                cout << "�������� �����! ����������, ���������� �����." << endl;
                break;
            }
        }
    }

}