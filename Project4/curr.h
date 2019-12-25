#pragma once
class currency {
protected:
	double course;
public:
	currency();
	double getcourse();
	virtual ~currency();
};

class ruble :public currency {
public:
	ruble();
	virtual ~ruble();
};
class dollar :public currency {
public:
	dollar();
	virtual ~dollar();
};
class euro :public currency {
public:
	euro();
	virtual ~euro();
};
class score {
	currency* cur;
	double scor;
	char symbol;
public:
	score(double sc, char cur);
	void setscore(double sc);
	double getscore();
	void printinf();
	virtual ~score();
};
class transfer {
public:
	transfer();
	virtual void Action(score& sc1, score& sc2, double sum);
	virtual ~transfer();
};
class transfer_ruble :public transfer {
public:
	transfer_ruble();
	virtual void Action(score& sc1, score& sc2, double sum);
	virtual ~transfer_ruble();
};
class transfer_dollar :public transfer {
public:
	transfer_dollar();
	virtual void Action(score& sc1, score& sc2, double sum);
	virtual ~transfer_dollar();
};
class transfer_euro :public transfer {
public:
	transfer_euro();
	virtual void Action(score& sc1, score& sc2, double sum);
	virtual ~transfer_euro();
};