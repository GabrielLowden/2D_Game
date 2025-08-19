#include "Menu.hpp"
#include <string>

int main()
{
	std::string title = "Welcome to....";
	unsigned int x = 800;
	unsigned int y = 600;
	menu mainMenu(x, y, title);

	mainMenu.run();



	return 0;
}

