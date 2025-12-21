#include "Enemy.h"

void Enemy::attack(Entity* target, int idx, int rand) {
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
Stats Enemy::goblin(int64_t lvl) {
    Stats goblin {
        .hp = 30,
        .magic_damage = 0,
        .mana = 0,
        .dmg = 10,
        .res = 0,
        .lvl = lvl,
        .exp = 0,
        .crit_chance = 5,
        .crit_damage = 2,
        .magic_res = 0,
        .exp_for_kill = 5,
        .name = "goblin"
    };
    return goblin;
}
Stats Enemy::golem(int64_t lvl) {
    Stats golem {
        .hp = 60,
        .magic_damage = 0,
        .mana = 0,
        .dmg = 5,
        .res = 2,
        .lvl = lvl,
        .exp = 0,
        .crit_chance = 0,
        .crit_damage = 0,
        .magic_res = 2,
        .exp_for_kill = 10,
        .name = "golem"
    };
    return golem;
}
Stats Enemy::skeleton(int64_t lvl) {
    Stats skeleton {
        .hp = 30,
        .magic_damage = 0,
        .mana = 0,
        .dmg = 15,
        .res = 0,
        .lvl = lvl,
        .exp = 0,
        .crit_chance = 10,
        .crit_damage = 2,
        .magic_res = 0,
        .exp_for_kill = 5,
        .name = "skeleton"
    };
    return skeleton;
}
Stats Enemy::spider(int64_t lvl) {
    Stats spider {
        .hp = 30,
        .magic_damage = 0,
        .mana = 0,
        .dmg = 10,
        .res = 0,
        .lvl = lvl,
        .exp = 0,
        .crit_chance = 0,
        .crit_damage = 0,
        .magic_res = 0,
        .exp_for_kill = 5,
        .name = "spider"
    };
    return spider;
}
Stats Enemy::bear(int64_t lvl) {
    Stats bear {
        .hp = 50,
        .magic_damage = 0,
        .mana = 0,
        .dmg = 15,
        .res = 1,
        .lvl = lvl,
        .exp = 0,
        .crit_chance = 0,
        .crit_damage = 0,
        .magic_res = 0,
        .exp_for_kill = 15,
        .name = "bear"
    };
    return bear;
}
Stats Enemy::dragon_child(int64_t lvl) {
    Stats dragon_child {
        .hp = 40,
        .magic_damage = 15,
        .mana = 100,
        .dmg = 0,
        .res = 0,
        .lvl = lvl,
        .exp = 0,
        .crit_chance = 5,
        .crit_damage = 2,
        .magic_res = 15,
        .exp_for_kill = 20,
        .name = "dragon_child"
    };
    return dragon_child;
}
Stats Enemy::Warden() {
    Stats Warden {
        .hp = 500,
        .magic_damage = 20,
        .mana = 100,
        .dmg = 30,
        .res = 10,
        .lvl = 1,
        .exp = 0,
        .crit_chance = 5,
        .crit_damage = 2,
        .magic_res = 15,
        .exp_for_kill = 500,
        .name = "Warden"
    };
    return Warden;
}
Stats Enemy::Iron_Nyanya() {
    Stats Iron_Nyanya {
        .hp = 10000,
        .magic_damage = 0,
        .mana = 0,
        .dmg = 400,
        .res = 228,
        .lvl = 1,
        .exp = 0,
        .crit_chance = 20,
        .crit_damage = 2,
        .magic_res = 200,
        .exp_for_kill = 100000,
        .name = "Iron_Nyanya"
    };
    return Iron_Nyanya;
}