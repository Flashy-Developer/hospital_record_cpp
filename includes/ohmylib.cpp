#ifndef OHMYLIB_CPP
# define OHMYLIB_CPP
# include <iostream>
# include <string>
# include <ctime>

using namespace std;

class	records
{
	public:
		string	user = "";
		string	data = "";
		string	date = "";

	public:
		int		check_user(void);
		int		check_user(string pass);
		void	load_data(void);
		void	show_records(void);
		void	show_records(string user);
};

class	patient: public records
{
	public:
		string	*patient_name = &user;
};

class	admin: public records
{
	protected:
		string	patient_name;
		string	pwd;

	protected:
		int		check_admin();
		void	add_records();
};

string	get_date(void);

#endif
