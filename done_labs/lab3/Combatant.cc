#include "Combatant.h"

void Combatant::takeDamage(int64_t damage, int idx) {
    int64_t real;
    switch (idx) {
        case 0: real = (damage > res) ? damage - res : 0; break;
        case 1: real = (damage > magic_res) ? damage - magic_res : 0; break;
    }
    hp = (hp > real) ? hp - real : 0;
    std::cout << name << " was hit for " << real << " health!\n";
}
void Combatant::heal(int64_t num) {
    hp = (hp + num > max_hp) ? max_hp : hp + num;
}