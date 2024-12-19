#include "lr3.h"
namespace lr3 {
    // ������� ��� ������������
    void runDemo() {
        setlocale(LC_ALL, "ru");

        while (true) {
            int N;
            cout << "\n������� ���������� ���������: ";
            cin >> N;
            DynamicArray dynamicArray(N); // �������� ������� ������
            dynamicArray.inputElements(); // ���� ���������

            // ����� ���������� ������
            char choice;
            cout << "�������� ������ ������ ���������� (m - �� ������, v - �� ��������): ";
            cin >> choice;
            bool byModulo = (choice == 'm');

            cout << "�������� ������ �� (M - ��������, m - �������): ";
            cin >> choice;
            bool replaceWithMax = (choice == 'M');

            dynamicArray.replaceDuplicates(byModulo, replaceWithMax); // ������ ����������
            cout << "���������� ";
            dynamicArray.display(); // ����� ����������� �������

            // ����� ����������� ��� ������
            char continueChoice;
            cout << "\n������ ����������? (y - ��, n - ���): ";
            cin >> continueChoice;
            if (continueChoice != 'y') {
                break; // ����� �� ����� � ���������� ���������
            }
        }
    }
}