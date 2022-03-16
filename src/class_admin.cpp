#include "../includes/ohmylib.hpp"

void admin::add_records(void)
{
	string	name, surname;

	date = get_date();
	do
	{
		cout << "Enter Patient name: ";
		cin >> name;
	} while (name.find(",") != (size_t) -1 || name.length() < 3 || !check_name(name));

	do
	{
		cout << "Enter Patient surname: ";
		cin >> surname;
	} while (surname.find(",") != (size_t) -1 || surname.length() < 3 || !check_name(surname));

	fullname = name + " " + surname;

	cout << "Enter patient details: ";
	cin >> data;

	fstream	file("records.txt");
	file << fullname << "," << date << "," << data << endl;
	file.close();
}
