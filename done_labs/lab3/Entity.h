#ifndef ENTITY_H
#define ENTITY_H
#include <cstdint>
#include <memory>

class Entity {
public:
    virtual void get_stats()=0;
    virtual void get_hp_and_mana()=0;
    virtual void getName() = 0;
    virtual int64_t getExpForKill() = 0;
    virtual int64_t getLvl() = 0;
    virtual void attack(Entity* target, int idx, int rand) = 0;
    virtual void heal(int64_t num) = 0;
    virtual void takeDamage(int64_t damage, int idx) = 0;
    virtual bool isAlive() const = 0;
    virtual ~Entity() = default;
};



#endif  // ENTITY_H