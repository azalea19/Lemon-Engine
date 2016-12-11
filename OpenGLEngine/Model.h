#ifndef Model_h__
#define Model_h__

#include <algorithm>
#include "Types.h"

/**
* @file   Model.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The model struct.
*
* The model struct contains all the data relating to a model.
*/


struct triangle
{
	uint32_t vIndex[3];			///< vIndex - the vertex index
	uint32_t uvIndex[3];			///< uvIndex - the UV index
	uint32_t normalIndex[3];		///< normalIndex - the normal index
};

///The texture data struct stores a number of faces to be rendered with a particular texture.
struct TextureData
{
	bool climbable;				///< climbable - whether the model is climbable
	uint32_t firstFace;			///< firstFace - the firstFace
	uint32_t faceCount;			///< faceCount - the number of faces
	string texturePath;			///< testurePath - location of the texture
};

struct Model
{
	std::vector<TextureData> subObjects;		///< subobjects - a vector of sub objects
	std::vector<vec3> vertices;					///< vertices - a vector of vertices
	std::vector<vec3> normals;					///< normals - a vector of normals
	std::vector<vec2> uvs;						///< uvs - a vector of UV's
	std::vector<triangle> faces;				///< faces - a vector of faces

												/**
												* @brief Gets the vertices data ready to be used for rendering.
												*
												* @return std::vector<float>
												*/
	std::vector<float> GetVertexArray();

	/**
	* @brief Gets the vertices data ready to be used for rendering.
	*
	* @param subIndex - the index of the sub object desired
	*
	* @return std::vector<vec3>
	*/
	std::vector<vec3> GetVertexArray(int subIndex);

	/**
	* @brief Gets the normals ready to be used for rendering.
	*
	* @return std::vector<float>
	*/
	std::vector<float> GetNormalArray();

	/**
	* @brief Gets the texture data ready to be used for rendering.
	*
	* @return std::vector<float>
	*/
	std::vector<float> GetUVArray();

	/**
	* @brief Returns climbability of subObject
	*
	* @param subIndex - the index of the sub object desired
	*
	* @return bool
	*/

	bool IsClimbable(int subIndex);


	/**
	* @brief Generates a normal vector to the triangle face
	*
	* @param tri - the triangle to generate a normal for
	*
	* @return vec3
	*/

	vec3 GetTriangleNormal(triangle const& tri);

	/**
	void Normalize();

	/**
	* @brief Gets the total area of the triangle.
	* See Heron's formula for calculation.
	* https://en.wikipedia.org/wiki/Heron%27s_formula
	*
	* @return float
	*/
	float GetTriangleArea(triangle const& tri);


	/**
	* @brief The generate smooth normals function creates one normal per vertex, where every normal is the
	* weighted average average normal of all the triangles that share that vertex, weighted by the triangles area
	*
	* @return void
	*/
	void GenerateSmoothNormals();

	/**
	* @brief Centers the model so that the point of origin is at the center of the model.
	*
	* @return void
	*/
	void CenterModel();

	/**
	* @brief Normalises the model.
	*
	* @return void
	*/
	void Normalize();

};

#endif // Model_h__
