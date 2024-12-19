#pragma once
#include <iostream>
#include <limits>
using namespace std;

namespace lr3 {
    class DynamicArray {
    private:
        int* arr; // ��������� �� ������
        int size; // ������ �������

    public:
        DynamicArray(int N); // �����������
        ~DynamicArray(); // ����������
        void inputElements(); // ����� ��� ����� ���������
        void replaceDuplicates(bool byModulo, bool replaceWithMax); // ����� ��� ������ ����������
        void display() const; // ����� ��� ������ �������
    };

    void runDemo(); // ���������� ������� ��� ������������
}