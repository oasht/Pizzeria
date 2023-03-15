#include "Header.h"
#pragma once

float Dollar::Convert()
{
	float dollar = 76.02;
	return dollar;
}



double Adapter_dollar::Get_cost_double(double price)
{
	return (double)(p_product->Convert() * price);
}

double Pizza::getCost()
{
	double total = 0;
	for (int i = 0; i < c.size(); ++i)
		total += c[i]->getCost();
	return total;
}

double Pizza::getWeight()
{
	double total = 0;
	for (int i = 0; i < c.size(); ++i)
		total += c[i]->getWeight();
	return total;
}

void Pizza::getName()
{
	for (int i = 0; i < c.size(); ++i)
		c[i]->getName();
}

string Pizza::set_Pizza_name(string _name)
{
	name = _name;
	return name;
}

void Pizza::get_Pizza_name()
{
	cout << name << " ";
}

void Pizza::addUnit(Unit* p)
{
	c.push_back(p);
}

Pizza* create_Margherita()
{
	Pizza* margherita = new Pizza;
	margherita->set_Pizza_name("Margherita");
	for (int i = 0; i < 1; ++i)
		margherita->addUnit(new Dough);
	for (int i = 0; i < 1; ++i)
		margherita->addUnit(new Sauce);
	for (int i = 0; i < 1; ++i)
		margherita->addUnit(new Cheese);
	return margherita;
}

Pizza* create_Ham_and_Mushrooms()
{

	Pizza* ham_mush = new Pizza;
	ham_mush->set_Pizza_name("Ham_and_Mushrooms");
	for (int i = 0; i < 1; ++i)
		ham_mush->addUnit(new Dough);
	for (int i = 0; i < 1; ++i)
		ham_mush->addUnit(new Sauce);
	for (int i = 0; i < 1; ++i)
		ham_mush->addUnit(new Cheese);
	for (int i = 0; i < 1; ++i)
		ham_mush->addUnit(new Ham);
	for (int i = 0; i < 1; ++i)
		ham_mush->addUnit(new Mushrooms);
	return ham_mush;
}

Pizza* create_Seafood()
{
	Pizza* seafood = new Pizza;
	seafood->set_Pizza_name("Seafood");
	for (int i = 0; i < 1; ++i)
		seafood->addUnit(new Dough);
	for (int i = 0; i < 1; ++i)
		seafood->addUnit(new Sauce);
	for (int i = 0; i < 1; ++i)
		seafood->addUnit(new Cheese);
	for (int i = 0; i < 1; ++i)
		seafood->addUnit(new Shrimps);
	return seafood;
}

double Get_discount(double a)
{
	return a * 0.9;
}

void show_menu()
{
	system("cls");
	cout << "Margherita" << endl;
	cout << "Ham and mushrooms" << endl;
	cout << "Seafood" << endl;
	cout << "=====================" << endl;
	cout << "Press ESC to exit" << endl;
}

void gotoxy(short x, short y)
{

	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

void Final(vector<Pizza*> v, Product* p_d)
{
	double total = 0;
	cout << "\nYOUR ORDER:\n\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << i + 1 << ") ";
		v[i]->get_Pizza_name();
		cout << "(";
		v[i]->getName();
		cout << ") ";
		cout << v[i]->getWeight()<<" kg";
		cout << "\nThis pizza costs: ";
		cout << v[i]->getCost();
		cout << " $" << endl;
		cout << "Price in rubles: " << p_d->Get_cost_double(v[i]->getCost()) << " rub" << endl;
		total += v[i]->getCost();
		cout << endl << endl;


	}

	if (v.size() > 3)
	{
		Get_discount(total);
		cout << "YOU GET 10% DISCOUNT! CONGRATULATIONS!" << endl << endl;
		cout << "\nYour total is: " << total << " $" << endl;
		cout << "Total price in rubles: " << p_d->Get_cost_double(total) << " rub" << endl;
	}
	else
	{
		cout << "\nYour total is: " << total << " $" << endl;
		cout << "Total price in rubles: " << p_d->Get_cost_double(total) << " rub" << endl;
	}

	
}
