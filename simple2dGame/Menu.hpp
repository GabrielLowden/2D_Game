#include <SFML/Graphics.hpp>

class menu {
	public:
		//constructor
		menu(int width, int height) {};

		void draw(sf::RenderWindow& window);
		void handleKeyboardInput(sf::Event event);
		void handleMouseInput(sf::Vector2f mousePos);
		const int getPressedItem();
		void addItem(const std::string& text);
		void setBackgroundTexture(const std::string& filename);
		void setSelectionSound(const std::string& filename);
		void animateSelection();

	private:
		sf::Font font;

};