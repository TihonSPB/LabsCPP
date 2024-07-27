// Запись текста в файл 
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    system("chcp 1251");

    string line;
    ofstream outFile("text.txt"); // Открываем файл для записи

    if (!outFile) {
        cout << "Не удалось открыть файл для записи." << endl;
        return 1;
    }

    cout << "Введите текст. Для завершения ввода введите пустую строку:" << endl;

    while (true) {
        getline(cin, line); // Считываем строку с клавиатуры
        if (line.empty()) {
            break; // Если строка пустая, завершаем ввод
        }
        outFile << line << endl; // Записываем строку в файл
    }

    outFile.close(); // Закрываем файл
    cout << "Текст успешно записан в файл text.txt." << endl;

    return 0;
}