#include <iostream>
#include "curr.h"
using namespace std;

template <class T> class transfers {
    T cur;
public:
    transfers() { }
    void Action(score& sc1, score& sc2, double sum) {
        if (sum * cur.getcourse() > sc1.getscore()) {
            cout << " Не хватает денег! " << endl;
            return;
        }
        sc1.setscore(sc1.getscore() - sum * cur.getcourse());
        sc2.setscore(sc2.getscore() + sum);
    }
    ~transfers() { }
};
int main() {
    score Vinny(70000, 'r'), Ia(0, 'r'), Sova(0, 'd'), Pyatochok(0, 'e');
    Vinny.printinf();
    Ia.printinf();
    Sova.printinf();
    Pyatochok.printinf();
    transfers<ruble> tr1;
    transfers<dollar> tr2;
    transfers<euro> tr3;
    tr1.Action(Vinny, Ia, 5000);
    tr2.Action(Vinny, Sova, 100);
    tr3.Action(Vinny, Pyatochok, 200);
    Vinny.printinf();
    Ia.printinf();
    Sova.printinf();
    Pyatochok.printinf();
    transfer* trans;
    trans = new transfer_ruble();
    trans->Action(Vinny, Ia, 5000);
    trans = new transfer_dollar();
    trans->Action(Vinny, Sova, 100);
    trans = new transfer_euro();
    trans->Action(Vinny, Pyatochok, 200);
    delete trans;
    cout << endl;
    Vinny.printinf();
    Ia.printinf();
    Sova.printinf();
    Pyatochok.printinf();
    return 0;
}