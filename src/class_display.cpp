#include "../includes/ohmylib.hpp"

int display::select_main_menu(void)
{
	string	choice;
	cout << "[1] admin\n";
	cout << "[2] patient\n";
	cout << "[3] exit\n";
	do
	{
		cout << "Please Enter Choice: ";
		cin >> choice;
		if (choice != "1" && choice != "2" && choice != "3")
			cout << "Error! Please Enter 1-3 only\n";

	} while (choice != "1" && choice != "2" && choice != "3");

	if(choice == "1")
		return (1);
	else if (choice == "2")
		return (2);
	else if(choice == "3")
		exit(0);
	else
		return (0);
}

void display::admin_menu(void)
{
	admin me;
	cout << "Enter username: ";
	cin >> me.user;
	cout << "Enter password: ";
	cin >> me.password;
	if (!me.login(me.password))
		cout << "Error! Please try again!\n";
	else
	{
		cout << "login Sucessfully!\n";
		// me.add_records();
	}
}

void display::patient_menu(void)
{
	patient	me;
	string	name, surname;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter surname: ";
	cin >> surname;
	*me.patient_name = name + " " + surname;
	if (!me.login())
		cout << "Error! Please try again!\n";
	else
	{
		cout << "login Sucessfully!\n";
	}
}

