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
	
	const int centurion{static_cast<int>(100*number)};
	
	wstringer << L"€" << centurion/100 << ".";
	
	if (abs(centurion)%100 < 10)
	{
		
		wstringer << 0;
		
	}	
	
	wstringer << abs(centurion)%100;
			
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

float start_delta_end(const float start, const float end, const int steps)
{
	
	assert(start != end);
	assert(steps > 0);
	
	return (end - start)/steps;	
	
}

void origin_from_text(sf::Text& text)
{
	
	sf::FloatRect float_rect{text.getLocalBounds()};
	
	text.setOrigin(0.5f*float_rect.width, 0.95f*float_rect.height);
	
}

struct name_entity
{
	
	const std::string nament_string_{"Chiaki"};
	
	sf::Font nament_font_;
	
	std::string nament_name_{"VeraMono.ttf"};		
	
	const float nament_size_{10.0f};
	
	sf::Vector2f nament_posit_{0.0f, 0.0f};
	
	sf::Vector2f nament_origin_{0.0f, 0.0f};
	
	sf::Color nament_color_{255, 255, 255};
	
	sf::Text nament_text_;
	
	name_entity(const std::string& name, const float size, const sf::Vector2f& posit, const sf::Color& color);
	
	~name_entity();
	
};

name_entity::name_entity(const std::string& name_string, const float size, const sf::Vector2f& posit, const sf::Color& color)
	:nament_string_(name_string), nament_font_(), nament_size_(size),
	nament_posit_(posit), nament_color_(color), nament_text_()
{
		
	assert(nament_string_ != "");	
	assert(nament_size_ > 0.0f);
	
	if (!nament_font_.loadFromFile(nament_name_))
	{
			
		std::cout << nament_name_ << " not found!\n";		
		std::cout << "Error -2\n";		
		exit (EXIT_FAILURE);
			
	}
	
	nament_text_.setFont(nament_font_);
	nament_text_.setCharacterSize(nament_size_);	
	nament_text_.setColor(nament_color_);	
	nament_text_.setString(nament_string_);	
	origin_from_text(nament_text_);	
	nament_text_.setPosition(nament_posit_);
	
}

name_entity::~name_entity()
{
	
}

void show_nament(sf::RenderWindow& window, const name_entity& nament)
{
	
	std::cout << "A\n"; 
	
	window.draw(nament.nament_text_);
	
	std::cout << "B\n"; 
	
}

struct text_entity
{
	
	float textent_value_{0.0f};
	
	std::wstring textent_wstring_{number_to_wstring(textent_value_)};
	
	sf::Font text_font_;
	
	std::string text_name_{"VeraMono.ttf"};		
	
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
	assert(text_size_ > 0.0f);
	
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
	
	std::cout << "a\n"; 
	
	window.draw(textent.textent_text_);
	
	std::cout << "b\n"; 
	
}

float value_to_radius(const float value, const float norm_radius)
{
	
	const float norm_value{100.0f};
	assert(norm_value > 0.0f);
	
	return sqrt(abs(value)/norm_value)*norm_radius + 1.0f;
	
}

void reposit_nament(name_entity& nament, const sf::Vector2f& objectent_posit,
					const float dist, const float size)
{
	nament.nament_posit_ = objectent_posit;
	nament.nament_posit_.y -= dist + 0.8*size;

	nament.nament_text_.setPosition(nament.nament_posit_);
	
}

void reposit_textent(text_entity& textent, const sf::Vector2f& objectent_posit,
					const float dist, const float size)
{
	textent.text_posit_ = objectent_posit;
	textent.text_posit_.y += dist + 0.8*size;

	textent.textent_text_.setPosition(textent.text_posit_);
	
}

struct circle_entity
{
	
	const std::string circlent_name_{"Chiaki Kurihara"};
	
	const float circlent_min_value_{-0.005};
	
	float circlent_value_{0.0f};
	
	const float circlent_norm_radius_{100.0f};
	
	float circlent_circle_radius_{value_to_radius(circlent_value_, circlent_norm_radius_)};
	
	sf::CircleShape circlent_circle_{circlent_circle_radius_};
	
	sf::Vector2f circlent_circle_posit_{0.0f, 0.0f};
	
	const sf::Color circlent_white_{255, 255, 255};
		
	const float circlent_textent_ratio_{0.5f};
	
	sf::Vector2f circlent_textent_posit_{0.0f, 0.0f};
	
	sf::Color circlent_textent_color_{circlent_white_};
	
