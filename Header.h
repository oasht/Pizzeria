#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

class Unit
{
public:
    virtual double getCost() = 0;
    virtual double getWeight() = 0;
    virtual void getName() = 0;
    virtual void addUnit(Unit* p) { }
    virtual ~Unit() {}
};
class Dollar
{
public:
    float Convert();
}; 
class Product
{
public:
    virtual ~Product() {}
    virtual double Get_cost_double(double price) = 0;
};

class Adapter_dollar : public Product
{
private:
    Dollar* p_product;

public:
    Adapter_dollar(Dollar* p)
    {
        p_product = p;
    }

    ~Adapter_dollar()
    {
        delete p_product;
    }

    double Get_cost_double(double price) override;

};



class Cheese : public Unit
{
    double cost = 0.55;
    string name = "cheese";
    double weight = 0.1;
public:
    double getCost() { return cost; }
    double getWeight() { return weight; }
    void getName() { cout << "/ " << name << " /"; }
};
class Dough : public Unit
{
    double cost = 0.25;
    string name = "dough";
    double weight = 0.5;
public:
    double getCost() { return cost; }
    double getWeight() { return weight; }
    void getName() { cout << "/ " << name << " /"; }
};
class Sauce : public Unit
{
    double cost = 0.2;
    string name = "sauce";
    double weight = 0.15;
public:
    double getCost() { return cost; }
    double getWeight() { return weight; }
    void getName() { cout << "/ " << name << " /"; }
};
class Mushrooms : public Unit
{
    double cost = 0.3;
    string name = "mushrooms";
    double weight = 0.1;
public:
    double getCost() { return cost; }
    double getWeight() { return weight; }
    void getName() { cout << "/ " << name << " /"; }
};
class Ham : public Unit
{
    double cost = 0.35;
    string name = "ham";
    double weight = 0.15;
public:
    double getCost() { return cost; }
    double getWeight() { return weight; }
    void getName() { cout << "/ " << name << " /"; }
};

class Shrimps : public Unit
{
    double cost = 0.8;
    string name = "Shrimps";
    double weight = 0.2;
public:
    double getCost() { return cost; }
    double getWeight() { return weight; }
    void getName() { cout << "/ " << name << " /"; }
};
// Composite
class Pizza : public Unit
{
private:
    string name;
    std::vector<Unit*> c;
public:
    double getCost();
    double getWeight();
    void getName();
    string set_Pizza_name(string _name);
    void get_Pizza_name();
    

    void addUnit(Unit* p);
    ~Pizza() {
        for (int i = 0; i < c.size(); ++i)
            delete c[i];
    }

};


Pizza* create_Margherita();
Pizza* create_Ham_and_Mushrooms();
Pizza* create_Seafood();
double Get_discount(double a);
void show_menu();
void gotoxy(short x, short y);

void Final(vector<Pizza*>v, Product* p_d);




