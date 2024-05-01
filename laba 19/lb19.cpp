#include <iostream>
#include <list>
#include <string>
#include <algorithm>

// Структура для хранения информации об игрушке
struct Toy {
    std::string name;
    double cost;
};

int main() {
    // Создаем список для хранения игрушек
    std::list<Toy> toyList;

    // Запрашиваем количество игрушек
    int n;
    std::cout << "Введите количество игрушек: ";
    std::cin >> n;

    // Вводим информацию об игрушках и добавляем их в список
    for (int i = 0; i < n; i++) {
        Toy newToy;
        std::cout << "Введите название игрушки: ";
        std::cin >> newToy.name;
        std::cout << "Введите стоимость игрушки: ";
        std::cin >> newToy.cost;
        toyList.push_back(newToy);
    }

    // Выводим список всех игрушек
    std::cout << "Список игрушек:\n";
    for (const auto& toy : toyList) {
        std::cout << "Название: " << toy.name << ", Стоимость: " << toy.cost << std::endl;
    }

    // Запрашиваем название игрушки для поиска
    std::string searchName;
    std::cout << "Введите название игрушки для поиска: ";
    std::cin >> searchName;

    // Ищем игрушку по названию и выводим ее информацию
    auto it = toyList.begin();
    while (it != toyList.end()) {
        if (it->name == searchName) {
            std::cout << "Название: " << it->name << ", Стоимость: " << it->cost << std::endl;
            break;
        }
        ++it;
    }

    // Находим самую дорогую игрушку и выводим ее информацию
    auto maxCostIter = std::max_element(toyList.begin(), toyList.end(), [](const Toy& a, const Toy& b) {
        return a.cost < b.cost;
    });
    std::cout << "Самая дорогая игрушка: Название: " << maxCostIter->name << ", Стоимость: " << maxCostIter->cost << std::endl;

    return 0;
}