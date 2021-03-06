#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>


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


struct circle_entity
{
	
	double circlent_value_{0};
		
	const double circlent_normal_{100};
	
	double circlent_radius_{value_to_radius(circlent_value_, circlent_normal_)};
	
	sf::Vector2f circlent_posit_{0, 0};
		
	sf::CircleShape circlent_circle_{static_cast<float>(circlent_radius_)};
	
	sf::Color circlent_color_{0, 0, 0};
	
	circle_entity(const double value, const double normal,
				const sf::Vector2f& posit, const sf::Color& color);
				
	~circle_entity();
	
};

circle_entity::circle_entity(const double value, const double normal,
							const sf::Vector2f& posit, const sf::Color& color)
	:circlent_value_(value), circlent_normal_(normal), circlent_radius_(value_to_radius(circlent_value_, circlent_normal_)),
	circlent_posit_(posit), circlent_circle_(static_cast<float>(circlent_radius_)), circlent_color_(color)
{
	
	circlent_circle_.setOrigin(circlent_radius_, circlent_radius_);
	
	circlent_circle_.setPosition(circlent_posit_);
	
	circlent_circle_.setFillColor(circlent_color_);
	
}

circle_entity::~circle_entity()
{
		
}

void reposit_circlent(circle_entity& circlent, const sf::Vector2f& posit)
{
	
	circlent.circlent_circle_.setPosition(posit);
	
}

void reorigin_circlent(circle_entity& circlent)
{
	
	circlent.circlent_circle_.setOrigin(circlent.circlent_radius_, circlent.circlent_radius_);
	
}

void reshape_circlent(circle_entity& circlent, const double value)
{
	
	circlent.circlent_circle_.setRadius(value_to_radius(value, circlent.circlent_normal_));
	
}

void recolor_circlent(circle_entity& circlent, const sf::Color& color)
{
	
	circlent.circlent_circle_.setFillColor(color);
	
}

void show_circlent(sf::RenderWindow& window, const circle_entity& circlent)
{
	
	window.draw(circlent.circlent_circle_);
	
}

void init_circlents(const int amount_x, const int amount_y, std::vector <circle_entity>& circlents,
				const std::vector <sf::Vector2f>& posits, const std::vector <double>& values,
				const sf::Color& color, const double radius)
{

	int counter_y{0};
	assert(counter_y == 0);
	
	while (counter_y < amount_y)
	{
		
		int counter_x{0};
		assert(counter_x == 0);
		
		while (counter_x < amount_x)
		{
			
			const circle_entity circlent(values[amount_x*counter_y + counter_x], radius,
										posits[amount_x*counter_y + counter_x], color);
						
			circlents.push_back(circlent);
			
			++counter_x;
			
		}
		
		++counter_y;
		
	}
		
}

struct rect_entity
{
	
	sf::Vector2f rectent_posit_{0, 0};	
	
	const sf::Vector2f rectent_sizes_{300, 300};
	
	sf::RectangleShape rectent_rectangle_{rectent_sizes_};
	
	const sf::Color rectent_color_{0, 127, 0};
	
	const sf::Color circlent_color_{0, 0, 127};
	
	std::vector <double> circlent_values_;
	
	const double circlent_normal_{0.1*rectent_sizes_.y};
	
	std::vector <circle_entity> rectent_circlents_;
	
	const int circlent_amount_{0};
	
	rect_entity(const sf::Vector2f& posit, const sf::Vector2f& sizes, const int circ_amount,
				const sf::Color rect_color, const sf::Color& circ_color, const std::vector <double>& values);
	
	~rect_entity();
			
};

