#include "lr2.h"
#include <cstdlib> // ��� malloc � free

namespace lr2 {
    // �����������
    DoublyLinkedList::DoublyLinkedList() {
        head = tail = nullptr;
    }

    // ����������
    DoublyLinkedList::~DoublyLinkedList() {
        while (head) {
            delHead(); // ������� ���� ���� �� ������
        }
    }

    // ���������� ���� � ������
    void DoublyLinkedList::addFirst(int height, int weight, int age) {
        Node* buf = (Node*)malloc(sizeof(Node)); // �������� ������ ��� ������ ����
        if (!buf) {
            cout << "������ ��������� ������!" << endl;
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
            tail = head; // ���� ��� ������ ����, �� ����� �����
        }
    }

    // ���������� ���� � �����
    void DoublyLinkedList::addLast(int height, int weight, int age) {
        Node* buf = (Node*)malloc(sizeof(Node)); // �������� ������ ��� ������ ����
        if (!buf) {
            cout << "������ ��������� ������!" << endl;
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
            head = tail; // ���� ��� ������ ����, �� ����� ������
        }
    }

    // �������� ������
    void DoublyLinkedList::delHead() {
        if (head) {
            Node* buf = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr; // ���� ������ ���� ������
            }
            free(buf); // ����������� ������
        }
        else {
            cout << "������ ����" << endl;
        }
    }

    // �������� ������
    void DoublyLinkedList::delTail() {
        if (tail) {
            Node* buf = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr; // ���� ������ ���� ������
            }
            free(buf); // ����������� ������
        }
        else {
            cout << "������ ����" << endl;
        }
    }

    // ���������� ������ �� ��������� ��������
    void DoublyLinkedList::sortingList(const string& criteria) {
        if (!head) return;

        // ���������� ���������
        for (Node* i = head; i; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                bool swapNeeded = false;

                // ���������� ���� �� ��������� ���������
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

                // ���� ����� ���������� �����
                if (swapNeeded) {
                    swap(i->height, j->height);
                    swap(i->weight, j->weight);
                    swap(i->age, j->age);
                }
            }
        }
    }

    // ����� ������
    void DoublyLinkedList::showList() const {
        if (head) {
            Node* buf = head;
            while (buf) {
                cout << "����: " << buf->height
                    << ",\t���: " << buf->weight
                    << ",\t�������: " << buf->age << endl;
                buf = buf->next;
            }
        }
        else {
            cout << "������ ����" << endl;
        }
    }
}