#include "../includes/ohmylib.cpp"

string	get_date(void)
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
