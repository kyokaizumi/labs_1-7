#include "lr2.h"
#include <cstdlib> // ��� malloc � free

namespace lr2 {
    // ���������������� �������
    void runDemo() {
        setlocale(LC_ALL, "ru");
        srand(static_cast<unsigned int>(time(0))); // ������������� ���������� ��������� �����

        DoublyLinkedList list;
        string choice;
        int i = 1; // ������� ���������

        while (true) {
            cout << endl << i << " �������\n";
            cout << "������ �� �� ������� ������ ������� ��� �������������?\n(������� 'y' - ������� ��� 'n' - �������������, ��� ���������� ����� ������� 'end'): ";
            cin >> choice;

            if (choice == "end") {
                break; // ���������� �����
            }

            if (choice == "y") {
                int height, weight, age;
                cout << "����: ";
                cin >> height;
                cout << "���: ";
                cin >> weight;
                cout << "�������: ";
                cin >> age;
                list.addFirst(height, weight, age);
            }
            else if (choice == "n") {
                int height = rand() % 51 + 160; // ���� �� 160 �� 210
                int weight = rand() % 61 + 40;   // ��� �� 40 �� 100
                int age = rand() % 57 + 14;      // ������� �� 14 �� 70
                list.addFirst(height, weight, age);
                cout << "������������� ���������: ���� = " << height << ", ��� = " << weight << ", ������� = " << age << endl;
            }
            else {
                cout << "�������� ����. ����������, ���������� �����." << endl;
                continue; // ������������ � ������ �����
            }
            i += 1; // ����������� ������� ���������
        }

        cout << "\n������ � �������� �������:\n";
        list.showList();

        string crit;
        cout << "\n������� �������� ���������� (hwa - ���� + ��� + �������,\nhw - ���� + ���, ha - ���� + �������, wa - ��� + �������,\nh - ����, w - ���, a - �������): ";
        cin >> crit;
        list.sortingList(crit);

        cout << "\n������ ����� ���������� �� " << crit << ":\n";
        list.showList();
    }
}