#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace lr2 {
    void runDemo();
    struct Node {
        int height; // ����
        int weight; // ���
        int age;    // �������
        Node* next; // ��������� �� ��������� ����
        Node* prev; // ��������� �� ���������� ����
    };

    class DoublyLinkedList {
    private:
        Node* head; // ��������� �� ������ ����
        Node* tail; // ��������� �� ��������� ����

    public:
        DoublyLinkedList(); // �����������
        ~DoublyLinkedList(); // ����������
        void addFirst(int height, int weight, int age); // ���������� ���� � ������
        void addLast(int height, int weight, int age); // ���������� ���� � �����
        void delHead(); // �������� ������
        void delTail(); // �������� ������
        void sortingList(const string& criteria); // ���������� ������
        void showList() const; // ����� ������
    };
}