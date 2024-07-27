// Передача параметров в программу

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {

    system("chcp 1251");

    // Проверка количества параметров
    if (argc != 4) {
        cerr << "Ошибка: неверное количество параметров." << endl;
        cerr << "Использование: " << argv[0] << " -a|-m число1 число2" << endl;
        return 1;
    }

    // Проверка формата параметра-флага
    if (strncmp(argv[1], "-a", 2) != 0 && strncmp(argv[1], "-m", 2) != 0) {
        cerr << "Ошибка: неверный формат параметра-флага." << endl;
        cerr << "Использование: " << argv[0] << " -a|-m число1 число2" << endl;
        return 1;
    }

    // Преобразование строк в целые числа
    int num1 = atoi(argv[2]);
    int num2 = atoi(argv[3]);

    // Выполнение операции в зависимости от параметра-флага
    if (strncmp(argv[1], "-a", 2) == 0) {
        cout << "Сумма: " << num1 + num2 << endl;
    }
    else if (strncmp(argv[1], "-m", 2) == 0) {
        cout << "Произведение: " << num1 * num2 << endl;
    }

    return 0;
}