	name_entity circlent_nament_{circlent_name_, circlent_textent_ratio_*circlent_norm_radius_,
								circlent_circle_posit_, circlent_textent_color_};
	
	text_entity circlent_textent_{circlent_value_, circlent_textent_ratio_*circlent_norm_radius_,
								circlent_circle_posit_, circlent_textent_color_};
								
	circle_entity(const std::string& name, const double value,
				const double norm_radius, const sf::Vector2f& posit);
				
	~circle_entity();
	
};

void color_circle(sf::CircleShape& circle, const float value)
{
	
	const float min_value{-0.005f};
	assert(min_value > -0.01f);
	assert(min_value < 0.0f);
	
	const sf::Color red{255, 0, 0};
	const sf::Color green{0, 255, 0};
	
	sf::Color color;
	
	if (value > min_value)
	{
		
		color = green;
		
	}
	else
	{
		
		color = red;
		
	}
	
	circle.setFillColor(color);	
	
}

void set_circle(sf::CircleShape& circle, const float radius, const sf::Vector2f& posit)
{
	
	assert(radius >= 0);
	
	circle.setRadius(radius);
	circle.setOrigin(radius, radius);
	circle.setPosition(posit);
	
}

void revalue_circlent(circle_entity& circlent, const float value)
{
	
	circlent.circlent_value_ = value;
	circlent.circlent_circle_radius_ = value_to_radius(circlent.circlent_value_, circlent.circlent_norm_radius_);
	
	set_circle(circlent.circlent_circle_, circlent.circlent_circle_radius_, circlent.circlent_circle_posit_);
		
	color_circle(circlent.circlent_circle_, value);
	
	revalue_textent(circlent.circlent_textent_, value);
	
	reposit_nament(circlent.circlent_nament_, circlent.circlent_circle_posit_, circlent.circlent_circle_radius_,
					circlent.circlent_textent_ratio_*circlent.circlent_norm_radius_);
					
	reposit_textent(circlent.circlent_textent_, circlent.circlent_circle_posit_, circlent.circlent_circle_radius_,
					circlent.circlent_textent_ratio_*circlent.circlent_norm_radius_);
			
}

circle_entity::circle_entity(const std::string& name, const double value,
							const double norm_radius, const sf::Vector2f& posit)
	:circlent_name_(name), circlent_value_(value), circlent_norm_radius_(norm_radius),
	circlent_circle_radius_(value_to_radius(circlent_value_, circlent_norm_radius_)),
	circlent_circle_(circlent_circle_radius_), circlent_circle_posit_(posit), 
	circlent_textent_posit_(circlent_circle_posit_),
	circlent_nament_(circlent_name_, circlent_textent_ratio_*circlent_norm_radius_,
					circlent_circle_posit_, circlent_textent_color_),
	circlent_textent_(circlent_value_, circlent_textent_ratio_*circlent_norm_radius_,
					circlent_circle_posit_, circlent_textent_color_)
	
{
	
	assert(circlent_norm_radius_ > 0);
	assert(circlent_textent_ratio_ > 0);
	
	set_circle(circlent_circle_, circlent_circle_radius_, circlent_circle_posit_);
	
	color_circle(circlent_circle_, value);
	
	reposit_nament(circlent_nament_, circlent_circle_posit_, circlent_circle_radius_,
					circlent_textent_ratio_*circlent_norm_radius_);
					
	reposit_textent(circlent_textent_, circlent_circle_posit_, circlent_circle_radius_,
					circlent_textent_ratio_*circlent_norm_radius_);
	
}

circle_entity::~circle_entity()
{
		
}

void show_circlent(sf::RenderWindow& window, const circle_entity& circlent)
{
	
	std::cout << "1\n"; 
	
	window.draw(circlent.circlent_circle_);
	
	std::cout << "2\n"; 
	
	show_nament(window, circlent.circlent_nament_);
	
	std::cout << "3\n"; 

	show_textent(window, circlent.circlent_textent_);
	
	std::cout << "4\n"; 
	
}

struct rectangle_entity
{
	
	const std::string rectent_name_{"Asuka Tanaka"};
		
	sf::Vector2f rectent_dimens_{200.0f, 100.0f};
	
	sf::Vector2f rectent_rect_posit_{0.5f*rectent_dimens_};
	
	sf::Vector2f rectent_rect_origin_{0.5f*rectent_dimens_};
	
	const sf::Color rectent_green_{127, 255, 127};
	
	sf::RectangleShape rectent_rect_{rectent_dimens_};
	
	std::vector <circle_entity> rectent_circlents_;
	
	std::vector <std::string> rectent_circlent_names_;
	
