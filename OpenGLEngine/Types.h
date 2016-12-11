#ifndef Types_h__
#define Types_h__

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include <vector>

/**
* @file   Types.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The 
*
* The types file contains the various types required in various files.
*/


#define SHAY_BOUNDARY 2608

typedef glm::vec4 vec4;
typedef glm::vec3 vec3;
typedef glm::vec2 vec2;
typedef glm::ivec2 vec2i;
typedef glm::ivec4 vec4i;
typedef glm::mat4 mat4;
typedef std::string string;

enum collisionTypes
{
	notColliding = 0,			///< notColliding - if a 0 then objects arent colliding
	colliding = 1,				///< colliding - if a 1 then objects are colliding
	climbable = 2,				///< climbable - if 2 then then object is climbable
	teleportable = 3
};


#endif
