#include "CarDealership.h"

CarDealership::CarDealership() : ID_{ 0 } { loadFromFile("data.txt"); };

void CarDealership::addNewCar(string name_, int yearOfProd_, double engineDispl_, double price_)
{
	CarInfo temp;

	temp.id = ++ID_;
	temp.name = name_;
	temp.yearOfProd = yearOfProd_;
	temp.engineDispl = engineDispl_;
	temp.price = price_;

	carsData.push_back(temp);
	saveInFile("data.txt");
}

void CarDealership::removeCar(int id_)
{
	int t{ 0 };
	for (list<CarInfo>::iterator i = carsData.begin(); i != carsData.end(); i++)
	{
		++t;
		if (t == id_)
		{
			carsData.erase(i);
			break;
		}
	}
	saveInFile("data.txt");
}

void CarDealership::findCar(string key_)
{
	cout << "\n\t KEYWORD: " << key_ << '\n';
	cout << "-------------------------------------------------------------------------\n";
	cout << "|                              SEARCH RESULT                            |\n";
	cout << "-------------------------------------------------------------------------\n"
		<< "|       Name       Year of production       Engine            Price     |\n"
		<< "|                      production        Displacement                   |\n"
		<< "-------------------------------------------------------------------------\n";

	for (auto& t : carsData)
	{
		if (std::to_string(t.id) == key_ || t.name == key_ || std::to_string(t.engineDispl) == key_
			|| std::to_string(t.yearOfProd) == key_ || std::to_string(t.price) == key_)
		{
			cout << std::fixed << std::setprecision(2) <<
				"| " << t.id << ". " << t.name << "\t " <<
				t.yearOfProd << "\t\t     " << t.engineDispl <<
				"\t    " << std::setprecision(1) << t.price << "\t|\n";
		}
	}
	cout << "-------------------------------------------------------------------------\n";
}

void CarDealership::sortCars(int choice_)
{
	switch (choice_)
	{
	case 1:
	{
		carsData.sort([](const CarInfo& a, const CarInfo& b) { return a.name[0] < b.name[0]; });
		break;
	}
	case 2:
	{
		carsData.sort([](const CarInfo& a, const CarInfo& b) { return a.yearOfProd < b.yearOfProd; });
		break;
	}
	case 3:
	{
		carsData.sort([](const CarInfo& a, const CarInfo& b) { return a.engineDispl < b.engineDispl; });
		break;
	}
	case 4:
	{
		carsData.sort([](const CarInfo& a, const CarInfo& b) { return a.price < b.price; });
		break;
	}
	default:
		return;
	}
	saveInFile("data.txt");
}

void CarDealership::showAll()
{
	loadFromFile("data.txt");
	cout << "-------------------------------------------------------------------------\n"
		<< "|       Name       Year of production       Engine            Price     |\n"
		<< "|                      production        Displacement                   |\n"
		<< "-------------------------------------------------------------------------\n";

	for (auto& t : carsData)
	{
		cout << std::fixed << std::setprecision(2) <<
			"| " << t.id << ". " << t.name << "\t " <<
			t.yearOfProd << "\t\t     " << t.engineDispl <<
			"\t    " << std::setprecision(1) << t.price << "\t|\n";
	}

	cout << "-------------------------------------------------------------------------\n";
	saveInFile("data.txt");
}

void CarDealership::loadFromFile(string fileName_)
{
	CarInfo temp;
	carsData.clear();

	fstream f;
	f.open(fileName_, ios::in);
	if (!f.is_open())
	{
		cout << "Error Input file\n";
		exit(2);
	}
	while (!f.eof())
	{
		f >> temp.id >> temp.name >> temp.yearOfProd >> temp.engineDispl >> temp.price;
		carsData.push_back(temp);
	}
	f.close();
}

void CarDealership::saveInFile(string fileName_)
{
	correctIds();
	fstream f;
	f.open(fileName_, ios::out);
	if (!f.is_open())
	{
		cout << "Error Output file\n";
		exit(1);
	}
	for (auto& t : carsData)
	{
		f << t.id << '\t' << t.name << '\t' << t.yearOfProd << '\t'
			<< t.engineDispl << '\t' << t.price;
		if (t.id != ID_)
			f << '\n';
	}
	f.close();
}

void CarDealership::correctIds()
{
	ID_ = 0;
	for (auto& t : carsData)
		t.id = ++ID_;
}