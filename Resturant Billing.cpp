#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

vector<string> item;
vector<int> price;
vector<int> quantityItem;
vector<int> total;

void Welcome();
void DisplayMenu();
void Manage();
void DisplayBill();
int GrandTotalBill();
void Thanks();

int main(int argc, char const* argv[])
{
	Welcome();
	Manage();
	return 0;
}

void Welcome()
{
	cout << "\t\t===========================================================" << endl;
	cout << "\t\t|                  Welcome to Restaurant                  |" << endl;
	cout << "\t\t===========================================================" << endl;
	cout << "\t\t                        | MENU |                           " << endl;
	cout << "\t\t                        ========                           " << endl;
}

void DisplayMenu()
{
	cout << "------------------------------------------------------\n";
	cout << "1. Chicken Burger        100/-\n";
	cout << "2. Kabab                 120/-\n";
	cout << "3. Chicken Tikka         130/-\n";
	cout << "4. Chicken Boti          140/-\n";
	cout << "5. Karahi               1300/-\n";
	cout << "6. Qourma                800/-\n";
	cout << "7. Tea                    50/-\n";
	cout << "8. Naan                   30/-\n";
	cout << "9. Coffee                 60/-\n";
	cout << "10.Mutton               1500/-\n";
	cout << "------------------------------------------------------\n";
}

void Manage()
{
	int choice, quantity;
	char ch = 0, cond = 0;
	do
	{
		do
		{
			DisplayMenu();
			cout << "What would you like to order? OR press 0 to Exit! : ";
			cin >> choice;
			if (choice == 0) {
				Thanks();
				exit(0);
			}
			cout << "Enter the desired quantity : ";
			cin >> quantity;
			cout << "Do you want to calculate bill? (y/n) : ";
			cin >> ch;

			switch (choice)
			{
			case 1:
				item.push_back("Chicken Burger");
				price.push_back(100);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 100);
				break;
			case 2:
				item.push_back("Kabab");
				price.push_back(120);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 120);
				break;
			case 3:
				item.push_back("Chicken Tikka");
				price.push_back(130);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 130);
				break;
			case 4:
				item.push_back("Chicken Boti");
				price.push_back(140);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 140);
				break;
			case 5:
				item.push_back("Karahi");
				price.push_back(1300);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 1300);
				break;
			case 6:
				item.push_back("Qourma");
				price.push_back(800);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 800);
				break;
			case 7:
				item.push_back("Tea");
				price.push_back(50);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 50);
				break;
			case 8:
				item.push_back("Naan");
				price.push_back(30);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 30);
				break;
			case 9:
				item.push_back("Coffee");
				price.push_back(60);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 60);
				break;
			case 10:
				item.push_back("Mutton");
				price.push_back(1500);
				quantityItem.push_back(quantity);
				total.push_back(quantity * 1500);
				break;
			default:
				cout << "Invalid order choice" << endl;
				char chr;
				cout << "Wannaa run again ? : ";
				cin >> chr;
				if (chr == 'y' || chr == 'Y') {
					Manage();
				}
				else {
					Thanks();
					exit(0);
				}
			}

		} while (ch == 'n' || ch == 'N');

		if (ch == 'y' || ch == 'Y')
		{
			DisplayBill();
		}

		cout << "Do you want to run the program again ? (y/n) : ";
		cin >> cond;
	} while (cond == 'y' || cond == 'Y');


}

void DisplayBill()
{
	cout << "\n\n";
	cout << "                        --------                           " << endl;
	cout << "                        | Bill |                           " << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|Name|          |Quantity|          |Price|         |Total| " << endl;
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0; i < item.size(); i++)
	{
		cout << left << setw(15) << item[i]
			<< right << setw(7) << quantityItem[i]
			<< right << setw(19) << price[i]
			<< right << setw(16) << total[i]
			<< endl;
	}
	cout << "-----------------------------------------------------------" << endl;
	cout << "|                  Grand Total = Rs." << GrandTotalBill() << setw(20) << "|" << endl;
	cout << "-----------------------------------------------------------" << endl;
	Thanks();
}

int GrandTotalBill()
{
	int GrandTotal = 0;
	for (int i = 0; i < total.size(); i++)
	{
		GrandTotal += total[i];
	}
	return GrandTotal;
}

void Thanks()
{
	cout << "\n\n";
	cout << "\t\t-----------------------------------------------------------" << endl;
	cout << "\t\t|                 Thanks For Visiting Us.                 | " << endl;
	cout << "\t\t-----------------------------------------------------------" << endl;
	cout << "\n\n";
}