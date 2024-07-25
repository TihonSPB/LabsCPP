

#include <iostream>
using namespace std;

int main()
{
    system("chcp 1251");

    char op;
    cout << "Сделай свой выбор, собери авто свой мечты: ";
    cin >> op;
    /*
    switch (op)
    {
    case 'S':
        cout << "Радио играть должно\n";
        cout << "Колеса круглые\n";
        cout << "Мощный двигатель\n";
        break;
    case 'V':
        cout << "Кондиционер хочу\n";        
        cout << "Радио играть должно\n";
        cout << "Колеса круглые\n";
        cout << "Мощный двигатель\n";
        break;
    default:
        cout << "Колеса круглые\n";
        cout << "Мощный двигатель\n";
    }
    */
    switch (op)
    {
    case 'V':
        cout << "Кондиционер хочу\n";
    case 'S':
        cout << "Радио играть должно\n";
    default:
        cout << "Колеса круглые\n";
        cout << "Мощный двигатель\n";
    }
}
