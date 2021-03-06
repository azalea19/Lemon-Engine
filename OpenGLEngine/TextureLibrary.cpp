#include "TextureLibrary.h"
#include "Texture.h"

#define NOT_FOUND GLuint(-1)

void TextureLibrary::initTextureLibrary()
{
}

void TextureLibrary::AddTexture(string name, GLuint textureID)
{
	textures.emplace(name, textureID);
}

void TextureLibrary::AddTexture(string name, string filePath)
{
	GLuint textureID = loadImage(filePath.c_str());
	AddTexture(name, textureID);

}

GLuint TextureLibrary::GetTexture(string name)
{
	std::unordered_map<string, GLuint>::const_iterator got = textures.find(name);
	if (got == textures.end())
	{
		printf("Texture with name %s not found.", name.c_str());
		return NOT_FOUND;
	}
	else
		return got->second;
}
