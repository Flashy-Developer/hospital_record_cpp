#ifndef OHMYLIB_CPP
# define OHMYLIB_CPP
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <ctime>

using namespace std;

class	records
{
	public:
		string	user = "";
		string	data = "";
		string	date = "";
		string	fullname = "";

	public:
		int		check_user(void);
		int		check_user(string pass);
		void	show_records(void);
		void	show_records(string user);
};

class	patient: public records
{
	public:
		string	*patient_name = &fullname;
};

class	admin: public records
{
	protected:
		string	patient_name;
		string	password;

	protected:
		void	add_records();
};

class display
{
	public:
		void	show_menu(void);
		int		login_menu(void);
		int		select_menu(int role);
};

string	get_date(void);

#endif
