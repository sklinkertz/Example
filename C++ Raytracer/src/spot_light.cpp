#include "spot_light.h"

spot_light::spot_light()
{
	set_position(10,10,10);
	set_spot_direction(-1,-1,-1);
	set_spot_exponent(80.0f);
	set_color(0.8f,0.8f,0.8f);
	set_spot_cutoff(30.0f);
	enable_shadows();
}

void spot_light::set_spot_direction(float dx, float dy, float dz)
{
	spot_direction[0] = dx;
	spot_direction[1] = dy;
	spot_direction[2] = dz;
	spot_direction.normalize();
}
void spot_light::set_direction(const tiny_vec<float,3>& dir)
{
	spot_direction=dir;
	spot_direction.normalize();
}
void spot_light::set_position(float px, float py, float pz)
{
	position[0] = px;
	position[1] = py;
	position[2] = pz;
	
}
void spot_light::set_position(const tiny_vec<float,3>& pos)
{
	position=pos;
}

void spot_light::set_spot_exponent(float exponent)
{
	spot_exponent=exponent;
}

float spot_light::get_spot_exponent() const
{
	return spot_exponent;
}

void spot_light::set_spot_cutoff(float co)
{
	spot_cos_cutoff=cos(co*3.14159f/180.0f);
}



tiny_vec<float,3> spot_light::get_attenuation_factors(const intersection_info* hit)
{
	//student begin
	//see task 1.5.2
	return tiny_vec<float,3>(0.0f,0.0f,0.0f);
	//student end
}

void spot_light::calc_light_direction_and_distance(intersection_info *hit)
{
	//student begin
	//see task 1.5.2
	tiny_vec<float,3> light_dir(1.0f,0.0f,0.0f);
	hit->set_light_distance(1.0f);
	hit->set_direction_to_light(light_dir);
	//student end
	
}


