#ifndef Utility_h__
#define Utility_h__

#include "Types.h"

/**
* @file   Utility.h
* @Author Maddisen Topaz, Elizabeth Haynes
* @date   S2, 2016
* @brief  The model loader.
*
* The utility file contains the various utility functions required for various classes.
*/


/**
* @brief Seperates strings at delimiter
*
* @param s - string
* @param delim - string delimiter
* @param elems - vector <string>
*
* @return void
*/
void split(const string &s, char delim, std::vector<string> &elems);

/**
* @brief Seperates strings at delimiter
*
* @param s - string
* @param delim - string delimiter
*
* @return std::vector<string>
*/
std::vector<string> split(const string &s, char delim);

/**
* @brief Returns conversion of metres to shay units. Uses values from Shay's 'Bush Court Plan.vsd' to calculate.
*
* @param metres - value in metres to convert to shay units
*
* @return float
*/
float MetresToShayUnits(float metres);

/**
* @brief Returns conversion of shay units to metres. Uses values from Shay's 'Bush Court Plan.vsd' to calculate.
*
* @param metres - value in shay units to convert to metress
*
* @return float
*/
float ShayUnitsToMetres(float shayUnits);



/**
* @brief  Allows for the creation of a vector inside a function call 
*
* See the following page for further explanation:
* http://eli.thegreenplace.net/2014/variadic-templates-in-c/
*
*/
template<typename T>
void  CreateVector(std::vector<T>& newVec)
{
}

template<typename T, typename ... Args>
void CreateVector(std::vector<T>& newVec, T val1, Args... args)
{
	newVec.push_back(val1);
	CreateVector(newVec, args...);
}

/**
* @brief Take one or more T's and returns a vector of T's
*/
template<typename T, typename ... Args>
std::vector<T> CreateVector(T val1, Args... args)
{
	std::vector<T> newVec;
	newVec.push_back(val1);
	CreateVector(newVec, args...);
	return newVec;
}


#endif // Utility_h__
