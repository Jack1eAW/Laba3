#include "Weapon.h"
#include <iostream>
using namespace std;
int main()
{
    cout << "enter the number of weapons(int)";
    int amountWeapons;
    cin >> amountWeapons;
    Shop ammuNation(amountWeapons);
    ammuNation.weaponSelection();
    return 0;
}
