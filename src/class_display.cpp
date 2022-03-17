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
	admin	me;
	string	choice;

	clear();
	cout << "Enter username: ";
	cin >> me.user;
	cout << "Enter password: ";
	cin >> me.password;

	if (!me.login(me.password))
		cout << color("Error! Please try again!\n", 198);
	else
	{
		cout << color("login Sucessfully!\n", 43);
		while (1)
		{
			cout << "[1] add records\n";
			cout << "[2] load all records\n";
			cout << "[3] load user records\n";
			cout << "[4] delete user records\n";
			cout << "[5] back to main menu\n";
			cout << "[6] exit\n";
			do
			{
				cout << "Please Enter Choice: ";
				cin >> choice;
				if (choice != "1" && choice != "2" && choice != "3" &&\
					choice != "4" && choice != "5" && choice != "6")
					cout << "Error! Please Enter 1-6 only\n";

			}
			while (choice != "1" && choice != "2" && choice != "3" &&\
					choice != "4" && choice != "5" && choice != "6");
			if (choice == "1")
				me.add_records();
			else if (choice == "2")
				me.show_records();
			else if (choice == "3")
			{
				string	name, surname;
				do
				{
					cout << "Enter Patient name: ";
					cin >> name;
					if (name.length() < 3)
						cout << color("Your name must more than 3 Alphabet\n", 198);
				} while (name.find(",") != (size_t) -1 || name.length() < 3 || !check_name(name));

				do
				{
					cout << "Enter Patient surname: ";
					cin >> surname;
					if (surname.length() < 3)
						cout << color("Your surname must more than 3 Alphabet\n", 198);
				} while (surname.find(",") != (size_t) -1 || surname.length() < 3 || !check_name(surname));

				me.fullname = name + " " + surname;
				if (!me.login())
					cout << color("Error! User not found!\n", 198);
				else
					me.show_records(me.fullname);
			}
			else if (choice == "4")
				me.remove_records();
			else if (choice == "5")
				break;
			else
				exit(0);
		}
	}
}

void display::patient_menu(void)
{
	patient	me;
	string	name, surname,choice;

	clear();
	do
	{
		cout << "Enter Patient name: ";
		cin >> name;
		if (name.length() < 3 || !check_name(name))
			cout << color("Your name must more than 3 Alphabet\n", 198);
	} while (name.find(",") != (size_t) -1 || name.length() < 3 || !check_name(name));

	do
	{
		cout << "Enter Patient surname: ";
		cin >> surname;
		if (surname.length() < 3 || !check_name(surname))
			cout << color("Your surname must more than 3 Alphabet\n", 198);
	} while (surname.find(",") != (size_t) -1 || surname.length() < 3 || !check_name(surname));

	*me.patient_name = name + " " + surname;
	if (!me.login())
		cout << color("You have no records!\n", 198);
	else
	{
		cout << color("login Sucessfully!\n", 43);
		while (1)
		{
			cout << "[1] show your records\n";
			cout << "[2] back to main menu\n";
			cout << "[3] exit\n";
			do
			{
				cout << "Please Enter Choice: ";
				cin >> choice;
				if (choice != "1" && choice != "2" && choice != "3")
					cout << "Error! Please Enter 1-3 only\n";

			}
			while (choice != "1" && choice != "2" && choice != "3");

			if (choice == "1")
				me.show_records(*me.patient_name);
			else if (choice == "2")
				break;
			else
				exit(0);
		}
	}
}
