#include <iostream>
#include "curr.h"
using namespace std;

currency::currency() { }
double currency::getcourse() {
    return course;
}
currency::~currency() { }
ruble::ruble() {
    course = 1;
}
ruble::~ruble() { }
dollar::dollar() {
    course = 63.25;
}
dollar::~dollar() { }
euro::euro() {
    course = 70.25;
}
euro::~euro() { }
score::score(double sc, char cur) {
    symbol = cur;
    this->scor = sc;
    switch (cur) {
    case 'r':
        this->cur = new ruble();
        break;
    case 'd':
        this->cur = new dollar();
        break;
    case 'e':
        this->cur = new euro();
    }
}
void score::printinf() {
    cout << scor << symbol << endl;
}
void score::setscore(double sc) {
    scor = sc;
}
double score::getscore() {
    return scor;
}
score::~score() {
    delete cur;
}
transfer::transfer() { }
void transfer::Action(score& sc1, score& sc2, double sum) { }
transfer::~transfer() { }
transfer_ruble::transfer_ruble() { }
void transfer_ruble::Action(score& sc1, score& sc2, double sum) {
    if (sum > sc1.getscore()) {
        cout << " Не хватает денег! " << endl;
        return;
    }
    sc1.setscore(sc1.getscore() - sum);
    sc2.setscore(sc2.getscore() + sum);
}
transfer_ruble::~transfer_ruble() { }
transfer_dollar::transfer_dollar() { }
void transfer_dollar::Action(score& sc1, score& sc2, double sum) {
    dollar cur;
    if (sum * cur.getcourse() > sc1.getscore()) {
        cout << " Не хватает денег! " << endl;
        return;
    }
    sc1.setscore(sc1.getscore() - sum * cur.getcourse());
    sc2.setscore(sc2.getscore() + sum);
}
transfer_dollar::~transfer_dollar() { }
transfer_euro::transfer_euro() { }
void transfer_euro::Action(score& sc1, score& sc2, double sum) {
    euro cur;
    if (sum * cur.getcourse() > sc1.getscore()) {
        cout << " Не хватает денег! " << endl;
        return;
    }
    sc1.setscore(sc1.getscore() - sum * cur.getcourse());
    sc2.setscore(sc2.getscore() + sum);
}
transfer_euro::~transfer_euro() { }

