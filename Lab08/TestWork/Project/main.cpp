//����� Time 

#include <iostream>
#include "time.h"

using namespace std;

int main() {

    system("chcp 1251");

    // ������� ��� ������������������ �������
    const Time time1(10, 30, 45);
    const Time time2(5, 70, 120);

    // ������� �������������������� ������
    Time time3;

    // ���������� ��� ������������������ ������� � ����������� ��������� �������� �������
    time3 = time1.add(time2);

    // ������� ���������
    cout << "����� 1: ";
    time1.displayTime();
    cout << "����� 2: ";
    time2.displayTime();
    cout << "����� 3 (����� ������� 1 � ������� 2): ";
    time3.displayTime();

    return 0;
}