#include "../includes/ohmylib.hpp"

int main(void)
{
	display	mydisplay;

	clear();
	mydisplay.show_logo();
	while (1)
	{
		int		role = 0;

		role = mydisplay.select_main_menu();
		if (role == 1)
			mydisplay.admin_menu();
		else if (role == 2)
			mydisplay.patient_menu();
	}
}
