#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

std::wstring number_to_wstring(const float number)
{
	
	std::wstringstream wstringer;
	wstringer << L"€" << number;
	return wstringer.str();
	
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
	
	text.setOrigin(0.5f*float_rect.width, 0.95f*float_rect.height);
	
}

struct text_entity
{
	
	float textent_value_{0.0f};
	
	std::wstring textent_wstring_{number_to_wstring(textent_value_)};
	
	sf::Font text_font_;
	
	std::string text_name_{"Ipanema_Secco.ttf"};		
	
	const float text_size_{10.0f};
	
	sf::Vector2f text_posit_{0.0f, 0.0f};
	
	sf::Vector2f text_origin_{0.0f, 0.0f};
	
	sf::Color text_color_{255, 255, 255};
	
	sf::Text textent_text_;
	
	text_entity(const float value, const float size, const sf::Vector2f& posit, const sf::Color& color);
	
	~text_entity();
	
};

text_entity::text_entity(const float value, const float size, const sf::Vector2f& posit, const sf::Color& color)
	:textent_value_(value), textent_wstring_(number_to_wstring(textent_value_)), text_font_(),
	text_size_(size), text_posit_(posit), text_color_(color), textent_text_()
{
		
	assert(textent_wstring_ != L"");	
	assert(text_size > 0.0f);
	
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

void revalue_textent(text_entity& textent, const float value)
{
	
	textent.textent_value_ = value;	
	textent.textent_wstring_ = number_to_wstring(textent.textent_value_);
	textent.textent_text_.setString(textent.textent_wstring_);	
	origin_from_text(textent.textent_text_);	
		
}

void set_textent(text_entity& textent)
{
	
	textent.textent_text_.setCharacterSize(textent.text_size_);	
	textent.textent_text_.setColor(textent.text_color_);	
	textent.textent_text_.setString(textent.textent_wstring_);	
	origin_from_text(textent.textent_text_);	
	textent.textent_text_.setPosition(textent.text_posit_);
		
}

void show_textent(sf::RenderWindow& window, const text_entity& textent)
{
	
	window.draw(textent.textent_text_);
	
}

float value_to_radius(const float value, const float norm_radius)
{
	
	const float norm_value{100.0f};
	assert(norm_value > 0.0f);
	
	return sqrt(abs(value)/norm_value)*norm_radius;
	
}

struct circle_entity
{
	
	float circlent_value_{0.0f};
	
	const float circlent_norm_radius_{100.0f};
	
	float circlent_circle_radius_{value_to_radius(circlent_value_, circlent_norm_radius_)};
	
	sf::CircleShape circlent_circle_{circlent_circle_radius_};
	
	sf::Vector2f circlent_circle_posit_{0.0f, 0.0f};
	
	const sf::Color circlent_white_{255, 255, 255};
	const sf::Color circlent_red_{255, 0, 0};
	const sf::Color circlent_green_{0, 255, 0};
		
	sf::Color circlent_circle_color_{circlent_green_};
	
	const float circlent_textent_ratio_{1.0f};
	
	sf::Vector2f circlent_textent_posit_{0.0f, 0.0f};
	
	sf::Color circlent_textent_color_{circlent_white_};
	
	text_entity circlent_textent_{circlent_value_, circlent_textent_ratio_*circlent_norm_radius_,
								circlent_circle_posit_, circlent_textent_color_};
								
	circle_entity(const double value, const double norm_radius,	const sf::Vector2f& posit);
				
	~circle_entity();
	
};

void revalue_circlent(circle_entity& circlent, const float value)
{
	
	circlent.circlent_value_ = value;
	circlent.circlent_circle_radius_ = value_to_radius(circlent.circlent_value_, circlent.circlent_norm_radius_);
	
	circlent.circlent_circle_.setRadius(circlent.circlent_circle_radius_);
	circlent.circlent_circle_.setOrigin(circlent.circlent_circle_radius_, circlent.circlent_circle_radius_);
	circlent.circlent_circle_.setPosition(circlent.circlent_circle_posit_);
	
	circlent.circlent_textent_posit_ = circlent.circlent_circle_posit_;
	
	if (value > 0)
	{
		
		circlent.circlent_circle_color_ = circlent.circlent_green_;
		
	}
	else
	{
		
		circlent.circlent_circle_color_ = circlent.circlent_red_;
		
	}
	
	circlent.circlent_circle_.setFillColor(circlent.circlent_circle_color_);

	revalue_textent(circlent.circlent_textent_, value);
	
	circlent.circlent_textent_posit_.y -= circlent.circlent_circle_radius_ +
								0.6*circlent.circlent_textent_ratio_*circlent.circlent_norm_radius_;

	circlent.circlent_textent_.textent_text_.setPosition(circlent.circlent_textent_posit_);
		
}

circle_entity::circle_entity(const double value, const double norm_radius, const sf::Vector2f& posit)
	:circlent_value_(value), circlent_norm_radius_(norm_radius),
	circlent_circle_radius_(value_to_radius(circlent_value_, circlent_norm_radius_)),
	circlent_circle_(circlent_circle_radius_), circlent_circle_posit_(posit),
	circlent_textent_posit_(circlent_circle_posit_),
	circlent_textent_(circlent_value_, circlent_textent_ratio_*circlent_norm_radius_,
					circlent_circle_posit_, circlent_textent_color_)
	
{
	
	assert(circlent_norm_radius_ > 0);
	assert(circlent_textent_ratio_ > 0);
		
	circlent_circle_.setOrigin(circlent_circle_radius_, circlent_circle_radius_);
	circlent_circle_.setPosition(circlent_circle_posit_);
	
	if (value > 0)
	{
		
		circlent_circle_color_ = circlent_green_;
		
	}
	else
	{
		
		circlent_circle_color_ = circlent_red_;
		
	}
	
	circlent_circle_.setFillColor(circlent_circle_color_);
	
	circlent_textent_posit_.y -= circlent_circle_radius_ +
								0.6*circlent_textent_ratio_*circlent_norm_radius_;

	circlent_textent_.textent_text_.setPosition(circlent_textent_posit_);
	
}

circle_entity::~circle_entity()
{
		
}

void show_circlent(sf::RenderWindow& window, const circle_entity& circlent)
{
	
	window.draw(circlent.circlent_circle_);

	show_textent(window, circlent.circlent_textent_);
	
}


int main()
{
	
	const int delaz{50};	
	assert(delaz > 0);
	
	const std::chrono::milliseconds delay(delaz);
	
	const std::string program_name{"Texts V0.2"};	
	assert(program_name != "");
	
	const sf::Color white{sf::Color(255, 255, 255)};	
	const sf::Color black{sf::Color(0, 0, 0)};	
	const sf::Color orange{sf::Color(255, 127, 0)};	
	const sf::Color purple{sf::Color(127, 0, 255)};	
	const sf::Color cyan{sf::Color(127, 255, 255)};
	const sf::Color red{sf::Color(255, 0, 0)};
	const sf::Color yellow{sf::Color(255, 255, 0)};
	const sf::Color green{sf::Color(0, 255, 0)};
	const sf::Color blue{sf::Color(0, 0, 255)};	
	
	const float window_x{800};
	const float window_y{600};	
		
	assert(window_x > 0.0f);	
	assert(window_y > 0.0f);
	
	const float mid_win_x{0.5f*window_x};
	const float mid_win_y{0.5f*window_y};
	
	const sf::Vector2f window_sizes{window_x, window_y};	
	const sf::Vector2f window_middle{mid_win_x, mid_win_y};
	const sf::Vector2f window_origin{0.0f, 0.0f};
	
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), program_name, sf::Style::Default);
	
	float value{-10000.0f};
	
	const float text_size{50.0f};
	assert(text_size > 0.0f);
	
	text_entity textent(value, text_size, window_middle, orange);
	
	const float norm_radius_ratio{0.05f};
	assert(norm_radius_ratio > 0.0f);
	
	circle_entity circlent(value, norm_radius_ratio*window_y, window_middle);
	
	value = -1.5f;
	
	revalue_circlent(circlent, value);
	
	while (window.isOpen())
	{

		sf::Event event;
		
		window.clear(black);
		
		int counter = 0;
		assert(counter == 0);
				
		while (counter < 4)
		{
						
			++counter;
			
		}
		
		show_circlent(window, circlent);
		
		// show_textent(window, textent);
		
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
