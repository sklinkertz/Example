#include "transformation_group.h"




transformation_group::transformation_group()
{
	trafo = eye<float>(4);	
}

transformation_group::transformation_group(mat<float>& tr)
{
	set_transformation(tr);
}

void transformation_group::set_transformation(const mat<float>& T)
{
	trafo = T;

	trafo_inv = inv_44<float>(T);
	
	trafo_inv_transpose = transpose(trafo_inv);	
	
}

bool transformation_group::closest_intersection(intersection_info* hit, float min_lambda,primitive* dont_hit)
{
	//transform incoming ray  and lambda into local frame

	ray<float> temp = hit->get_incoming_ray();
	ray<float> rt=temp;
	rt.transform(trafo_inv);
	hit->set_incoming_ray(rt);
	
	bool intersect =  primitive_group::closest_intersection(hit,min_lambda,dont_hit);

	if(intersect)
	{
		vec<float> n =trafo_inv_transpose*homog_nml<float,3>(hit->get_normal());
		tiny_vec<float,4> nn(n.begin(),n.end());
		tiny_vec<float,3> nml =unhomog_nml<float,4>(nn);
		
		hit->set_normal(nml);
		
	}
	hit->set_incoming_ray(temp);
	return intersect;
	

}

bool transformation_group::any_intersection( ray<float>& r,float min_lambda, float max_lambda,primitive* dont_hit) 
{
	ray<float> rt = r;
	rt.transform(trafo_inv);

	return primitive_group::any_intersection(rt,min_lambda,max_lambda,dont_hit);

	
}

