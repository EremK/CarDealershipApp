#pragma once
#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <string>
#include <list>
#include <iomanip>
#include <functional>

using std::string;
using std::list;
using std::cout;
using std::fstream;
using std::ios;

class CarDealership
{
	int ID_;

	struct CarInfo
	{
		int id{};
		string name{};
		int yearOfProd{};
		double engineDispl{};
		double price{};
	};

	list<CarInfo> carsData{};

public:

	CarDealership();

	void addNewCar(string name_, int yearOfProd_, double engineDispl_, double price_);

	void removeCar(int id_);

	void findCar(string key_);

	void sortCars(int choice_);

	void showAll();

	void loadFromFile(string fileName_);

	void saveInFile(string fileName_);

	int size() { return carsData.size(); }

private:
	void correctIds();
};