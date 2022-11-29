// RBGshop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Player
{
public:
	int money;
};

class Item
{
public:
	string name;
	int price;

	Item(string itemname, int itemprice);
};

Item::Item(string itemname, int itemprice)
{
	name = itemname;
	price = itemprice;
}

class ItemSlot
{
public:
	Item item;
	int quantity;

	ItemSlot(Item i, int qty);
};

ItemSlot::ItemSlot(Item i, int qty)
{
	item = i;
	quantity = qty;
}

int main()
{

	Player player;

	player.money = 100;

	Item sword("Aurther", 50);
	Item shield("Link", 25);
	Item armor("Sir Aurther's armor", 75);
	Item potion("Health", 15);
}

//HELLO LOOK AT ME!!!!



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
