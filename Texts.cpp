#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

std::wstring number_to_wstring(const double number)
{
	
	std::wstringstream wstringer;
	wstringer << L"€" << number;
	return wstringer.str();
	
}


double value_to_radius(const double value, const double normal_radius)
{
	
	const double normal_value{100};
	
	return sqrt(abs(value)/normal_value)*normal_radius;
	
}

void init_posits(const int amount_x, const int amount_y, std::vector <sf::Vector2f>& posits,
				const sf::Vector2f& posit, const sf::Vector2f& jump)
{
	
	assert(amount_x > 0);
	assert(amount_y > 0);
	
	int counter_y{0};
	assert(counter_y == 0);
	
	while (counter_y < amount_y)
	{
		
		int counter_x{0};
		assert(counter_x == 0);
		
		while (counter_x < amount_x)
		{
			
			const sf::Vector2f temp_posit{posit.x + static_cast<float>(counter_x)*jump.x,
									posit.y + static_cast<float>(counter_y)*jump.y};
			
			posits.push_back(temp_posit);
			
			++counter_x;
			
		}
		
		++counter_y;
		
	}
		
}

void origin_from_text(sf::Text& text)
{
	
	sf::FloatRect float_rect{text.getLocalBounds()};
	
	text.setOrigin(0.5*float_rect.width, 0.5*float_rect.height);
	
}

struct text_entity
{
	
	double textent_value_{0};
	
	std::wstring textent_wstring_{number_to_wstring(textent_value_)};
	
	sf::Font text_font_;
	
	std::string text_name_{"Ipanema_Secco.ttf"};		
	
	const double text_size_{10};
	
	sf::Vector2f text_posit_{0, 0};
	
	sf::Vector2f text_origin_{0, 0};
	
	sf::Color text_color_{255, 255, 255};
	
	sf::Text textent_text_;
	
	text_entity(const double value, const double size, const sf::Vector2f& posit, const sf::Color& color);
	
	~text_entity();
	
};

text_entity::text_entity(const double value, const double size, const sf::Vector2f& posit, const sf::Color& color)
	:textent_value_(value), textent_wstring_(number_to_wstring(textent_value_)), text_font_(),
	text_size_(size), text_posit_(posit), text_origin_(), text_color_(color), textent_text_()
{
	
	assert(textent_wstring_ != L"");
	
	if (!text_font_.loadFromFile(text_name_))
	{
			
		std::cout << text_name_ << " not found!\n";		
		std::cout << "Error -2\n";		
		exit (EXIT_FAILURE);
			
	}
	
	textent_text_.setFont(text_font_);
	textent_text_.setCharacterSize(text_size_);	
	textent_text_.setColor(text_color_);	
	textent_text_.setString(textent_wstring_);	
	origin_from_text(textent_text_);	
	textent_text_.setPosition(text_posit_);
	
}

text_entity::~text_entity()
{
		
}

void show_textent(sf::RenderWindow& window, const text_entity& textent)
{
	
	// std::cout << 
	
	// window.draw(textent.textent_text_);
	
}
