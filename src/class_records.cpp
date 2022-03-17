#include "../includes/ohmylib.hpp"

int records::login(void)
{
	string	raw_data, name;
	fstream	file("records.txt");
	while (getline (file, raw_data))
	{
		raw_data = raw_data.substr(0, raw_data.length() - 1);
		name = raw_data.substr(0, raw_data.find(","));
		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		date = raw_data.substr(0, raw_data.find(","));
		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		data = raw_data.substr(0, raw_data.find(","));
		if (name == fullname)
		{
			file.close();
			return (1);
		}
	}
	file.close();
	return (0);
}

int records::login(string pwd)
{
	string	raw_data, username, pass;
	fstream	file("admin.txt");
	while (getline (file, raw_data))
	{
		username = raw_data.substr(0, raw_data.find(","));
		pass = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		if (username == user && pwd == pass)
		{
			file.close();
			return (1);
		}
	}
	file.close();
	return (0);
}

int records::show_records(void)
{
	size_t	 count = 0, space_size = 1;
	string	raw_data;
	fstream	file("records.txt");
	clear();
	header("all records");
	cout << endl;

	while (getline (file, raw_data))
		count++;
	file.close();

	if (count == 0)
	{
		cout << color("No Records file!\n\n", 198);
		cout << color("Press Enter to continue...\n", 49);
		(void) getchar();
		(void) getchar();
		return (0);
	}

	file.open("records.txt");
	cout << "Name\t\t\t\tdate\t\t\tdetails\n";
	while (getline (file, raw_data))
	{
		fullname = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		date = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		data = raw_data.substr(0, raw_data.find(","));

		if (fullname.length() < 32)
			space_size = 32 - fullname.length();

		cout << fullname;

		for (size_t i = 0; i < space_size; i++)
			cout << " ";

		cout << date;
		if (date.length() < 16)
			cout << "\t\t";
		else
			cout << "\t";
		cout << data << endl;
	}
	file.close();
	cout << endl;
	cout << color("Press Enter to continue...\n", 49);
	(void) getchar();
	(void) getchar();
	return (1);
}

int records::show_records(string username)
{
	size_t	space_size = 0;
	string	raw_data, fullname, space;
	fstream	file("records.txt");

	clear();
	header(username + "'s Records");
	cout << endl;
	cout << "Name\t\t\t\tdate\t\t\tdetails\n";
	while (getline (file, raw_data))
	{
		fullname = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		date = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		data = raw_data.substr(0, raw_data.find(","));

		if (fullname == username)
		{
			if (fullname.length() < 32)
				space_size = 32 - fullname.length();

			cout << fullname;

			for (size_t i = 0; i < space_size; i++)
				cout << " ";

			cout << date;
			if (date.length() < 16)
				cout << "\t\t";
			else
				cout << "\t";
			cout << data << endl;
		}
	}
	cout << endl;
	file.close();
	cout << color("Press Enter to continue...\n", 49);
	(void) getchar();
	(void) getchar();
	return (1);
}
