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
	vector<ItemSlot> playerInventory;
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

	int choose;
	int buyChoose;
	int sellChoose;
	int yesNo;

	do {
		cout << "\nHello welcome to my Shop" << endl;
		cout << "1. buy" << endl;
		cout << "2.sell" << endl;
		cout << "3.Quit" << endl;
		choose = askNumber("What would you like to Do?", 3, 1); 

		switch (choose) {
		case 1:
			cout << "\n*You have " << player.money << " gold coins*";

			displayInventory(&merchantInventory);

			cout << "\n(5) leave\n";

			buyChoose = askNumber("", static_cast<int>(merchantInventory.size())+1, 1);

			if (buyChoose == 5)
			{
				cout << "\nleaving...\n";
				break;
			}
			cout << "\nWould you like to buy " << merchantInventory[buyChoose - 1].item.name << " for " << merchantInventory[buyChoose - 1].item.price << " gold coins? There are " << merchantInventory[buyChoose - 1].quantity << " " << merchantInventory[buyChoose - 1].item.name << "'s in stock.\n";
			cout << "\n(1) Yes\n";
			cout << "\n(2) No\n";

			yesNo = askNumber("", 2, 1);
			if (yesNo == 1) {
				if (player.money < merchantInventory[buyChoose - 1].item.price) {
					cout << "\nCome back with more money to be able to buy this item";
					break; 
				}
				if (merchantInventory[buyChoose - 1].quantity < 1) {
					cout << "\nI'm sold out of that item";
					break; 
				}
				player.money -= merchantInventory[buyChoose - 1].item.price;
				ItemSlot slot(merchantInventory[buyChoose - 1].item, 1);
				playerInventory.push_back(slot);
			}
			else {
				break;
			}
			break; 
		case 2:
			cout << "\n*You have " << player.money << " gold coins*";

			displayInventory(&playerInventory);

			cout << "\n(5) leave\n";

			sellChoose = askNumber("", static_cast<int>(playerInventory.size()) + 1, 1);

			if (sellChoose == 5)
			{
				cout << "\nleaving...\n";
				break;
			}
			cout << "\nWould you like to sell" << playerInventory[sellChoose - 1].item.name << " for " << playerInventory[buyChoose - 1].item.price << " gold coins? There are " << playerInventory[buyChoose - 1].quantity << " " << playerInventory[sellChoose - 1].item.name << "'s in stock.\n";
			cout << "\n(1) Yes\n";
			cout << "\n(2) No\n";

			yesNo = askNumber("", 2, 1);
			if (yesNo == 1) {
				
				player.money += playerInventory[sellChoose - 1].item.price;
				ItemSlot slot(playerInventory[sellChoose - 1].item, 1);
				merchantInventory.push_back(slot);
				vector<ItemSlot>::iterator iter;
				iter = playerInventory.begin() + sellChoose - 1;
				playerInventory.erase(iter);
			}
			else {
				break;
			}
			break;
			break;

		case 3:

			break;
		}
		
	} while (choose != 3);
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
