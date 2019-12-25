

#ifndef CS_30_C_PLUS_PLUS_WEAPON_H
#define CS_30_C_PLUS_PLUS_WEAPON_H


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

class Sheath{
private:
    int convenience;
    int beauty;
public:
    Sheath(int, int);
    void getInfo();
};

class Clip{
private:
    int capacity;
    int caliber;
public:
    Clip(int, int);
    void getInfo();
};

class Pistol: public Weapon {
private:
    Clip clip;
public:
    explicit Pistol(int, int, int, Clip);
    void check() override;
    void getInfo() override;
};

class Knife: public Weapon{
private:
    Sheath sheath;
public:
    explicit Knife(int, int, int, Sheath);
    void check() override;
    void getInfo() override;
};

class MachineGun: public Weapon{
private:
    Clip clip;
public:
    explicit MachineGun(int, int, int, Clip);
    void check() override;
    void getInfo() override;
};

class AssaultRifle:public Weapon{
private:
    Clip clip;
public:
    explicit AssaultRifle(int, int, int, Clip);
    void check() override;
    void getInfo() override;
};

class Rifle:public Weapon{
private:
    Clip clip;
public:
    explicit Rifle(int, int, int, Clip);
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

#endif //CS_30_C_PLUS_PLUS_WEAPON_H
