final PVector wind_xy = new PVector (600, 600);


final int planet_d = 50;
final float planet_r = 0.5*planet_d;
final float max_reach = 10*planet_r;
final PVector planet_xy = new PVector (round(0.5*wind_xy.x),
                                       round(0.5*wind_xy.y));

final color planet_c = color(32, 192, 96);

final int spaceball_d = 25;
final float spaceball_r = 0.5*spaceball_d;
PVector spall_xy = new PVector (round(0.5*wind_xy.x),
                                round(0.25*wind_xy.y));

PVector spaceball_xy = new PVector (round(spall_xy.x),
                                    round(spall_xy.y));
            
float rotation = -PI;
                                    
PVector direct_xy = new PVector (sin(rotation), cos(rotation));

PVector direction_xy = new PVector (round(spaceball_r*direct_xy.x),
                                    round(spaceball_r*direct_xy.y));

final color direction_c = color (32, 96, 192);

PVector vall_xy = new PVector (0, 0);

PVector acc_xy = new PVector (0, 0);



final color spaceball_c = color(192, 96, 32);

final float nimh_r = planet_r + spaceball_r;

float dist = 0;

PVector diff_xy = new PVector (0, 0);

final float mult_acc = -5000;

final float mult_delta = 0.1;

final float delta_rot = 0.01*TWO_PI;

boolean up_pressed = false;
boolean down_pressed = false;
boolean right_pressed = false;
boolean left_pressed = false;

final float mult_pressed = 0.8;

void setup()
{
  
  size(600, 600);
  noStroke();
  
}



void draw()
{
  
  background(0);
  
  fill(planet_c);
  ellipse(planet_xy.x, planet_xy.y, planet_d, planet_d);
  
  fill(spaceball_c);
  ellipse(spaceball_xy.x, spaceball_xy.y, spaceball_d, spaceball_d);
  
  stroke(direction_c);
  line(spaceball_xy.x, spaceball_xy.y, spaceball_xy.x + direction_xy.x, spaceball_xy.y + direction_xy.y);
  
  diff_xy.x = spall_xy.x - planet_xy.x;
  diff_xy.y = spall_xy.y - planet_xy.y;
  
  dist = sqrt(diff_xy.x*diff_xy.x + diff_xy.y*diff_xy.y + 1);
  
  acc_xy.x = 0;
  acc_xy.y = 0;
  
  if (max_reach > dist)
  {
  
    acc_xy.x += mult_acc*diff_xy.x*sqrt(abs(max_reach - dist)/max_reach)/(dist*dist*dist);
    acc_xy.y += mult_acc*diff_xy.y*sqrt(abs(max_reach - dist)/max_reach)/(dist*dist*dist);
    
  }
  
  if (dist <= nimh_r)  
  {
    
    vall_xy.x = 0;
    vall_xy.y = 0;
    
    spall_xy.x = diff_xy.x*nimh_r/dist + planet_xy.x;
    spall_xy.y = diff_xy.y*nimh_r/dist + planet_xy.y;
    
  }
  
  if (up_pressed)
  {
    
    acc_xy.x += mult_pressed*direct_xy.x;
    acc_xy.y += mult_pressed*direct_xy.y;
    
  }
  
  if (down_pressed)
  {
    
    acc_xy.x += -mult_pressed*direct_xy.x;
    acc_xy.y += -mult_pressed*direct_xy.y;
    
  }
  
  if (right_pressed)
  {
    
    rotation -= delta_rot;
        
  }
  
  if (left_pressed)
  {
    
    rotation += delta_rot;
    
  }
  
  vall_xy.x += mult_delta*acc_xy.x;
  vall_xy.y += mult_delta*acc_xy.y;
  
  spall_xy.x += mult_delta*vall_xy.x;
  spall_xy.y += mult_delta*vall_xy.y;
  
  spaceball_xy.x = round(spall_xy.x);
  spaceball_xy.y = round(spall_xy.y);
  
  direct_xy.x = sin(rotation);
  direct_xy.y = cos(rotation);
  
  direction_xy.x =  round(spaceball_r*direct_xy.x);
  direction_xy.y =  round(spaceball_r*direct_xy.y);
  
  delay(10);
  
  
  
  
}

void keyPressed()
  {
  if (key == CODED)
  {
    if (keyCode == UP)
    {
      
      up_pressed = true;
      
    }
    if (keyCode == DOWN)
    {
      
      down_pressed = true;
      
    }
    if (keyCode == RIGHT)
    {
      
      right_pressed = true;
      
    }
    if (keyCode == LEFT)
    {
      
      left_pressed = true;
      
    }
 
}
  }

void keyReleased()
{
  if (key == CODED)
  {
    if (keyCode == UP)
    {
      
      up_pressed = false;
      
    }
    if (keyCode == DOWN)
    {
      
      down_pressed = false;
      
    }
    if (keyCode == RIGHT)
    {
      
      right_pressed = false;
      
    }
    if (keyCode == LEFT)
    {
      
      left_pressed = false;
      
    }
 
}
}
