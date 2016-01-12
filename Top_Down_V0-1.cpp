#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

struct name_entity
{
	
	// name in text form
	
	const std::string m_entity_name{"Chiaki"};
	
	sf::Font m_font;
	
	const std::string m_font_name{"VeraMono-Bold.ttf"};
	
	const float m_text_size{20.0f};
	
	sf::Vector2f m_position{0.0f, 0.0f};
	
	const sf::Color m_color{255, 255, 255};
	
	sf::Text m_text;
	
	name_entity(const std::string& name, const float size, const sf::Vector2f& posit, const sf::Color& color);
	
	~name_entity();
		
};

name_entity::name_entity(const std::string& name, const float size, const sf::Vector2f& posit, const sf::Color& color)
	:m_entity_name(name), m_font(), m_text_size(size), m_position(posit), m_color(color), m_text()
{
	
	assert(m_entity_name != "");	
	assert(m_text_size > 0.0f);
	
	if (!m_font.loadFromFile(m_font_name))
	{
			
		std::cout << m_font_name << " not found!\n";		
		std::cout << "Error -2\n";		
		exit (EXIT_FAILURE);
			
	}
	
	m_text.setFont(m_font);
	m_text.setCharacterSize(m_text_size);	
	m_text.setColor(m_color);	
	m_text.setString(m_entity_name);	
	// origin_from_text(m_text);	
	m_text.setPosition(m_position);
	
}

name_entity::~name_entity()
{
	
}

void show_name_ent(sf::RenderWindow& window, const name_entity& nament)
{
	
	window.draw(nament.m_text);
	
}

struct value_ent
{
	
	// value in text form
	
};

struct tria_ent
{
	
	// triangle
	
};

struct circ_ent
{
	
	// circle
	
};

struct rect_ent
{
	
	// rectangle
	
};

int main()
{
	
	const std::string program_name{"Top Down V0.1"};
	
	assert(program_name != "");
	
	const float window_x{800.0f};
	const float window_y{600.0f};	
		
	assert(window_x > 0.0f);	
	assert(window_y > 0.0f);
	
	const sf::Vector2f window_sizes{window_x, window_y};
	
	const int delaz{5};	
	assert(delaz > 0);
	
	const std::chrono::milliseconds delay(delaz);
	
	const sf::Color white{sf::Color(255, 255, 255)};	
	const sf::Color black{sf::Color(0, 0, 0)};	
	const sf::Color orange{sf::Color(255, 127, 0)};	
	const sf::Color purple{sf::Color(127, 0, 255)};	
	const sf::Color cyan{sf::Color(127, 255, 255)};
	const sf::Color red{sf::Color(255, 0, 0)};
	const sf::Color yellow{sf::Color(255, 255, 0)};
	const sf::Color green{sf::Color(0, 255, 0)};
	const sf::Color blue{sf::Color(0, 0, 255)};	
	
	const std::string nament_name{"Alesta"};
	
	const float nament_size{15};
	
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), program_name, sf::Style::Default);
	
	const sf::Vector2f nament_posit{0.25f*window_sizes};
	
	name_entity nament{nament_name, nament_size, nament_posit, yellow};
	
	while (window.isOpen())
	{

		sf::Event event;
		
		window.clear(black);
		
		show_name_ent(window, nament);
		
		window.display();
		
		std::this_thread::sleep_for(delay);
					
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			
			window.close();
					
			return 1;
					
		}	
		
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
			{
				
				window.close();
				
				return 2;
				
			}
		
		}
			

	}
	
	return 0;

}
