#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

// Структура для хранения информации о человеке
struct Person {
    std::string name;
    std::vector<Person*> acquaintances;
};

void findAcquaintancesThroughThreeHandshakes(Person* person, std::vector<std::pair<std::string, std::string>>& result) {
    std::queue<Person*> q;
    q.push(person);

    std::unordered_set<Person*> visited;
    visited.insert(person);

    int distance = 0;
    while (!q.empty() && distance <= 3) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Person* current = q.front();
            q.pop();

            for (Person* acquaintance : current->acquaintances) {
                if (!visited.count(acquaintance)) {
                    visited.insert(acquaintance);
                    q.push(acquaintance);

                    if (distance == 3) {
                        result.push_back({ person->name, acquaintance->name });
                    }
                }
            }
        }
        ++distance;
    }
}

// Функция для вывода результатов
void printResults(const std::vector<std::pair<std::string, std::string>>& result) {
    std::cout << "Пары знакомств через три рукопожатия:" << std::endl;
    for (const auto& pair : result) {
        std::cout << pair.first << " - " << pair.second << std::endl;
    }
}

int main() {
    // Создание людей и их знакомств
    Person person1 = { "Иван", {} };
    Person person2 = { "Петр", {} };
    Person person3 = { "Сергей", {} };
    Person person4 = { "Мария", {} };
    Person person5 = { "Алексей", {} };

    person1.acquaintances.push_back(&person2);
    person1.acquaintances.push_back(&person3);
    person2.acquaintances.push_back(&person4);
    person3.acquaintances.push_back(&person5);
    person4.acquaintances.push_back(&person5);

    std::vector<std::pair<std::string, std::string>> result;
    findAcquaintancesThroughThreeHandshakes(&person1, result);

    // Вывод результатов
    printResults(result);

    return 0;
}