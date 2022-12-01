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

	Item(string itemname = "mt", int itemprice = 0);
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

	ItemSlot(Item i, int qty = 1);
};

ItemSlot::ItemSlot(Item i, int qty)
{
	item = i;
	quantity = qty;
}

void displayInventory(vector<ItemSlot>* inventory);

int askNumber(string question, int high, int low);

int main()
{

	vector<ItemSlot> merchantInventory;

	Player player;

	player.money = 100;

	Item sword("Aurther", 50);
	Item shield("Link", 25);
	Item armor("Sir Aurther's armor", 75);
	Item potion("Health", 15);

	ItemSlot slot1(sword); 
	ItemSlot slot2(shield);
	ItemSlot slot3(armor);
	ItemSlot slot4(potion, 4);

	merchantInventory.push_back(slot1);
	merchantInventory.push_back(slot2);
	merchantInventory.push_back(slot3);
	merchantInventory.push_back(slot4);

	displayInventory(&merchantInventory);
}

void displayInventory(vector<ItemSlot>* inventory)
{
	if (inventory->size() == 0)
	{
		cout << "\nnothing.\n";
	}

	for (int i = 0; i < inventory->size(); i++)
	{
		cout << "\n(" << i + 1 << ")" << endl;
		cout << "Item: " << (*inventory)[i].item.name << endl;
		cout << "Price: " << (*inventory)[i].item.price << endl;
		cout << "Quantity: " << (*inventory)[i].quantity << endl;
	}
}

int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << "\n(" << low << "-" << high << "): ";
		cin >> number;
		if (number > high || number < low)
		{
			cout << "Pick a valid option.\n";
		}
	} while (number > high || number < low);
	return number;
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
