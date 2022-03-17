#include "../includes/ohmylib.hpp"

int display::select_main_menu(void)
{
	string	choice;

	header("Main Menu");
	cout << endl;
	cout << "[1] login as admin\n";
	cout << "[2] login as patient\n";
	cout << "[3] exit\n";
	cout << endl;
	do
	{
		cout << color("Please enter your choice: ", 220);
		cin >> choice;
		if (choice != "1" && choice != "2" && choice != "3")
			cout << color("Error! Please Enter 1-3 only\n", 198);

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
	header("Admin login page");
	cout << endl;
	cout << "Enter username: ";
	cin >> me.user;
	cout << "Enter password: ";
	cin >> me.password;

	if (!me.login(me.password))
	{
		cout << color("Error! Please try again!\n\n", 198);
		cout << "Press Enter to continue...\n";
		(void) getchar();
		(void) getchar();
		clear();
	}
	else
	{
		cout << color("login Sucessfully!\n", 43);
		system("sleep 1");
		while (1)
		{
			clear();
			header("admin menu");
			cout << endl;
			cout << "[1] add records\n";
			cout << "[2] load all records\n";
			cout << "[3] load user records\n";
			cout << "[4] delete records\n";
			cout << "[5] back to main menu\n";
			cout << "[6] exit\n";
			cout << endl;
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
				clear();
				header("user records");
				cout << endl;
				string	name, surname;
				do
				{
					cout << "Enter Patient name: ";
					cin >> name;
					if (name.length() < 3)
						cout << color("Your name must more than 3 Alphabet\n", 198);
					else if (!check_name(name))
						cout << color("Your name must be Alphabet only! \n", 198);
				} while (name.find(",") != (size_t) -1 || name.length() < 3 || !check_name(name));

				do
				{
					cout << "Enter Patient surname: ";
					cin >> surname;
					if (surname.length() < 3)
						cout << color("Your surname must more than 3 Alphabet!\n", 198);
					else if (!check_name(surname))
						cout << color("Your surname must be Alphabet only! \n", 198);
				} while (surname.find(",") != (size_t) -1 || surname.length() < 3 || !check_name(surname));

				me.fullname = name + " " + surname;
				if (!me.login())
				{
					cout << color("Error! User not found!\n\n", 198);
					cout << "Press Enter to continue...\n";
					(void) getchar();
					(void) getchar();
				}
				else
					me.show_records(me.fullname);
			}
			else if (choice == "4")
				me.remove_records();
			else if (choice == "5")
			{
				clear();
				break;
			}
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
	header("Patient login page");
	cout << endl;
	do
	{
		cout << "Enter Patient name: ";
		cin >> name;
		if (name.length() < 3)
			cout << color("Your name must more than 3 Alphabet\n", 198);
		else if (!check_name(name))
			cout << color("Your name must be Alphabet only! \n", 198);
	} while (name.find(",") != (size_t) -1 || name.length() < 3 || !check_name(name));

	do
	{
		cout << "Enter Patient surname: ";
		cin >> surname;
		if (surname.length() < 3)
			cout << color("Your surname must more than 3 Alphabet!\n", 198);
		else if (!check_name(surname))
			cout << color("Your surname must be Alphabet only! \n", 198);
	} while (surname.find(",") != (size_t) -1 || surname.length() < 3 || !check_name(surname));

	*me.patient_name = name + " " + surname;
	if (!me.login())
	{
		cout << color("You have no records!\n\n", 198);
		cout << "Press Enter to continue...\n";
		(void) getchar();
		(void) getchar();
		clear();
	}
	else
	{
		cout << color("login Sucessfully!\n", 43);
		system("sleep 1");
		while (1)
		{
			clear();
			header("Patient menu");
			cout << endl;
			cout << "[1] show your records\n";
			cout << "[2] back to main menu\n";
			cout << "[3] exit\n";
			cout << endl;
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
			{
				clear();
				break;
			}
			else
				exit(0);
		}
	}
}

void display::show_logo(void)
{
	string logo = "\n\n\n\n\
\t\t                                           @@@@\n\
\t\t                                           @@@@\n\
\t\t                                       @@@@@@@@@@@@\n\
\t\t                                       @@@@@@@@@@@@\n\
\t\t                                           @@@@\n\
\t\t                                           @@@@\n\
\t\t      @@@@@        @@@@@   @@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@\n\
\t\t     @@@@@        @@@@@@   @@@@@      @@@@@@  @@@@@        @\n\
\t\t     @@@@@        @@@@@   @@@@@       @@@@@@ @@@@@@\n\
\t\t    @@@@@@@@@@@@@@@@@@@   @@@@@      @@@@@@   @@@@@@@@@@@%\n\
\t\t    @@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@          @@@@@@@@\n\
\t\t   @@@@@        @@@@@    @@@@@@@@@@#                  @@@@@\n\
\t\t   @@@@@        @@@@@   @@@@@   @@@@@#     @@@@@@@@@@@@@@@\n\
\t\t  @@@@@        @@@@@    @@@@@    @@@@@#   @@@@@@@@@@@@@\n\n\n";

	cout << color(logo, 16);
	system("sleep 0.2");
	clear();
	cout << color(logo, 22);
	system("sleep 0.3");
	clear();
	cout << color(logo, 28);
	system("sleep 0.4");
	clear();
	cout << color(logo, 35);
	system("sleep 0.5");
	clear();
	cout << color(logo, 42);
	system("sleep 0.6");
	clear();
	cout << color(logo, 48);
	system("sleep 0.6");
	clear();
}


void display::header(string str)
{
	size_t space;
	string line;
	line = "######################################################################\n";
	cout << color(line, 48);

	line = "#                                                                    #\n";
	cout << color(line, 42);

	line = "#";
	space = 35 - (str.length() / 2);
	for (size_t i = 0; i < space; i++)
		line += " ";
	line += str;
	while (line.length() < 69)
		line += " ";
	line += "#\n";
	cout << color(line, 41);

	line = "#                                                                    #\n";
	cout << color(line, 47);

	line = "######################################################################\n";
	cout << color(line, 40);
}
