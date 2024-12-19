#include "lr5.h"

namespace lr5 {

    // ���������� �������
    DATE::DATE(unsigned dd, month mm, unsigned yy) : dd(dd), mm(mm), yy(yy), format('.') {}

    void DATE::Print() const {
        cout << dd << format << static_cast<int>(mm) << format << yy << endl;
    }

    void DATE::Print(char smb) {
        cout << dd << smb << static_cast<int>(mm) << smb << yy << endl;
    }

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

    DATE DATE::Prev(unsigned daysBack) {
        DATE currentDate = *this; // �������� ������� ����
        for (unsigned i = 0; i < daysBack; ++i) {
            currentDate = currentDate.Prev(); // �������� ������������ ����� Prev
        }
        return currentDate; // ���������� ����, ������� �� daysBack ���� ������
    }

    void DATE::Setformat(char format) {
        this->format = format;
    }

    DATE operator+(const DATE& d1, const DATE& d2) {
        unsigned d = d1.dd + d2.dd; // ����� ����
        month m = static_cast<month>(d1.mm + d2.mm); // ����� �������
        unsigned y = d1.yy + d2.yy; // ����� �����

        if (m > dek) {
            y += (m - 1) / 12; // ����������� ��� �� ���������� ������ ���
            m = static_cast<month>((m - 1) % 12 + 1); // ������������ �����
        }

        unsigned daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
            (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;

        while (d > daysInMonth) {
            d -= daysInMonth;
            m = static_cast<month>(static_cast<int>(m) + 1);
            if (m > 12) {
                m = jan;
                y++;
            }
            daysInMonth = (m == feb) ? ((y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) ? 29 : 28) :
                (m == apr || m == jun || m == sep || m == nov) ? 30 : 31;
        }
        return DATE(d, m, y);
    }

    bool operator==(const DATE& d1, const DATE& d2) {
        return (d1.dd == d2.dd && d1.mm == d2.mm && d1.yy == d2.yy);
    }

    DATE::DATE(const DATE& other) : dd(other.dd), mm(other.mm), yy(other.yy), format(other.format) {}

    DATE::DATE(DATE&& other) noexcept : dd(other.dd), mm(other.mm), yy(other.yy), format(other.format) {
        other.dd = 0;
        other.mm = jan;
        other.yy = 0;
    }

    DATE& DATE::operator=(const DATE& other) {
        if (this != &other) {
            dd = other.dd;
            mm = other.mm;
            yy = other.yy;
            format = other.format;
        }
        return *this;
    }

    DATE& DATE::operator=(DATE&& other) noexcept {
        if (this != &other) {
            dd = other.dd;
            mm = other.mm;
            yy = other.yy;
            format = other.format;
            other.dd = 0;
            other.mm = jan;
            other.yy = 0;
        }
        return *this;
    }

    ostream& operator<<(ostream& os, const DATE& date) {
        os << date.dd << date.format << static_cast<int>(date.mm) << date.format << date.yy;
        return os;
    }

    istream& operator>>(istream& is, DATE& date) {
        char format1, format2;
        unsigned monthInput;
        // ������ ����, ����� � ���
        is >> date.dd >> format1 >> monthInput >> format2 >> date.yy;
        // �������� ����� � ���� enum
        if (monthInput < 1 || monthInput > 12) {
            cerr << "������: �������� �����!" << endl;
            is.setstate(ios::failbit); // ������������� ���� ������
            return is;
        }
        date.mm = static_cast<month>(monthInput); // ���������� � ���� month
        date.format = format1; // ������������� ������
        return is;
    }

    string DATE::operator()() const {
        return to_string(dd) + format + to_string(static_cast<int>(mm)) + format + to_string(yy);
    }
}