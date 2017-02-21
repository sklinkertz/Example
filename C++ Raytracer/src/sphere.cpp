#include "sphere.h"



sphere::sphere():radius(1.0f),sqr_radius(1.0f)
{
	center.zeros();
}

sphere::sphere(float cx, float cy, float cz, float r):center(cx,cy,cz),radius(r)
{
	sqr_radius=r*r;
}

sphere::sphere(const tiny_vec<float,3>& c, float r):center(c),radius(r)
{
	sqr_radius=r*r;
}

void sphere::set_radius(float r)
{
	radius = r;
	sqr_radius = r*r;
}

void sphere::calc_normal(intersection_info* hit)const 
{
	tiny_vec<float,3> nml = hit->get_location()-center;
	nml.normalize();
	
	hit->set_normal(nml);
}

std::pair<tiny_vec<float,3>, tiny_vec<float,3> > sphere::calc_bounds()
{
	return std::make_pair(center-radius,center+radius);
}

bool sphere::closest_intersection(intersection_info* hit, float min_lambda, primitive* dont_hit)
{
	//student begin
	//see task 1.2.1
	return false;
	//student end
}

bool sphere::any_intersection(ray<float>& r,float min_lambda,float max_lambda, primitive* dont_hit)
{
	//student begin
	//see task 1.2.1
	return false;
	//student end

}
