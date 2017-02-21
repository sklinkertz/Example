#include "triangle.h"
#include <limits>



triangle::triangle(const tiny_vec<float,3>& p0, const tiny_vec<float,3>& p1, const tiny_vec<float,3>& p2,
		const tiny_vec<float,3>& n1, const tiny_vec<float,3>& n2, const tiny_vec<float,3>& n3)
{
	v0=p0;
	edge1=p1-p0;
	edge2=p2-p0;
	nml1=n1;
	nml2=n2;
	nml3=n3;
	
	nml1.normalize();nml2.normalize();nml3.normalize();

	normal = cross(edge1,edge2);
	normal.normalize();
}
	
triangle::triangle(const tiny_vec<float,3>& p0, const tiny_vec<float,3>& p1, const tiny_vec<float,3>& p2)
	
{
	v0.set(p0(0),p0(1),p0(2));
	edge1=p1-p0;
	edge2=p2-p0;
	
	normal = cross(edge1,edge2);
	normal.normalize();
	nml1 = nml2 = nml3 = normal;
	
}



std::pair<tiny_vec<float,3>, tiny_vec<float,3> > triangle::calc_bounds()
{
	tiny_vec<float,3> minb(v0(0),v0(1),v0(2));
	tiny_vec<float,3> maxb(v0(0),v0(1),v0(2));

	for(int i = 0; i < 3; i++)
	{
		if(minb[i] > v0[i]+edge1[i])
			minb[i] = v0[i]+edge1[i];
		if(maxb[i] < v0[i]+edge1[i])
			maxb[i] = v0[i]+edge1[i];
		if(minb[i] > v0[i]+edge2[i])
			minb[i] = v0[i]+edge2[i];
		if(maxb[i] < v0[i]+edge2[i])
			maxb[i] = v0[i]+edge2[i];
	
	
	}
	return std::make_pair(minb,maxb);
}

void triangle::calc_normal(intersection_info* hit, float  u, float v)
{
	float w = 1-u-v;
	tiny_vec<float,3> nml = u*nml2+v*nml3+w*nml1;
	nml.normalize();
	hit->set_normal(nml);
	
}

bool triangle::closest_intersection(intersection_info* hit, float min_lambda, primitive* dont_hit)
{
	//student begin
	//see task 1.2.2
	return false;
	//student end
}

bool triangle::any_intersection(ray<float>& r,float min_lambda, float max_lambda,primitive* dont_hit)
{
	
	//student begin
	//see task 1.2.2
	return false;
	//student end
	

}
