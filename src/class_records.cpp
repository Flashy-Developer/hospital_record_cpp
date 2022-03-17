#include "../includes/ohmylib.hpp"

int records::login(void)
{
	string	raw_data, name, date, data;
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

void records::show_records(void)
{
	size_t	space_size = 1;
	string	raw_data, name, date, data;
	fstream	file("records.txt");
	clear();
	cout << endl;
	cout << "Name\t\t\t\tdate\t\t\tdetails\n";
	while (getline (file, raw_data))
	{
		name = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		date = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		data = raw_data.substr(0, raw_data.find(","));

		if (name.length() < 32)
			space_size = 32 - name.length();

		cout << name;

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
}

void records::show_records(string username)
{
	size_t	space_size = 0;
	string	raw_data, name, date, data, space;
	fstream	file("records.txt");

	clear();
	cout << endl;
	cout << "Name\t\t\t\tdate\t\t\tdetails\n";
	while (getline (file, raw_data))
	{
		name = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		date = raw_data.substr(0, raw_data.find(","));

		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		data = raw_data.substr(0, raw_data.find(","));

		if (name.length() < 32)
			space_size = 32 - name.length();
		space = "";

		for (size_t i = 0; i < space_size; i++)
			space += " ";

		if (username == name)
			cout << name << space << date << "\t\t" << data << endl;
	}
	cout << endl;
	file.close();
}
