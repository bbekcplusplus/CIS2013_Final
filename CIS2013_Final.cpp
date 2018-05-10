
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class BikeInventory
{
private:
	string make;
	string model;
	string Acc;
	string Mut;
	string vin;
	string engine_size;
	int year;
	float dealer_cost;
	float dealer_price;
	char exterior_color[15];
	char interior_color[15];
	void check_price();
public:
	friend bool operator ==(BikeInventory& Auto, BikeInventory& Inventory);
	void initArrays();
	void set_make();
	void set_model();
	void get_make();
	void get_model();
	void get_year();
	void get_dealer_cost();
	void get_dealer_price();
	void get_exterior_color();
	void get_interior_color();
	void get_vin();
	void get_engine_size();
	void output_info(ostream& outs, BikeInventory& Inventory);
	void delete_car();
	void add_car(istream& ins, BikeInventory& Inventory);
	int search();
	int menu();
};
int main()
{
	BikeInventory Inventory[100], Auto;
	int menu();
	bool yes = true;
	while (yes = true)
	{
		switch (menu())
		{
		case 1:
			Inventory[100].add_car(cin, *Inventory);
			break;
		case 2:
			Inventory[100].delete_car();
			break;
		case 3:
			Inventory[100].search();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	return 0;
}
int menu()
{
	int selection;
	cout << "(1) Enter to add motorcycles .......:" << endl;
	cout << "(2) Enter to delete motorcycles.....:" << endl;
	cout << "(3) Enter to search motorcycles.....:" << endl;
	cout << "(4) Enter to exit............:" << endl;
	cout << "PLEASE ENTER YOUR SELECTIO:::" << endl;
	cin >> selection;
	cout << endl;
	while ((selection < 1 || selection > 4))
	{
		cout << "Wrong selection please try again. Enter 1,2,3,4 or 5" << endl;
		cin >> selection;
	}
	return selection;
}
bool operator == (BikeInventory &Auto, BikeInventory &Inventory)
{
	return(Auto.make == Inventory.make);
}
void BikeInventory::check_price()
{
	if (dealer_price < 0.0 || dealer_cost < 0.0)
	{
		cout << "OOPS! Wrong Price please enter right price...:" << endl;
		exit(0);
	}
}
void BikeInventory::set_make()
{
	Acc = make;
}
void BikeInventory::set_model()
{
	Acc = model;
}
void BikeInventory::initArrays()
{
	for (int i = 0; i < 100; i++)
	{
		make[i] = '#';
		model[i] = '#';
	}
}
void BikeInventory::get_make()
{
	cin >> make;
	Mut = make;
}
void BikeInventory::get_model()
{
	cin >> model;
	Mut = model;
}
void BikeInventory::add_car(istream& ins, BikeInventory& Inventory)
{
	int i = 0, number_of_cars;
	cout << " how many bikes do you want to Inventory? " << endl;
	cin >> number_of_cars;
	while (i < number_of_cars)
	{
		cout << "Enter the make of the motorcycle. " << endl;
		ins >> Inventory.make;
		cout << "Enter the model of the motorcycle. " << endl;
		ins >> Inventory.model;
		cout << "Enter the year of the motorcycle. " << endl;
		ins >> Inventory.year;
		cout << "Enter the dealer cost. " << endl;
		ins >> Inventory.dealer_cost;
		cout << "Enter the dealer price. " << endl;
		ins >> Inventory.dealer_price;
		cout << "Enter the exterior color of the motorcycle. " << endl;
		ins >> Inventory.exterior_color;
		cout << "Enter the interior color of the motorcycle. " << endl;
		ins >> Inventory.interior_color;
		cout << "Enter the VIN number of the motorcycle. " << endl;
		ins >> Inventory.vin;
		cout << "Enter the engine size of the motorcycle. " << endl << endl;
		ins >> Inventory.engine_size;
		i++;
	}cout << "The number of motorcycles in inventory is: " << number_of_cars << endl;
}
void BikeInventory::output_info(ostream &outs, BikeInventory& Inventory)
{
	outs << "Make...........: " << Inventory.make << endl;
	outs << "Model..........:" << Inventory.model << endl;
	outs << "Year...........:" << Inventory.year << endl;
	outs << "Interior Color.:" << Inventory.interior_color << endl;
	outs << "Exterior Color.:" << Inventory.exterior_color << endl;
	outs << "Vin............:" << Inventory.vin << endl;
	outs << "Engine Size....:" << Inventory.engine_size << endl;
	outs << "Dealer Cost....:" << Inventory.dealer_cost << endl;
	outs << "Dealer Price...:" << Inventory.dealer_price << endl << endl;
}
void BikeInventory::delete_car()
{
	BikeInventory Inventory[100];
	int car_num;
	char choice;
	int item, i = 0;
	cout << "Enter inventory number of the motorcycle you want to delete?" << endl;
	cin >> car_num;
	item = car_num - 100;
	cout << "comfirm delete!!" << item << " ? (y/n)";
	cin >> choice;
	if (choice == 'y')
		for (int count = item; count + 1 < i + 1; count++)
			Inventory[count] = Inventory[count + 1];
	Inventory[i].initArrays();
}
int BikeInventory::search()
{
	BikeInventory Inventory[100], Auto;
	int choice, count, i = 2;
	cout << "(1) Enter Make of motorcycle...:" << endl;
	cout << "(2) Enter Model of motorcycle..:" << endl;
	cout << "(3) Display all motorcycles....:" << endl;
	cout << "(4) Enter to EXIT....:" << endl << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter Make of motorcycle:" << endl;
		Auto.get_make();
		for (count = 1; count < i; count++)
		{
			Inventory[count].Acc;
			if (Auto == Inventory[count])
				cout << "Hmm. Match found" << 100 + count << count << endl;
			else
				cout << "OOPS! Match not found, try again." << endl;
		}
		break;
	case 2:
		cout << "Enter Model of motorcycle:";
		Auto.get_model();
		for (count = 1; count < i; count++)
		{
			Inventory[count].Mut;
			if (Auto == Inventory[count])
				cout << "Match found" << count << endl;
			else
				cout << "Match not found, try again." << endl;
		}
		break;
	case 3:
		Auto.output_info(cout, *Inventory);
		break;
	case 4:
		exit(0);
		break;
	}
	return 0;
}