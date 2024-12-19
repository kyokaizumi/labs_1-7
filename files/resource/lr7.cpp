#include "lr7.h"

namespace lr7 {

    tuple<float, int, float, char, char> DataProcessor::Get() {
        float f1, f2;
        int i;
        char c1, c2;

        cout << "Ввод f2, i, f1, c1, c2: ";
        cin >> f2 >> i >> f1 >> c1 >> c2;

        return make_tuple(f2, i, f1, c1, c2);
    }

    void DataProcessor::print(const tuple<float, int, float, char, char>& data, ofstream& outfile, const Manip& manip) {
        float f2 = get<0>(data);
        int i = get<1>(data);
        float f1 = get<2>(data);
        char c1 = get<3>(data);
        char c2 = get<4>(data);

        // Запись заголовка в файл
        outfile << "Введённые данные: ";
        manip.apply(outfile);
        outfile << f2 << " " << i << " " << f1 << " " << c1 << " " << c2 << "\n";

        string output;

        if (manip.getBase() == 10) {
            output = "c2: " + string(1, c2) +
                "\nc1: " + string(1, c1) +
                "\nf2 (formatted): " + formatOutput(to_string(f2), manip.getWidth(), manip.getFill()) +
                "\ni (formatted): " + formatOutput(to_string(i), manip.getWidth(), manip.getFill()) +
                "\nf1 (formatted): " + formatOutput(to_string(f1), manip.getWidth(), manip.getFill()) + "\n\n";
        }
        else if (manip.getBase() == 16) {
            output = "c2: " + string(1, c2) +
                "\nc1: " + string(1, c1) +
                "\nf2 (hex decimals): " + formatOutput(decimalToHexWithDecimals(f2, manip.getPrecision()), manip.getWidth(), manip.getFill()) +
                "\ni (hex): " + formatOutput(decimalToHex(i), manip.getWidth(), manip.getFill()) +
                "\nf1 (hex decimals): " + formatOutput(decimalToHexWithDecimals(f1, manip.getPrecision()), manip.getWidth(), manip.getFill()) + "\n\n";
        }

        // Выводим результат в консоль и в файл
        cout << output;
        outfile << output;
    }

    string DataProcessor::decimalToHex(int decimal) {
        stringstream hexStream;
        hexStream << hex << uppercase << decimal;
        return hexStream.str();
    }

    string DataProcessor::decimalToHexWithDecimals(float decimal, int decimalPlaces) {
        int integerPart = static_cast<int>(decimal);
        float fractionalPart = decimal - integerPart;
        stringstream hexStream;
        hexStream << hex << uppercase << integerPart;

        hexStream << ".";
        for (int i = 0; i < decimalPlaces; ++i) {
            fractionalPart *= 16;
            int fractionalInt = static_cast<int>(fractionalPart);
            hexStream << hex << uppercase << fractionalInt;
            fractionalPart -= fractionalInt;
            if (fractionalPart == 0.0f) {
                for (int j = i + 1; j < decimalPlaces; ++j) {
                    hexStream << "0";
                }
                break;
            }
        }
        return hexStream.str();
    }

    string DataProcessor::hexUpper(int value) {
        stringstream hexStream;
        hexStream << hex << uppercase << value;
        return hexStream.str();
    }

    string DataProcessor::formatOutput(const string& value, int width, char fill) {
        stringstream formatted;
        if (value.length() < width) {
            int starsNeeded = width - value.length();
            formatted << string(starsNeeded, fill) << value;
        }
        else {
            formatted << value;
        }
        return formatted.str();
    }

    string DataProcessor::formatOutput(int value, int width, char fill) {
        stringstream formatted;
        formatted << hex << uppercase << value;
        string hexString = formatted.str();

        // Проверяем, нужно ли добавлять недостающие символы
        if (hexString.length() < width) {
            int starsNeeded = width - hexString.length();
            return formatOutput(hexString, width, fill);
        }

        return hexString;
    }
}