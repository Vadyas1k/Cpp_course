#include "Characters.h"

void Characters::attack(Entity* target, int idx, int rand) {
    int64_t mult = 1;
    if (rand < crit_chance) {
        mult = crit_damage;
    }
    if (idx == 2) {
        if (mana < 10) {
            std::cout << "Not enough mana!\n";
            return;
        }
        mana -= 10;
        target->heal(magic_damage);
    }
    else if (idx == 1) {
        if (mana < 10) {
            std::cout << "Not enough mana!\n";
            return;
        }
        mana -= 10;
        target->takeDamage(magic_damage, 1);
    }
    else target->takeDamage(dmg, 0);
}
void Characters::gainExp(int64_t e) {
    exp += e;
    while (exp >= getExpForNextLevel()) {
        lvl += 1;
        exp -= getExpForNextLevel();
        int answ;
        std::cout << "You have leveled up! Choose a stat to upgrade: 1 - max hp, 2 - damage, 3 - max mana, 4 - magic damage, 5 - resistance, 6 - magic resistance, 7 - crit chance, 8 - crit damage\n";
        std::cin >> answ;
        switch (answ) {
            case 1: max_hp += 10;
            case 2: dmg += 2;
            case 3: max_mana += 10;
            case 5: res += 1;
            case 6: magic_res += 1;
            case 7: crit_chance += 3;
            case 8: crit_damage += 0.5;
        }
        hp = max_hp;
        mana = max_mana;
    }
}
Stats Characters::knight() { 
    Stats knight { 
        .hp = 100, 
        .magic_damage = 0, 
        .mana = 0, 
        .dmg = 10, 
        .res = 5, 
        .lvl = 1, 
        .exp = 0, 
        .crit_chance = 5, 
        .crit_damage = 2, 
        .magic_res = 0, 
        .exp_for_kill = 100, 
        .max_hp = 100, 
        .max_mana = 0, 
        .name = "knight" 
    }; 
    return knight; 
} 
Stats Characters::archer() { 
    Stats archer { 
        .hp = 50, 
        .magic_damage = 0, 
        .mana = 0, 
        .dmg = 15, 
        .res = 0, 
        .lvl = 1, 
        .exp = 0, 
        .crit_chance = 10, 
        .crit_damage = 3, 
        .magic_res = 0, 
        .exp_for_kill = 100, 
        .max_hp = 50, 
        .max_mana = 0, 
        .name = "archer" 
    }; 
    return archer; 
} 
Stats Characters::mage() { 
    Stats mage { 
        .hp = 40, 
        .magic_damage = 25, 
        .mana = 50, 
        .dmg = 5, 
        .res = 0, 
        .lvl = 1, 
        .exp = 0, 
        .crit_chance = 5, 
        .crit_damage = 2, 
        .magic_res = 5, 
        .exp_for_kill = 100, 
        .max_hp = 40, 
        .max_mana = 50, 
        .name = "mage" 
    }; 
    return mage; 
} 
Stats Characters::thief() { 
    Stats thief { 
        .hp = 50, 
        .magic_damage = 0, 
        .mana = 0, 
        .dmg = 10, 
        .res = 1, 
        .lvl = 1, 
        .exp = 0, 
        .crit_chance = 20, 
        .crit_damage = 3, 
        .magic_res = 0, 
        .exp_for_kill = 100, 
        .max_hp = 50, 
        .max_mana = 0, 
        .name = "thief" 
    }; 
    return thief; 
} 
Stats Characters::megaknight() { 
    Stats megaknight { 
        .hp = 150, 
        .magic_damage = 0, 
        .mana = 0, 
        .dmg = 10, 
        .res = 10, 
        .lvl = 1, 
        .exp = 0, 
        .crit_chance = 0, 
        .crit_damage = 0, 
        .magic_res = 0, 
        .exp_for_kill = 100, 
        .max_hp = 150, 
        .max_mana = 0, 
        .name = "megaknight" 
    }; 
    return megaknight; 
} 
Stats Characters::PEKKA() { 
    Stats PEKKA { 
        .hp = 100, 
        .magic_damage = 0, 
        .mana = 0, 
        .dmg = 25, 
        .res = 5, 
        .lvl = 1, 
        .exp = 0, 
        .crit_chance = 0, 
        .crit_damage = 0, 
        .magic_res = 0, 
        .exp_for_kill = 100, 
        .max_hp = 100, 
        .max_mana = 0, 
        .name = "PEKKA" 
    }; 
    return PEKKA; 
} 
Stats Characters::Steve() { 
    Stats Steve { 
        .hp = 20, 
        .magic_damage = 0, 
        .mana = 0, 
        .dmg = 15, 
        .res = 9, 
        .lvl = 1, 
        .exp = 0, 
        .crit_chance = 100, 
        .crit_damage = 2, 
        .magic_res = 0, 
        .exp_for_kill = 100, 
        .max_hp = 20, 
        .max_mana = 0, 
        .name = "Steve" 
    }; 
    return Steve; 
} 
Stats Characters::Naumov() { 
    Stats Naumov { 
        .hp = 4242, 
        .magic_damage = 4242, 
        .mana = 4242, 
        .dmg = 4242, 
        .res = 4242, 
        .lvl = 4242, 
        .exp = 4242, 
        .crit_chance = 4242, 
        .crit_damage = 4242, 
        .magic_res = 4242, 
        .exp_for_kill = 4242, 
        .max_hp = 4242, 
        .max_mana = 4242, 
        .name = "Naumov" 
    }; 
    return Naumov;
}