#include "../includes/ohmylib.hpp"

int main( )
{
	patient me;
	string name, surname;
	me.user = "admin";
	cout << me.check_user("password") << endl;
	cout << "enter name: ";
	cin >> name;
	cout << "enter surname: ";
	cin >> surname;
	me.fullname = name + " " + surname;
	cout << "Your name is: " << me.fullname << endl;
}