rect_entity::rect_entity(const sf::Vector2f& posit, const sf::Vector2f& sizes, const int circ_amount,
						const sf::Color rect_color, const sf::Color& circ_color, const std::vector <double>& values)
	:rectent_posit_(posit), rectent_sizes_(sizes), rectent_rectangle_(rectent_sizes_), rectent_color_(rect_color),
	circlent_color_(circ_color), circlent_values_(values), circlent_normal_(0.1*rectent_sizes_.y), rectent_circlents_(),
	circlent_amount_(circ_amount)
{
	
	assert(circlent_amount_ > 0);
	
	assert(rectent_sizes_.x > 0);
	assert(rectent_sizes_.y > 0);
	
	const int circ_amount_x{2};
	
	const int circ_amount_y{2};
		
	rectent_rectangle_.setPosition(rectent_posit_);
	
	rectent_rectangle_.setFillColor(rectent_color_);
	
	const float posit_part{0.25f};
	
	const sf::Vector2f first_posit{posit_part*sizes};
	
	const sf::Vector2f jump_posit{0.5f*sizes};	
	
	sf::Vector2f circlent_posit{posit + first_posit};
	
	std::vector <sf::Vector2f> circlent_posits;
	
	init_posits(circ_amount_x, circ_amount_x, circlent_posits, circlent_posit, jump_posit);
	
	init_circlents(circ_amount_x, circ_amount_y, rectent_circlents_, circlent_posits, values, circlent_color_, circlent_normal_);
	
}

rect_entity::~rect_entity()
{
			
}

void show_rectent(sf::RenderWindow& window, const rect_entity& rectent)
{
	
	assert(rectent.circlent_amount_ > 0);
	
	window.draw(rectent.rectent_rectangle_);
	
	int counter{0};
	assert(counter == 0);
	
	while (counter < rectent.circlent_amount_)
	{
		
		show_circlent(window, rectent.rectent_circlents_[counter]);
			
		++counter;
		
		assert(counter > 0);
		
	}
	
}

	

int main()
{

	const int delaz{50};	
	assert(delaz > 0);
	
	const std::chrono::milliseconds delay(delaz);
	
	const std::string program_name{"Rectangle Circles V0.5"};
	
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
		
	assert(window_x > 0);	
	assert(window_y > 0);
	
	const sf::Vector2f window_sizes{window_x, window_y};
	
	const float rect_part{0.3};
	const float moat_part{0.5*(0.5 - rect_part)};
	assert(rect_part > 0);
	assert(rect_part < 0.5);
	
	const sf::Vector2f rect_sizes{rect_part*window_sizes};
	const sf::Vector2f rect_posit{moat_part*window_sizes};
	const sf::Vector2f rect_jump{0.5f*window_sizes};

	const int rect_amount_x{2};
	assert(rect_amount_x > 0);
	
	const int rect_amount_y{2};
	assert(rect_amount_y > 0);
	
	const int rect_amount{rect_amount_x*rect_amount_y};
	
	std::vector <sf::Vector2f> rect_posits;
	
	init_posits(rect_amount_x, rect_amount_y, rect_posits, rect_posit, rect_jump);
		
	std::vector <int> rect_circlent_amounts;
	
	rect_circlent_amounts.push_back(4);
	rect_circlent_amounts.push_back(2);
	rect_circlent_amounts.push_back(4);
	rect_circlent_amounts.push_back(4);
	
	std::vector <sf::Color> rect_colors;
	
	rect_colors.push_back(purple);
	rect_colors.push_back(yellow);
	rect_colors.push_back(green);
	rect_colors.push_back(orange);
	
	std::vector <sf::Color> circlent_colors;
	
	circlent_colors.push_back(red);
	circlent_colors.push_back(cyan);
	
	std::vector <double> circlent_values;
	
	circlent_values.push_back(100);
	circlent_values.push_back(30);
	circlent_values.push_back(160);
	circlent_values.push_back(80);
	
	std::vector <rect_entity> rectents;
	
	int counter{0};
	assert(counter == 0);
	
	while (counter < rect_amount)
	{
			
		const rect_entity rectent(rect_posits[counter], rect_sizes, rect_circlent_amounts[counter],
							rect_colors[counter], circlent_colors[0], circlent_values);
							
		rectents.push_back(rectent);
		
		++counter;
			
	}
	
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), program_name, sf::Style::Default);
	
	while (window.isOpen())
	{

		sf::Event event;
		
		window.clear(black);
		
		counter = 0;
		assert(counter == 0);
		
		while (counter < 4)
		{
			
			show_rectent(window, rectents[counter]);
			
			++counter;
			
		}
		
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
