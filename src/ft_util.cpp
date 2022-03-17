#include "../includes/ohmylib.hpp"

string get_date(void)
{
	string	date = "";
	time_t init_time = time(0);

	tm *time_now = localtime(&init_time);
	date += to_string(time_now->tm_mday) + "/"	\
	+ to_string(time_now->tm_mon) + "/"			\
	+ to_string(time_now->tm_year + 1900) + " "	\
	+ to_string(time_now->tm_hour) + ":"		\
	+ to_string(time_now->tm_min);
	return (date);
}

int check_name(string text)
{
	size_t	i;

	i = 0;
	while (text[i])
	{
		if (!isalpha(text[i]))
			return (0);
		i++;
	}
	return (1);
}

string color(string str, unsigned char color)
{
	return ("\x1b[38;5;" + to_string(color) + "m" + str + "\e[0m");
}
