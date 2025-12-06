// Base64Project.cpp (главный файл с тестами)
#include <iostream>
#include <string>
#include "base64_decode.h"
#include "ascii_table.h"

int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "=== ЛАБОРАТОРНАЯ РАБОТА №4 ===\n";
    std::cout << "=== Декодирование Base64 ===\n\n";

    // КОНТРОЛЬНЫЕ ЗАДАНИЯ ИЗ ЛАБОРАТОРНОЙ
    std::cout << "=== Контрольные задания (стр. 7) ===\n\n";

    // Задание 4: Раскодировать Pt54
    std::cout << "4. Раскодировать 'Pt54':\n";
    std::string result1 = base64_decode("Pt54");
    std::cout << "   Результат: " << result1 << "\n";
    std::cout << "   ASCII коды: ";
    for (char c : result1) std::cout << (int)c << " ";
    std::cout << "\n";
    std::cout << "   Символы: ";
    for (char c : result1) {
        if (c >= 32 && c <= 126) std::cout << c << " ";
        else std::cout << "? ";
    }
    std::cout << "\n\n";

    // Задание 5: Раскодировать Rj0v
    std::cout << "5. Раскодировать 'Rj0v':\n";
    std::string result2 = base64_decode("Rj0v");
    std::cout << "   Результат: " << result2 << "\n";
    std::cout << "   ASCII коды: ";
    for (char c : result2) std::cout << (int)c << " ";
    std::cout << "\n";
    std::cout << "   Символы: ";
    for (char c : result2) {
        if (c >= 32 && c <= 126) std::cout << c << " ";
        else std::cout << "? ";
    }
    std::cout << "\n\n";

    // Задание 6: Раскодировать zbTM
    std::cout << "6. Раскодировать 'zbTM':\n";
    std::string result3 = base64_decode("zbTM");
    std::cout << "   Результат: " << result3 << "\n";
    std::cout << "   ASCII коды: ";
    for (char c : result3) std::cout << (int)c << " ";
    std::cout << "\n";
    std::cout << "   Символы: ";
    for (char c : result3) {
        if (c >= 32 && c <= 126) std::cout << c << " ";
        else std::cout << "? ";
    }
    std::cout << "\n\n";

    // ДОПОЛНИТЕЛЬНЫЕ ТЕСТЫ
    std::cout << "=== Дополнительные тесты ===\n\n";

    // Тест с padding (из методички)
    std::cout << "Тест с padding:\n";
    std::cout << "   'QWJ=' -> '" << base64_decode("QWJ=") << "' (должно быть 'Ab')\n";
    std::cout << "   'QW==' -> '" << base64_decode("QW==") << "' (должно быть 'A')\n";
    std::cout << "   'QWJm' -> '" << base64_decode("QWJm") << "' (должно быть 'Abf')\n\n";

    // Тест из методички (раздел 4.3.3)
    std::cout << "Тест из методички (стр. 2-3):\n";
    std::cout << "   'Abf' в Base64 должно быть 'QWJm'\n";
    std::cout << "   Декодируем 'QWJm': " << base64_decode("QWJm") << "\n\n";

    // ПРОВЕРКА ASCII ТАБЛИЦЫ
    std::cout << "=== Проверка ASCII таблицы ===\n";
    std::cout << "Коды из первого результата (" << result1 << "):\n";
    for (char c : result1) {
        print_ascii_char(static_cast<int>(c));
    }

    std::cout << "\n=== РЕЗУЛЬТАТЫ ДЛЯ ОТЧЕТА ===\n";
    std::cout << "4. Pt54 -> " << result1 << "\n";
    std::cout << "5. Rj0v -> " << result2 << "\n";
    std::cout << "6. zbTM -> " << result3 << "\n";

    std::cout << "\nНажмите Enter для выхода...";
    std::cin.get();

    return 0;
}