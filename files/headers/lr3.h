#pragma once
#include <iostream>
#include <limits>
using namespace std;

namespace lr3 {
    class DynamicArray {
    private:
        int* arr; // Указатель на массив
        int size; // Размер массива

    public:
        DynamicArray(int N); // Конструктор
        ~DynamicArray(); // Деструктор
        void inputElements(); // Метод для ввода элементов
        void replaceDuplicates(bool byModulo, bool replaceWithMax); // Метод для замены дубликатов
        void display() const; // Метод для вывода массива
    };

    void runDemo(); // Объявление функции для демонстрации
}