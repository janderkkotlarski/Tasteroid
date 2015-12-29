#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

struct Pirate_Captain
{
	
	const std::string pirate_call{"YAAAAAAAAAAAAAAAAAAAARRRRRRRRRRRRRRRRRRRR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"};
	
	const std::string pirate_question{"IS ZER SUM RUM?!\n"};
	
	Pirate_Captain();
	
	~Pirate_Captain();
	
	void pirate_sez_wut()
	{
		
		std::cout << pirate_call;
		
	}
	
	void pirate_axe_wut()
	{
		
		std::cout << pirate_question;
		
	}
	
};

Pirate_Captain::Pirate_Captain()
{
	
}

Pirate_Captain::~Pirate_Captain()
{
	
}

double value_to_radius(const double value, const double normal_radius)
{
	
	const double normal_value{100};
	
	return sqrt(abs(value)/normal_value)*normal_radius;
	
}

struct circle_entity
{
	
	double value{0};
		
	const double normal_radius{100};
	
	double radius{value_to_radius(value, normal_radius)};
	
	sf::Vector2f posit{0, 0};
		
	sf::CircleShape circle{static_cast<float>(radius)};
	
	sf::Color color{0, 0, 0};
	
	circle_entity(const double walue, const sf::Vector2f& pozit,
				const sf::Color& kolor);
				
	~circle_entity();
	
};

circle_entity::circle_entity(const double walue, const sf::Vector2f& pozit,
							const sf::Color& kolor)
	:value(walue), radius(value_to_radius(value, normal_radius)),
	posit(pozit), circle(static_cast<float>(radius)), color(kolor)
{
	
	circle.setOrigin(radius, radius);
	
	circle.setPosition(posit);
	
	circle.setFillColor(color);
	
}

circle_entity::~circle_entity()
{
		
}

void reposit_circlent(circle_entity& circlent, const sf::Vector2f& posit)
{
	
	circlent.circle.setPosition(posit);
	
}

void reshape_circlent(circle_entity& circlent, const double value)
{
	
	circlent.circle.setRadius(value_to_radius(value, circlent.normal_radius));
	
}

void recolor_circlent(circle_entity& circlent, const sf::Color& color)
{
	
	circlent.circle.setFillColor(color);
	
}

void show_circlent(sf::RenderWindow& window, const circle_entity& circlent)
{
	
	window.draw(circlent.circle);
	
}

struct rect_entity
{
	
	sf::Vector2f posit{0, 0};	
	
	const sf::Vector2f sizes{300, 75};
	
	sf::RectangleShape rectangle{sizes};
	
	const sf::Color rect_color{0, 127, 0};
	
	const sf::Color circlent_color{0, 0, 127};
	
	std::vector <double> values;
	
	const double normal_radius{0.4*sizes.y};
	
	std::vector <circle_entity> circlents;
	
	const int circlent_amount{0};
	
	rect_entity(const sf::Vector2f& pozit, const sf::Vector2f& zisez, const int kirkle_amount,
				const sf::Color rekt_kolor, const sf::Color& kirkle_kolor, const std::vector <double>& walues);
	
	~rect_entity();
			
};

rect_entity::rect_entity(const sf::Vector2f& pozit, const sf::Vector2f& zisez, const int kirklent_amount,
						const sf::Color rekt_kolor, const sf::Color& kirklent_kolor, const std::vector <double>& walues)
	:posit(pozit), sizes(zisez), rectangle(sizes), rect_color(rekt_kolor), circlent_color(kirklent_kolor),
	 values(walues), normal_radius(0.4*sizes.y), circlents(), circlent_amount(kirklent_amount)
{
	
	assert(circlent_amount > 0);
	
	assert(sizes.x > 0);
	assert(sizes.y > 0);
		
	rectangle.setPosition(posit);
	
	rectangle.setFillColor(rect_color);
	
	int counter{0};
	
	assert(counter == 0);
	
	const float half_y{static_cast<float>(0.5*sizes.y)};
	
	const sf::Vector2f first_posit{half_y, half_y};
	
	const sf::Vector2f jump_posit{2*half_y, 0};
	
	sf::Vector2f circlent_posit{posit + first_posit};	
	
	const circle_entity circlent(0, circlent_posit, circlent_color);
	
	while (counter < circlent_amount)
	{
		
		circlents.push_back(circlent);		
		
		reshape_circlent(circlents[counter], values[counter]);
		
		reposit_circlent(circlents[counter], circlent_posit + static_cast<float>(counter)*jump_posit);
			
		++counter;
		
		assert(counter > 0);	
			
	}
	
}

rect_entity::~rect_entity()
{
			
}

void show_rectent(sf::RenderWindow& window, const rect_entity& rectent)
{
	
	assert(rectent.circlent_amount > 0);
	
	window.draw(rectent.rectangle);
	
	int counter{0};
	
	while (counter < rectent.circlent_amount)
	{
		
		show_circlent(window, rectent.circlents[counter]);
			
		++counter;
		
		assert(counter > 0);
		
	}
	
}


int main()
{
	
	Pirate_Captain Blackbeard;
	
	Blackbeard.pirate_sez_wut();
	
	
	
	Blackbeard.pirate_axe_wut();
	
	return 0;
	
}
