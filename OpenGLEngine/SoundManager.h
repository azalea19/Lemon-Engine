#ifndef SoundManager_h__
#define SoundManager_h__

#include "Types.h"
#include <unordered_map>
#include "SDL_mixer.h"

/**
* @file   SoundManager.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The sound manager.
*
* The sound manager uses SDL2's SDL_mixer library to handle multiple channels of sound. 
* Sounds are stored in a map and accessed using the SoundManager.
* See Lazy Foo's tutorial for setting up SDL_mixer:
* http://www.lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php
* See the following page for information on how to use the SDL_mixer API:
* https://www.libsdl.org/projects/SDL_mixer/docs/SDL_mixer_6.html#SEC6
*
*/


typedef int ChannelHandle;

class SoundManager
{
	std::unordered_map<string, Mix_Chunk*> soundMap;
	int numChannels;

	/**
	* @brief default constructor
	*/
	SoundManager();

public:

	/**
	* @brief Initialises a new sound manager unless one already exists and allocates 16 channels to audio
	* These channels are pushed in to the vector of channels to be used to play sound
	*
	* @return void
	*/
	static void initSoundManager();


	/**
	* @brief Returns the sound manager singleton
	*
	* @return static SoundManager*
	*/
	static SoundManager* GetSoundManager();


	/**
	* @brief Adds a sound to the map of sounds ( Mix_Chunk* )
	* This function is a wrapper around the Mix_LoadWAV() function in the SDL_mixer API
	*
	* @param name - the name of the sound file to add
	* @param filePath - the file path of the sound to add
	* 
	* @return void
	*/
	void AddSound(string name, string filePath);

	/**
	* @brief Checks if there is a free channel to play the requested sound, if there is and the sound exists inside 
	* the sound map, the sound is played using Mix_PlayChannel()
	*
	* @param name - the name of the sound to play
	* @param loopCount - the number of times to play the sound. A loop count of -1 will cause the track to loop
	* continuously until the channel is halted
	*
	* @return ChannelHandle
	*/
	ChannelHandle PlaySound(string name, int loopCount);

	/**
	* @brief Pauses the requested channel
	*
	* @param sound - the channel that the sound you want to pause is playing on
	*
	* @return void
	*/
	void PauseChannel(ChannelHandle sound);

	/**
	* @brief Resumes playing the requested channel
	*
	* @param sound - the channel that the sound you want to resume playing is playing on
	*
	* @return void
	*/
	void ResumeChannel(ChannelHandle sound);

};

#endif
