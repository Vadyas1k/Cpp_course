#ifndef ENEMY_H
#define ENEMY_H
#include "Combatant.h"
#include <cstdint>
#include <iostream>


class Enemy : public Combatant {
    public:
        Enemy(const Stats& stats) : Combatant(stats) {}
        int64_t get_dmg() const {return dmg;}
        int64_t get_magic_dmg() const {return magic_damage;}
        void attack(Entity* target, int idx, int rand) override;
        static Stats goblin(int64_t lvl);
        static Stats golem(int64_t lvl);
        static Stats skeleton(int64_t lvl);
        static Stats spider(int64_t lvl);
        static Stats bear(int64_t lvl);
        static Stats dragon_child(int64_t lvl);
        static Stats Warden();
        static Stats Iron_Nyanya();
        ~Enemy() = default;
};


#endif // ENEMY_H