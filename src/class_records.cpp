#include "../includes/ohmylib.cpp"

int	records::check_user(void)
{
	string	raw_data, name, date, data;
	fstream	file("records.txt");
	while (getline (file, raw_data)) {
		raw_data = raw_data.substr(0, raw_data.length() - 1);
		name = raw_data.substr(0, raw_data.find(","));
		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		date = raw_data.substr(0, raw_data.find(","));
		raw_data = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		data = raw_data.substr(0, raw_data.find(","));
		if (name == user)
		{
			file.close();
			return (1);
		}
	}
	file.close();
	return (0);
}

int	records::check_user(string pwd)
{
	string	raw_data, username, pass;
	fstream	file("admin.txt");
	while (getline (file, raw_data)) {
		raw_data = raw_data.substr(0, raw_data.length() - 1);
		username = raw_data.substr(0, raw_data.find(","));
		cout << username << endl;
		pass = raw_data.substr(raw_data.find(",") + 1, raw_data.length());
		cout << pass << endl;
		if (username == user && pwd == pass)
		{
			file.close();
			return (1);
		}
	}
	file.close();
	return (0);
}
