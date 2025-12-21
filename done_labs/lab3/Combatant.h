// Combatant.h
#ifndef COMBATANT_H
#define COMBATANT_H

#include "Entity.h"
#include <cstdint>
#include <iostream>
#include <string>

struct Stats { 
    int64_t hp = 100; 
    int64_t magic_damage = 0; 
    int64_t mana = 0; 
    int64_t dmg = 10; 
    int64_t res = 0; 
    int64_t lvl = 1; 
    int64_t exp = 0; 
    int64_t crit_chance = 5; 
    float crit_damage = 2; 
    int64_t magic_res = 0; 
    int64_t exp_for_kill = 0; 
    int64_t max_hp = 100; 
    int64_t max_mana = 0; 
    std::string name = ""; 
}; 
 
class Combatant : public Entity { 
protected: 
    int64_t hp; 
    int64_t magic_damage; 
    int64_t mana; 
    int64_t dmg; 
    int64_t res; 
    int64_t lvl; 
    int64_t exp; 
    int64_t crit_chance; 
    float crit_damage; 
    int64_t magic_res; 
    int64_t exp_for_kill; 
    int64_t max_hp; 
    int64_t max_mana; 
    std::string name;

public:
    Combatant(const Stats& stats) 
        : hp(stats.hp * (0.9f + stats.lvl / 10.0f)), magic_damage(stats.magic_damage * (0.9f + stats.lvl / 10.0f)), mana(stats.mana * (0.9f + stats.lvl / 10.0f)), 
          dmg(stats.dmg * (0.9f + stats.lvl / 10.0f)), res(stats.res * (0.9f + stats.lvl / 10.0f)), lvl(stats.lvl), exp(stats.exp), 
          crit_chance(stats.crit_chance * (0.9f + stats.lvl / 10.0f)), crit_damage(stats.crit_damage * (0.9f + stats.lvl / 10.0f)), magic_res(stats.magic_res * (0.9f + stats.lvl / 10.0f)), 
          exp_for_kill(stats.exp_for_kill * (0.5 + stats.lvl / 2)), max_hp(stats.max_hp * (0.9f + stats.lvl / 10.0f)), max_mana(stats.max_mana * (0.9f + stats.lvl / 10.0f)), name(stats.name) {}

    void takeDamage(int64_t damage, int idx) override;
    void heal(int64_t num) override;
    int64_t getMagicRes() {return magic_res;}

    bool isAlive() const override {
        return hp > 0;
    }
    void get_stats() override {
        std::cout << "Stats:\ndmg: " << dmg << "\nres: " << res << "\nhp: " << hp << "\nmagic_dmg: " << magic_damage << "\nlvl: " << lvl << "\ncrit damage: " << crit_damage << "\ncrit chance: " << crit_chance << "\nmana: " << mana << "\nmagic_res: " << magic_res << "\nname: " << name << "\nmax_health: " << max_hp << "\nmax_mana: " << max_mana << std::endl;
    }
    void get_hp_and_mana() override {std::cout << "Current health: " << hp << ", current mana: " << mana;}
    void getName() override {
        std::cout << name << ":" << std::endl;
    }
    void attack(Entity* target, int idx, int rand) override = 0;
    int64_t getExpForKill() override {return exp_for_kill;}
    int64_t getLvl() override {return lvl;}
};

#endif // COMBATANT_H