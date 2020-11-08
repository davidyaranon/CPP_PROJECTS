#ifndef WARRIORS_H
#define WARRIORS_H

#include <string>
class Warrior{
private:
    int damage;
    int health;

public:
    std::string name;
    int bonusDamage;
    int bonusHealth;
    Warrior();
    Warrior(int damage, int health, std::string name);
    int getDamage();
    void setDamage(int newDamage);
    int getHealth();
    void setHealth(int health);
    void tookDamage(int damage);
    std::string getName();
    void setName(std::string name);
    void setAllDetails(int damage, int health, std::string name);
    ~Warrior();
};

#endif