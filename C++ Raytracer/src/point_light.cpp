#include "point_light.h"


point_light::point_light() : position(0,10,0)
{
}

point_light::point_light(float px, float py, float pz) : position(px,py,pz)
{
}
	
void point_light::set_position(float px, float py, float pz)
{
	position[0] = px;
	position[1] = py;
	position[2] = pz;
	
}
void point_light::set_position(const tiny_vec<float,3>& pos)
{
	position=pos;
}

tiny_vec<float,3> point_light::get_attenuation_factors(const intersection_info* hit)
{
	//student end
	//see task 1.5.1
	return tiny_vec<float,3>(0.0f,0.0f,0.0f);
	//student end
}

void point_light::calc_light_direction_and_distance(intersection_info *hit)
{
	//student begin
	//see task 1.5.1
	tiny_vec<float,3> light_dir(1.0f,0.0f,0.0f);

	hit->set_light_distance(1.0f);
	hit->set_direction_to_light(light_dir);
	//student end
}

