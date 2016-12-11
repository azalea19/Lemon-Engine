#ifndef ShaderLibrary_h__
#define ShaderLibrary_h__

#include "Types.h"
#include "Shader.h"
#include <unordered_map>

/**
* @file   ShaderLibrary.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The shader library.
*
* The shader library contains all of the various shaders we have access to in the program
*/

struct ShaderLibrary
{

	std::unordered_map<string, Shader*> shaders; ///< The map of shaders


	/**
	* @brief Initialises the shader library by adding various shaders to the library needed in the program
	*
	* @return void
	*/
	void initShaderLibrary();


	/**
	* @brief Adds a new shader to the shader library
	*
	* @param name - the name of the shader
	* @param uniforms - the uniforms required by the shader
	* @param attributes - the attributes required by the shader
	*
	* @return std::vector<glm::vec3>
	*/
	void addShader(string name, std::vector<string> uniforms, std::vector<string> attributes);

	/**
	* @brief Returns a constant reference to the shader requested if it exists in the shader library
	*
	* @param name - the name of the shader
	*
	* @return const Shader*
	*/
	const Shader* getShader(string name) const;

	/**
	* @brief Returns a static reference to the shaderLib singleton
	*
	* @return ShaderLibrary*
	*/
	static ShaderLibrary* getLib();

	/**
	* @brief Binds the shader pass in the argument
	*
	* @param shaderName - the name of the shader 
	*
	* @return void
	*/
	void bindShader(string shaderName);

	/**
	* @brief Binds the default shader
	*
	* @return void
	*/
	void bindDefaultShader();

	/**
	* @brief Returns the current shader bound
	*
	* @return const Shader*
	*/
	const Shader* currentShader();

	/**
	* @brief Returns the name of the current shader bound
	*
	* @return string
	*/
	const string getCurrentShaderName();

private:
	string currentShaderName;
};



#endif