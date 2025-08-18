#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class menu {
	public:
		menu(unsigned int width, unsigned int height, const std::string& title);
		bool isOpen() const;

		void run();
		void draw(sf::RenderWindow& window);
		void handleKeyboardInput(sf::Event event);
		void handleMouseInput(sf::Vector2f mousePos);
	    int getPressedItem();
		void addItem(const std::string& text);
		void setBackgroundTexture(const std::string& filename);
		void setSelectionSound(const std::string& filename);
		void animateSelection();


	private:
		sf::RenderWindow window;
		sf::Font font;
		std::vector<sf::Text> menuItems;
		int selectedItem;



};