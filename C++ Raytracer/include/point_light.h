#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "light_source.h"

class point_light: public light_source
{
public:
	point_light();
	point_light(float px, float py, float pz);
	void set_position(float px, float py, float pz);
	void set_position(const tiny_vec<float,3>& pos);
	virtual tiny_vec<float,3> get_attenuation_factors(const intersection_info* hit);
	virtual void calc_light_direction_and_distance(intersection_info *hit);
	
	
private:
	tiny_vec<float,3> position;
};


#endif