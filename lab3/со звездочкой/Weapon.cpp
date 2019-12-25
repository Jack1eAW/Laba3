#include "Weapon.h"
#include <iostream>
#include <random>
using namespace std;

Weapon::Weapon(int w, int c, int m): weight(w), cost(c), materialType(m) {}
void Weapon::getInfo() {
    cout << "weight: " << weight << endl << "cost: " << cost << endl << "materialType: " << materialType << endl;
}

Weapon::~Weapon() = default;

Pistol::Pistol(int w, int c, int m, Clip cl): Weapon(w, c, m), clip(cl){
}
void Pistol::check() {
    cout << "piu" << endl;
}
void Pistol::getInfo() {
    Weapon::getInfo();
}

Knife::Knife(int w, int c, int m, Sheath shea): Weapon(w, c, m), sheath(shea){}
void Knife::check() {
    cout << "swish" << endl;
}
void Knife::getInfo() {
    Weapon::getInfo();
}

MachineGun::MachineGun(int w, int c, int m, Clip cl): Weapon(w, c, m), clip(cl) {}
void MachineGun::check() {
    cout << "brrrau" << endl;
}
void MachineGun::getInfo() {
    Weapon::getInfo();
}

AssaultRifle::AssaultRifle(int w, int c, int m, Clip cl): Weapon(w, c, m), clip(cl) {}
void AssaultRifle::check() {
    cout<< "brr-brr-brr" << endl;
}
void AssaultRifle::getInfo() {
    Weapon::getInfo();
}

Rifle::Rifle(int w, int c, int m, Clip cl): Weapon(w, c, m), clip(cl) {}
void Rifle::check() {
    cout << "buy";
}
void Rifle::getInfo() {
    Weapon::getInfo();
}

Shop::Shop(int amountWeapons): amountWeapons(amountWeapons) {
    weapons = nullptr;
    _generate(amountWeapons);
}
Shop::~Shop() {
    for (int i = 0; i < amountWeapons; ++i) {
        delete weapons[i];
    }
    delete[] weapons;
}
Weapon* Shop::_randomWeapon() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> randNumberWeapon(0, 4);
    uniform_int_distribution<> randProperties(1, 10);
    switch(randNumberWeapon(gen)){
        case 0: {
            auto *p = new Pistol(randProperties(gen), randProperties(gen), randProperties(gen),
                    Clip(randProperties(gen), randProperties(gen)));
            return p;
        }
        case 1: {
            auto *k = new Knife(randProperties(gen), randProperties(gen), randProperties(gen),
                                Sheath(randProperties(gen), randProperties(gen)));
            return k;
        }
        case 2: {
            auto* mg = new MachineGun(randProperties(gen), randProperties(gen), randProperties(gen),
                                      Clip(randProperties(gen), randProperties(gen)));
            return mg;
        }
        case 3: {
            auto ar = new AssaultRifle(randProperties(gen), randProperties(gen), randProperties(gen),
                                       Clip(randProperties(gen), randProperties(gen)));
            return ar;
        }
        case 4: {
            auto r = new Rifle(randProperties(gen), randProperties(gen), randProperties(gen),
                               Clip(randProperties(gen), randProperties(gen)));
            return r;
        }
    }
    return nullptr;
}
void Shop::_generate(int n) {
    amountWeapons = n;
    weapons = new Weapon*[amountWeapons];
    for (int i = 0; i < amountWeapons; ++i) {
        weapons[i] = _randomWeapon();
    }
}
void Shop::weaponSelection() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> probability1Percent(1, 100);
    bool flagSucces = false;
    while (!flagSucces){
        for (int i = 0; i < amountWeapons; ++i) {
            weapons[i]->check();
            weapons[i]->getInfo();
            if (probability1Percent(gen) == 1){
                flagSucces = true;
                cout << "I chose a weapon";
                break;
            }
            cout << endl;
        }
    }
}
