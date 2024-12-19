#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace lr2 {
    void runDemo();
    struct Node {
        int height; // Рост
        int weight; // Вес
        int age;    // Возраст
        Node* next; // Указатель на следующий узел
        Node* prev; // Указатель на предыдущий узел
    };

    class DoublyLinkedList {
    private:
        Node* head; // Указатель на первый узел
        Node* tail; // Указатель на последний узел

    public:
        DoublyLinkedList(); // Конструктор
        ~DoublyLinkedList(); // Деструктор
        void addFirst(int height, int weight, int age); // Добавление узла в начало
        void addLast(int height, int weight, int age); // Добавление узла в конец
        void delHead(); // Удаление головы
        void delTail(); // Удаление хвоста
        void sortingList(const string& criteria); // Сортировка списка
        void showList() const; // Вывод списка
    };
}