#include "../includes/ohmylib.hpp"

void admin::add_records(void)
{
	string	name, surname, buff;

	date = get_date();
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

	fullname = name + " " + surname;

	cout << "Enter patient details: ";
	cin >> data;

	rename("records.txt", "old_records.txt");
	ifstream	old_file("old_records.txt");
	ofstream	new_file("records.txt");
	while (getline(old_file, buff))
		new_file << buff << endl;
	new_file << fullname << "," << date << "," << data << endl;
	old_file.close();
	new_file.close();
	remove("old_records.txt");
}

int admin::remove_records(void)
{
	int		state = 0;
	size_t	count = 0, i;
	string	buff, input;

	rename("records.txt", "old_records.txt");
	ifstream	old_file("old_records.txt");
	ofstream	new_file("records.txt");

	clear();

	while (getline(old_file, buff))
	{
		cout << "[" << to_string(count + 1) << "] " << buff << endl;
		count++;
	}
	old_file.close();

	do
	{
		if (count == 0)
		{
			cout << color("no Records file!\n", 198);
			return (0);
		}
		cout << "Enter index of data you want to delete: ";
		cin >> input;
		for (i = 0; i < count; i++)
			if (to_string(i + 1) == input)
				state = 1;
		if (!state)
			cout << color("data not found! Enter index only!\n", 198);
	} while (!state);

	i = 0;
	old_file.open("old_records.txt");
	while (getline(old_file, buff))
	{
		if (i + 1 != (size_t) stoi(input))
			new_file << buff << endl;
		i++;
	}
	old_file.close();
	new_file.close();
	remove("old_records.txt");
	cout << "remove data Complete." << endl;
	return (1);
}
