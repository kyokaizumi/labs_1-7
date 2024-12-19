#include "lr2.h"
#include <cstdlib> // Для malloc и free

namespace lr2 {
    // Конструктор
    DoublyLinkedList::DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Деструктор
    DoublyLinkedList::~DoublyLinkedList() {
        while (head) {
            delHead(); // Удаляем узлы один за другим
        }
    }

    // Добавление узла в начало
    void DoublyLinkedList::addFirst(int height, int weight, int age) {
        Node* buf = (Node*)malloc(sizeof(Node)); // Выделяем память для нового узла
        if (!buf) {
            cout << "Ошибка выделения памяти!" << endl;
            return;
        }

        buf->height = height;
        buf->weight = weight;
        buf->age = age;
        buf->next = head;
        buf->prev = nullptr;

        if (head) {
            head->prev = buf;
        }
        head = buf;

        if (!tail) {
            tail = head; // Если это первый узел, он также хвост
        }
    }

    // Добавление узла в конец
    void DoublyLinkedList::addLast(int height, int weight, int age) {
        Node* buf = (Node*)malloc(sizeof(Node)); // Выделяем память для нового узла
        if (!buf) {
            cout << "Ошибка выделения памяти!" << endl;
            return;
        }

        buf->height = height;
        buf->weight = weight;
        buf->age = age;
        buf->next = nullptr;
        buf->prev = tail;

        if (tail) {
            tail->next = buf;
        }
        tail = buf;

        if (!head) {
            head = tail; // Если это первый узел, он также голова
        }
    }

    // Удаление головы
    void DoublyLinkedList::delHead() {
        if (head) {
            Node* buf = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr; // Если список стал пустым
            }
            free(buf); // Освобождаем память
        }
        else {
            cout << "Список пуст" << endl;
        }
    }

    // Удаление хвоста
    void DoublyLinkedList::delTail() {
        if (tail) {
            Node* buf = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr; // Если список стал пустым
            }
            free(buf); // Освобождаем память
        }
        else {
            cout << "Список пуст" << endl;
        }
    }

    // Сортировка списка по заданному критерию
    void DoublyLinkedList::sortingList(const string& criteria) {
        if (!head) return;

        // Сортировка пузырьком
        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                bool swapNeeded = false;

                // Сравниваем узлы по указанным критериям
                if (criteria == "ha") {
                    int sumI = i->height + i->age;
                    int sumJ = j->height + j->age;
                    swapNeeded = (sumI > sumJ);
                }
                else if (criteria == "hw") {
                    int sumI = i->height + i->weight;
                    int sumJ = j->height + j->weight;
                    swapNeeded = (sumI > sumJ);
                }
                else if (criteria == "wa") {
                    int sumI = i->weight + i->age;
                    int sumJ = j->weight + j->age;
                    swapNeeded = (sumI > sumJ);
                }
                else if (criteria == "hwa") {
                    int sumI = i->height + i->weight + i->age;
                    int sumJ = j->height + j->weight + j->age;
                    swapNeeded = (sumI > sumJ);
                }
                else {
                    if (criteria == "h") {
                        swapNeeded = (i->height > j->height);
                    }
                    else if (criteria == "w") {
                        swapNeeded = (i->weight > j->weight);
                    }
                    else if (criteria == "a") {
                        swapNeeded = (i->age > j->age);
                    }
                }

                // Если нужно произвести обмен
                if (swapNeeded) {
                    swap(i->height, j->height);
                    swap(i->weight, j->weight);
                    swap(i->age, j->age);
                }
            }
        }
    }

    // Вывод списка
    void DoublyLinkedList::showList() const {
        if (head) {
            Node* buf = head;
            while (buf) {
                cout << "Рост: " << buf->height
                    << ",\tВес: " << buf->weight
                    << ",\tВозраст: " << buf->age << endl;
                buf = buf->next;
            }
        }
        else {
            cout << "Список пуст" << endl;
        }
    }
}