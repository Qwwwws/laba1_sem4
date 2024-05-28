#include <iostream>

using namespace std;

class cashRegister {
private:
    int cashOnHand; // Наличные в кассе

public:  // Конструктор по умолчанию, устанавливающий начальное количество наличных в кассе равным 500
    cashRegister() {
        cashOnHand = 500;
    }
    // Конструктор, устанавливающий начальное количество наличных в кассе на указанную сумму
    cashRegister(int initialCash) { 
        cashOnHand = initialCash;
    }
    // Функция для получения текущего баланса кассы
    int getCurrentBalance() {
        return cashOnHand;
    }
    // Функция для принятия суммы, внесенной клиентом, и обновления суммы в кассе
    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
};
// Класс для представления диспенсера (раздатчика) продуктов
class dispenserType {
private:
    int numberOfItems; // Количество предметов в диспенсере
    int typeCost; // Стоимость одного предмета

public:
    dispenserType() { // Конструктор по умолчанию, устанавливающий количество предметов и стоимость по умолчанию
        numberOfItems = 50;
        typeCost = 50;
    }
    // Конструктор, устанавливающий количество предметов и стоимость на указанные значения
    dispenserType(int num, int cost) { 
        numberOfItems = num;
        typeCost = cost;
    }
    // Функция для получения количества предметов в диспенсере
    int getNoOfItems() {
        return numberOfItems;
    }
    // Функция для получения стоимости одного предмета
    int getCost() {
        return typeCost;
    }
    // Функция для совершения продажи (уменьшения количества предметов на 1)
    void makeSale() {
        numberOfItems--;
    }
};
// Функция для отображения меню выбора продуктов
void showSelection() {
    cout << "Available products:" << endl;
    cout << "1. Candy: $1" << endl;
    cout << "2. Chips: $2" << endl;
    cout << "3. Gum: $0.50" << endl;
    cout << "4. Cookie: $1.50" << endl;
}
// Функция для обработки продажи продукта
void sellProduct(dispenserType& dispenser, cashRegister& cashRegister) {
    int choice;
    int amount;

    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
    case 1: // Проверка наличия конфет в диспенсере
        if (dispenser.getNoOfItems() > 0) {
            cout << "Candy costs $1" << endl;
            cout << "Enter amount: ";
            cin >> amount;
            // Проверка того, достаточно ли у пользователя денег
            if (amount >= 1) {
                dispenser.makeSale();
                cashRegister.acceptAmount(amount); // Обновление суммы в кассе
                cout << "Candy dispensed" << endl; // Выдача конфеты
            }
            else {
                cout << "Insufficient funds" << endl;
            }
        }
        else {
            cout << "Candy is out of stock" << endl;
        }
        break;
        // Аналогичная логика для других продуктов
    case 2:
        if (dispenser.getNoOfItems() > 0) {
            cout << "Chips cost $2" << endl;
            cout << "Enter amount: ";
            cin >> amount;

            if (amount >= 2) {
                dispenser.makeSale();
                cashRegister.acceptAmount(amount);
                cout << "Chips dispensed" << endl;
            }
            else {
                cout << "Insufficient funds" << endl;
            }
        }
        else {
            cout << "Chips are out of stock" << endl;
        }
        break;

    case 3:
        if (dispenser.getNoOfItems() > 0) {
            cout << "Gum costs $0.50" << endl;
            cout << "Enter amount: ";
            cin >> amount;

            if (amount >= 0.5) {
                dispenser.makeSale();
                cashRegister.acceptAmount(amount);
                cout << "Gum dispensed" << endl;
            }
            else {
                cout << "Insufficient funds" << endl;
            }
        }
        else {
            cout << "Gum is out of stock" << endl;
        }
        break;

    case 4:
        if (dispenser.getNoOfItems() > 0) {
            cout << "Cookie costs $1.50" << endl;
            cout << "Enter amount: ";
            cin >> amount;

            if (amount >= 1.5) {
                dispenser.makeSale();
                cashRegister.acceptAmount(amount);
                cout << "Cookie dispensed" << endl;
            }
            else {
                cout << "Insufficient funds" << endl;
            }
        }
        else {
            cout << "Cookie is out of stock" << endl;
        }
        break;

    default:
        cout << "Invalid choice" << endl;
    }
}

int main() { // Создание экземпляров кассового аппарата и диспенсеров для каждого продукта
    cashRegister cash;
    dispenserType candy(50, 1);
    dispenserType chips(50, 2);
    dispenserType gum(50, 0.5);
    dispenserType cookie(50, 1.5);

    showSelection(); // Отображение меню выбора продуктов
    sellProduct(candy, cash);  // Обработка продажи конфеты

    return 0;
}
