#ifndef CHARACTERS_H
#define CHARACTERS_H
#include "Combatant.h"
#include <cstdint>
#include <iostream>

            // std::cout << "Created character with folowwing characteristics:\ndmg: " << d << "\nres: " << r << "\nhp: " << h << "\nstamina: " << s << "\nlvl: " << l << "\ncrit damage: " << cd << "\ncrit chance: " << cc << "\nmana: " << m << std::endl;
class Characters : public Combatant {
public:
    Characters(const Stats& stats) : Combatant(stats) {}
    void attack(Entity* target, int idx, int rand) override;
    int64_t getMana() const {return mana;}
    int64_t getRes() const {return res;}
    int64_t getMagic_res() const {return magic_res;}
    void gainMana() {mana = (mana + max_mana/5 > max_mana) ? max_mana : mana + max_mana/5;}
    int64_t getExpForNextLevel() const { return lvl * lvl * 10; }
    void gainExp(int64_t e);
    static Stats knight();
    static Stats archer();
    static Stats mage();
    static Stats thief();
    static Stats megaknight();
    static Stats PEKKA();
    static Stats Steve();
    static Stats Naumov();
    ~Characters() = default;
};



#endif  // CHARACTERS_H