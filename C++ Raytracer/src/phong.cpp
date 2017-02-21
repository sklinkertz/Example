#include "phong.h"
#include "utils.h"
	
tiny_vec<float,3> phong::shade_diffuse(intersection_info* hit, light_source *light)
{
	tiny_vec<float,3> col(0.0f,0.0f,0.0f);
	tiny_vec<float,3> attenuation = light->get_attenuation_factors(hit); 
		
	//student begin
	//see task 1.3.2

	//student end

	return col;	


}

tiny_vec<float,3> phong::shade_specular(intersection_info* hit, light_source *light)
{
	tiny_vec<float,3> col(0.0f,0.0f,0.0f);
	tiny_vec<float,3> attenuation = light->get_attenuation_factors(hit); 
	
	
	//student begin
	//see task 1.3.2

	//student end

	return col;	


}