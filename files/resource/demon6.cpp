#include "lr6.h"

namespace lr6 {

    // Функции для заполнения массива
    template <typename T>
    void fillArrayManually(T* arr, size_t size) {
        cout << "Введите " << size << " чисел:" << endl;
        for (size_t i = 0; i < size; ++i) {
            cin >> arr[i];
        }
    }

    void fillArrayRandomly(int* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = rand() % 100; // Генерируем случайное число от 0 до 99
        }
    }

    void fillDoubleArrayRandomly(double* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = static_cast<double>(rand()) / RAND_MAX * 100.0; // Генерируем случайное число от 0.0 до 100.0
        }
    }

    // Функция для проверки типа элементов массива
    template <typename T>
    bool validateArrayInput(T* arr, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            if (cin.fail()) {
                cin.clear(); // Очистка состояния потока
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем неверный ввод
                return false; // Возвращаем false, если ввод не соответствует типу
            }
        }
        return true; // Все элементы корректны
    }
    // Функция для демонстрации
    void runDemo() {
        setlocale(LC_ALL, "ru");
        srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
        while (true) {
            int choice;
            cout << "\nМеню:" << endl;
            cout << "1) Создать массив целых чисел" << endl;
            cout << "2) Создать массив вещественных чисел" << endl;
            cout << "0) Выход" << endl;
            cout << "Выберите опцию (0, 1 или 2): ";
            cin >> choice;

            switch (choice) {
            case 1: {
                size_t intSize;
                cout << "Введите размер массива целых чисел: ";
                cin >> intSize;

                int* intArray = new int[intSize];
                int fillChoice;

                cout << "Выберите способ заполнения массива:" << endl;
                cout << "1) Вручную" << endl;
                cout << "2) Случайно" << endl;
                cin >> fillChoice;

                if (fillChoice == 1) {
                    while (true) {
                        fillArrayManually(intArray, intSize);
                        if (validateArrayInput(intArray, intSize)) {
                            break; // Ввод корректен, выходим из цикла
                        }
                        else {
                            cout << "Некорректный ввод. Пожалуйста, введите массив заново." << endl;
                        }
                    }
                }
                else {
                    fillArrayRandomly(intArray, intSize);
                }

                NumberArray<int> intNumbers(intArray, intSize);
                cout << "Исходный массив целых чисел: ";
                intNumbers.print();

                intNumbers.Sort();
                cout << "Отсортированный массив целых чисел: ";
                intNumbers.print();

                delete[] intArray; // Освобождаем память
                break;
            }
            case 2: {
                size_t doubleSize;
                cout << "Введите размер массива вещественных чисел: ";
                cin >> doubleSize;

                double* doubleArray = new double[doubleSize];
                int fillChoice;

                cout << "Выберите способ заполнения массива:" << endl;
                cout << "1) Вручную" << endl;
                cout << "2) Случайно" << endl;
                cin >> fillChoice;

                if (fillChoice == 1) {
                    while (true) {
                        fillArrayManually(doubleArray, doubleSize);
                        if (validateArrayInput(doubleArray, doubleSize)) {
                            break; // Ввод корректен, выходим из цикла
                        }
                        else {
                            cout << "Некорректный ввод. Пожалуйста, введите массив заново." << endl;
                        }
                    }
                }
                else {
                    fillDoubleArrayRandomly(doubleArray, doubleSize);
                }

                NumberArray<double> doubleNumbers(doubleArray, doubleSize);
                cout << "Исходный массив вещественных чисел: ";
                doubleNumbers.print();

                doubleNumbers.Sort();
                cout << "Отсортированный массив вещественных чисел: ";
                doubleNumbers.print();

                delete[] doubleArray; // Освобождаем память
                break;
            }
            case 0:
                cout << "Выход из программы." << endl;
                return; // Завершение программы
            default:
                cout << "Неверный выбор! Пожалуйста, попробуйте снова." << endl;
                break;
            }
        }
    }

}