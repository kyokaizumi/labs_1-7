#include "lr1.h"

namespace lr1 {
    // �����������
    DATE::DATE(unsigned dd, month mm, unsigned yy) : dd(dd), mm(mm), yy(yy), format('.') {}

    // ����� ����
    void DATE::Print(char smb) {
        cout << dd << smb << mm << smb << yy << endl;
    }

    // ���������� ���������� ����
    DATE DATE::Prev() {
        if (dd > 1) {
            return DATE(dd - 1, mm, yy);
        }
        else {
            if (mm == jan) {
                return DATE(31, dek, yy - 1);
            }
            else {
                month prevMonth = static_cast<month>(mm - 1);
                unsigned prevDay = 31;
                switch (prevMonth) {
                case apr: case jun: case sep: case nov:
                    prevDay = 30;
                    break;
                case feb:
                    prevDay = (yy % 4 == 0) ? 29 : 28; // ���� ����������� ����
                    break;
                }
                return DATE(prevDay, prevMonth, yy);
            }
        }
    }

    // ������ ������
    void DATE::Setformat(char format) {
        this->format = format;
    }

    // ������� ������
    void DATE::getCF() {
        cout << format << endl;
    }

    // friend ����� ��� �������� ���� ���
    DATE operator+(const DATE& d1, const DATE& d2) {
        unsigned d = d1.dd + d2.dd; // ����� ����
        month m = static_cast<month>(d1.mm + d2.mm); // ����� �������
        unsigned y = d1.yy + d2.yy; // ����� �����

        // ������������ ������ � ����, ���� ����� ������� ������ 12
        if (m > dek) {
            y += (m - 1) / 12; // ����������� ��� �� ���������� ������ ���
            m = static_cast<month>((m - 1) % 12 + 1); // ������������ �����
        }

        // ��������� ������������ ���� � �������
        unsigned daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
            (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;

        while (d > daysInMonth) {
            d -= daysInMonth;
            m = static_cast<month>(static_cast<int>(m) + 1); // ����������� �����
            if (m > 12) {
                m = jan;
                y++;
            }
            daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
                (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;
        }
        return DATE(d, m, y);
    }
}