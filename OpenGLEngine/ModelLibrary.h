#ifndef ModelLibrary_h__
#define ModelLibrary_h__

#include <unordered_map>
#include <string>
#include "Types.h"

/**
* @file   ModelLibrary.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The model library.
*
* The model library contains all the models used in various scenes
*/

struct RenderableObject; ///< A model that can be rendered in a scene.
struct ObjectInstance; ///< Individual instance of a RenderableObject

struct ModelLibrary
{

	std::unordered_map<std::string, RenderableObject*> models; ///< Map of strings to renderable objects in the library.

	/**
	* @brief initialise the model library
	*
	* @return void
	*/

	void initModelLibrary();

	/**
	* @brief Add a model to the model library
	*
	* @param name - Name for the model
	* @param path - Path of the obj file
	*
	* @return void
	*/
	void addModel(std::string name, std::string path, bool normalized = false);

	/**
	* @brief Returns pointer to an instance of a string name
	*
	* @param name - Name for the model
	*
	* @return ObjectInstance*
	*/
	ObjectInstance* getInstance(std::string name);

	/**
	* @brief Returns pointer to model library
	*
	* @return ModelLibrary*
	*/
	static ModelLibrary* getLib();

};

#endif