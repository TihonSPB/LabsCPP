// Размен монет 

#include <iostream>

int main() {

    system("chcp 1251");

    int amount;
    std::cout << "Введите сумму: ";
    std::cin >> amount;

    // Номиналы монет в порядке убывания
    int coins[] = { 10, 5, 2, 1 };
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    std::cout << "Для суммы " << amount << " рублей нужно выдать:" << std::endl;

    for (int i = 0; i < numCoins; ++i) {
        int coin = coins[i];
        int count = amount / coin;
        if (count > 0) {
            std::cout << count << " монет(ы) номиналом " << coin << " руб." << std::endl;
            amount -= count * coin;
        }
    }

    return 0;
}