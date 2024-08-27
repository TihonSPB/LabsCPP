// Шаблонная функция вывода данных в поток

#include <iostream>
#include <vector>

template<typename T>
void Print(const T& container, const std::string& delimiter) {
    bool isFirst = true;
    for (const auto& element : container) {
        if (!isFirst) {
            std::cout << delimiter;
        }
        std::cout << element;
        isFirst = false;
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> data = { 1, 2, 3 };
    Print(data, ", "); // на экране: 1, 2, 3

    return 0;
}