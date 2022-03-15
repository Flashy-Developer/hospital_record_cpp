#include "../includes/ohmylib.hpp"

int display::select_main_menu(void)
{
    string	choice;
    cout << "[1] admin\n";
    cout << "[2] patient\n";
    cout << "[3] exit\n";
    cout << "Please Enter Choice: ";
    cin >> choice;
    if(choice == "1")
		return (1);
	else if (choice == "2")
        return (2);
    else if(choice == "3")
        exit(0);
    else
    {
        cout << "Error! Please Enter 1-3 only\n";
        return (0);
    }
}
