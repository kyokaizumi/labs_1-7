#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace lr5 {

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };
    class DATE {
    public:
        DATE(unsigned dd, month mm, unsigned yy);
        void Print() const; // ������������� ����� Print ��� ����������
        void Print(char smb);
        DATE Prev();
        DATE Prev(unsigned daysBack); // ����� Prev �� ��������� ���� �����
        void Setformat(char format);
        friend DATE operator+(const DATE& d1, const DATE& d2); // �������� ���� ���
        friend bool operator==(const DATE& d1, const DATE& d2); // �������� ���������

        DATE(const DATE& other); // ����������� �����������
        DATE(DATE&& other) noexcept; // ����������� �����������
        DATE& operator=(const DATE& other); // �������� ������������
        DATE& operator=(DATE&& other) noexcept; // �������� ������������ �� �����������
        friend ostream& operator<<(ostream& os, const DATE& date); // �������� ������
        friend istream& operator>>(istream& is, DATE& date); // �������� �����
        string operator()() const; // ���������� ��������� ()
    private:
        unsigned dd;
        month mm;
        unsigned yy;
        char format;
    };

    void runDemo(); // ������� ��� ������������

}