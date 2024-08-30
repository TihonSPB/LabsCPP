// Использование STL
// Организация хранения данных в контейнере

#include <iostream>
#include <map>
#include <string>

using namespace std;

// Структура для хранения данных о студенте и его оценке
struct StudentGrade {
    string name;
    char grade;
};

// Функция для ввода данных о студенте в map
void addStudent(map<string, char>& sGrades) {
    
    StudentGrade student; // Создание экземпляра структуры
   
    cout << "Введите имя студента: ";
    cin >> student.name;

    // Проверка ввода оценки
    while (true) {
        cout << "Введите оценку студента (A, B, C, D, F или 1-5): ";
        cin >> student.grade;
        if (student.grade >= 'A' && student.grade <= 'F' || student.grade >= '1' && student.grade <= '5') {
            break;
        }
        else {
            cout << "Некорректная оценка. Попробуйте снова." << endl;
        }
    }
    // Добавление студента и оценки в map
    sGrades[student.name] = student.grade;
}

// Функция для вывода данных из map
void printGrades(const map<string, char>& sGrades) {
    cout << "Оценки студентов:" << endl;
    for (const auto& pair : sGrades) {
        cout << "Имя: " << pair.first << ", Оценка: " << pair.second << endl;
    }
}

// Функция для поиска оценки студента по имени
void findGrade(const map<string, char>& sGrades) {

    string searchName;
    cout << "Введите имя студента для поиска оценки: ";
    cin >> searchName;
    auto it = sGrades.find(searchName);
    if (it != sGrades.end()) {
        cout << "Оценка студента " << searchName << ": " << it->second << endl;
    }
    else {
        cout << "Студент с именем " << searchName << " не найден." << endl;
    }
}

int main() {

    system("chcp 1251");

    // Контейнер map для хранения пар "имя студента - оценка"
    map<string, char> studentGrades;

    while (true) {
        cout << "\nВыберите действие:\n";
        cout << "1. Добавить студента и оценку\n";
        cout << "2. Вывести оценки студентов\n";
        cout << "3. Найти оценку студента\n";
        cout << "4. Выйти из программы\n";
        cout << "Введите номер действия: ";

        int choice;
        cin >> choice;
        cout << "\n";

        // Проверка на ошибку ввода
        if (cin.fail()) {
            cin.clear(); // Очистка флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера ввода
            cout << "Неверный ввод. Пожалуйста, введите число.\n";
            continue;
        }

        switch (choice) {
        case 1:
            addStudent(studentGrades);
            break;
        case 2:
            printGrades(studentGrades);
            break;
        case 3:
            findGrade(studentGrades);
            break;
        case 4:
            cout << "Выход из программы.\n";
            return 0;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }        
    }    
    return 0;
}