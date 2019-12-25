

#ifndef CS_34_C_PLUS_PLUS_WEAPON_H
#define CS_34_C_PLUS_PLUS_WEAPON_H


class Weapon {
protected:
    int weight;
    int cost;
    int materialType;
public:
    Weapon(int, int, int);
    virtual ~Weapon();
    virtual void check() = 0;
    virtual void getInfo();
};

class Pistol: public Weapon {
public:
    explicit Pistol(int, int, int, Clip);
    void check() override;
    void getInfo() override;
};

class Knife: public Weapon{
public:
    void check() override;
    void getInfo() override;
};

class MachineGun: public Weapon{
public:
    void check() override;
    void getInfo() override;
};

class AssaultRifle:public Weapon{
public:
    void check() override;
    void getInfo() override;
};

class Rifle:public Weapon{
public:
    void check() override;
    void getInfo() override;
};

class Shop{
private:
    int amountWeapons;
    Weapon** weapons;
    static Weapon* _randomWeapon();
    void _generate(int);
public:
    explicit Shop(int);
    ~Shop();
    void weaponSelection();

};

#endif //CS_34_C_PLUS_PLUS_WEAPON_H
