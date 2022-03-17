#include "../includes/ohmylib.hpp"

void admin::add_records(void)
{
	clear();
	header("Add Records");
	cout << endl;
	string	name, surname, buff;

	date = get_date();
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

	fullname = name + " " + surname;

	cout << "Enter patient details: ";
	getline(cin, data);
	getline(cin, data);

	rename("records.txt", "old_records.txt");
	ifstream	old_file("old_records.txt");
	ofstream	new_file("records.txt");
	while (getline(old_file, buff))
		new_file << buff << endl;
	new_file << fullname << "," << date << "," << data << endl;
	old_file.close();
	new_file.close();
	remove("old_records.txt");
	cout << endl;
	cout << color("Add Records complete!\nPress Enter to continue...\n", 49);
	(void) getchar();
}

int admin::remove_records(void)
{
	int		state = 0;
	size_t	count = 0, i, space_size = 1;
	string	buff, input;

	ifstream	old_file("records.txt");

	clear();
	header("Remove Records");
	cout << endl;

	while (getline (old_file, buff))
		count++;
	old_file.close();

	if (count == 0)
	{
		cout << color("No Records file!\n\n", 198);
		cout << color("Press Enter to continue...\n", 49);
		(void) getchar();
		(void) getchar();
		return (0);
	}

	count = 0;
	cout << "index\tName\t\t\t\tdate\t\t\tdetails\n";
	rename("records.txt", "old_records.txt");
	old_file.open("old_records.txt");
	while (getline (old_file, buff))
	{
		fullname = buff.substr(0, buff.find(","));

		buff = buff.substr(buff.find(",") + 1, buff.length());
		date = buff.substr(0, buff.find(","));

		buff = buff.substr(buff.find(",") + 1, buff.length());
		data = buff.substr(0, buff.find(","));

		if (fullname.length() < 32)
			space_size = 32 - fullname.length();

		cout << "[" << to_string(count + 1) << "]\t" << fullname;

		for (size_t i = 0; i < space_size; i++)
			cout << " ";

		cout << date;
		if (date.length() < 16)
			cout << "\t\t";
		else
			cout << "\t";
		cout << data << endl;
		count++;
	}
	old_file.close();

	cout << endl;

	do
	{
		cout << "Enter index of data to delete or Enter q to exit: ";
		cin >> input;
		if (input == "q" || input == "Q")
			state = 2;
		for (i = 0; i < count; i++)
			if (to_string(i + 1) == input)
				state = 1;
		if (!state)
			cout << color("data not found! Enter index only!\n", 198);
	} while (!state);

	if (state == 2)
	{
		rename("old_records.txt", "records.txt");
		return (1);
	}

	ofstream	new_file("records.txt");

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
	cout << endl;
	cout << color("Remove Records complete!\nPress Enter to continue...\n", 49);
	(void) getchar();
	(void) getchar();
	return (1);
}
