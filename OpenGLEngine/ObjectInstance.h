#ifndef ObjectInstance_h__
#define ObjectInstance_h__

#include "RenderableObject.h"

/**
* @file   ObjectInstance.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The object instance struct.
*
* The object instance class stores the data relating to a particular instance of a model.
*/


struct ObjectInstance
{

	/**
	* @brief The object instance structure represents an instance of a model
	*
	* @param newZ - the new value for z
	* @param index - the index of the vector to set
	*/
	ObjectInstance(RenderableObject* object, glm::vec3 coords = glm::vec3(0, 0, 0), glm::vec3 scaleFactor = glm::vec3(1, 1, 1), float a_yaw = 0, float a_pitch = 0);

	/**
	* @brief Sets the position that the model will be rendered at in the world
	*
	* @param coords - the new posistion of the model
	*
	* @return void
	*/

	void SetPosition(glm::vec3 coords);

	/**
	* @brief Sets the scale that the model will be rendered at in the world
	*
	* @param a_scale - new value for scale
	*
	* @return void
	*/
	void SetScale(glm::vec3 a_scale);

	/**
	* @brief Rotates the model by a specified number of degrees around the x-axis
	*
	* @param degrees - the new value for pitch
	*
	* @return void
	*/
	void SetPitch(float degrees);

	/**
	* @brief Rotates the model by a specified number of degrees around the y-axis
	*
	* @param degrees - the new value for yaw
	*
	* @return void
	*/

	void SetYaw(float degrees);

	/**
	* @brief Returns the number of sub objects in the model rendered with a different material
	*
	* @return int
	*/
	int SubObjectCount();

	/**
	* @brief Returns a vector of vertices for the specified sub object
	*
	* @param subIndex - the desired subObject
	* @param parentModelMatrix - the parent matrix
	*
	* @return std::vector<glm::vec3>
	*/
	std::vector<glm::vec3> GetVertices(int subIndex, glm::mat4 parentModelMatrix = glm::mat4());


/**
* @brief Returns climbability of subObject
*
* @param subIndex - the index of the subobject desired
*
* @return bool
*/

bool IsClimbable(int subIndex);

/**
* @brief Gets the model matrix
*
* @return glm::mat4
*/
glm::mat4 GetModelMatrix();


/**
* @brief Render an object
*
* @param viewMatrix - the view matrix
* @param projectionMatrix - the projection matrix
* @param parentModelatrix - the parent model matrix
*
* @return void
*/

void Render(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::mat4 parentModelMatrix = glm::mat4());

/**
* @brief gets a renderable object
*
* @return RenderableObject address
*/

const RenderableObject & GetRenderableObject() const;


/**
* @brief gets the posistion of the object
*
* @return vec3
*/

glm::vec3 GetPosition() const;

/**
* @brief gets the scale of the object
*
* @return vec3
*/

glm::vec3 GetScale() const;

/**
* @brief gets the yaw of the object.
*
* @return float
*/

float GetYaw() const;

/**
* @brief gets the pitch of the object
*
* @return float
*/
float GetPitch() const;

	

private:

	RenderableObject * m_renderableObject;		///< pObject - a pointer to a renderable object
	glm::vec3 position;				///< posistion - the posistion of the object
	glm::vec3 scale;				///< scale - the scale of the object
	float yaw = 0;					///< yaw - the yaw of the object
	float pitch = 0;				///< pitch - the pitch of the object
};

#endif //ObjectInstance_h__