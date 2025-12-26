#include "Characters.h"
#include "Enemy.h"
#include <cstdint>
#include <iostream>
#include <memory>

std::unique_ptr<Characters> createCharacter(int choice) {
    switch (choice) {
        case 1: return std::make_unique<Characters>(Characters::knight());
        case 2: return std::make_unique<Characters>(Characters::archer());
        case 3: return std::make_unique<Characters>(Characters::mage());
        case 4: return std::make_unique<Characters>(Characters::thief());
        case 5: return std::make_unique<Characters>(Characters::megaknight());
        case 6: return std::make_unique<Characters>(Characters::PEKKA());
        case 7: return std::make_unique<Characters>(Characters::Steve());
        case 42: std::cout << "Oh, so you are the chose one...\n"; return std::make_unique<Characters>(Characters::Naumov());
        default: return std::make_unique<Characters>(Characters::knight());
    }
}
std::unique_ptr<Enemy> createEnemy(int choice, int64_t lvl) {
    switch (choice) {
        case 0: return std::make_unique<Enemy>(Enemy::goblin(lvl));
        case 1: return std::make_unique<Enemy>(Enemy::golem(lvl));
        case 2: return std::make_unique<Enemy>(Enemy::skeleton(lvl));
        case 3: return std::make_unique<Enemy>(Enemy::spider(lvl));
        case 4: return std::make_unique<Enemy>(Enemy::bear(lvl));
        case 5: return std::make_unique<Enemy>(Enemy::dragon_child(lvl));
        default: return 0;
    }
}
std::unique_ptr<Enemy> createBoss(int64_t lvl) {
    if (lvl < 100) return std::make_unique<Enemy>(Enemy::Warden());
    else return std::make_unique<Enemy>(Enemy::Iron_Nyanya());
}

int main() {
    bool isRunning;
    srand(time(NULL));
    std::cout << "Choose your character: 1 - knight, 2 - archer, 3 - mage, 4 - thief, 5 - megaknight, 6 - PEKKA, 7 - Steve\n";
    int answ;
    std::cin >> answ;
    std::unique_ptr<Entity> Char = createCharacter(answ);
    std::unique_ptr<Entity> curr_en;
    while (Char->isAlive()) {
        answ = 2;
        isRunning = false;
        if (Char->getLvl() >= 15) {
            std::cout << "You have reached enough lvl to fight the bosses, would you like to? 1 - yes, 2 - no\n";
            std::cin >> answ;
        }
        if (answ == 2) {
            int en = rand() % 6;
            curr_en = createEnemy(en, Char->getLvl());
        }
        else {
            curr_en = createBoss(Char->getLvl());
        }
        std::cout << "You have met ";
        curr_en->getName();
        while (Char->isAlive() && curr_en->isAlive() && !isRunning) {
            std::cout << "                       It's your turn!\n1 - hit, 2 - magic hit, 3 - magic heal, 4 - wait(restore some mana), 5 - run away(30% chance)\n";
            std::cin >> answ;
            switch (answ) {
                case 1: Char->attack(curr_en.get(), 0, rand() % 100); break;
                case 2: Char->attack(curr_en.get(), 1, rand() % 100); break;
                case 3: Char->attack(Char.get(), 2, rand() % 100); break;
                case 4: if (auto* temp1 = dynamic_cast<Characters*>(Char.get())) {
                    temp1->gainMana();
                    break;
                }
                case 5: if (rand() % 10 < 3) {
                    isRunning = true;
                    std::cout << "You have ran away!\n";
                    break;
                }
            }
           if (!curr_en->isAlive()) {
            break;
           }
           if (auto* temp2 = dynamic_cast<Enemy*>(curr_en.get())) {
            if (temp2->get_magic_dmg() < 1){
                curr_en->attack(Char.get(), 0, rand() % 100);
            }
            else {
                if (auto* temp1 = dynamic_cast<Characters*>(Char.get())) {
                    if (temp2->get_dmg()-temp1->getRes() >= temp2->get_magic_dmg()-temp1->getMagic_res()){
                        curr_en->attack(Char.get(), 0, rand() % 100);
                    }
                    else {
                        curr_en->attack(Char.get(), 1, rand() % 100);
                    }
                }
            }
            }
            std::cout << "                   You:";
            std::cout << "                                            ";
            curr_en->getName();
            Char->get_hp_and_mana();
            std::cout << "             ";
            curr_en->get_hp_and_mana();
            std::cout << std::endl;
        }
        if (!Char->isAlive()) {
            std::cout << "You have died!\n";
            break;
        }
        if (auto* temp1 = dynamic_cast<Characters*>(Char.get())) {
            if (!isRunning) {
                temp1->gainExp(curr_en->getExpForKill());
            }
        }
    }
}