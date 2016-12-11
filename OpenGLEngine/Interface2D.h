#ifndef Interface2D_h__
#define Interface2D_h__

#include "Types.h"

/**
* @file   2DInterface.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The methods used to render the 2D aspects of the game.
*
* The text rendering file uses SDL2's SDL_ttf and SDL_Image library to Blit on to an SDL surface.
* This surface is copied in to an OpenGL format where we can render it to the screen using an orthographic shader.
* 
* SDL_ttf's extension library and use is explained here in Lazy Foo's tutorial:
* http://lazyfoo.net/tutorials/SDL/16_true_type_fonts/index.php
* See this link for using an SDL surface as an OpenGL texture:
* http://www.sdltutorials.com/sdl-tip-sdl-surface-to-opengl-texture
*
*/



/**
* @brief draws a 2D Image to the screen
*
* @param filePath - the image filepath to be rendered to the screen
* @return void
*/
void drawImage(string filePath);


/**
* @brief draws a 2D string of text to the screen
*
* @param size - the size of the font you want it to render at
* @param filePath - the true type font file you want to render with
* @param text - the text to render to the screen
* @param xpos - the x position of the text
* @param ypos - the y position of the text
* @param color - the color of the text (black default)
*
* @return void
*/
void drawText(int size, string filePath, string text, int xpos, int ypos, vec3 color = vec3(0, 0, 0));

/**
* @brief useful function for debugging that returns a glError code
*
* @return void
*/
static void breakOnGLError();

#endif 
