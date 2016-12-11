#ifndef GeometricPrimitives_h__
#define GeometricPrimitives_h__

#include "Types.h"

/**
* @file   GeometricPrimitves.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  Structs of geometric primitives.
*
* The various geometric primitives needed for collisions.
*/

struct mSphere
{
	vec3 centre;	///< centre - posisition for the centre of a sphere
	float radius;	///< radiues - spheres radius
};

struct mAABB
{
	vec3 min;		///< min - the minimum coordinate of an AABB 
	vec3 max;		///< max - the maxmimum coordinate of an AABB
};

struct mRay
{
	vec3 position;	///< position - start of a ray
	vec3 direction;	///< direction - the direction of the ray
};

struct mOBB
{
	vec3 corners[8];	///< corners- corners of an OBB
	vec3 axes[3];		///< axes - rotation of an AABB
};

struct mTriangle
{
	vec3 corners[3];	///< corners - corners of a triangle
};

#endif // GeometricPrimitives_h__