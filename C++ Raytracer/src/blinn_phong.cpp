#include "blinn_phong.h"
#include "utils.h"



tiny_vec<float,3> blinn_phong::shade_specular(intersection_info* hit, light_source *light)
{
		
	tiny_vec<float,3> attenuation = light->get_attenuation_factors(hit); 
	tiny_vec<float,3> col(0.0f,0.0f,0.0f);
	//studen begin
	//see task 1.3.1
	
	//student end
	return col;	

}

