
#ifndef RenderableObject_h__
#define RenderableObject_h__


#include <stdio.h>
#include "Model.h"
#include "Loader.h"
#include "Texture.h"
#include "Types.h"

/**
* @file   RenderableObject.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The renderable object struct.
*
* The renderable object struct takes a model and its data and transforms it in to something that can be rendered.
* It is a handle to the data on the video card representing a model.
*/

///A Render sub object contains the number of faces to be rendered with a particular texture
struct RenderSubObject
{
	uint32_t firstFace;	///< minX - the minimum value of x for an AABB
	uint32_t faceCount;	///< minX - the minimum value of x for an AABB
	GLint texture;		///< minX - the minimum value of x for an AABB
};

///A handle to the data on the video card representing a model
struct RenderableObject
{
public:
	std::vector<RenderSubObject> subObjects;		///< subObjects - A vector of sub objects that are each rendered with a different texture

	/**
	* @brief The renderable object constructor
	*
	* @param modelPath - the path to the model
	*/
	RenderableObject(string modelPath, bool normalized = false);

	/**
	* @brief Generates the sub objects to be used to Render the renderable object
	*
	* @return void
	*/
	void GenerateSubObjects();

	/**
	* @brief Returns the number of sub objects in the model rendered with a different material
	*
	* @return int
	*/
	int SubObjectCount();

	/**
	* @brief Returns a vector of vertices for the specified sub object
	*
	* @param subIndex - an index to a sub object
	*
	* @return std::vector<glm::vec3>
	*/
	std::vector<glm::vec3> GetVertices(int subIndex);


	/**
	* @brief Returns climbability of subObject
	*
	* @param subIndex - an index to a sub object
	*
	* @return bool
	*/

	bool IsClimbable(int subIndex);

	/**
	* @brief Initialises the default shader.
	*
	* The default shader only supports a model with multiple or at least one texture. All parts of the model must be textured.
	*
	* @return bool
	*/
	bool generateBuffers();

	/**
	* @brief Uploads the vertex and texture data to the buffers
	*
	* @return bool
	*/
	bool uploadBuffers();

	/**
	* @brief Uploads the the information to get the model-view projection matrix
	*
	* @param projectionMatrix - the projection matrix to upload
	* @param viewMatrix - the view matrix to upload
	* @param modelMatrix - the model matrix to upload
	*
	* @return void
	*/
	void UploadMVPMatrix(glm::mat4 projectionMatrix, glm::mat4 viewMatrix, glm::mat4 modelMatrix);

	/**
	* @brief Draws the model to the display
	*
	* @param projectionMatrix - the projection matrix
	* @param viewMatrix - the view matrix
	* @param modelMatrix - the model matrix
	*
	* @return void
	*/
	void Render(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::mat4 modelMatrix);

	/**
	* @brief returns the model name
	*/

	string GetModel() const { return model; }

	/**
	* @brief returns the texture
	*/

	GLint GetTexture() const { return texture; }

	/**
	* @brief returns the model
	*/
	const Model & GetMyModel() const { return *myModel; }

	/**
	* @brief gets the vertex buffer
	*/

	GLuint GetgVBO() const { return gVBO; }

	/**
	* @brief gets the UV buffer
	*/

	GLuint GetgUVBO() const { return gUVBO; }

private:
	string model;		///< model - the name of the model
	GLint texture;		///< texture - A texture for a model
	Model* myModel;		///< mmyModel - a pointer to a model

	GLuint gVBO;		///< gVBO - vertex buffer
	GLuint gUVBO;		///< gUVBO - UV buffer
	GLuint gNBO;		///< gNBO - normal buffer


};


#endif // !ModelHandler_h__