	std::vector <float> rectent_circlent_values_;
	
	rectangle_entity(const std::string& name, const sf::Vector2f& dimens,
					const sf::Vector2f& rect_pos, const std::vector <std::string>& circlent_names,
					const std::vector <float>& values);
					
	~rectangle_entity();
					
		
};

rectangle_entity::rectangle_entity(const std::string& name, const sf::Vector2f& dimens,
									const sf::Vector2f& rect_posit, const std::vector <std::string>& circle_names,
									const std::vector <float>& values)
	:rectent_name_(name), rectent_dimens_(dimens), rectent_rect_posit_(rect_posit), rectent_rect_origin_(0.5f*rectent_dimens_),
	rectent_rect_(rectent_dimens_),	rectent_circlents_(), rectent_circlent_names_(circle_names),
	rectent_circlent_values_(values)
{
	
	assert(rectent_name_ != "");
	
	const int circlent_number{static_cast<int>(rectent_circlent_names_.size())};
	
	assert(circlent_number > 0);
	
	assert(circlent_number == static_cast<int>(rectent_circlent_values_.size()));
	
	int current_circlent{0};
	
	const float norm_radius{0.2f*rectent_dimens_.y};
	
	const sf::Vector2f circlent_posit{0.25f*rectent_dimens_.y, 0.25f*rectent_dimens_.y};
	
	while (current_circlent < circlent_number)
	{
		
		assert(rectent_circlent_names_[current_circlent] != "");
		
		std::cout << rectent_circlent_names_[current_circlent] << "\n";
		
		const circle_entity circlent{rectent_circlent_names_[current_circlent], rectent_circlent_values_[current_circlent],
									norm_radius, circlent_posit};
									
		rectent_circlents_.push_back(circlent);
		
		++current_circlent;
		
	}
	
	
	
}

rectangle_entity::~rectangle_entity()
{
	
}

void show_rectent(sf::RenderWindow& window, const rectangle_entity& rectent)
{
	
	std::cout << "Banzai!\n";
	
	window.draw(rectent.rectent_rect_);
	
	const int circlent_number{static_cast<int>(rectent.rectent_circlent_names_.size())};
	
	int current_circlent{0};
	
	
	
	while (current_circlent < circlent_number)
	{
			
		std::cout << current_circlent << "\n";	
		
		show_circlent(window, rectent.rectent_circlents_[current_circlent]);
		
		++current_circlent;
		
		std::cout << "Banzai!\n";
		
	}
	
}

int main()
{
	
	const int delaz{5};	
	assert(delaz > 0);
	
	const std::chrono::milliseconds delay(delaz);
	
	bool pause{false};
	
	const int react_cycle_number{5};
	
	const std::string program_name{"Texts V0.9"};	
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
	
	const sf::Vector2f rectent_sizes{0.4f*window_sizes};
	const sf::Vector2f rectent_posit{0.25f*window_sizes};
	
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), program_name, sf::Style::Default);
	
	const float start_value{-666.66f};
	const float end_value{42.0f};
	
	const int value_steps{100};
	assert(value_steps > 0);
	
	const float delta{0.001f};
	assert(delta > 0);
	
	const float delta_value{start_delta_end(start_value, end_value, value_steps)};
	const float delta_delta{delta*delta_value};
	
	float value{start_value};
	
	const float norm_radius_ratio{0.05f};
	assert(norm_radius_ratio > 0.0f);
	
	const std::string r_name{"Adele Balfetto"};
	
	const std::vector <std::string> rc_names{"Tsubaki Shinra"};
	
	const std::vector <float> rc_values{300.0f};
	
	const std::string c_name{"Tearju Lunatique"};
	
	rectangle_entity rectent(r_name, rectent_sizes, rectent_posit, rc_names, rc_values);
	
	circle_entity circlent(c_name, value, norm_radius_ratio*window_y, window_middle);
	
	name_entity nament("Mari Makinami", 20.0f, 1.5f*window_middle, orange);

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
		
		show_rectent(window, rectent);
				
		show_circlent(window, circlent);
		
		show_nament(window, nament);
		
		window.display();
		
		if ((value + delta_delta < end_value) && !pause)
		{
			
			value += delta_value;
			
			revalue_circlent(circlent, value);
			
		}
		
		int react_cycle{0};
		
		while (react_cycle < react_cycle_number)
		{
				
			std::this_thread::sleep_for(delay);
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				
				pause = !pause;
						
			}	
			
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
			
			++react_cycle;
			
		}
		
	}
	
	return 0;
	
}
