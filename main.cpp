#include <iostream>


class Item {
    std::string name;
    int price;
public:
    void addParameters(std::string aName, int aPrice) {
        name = aName;
        price = aPrice;
    }

    void coutParameters() {
        std::cout << std::endl << name << " ( ";
        std::cout << price << " з. )\n";
    }
};

class Character {
    std::vector <Item> inventory;
    std::string name;
    const int MAX_HEALTH = 100;
    int health, gold;

public:
    void getName(std::string n = "Unknow") {name = n;}
    void getHealth(int h = 1) {
        if(h >= MAX_HEALTH) health = MAX_HEALTH;
        else if(h > 0) health = h;
        else health = 1;
    }
    void getGold(int g = 0) {
        if(g > 0) gold = g;
        else gold = 0;
    }

    void takeDamage(int h = 0) {if(h > 0) health-=h;}

    bool death() {return (health <= 0 ? true : false);}

    void heal(int h = 0) {
        if(h > 0) health+=h;
        if(health > MAX_HEALTH) health = MAX_HEALTH;
    }

    void addGold(int g = 0) {if(g > 0) gold += g;}

    void spendGold(int g = 0) {
        if(g > 0 && gold >= g) gold -= g;
        else if(g > 0 && gold < g) {std::cout << "\nСлишком дорого!";}
    }

    void printInfo() {
        std::cout << "\nИмя героя: " << name;
        std::cout << "\nЗдоровье: " << health;
        std::cout << "\nЗолото: " << gold << std::endl;
    }

    void addItem(std::string iName = "Unknow item", int iPrice = 0) {
        Item i;
        if(iPrice >= 0) {
            i.addParameters(iName, iPrice);
            inventory.push_back(i);
        }
        else {
            i.addParameters(iName, 0);
            inventory.push_back(i);
        }
    }

    void removeItem() {inventory.pop_back();}

    void showInventory() {
        std::cout << "\nВаш инвентарь:";
        for(int i = 0; i < inventory.size(); i++) inventory[i].coutParameters();
    }
};

int main()
{
    Character player;
    std::string buffer, itemPrice;

    std::cout << "\nСоздайте своего героя!\n";

    std::cout << "Введите имя: ";
    std::getline(std::cin, buffer);
    player.getName(buffer);

    std::cout << "Введите здоровье (до 100): ";
    std::getline(std::cin, buffer);
    player.getHealth(std::stoi(buffer));

    std::cout << "Введите золото: ";
    std::getline(std::cin, buffer);
    player.getGold(std::stoi(buffer));

    player.printInfo();

    std::cout << "\nВам был нанесен урон 7!\n";
    player.takeDamage(7);
    if(player.death()) {
        std::cout << "\nВаш герой был убит!\n";
        return 0;
    }

    std::cout << "\nВы вылечились Зельем здоровья на 5!\n";
    player.heal(5);

    std::cout << "\nВы нашли мешок с 25 золотыми монетами!\n";
    player.addGold(25);

    std::cout << "\nУ вас украли мешок с монетами!\n";
    player.spendGold(25);

    player.printInfo();

    std::cout << "\nВы нашли предмет!\nЭто - ";
    std::getline(std::cin, buffer);

    std::cout << "\nСколько стоит? ";
    std::getline(std::cin, itemPrice);
    player.addItem(buffer, std::stoi(itemPrice));

    player.showInventory();

    std::cout << "\nНа Вас напали и отобрали Ваш последний предмет!\n";
    player.removeItem();
}