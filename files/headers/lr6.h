#pragma once

#include <iostream>
#include <algorithm>
#include <limits> // Для numeric_limits
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

using namespace std;

namespace lr6 {

    template <typename T>
    class NumberArray {
    public:
        NumberArray(T* arr, size_t size);
        ~NumberArray();

        void Sort();
        void print() const;

    private:
        T* data;      // Динамический массив
        size_t size;  // Размер массива
    };
    template <typename T>
    void fillArrayManually(T* arr, size_t size);
    void fillArrayRandomly(int* arr, size_t size);
    void fillDoubleArrayRandomly(double* arr, size_t size);
    template <typename T>
    bool validateArrayInput(T* arr, size_t size);
    void runDemo(); // Функция для демонстрации
}