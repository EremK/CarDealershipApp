//	Тема: STL часть 2
// 
//	Задание 1.
//	Создайте приложение для работы автосалона.Необходимо
//	хранить информацию о продаваемых автомобилях(наз -
//	вание, год выпуска, объем двигателя, цену).Реализуйте
//	интерфейс для добавления данных, удаления данных,
//	отображения данных, сортировке данных по различным
//	параметрам, поиску данных по различным параметрам.
//	При реализации используйте контейнеры, функторы и
//	алгоритмы.Необходимо сохранять и загружать данные
//	из файла.Вывод на консоль и хранение данных в файле
//	необходимо выполнить в табличном виде.Желательно
//	управление и вывод на консоль выполнить динамически.

#include "CarDealership.h"

using std::cin;

int correctIntegerInput();

int main()
{
	CarDealership carDealership;

	bool prIsRunning = true;
	bool yesOrNo = 0;
	int choice = 0;

	while (prIsRunning)
	{
		cout << "------------MENU------------\n"
			<< "| 1 - add new car,        |\n"	
			<< "| 2 - delete car,         |\n"	
			<< "| 3 - show all cars,      |\n"	
			<< "| 4 - find cars,          |\n"	
			<< "| 5 - sort cars,          |\n"	
			<< "|-------------------------|\n"
			<< "| 0 - exit.               |\n"	
			<< "---------------------------\n";
		cout << "| ---> ";
		choice = correctIntegerInput();
		system("cls");

		switch (choice)
		{
		case 1:
		{
		do
		{
			string name_;
			int yearOfProd_{};
			double engineDispl_{}, price_{};

			cout << "Enter (name, yearOfProd, engineDispl, price)\n";
			cout << "| ---> ";
			cin >> name_ >> yearOfProd_ >> engineDispl_ >> price_;
			carDealership.addNewCar(name_, yearOfProd_, engineDispl_, price_);
			cin.clear();

				cout << "Continue entering data (1 - yes, 0 - no): ";
				yesOrNo = correctIntegerInput();
			} while (yesOrNo != 0);
			system("cls");
			break;
		}
		case 2:
		{
			carDealership.showAll();
			cout << '\n';

			int delOrBack;

			while (true)
			{
				cout << "---------------------------\n"
					<< "| 0 - back to main menu,  |\n"
					<< "| (ID) - del car.         |\n"
					<< "---------------------------\n";
				cout << "| ---> ";
				delOrBack = correctIntegerInput();

				if (delOrBack <= 0 || delOrBack > carDealership.size())
				{
					system("cls");
					break;
				}

				carDealership.removeCar(delOrBack);
			}
			break;
		}
		case 3:
		{
			carDealership.showAll();
			cout << '\n';
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			int searchType = 0;
			string keyWord{};

			cout << "Enter a key: ";
			cin >> keyWord;
			system("cls");

			carDealership.findCar(keyWord);
			cout << '\n';

			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			cout << "------------------------------\n"
				<< "| 1 - sort by name,           |\n"
				<< "| 2 - sort by year of prod.,  |\n"
				<< "| 3 - sort by engine displ.,  |\n"
				<< "| 4 - sort by price,          |\n"
				<< "| 0 - back to main menu.      |\n"
				<< "------------------------------\n";
			cout << "| ---> ";
			choice = correctIntegerInput();

			cout << '\n';
			carDealership.sortCars(choice);
			system("pause");
			system("cls");
			break;
		}
		default:
			prIsRunning = false;
			break;
		}
	}

	return 0;
}

int correctIntegerInput()
{
	while (1)
	{
		int value;
		cin >> value;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid input data, try again!\n"
				<< "---> ";
		}
		else
		{
			cin.ignore(32767, '\n');
			return value;
		}
	}
}
