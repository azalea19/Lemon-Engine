#ifndef InputManager_H__
#define InputManager_H__
#include <cstdint>
#include "SDL.h"
#include "Types.h"

/**
* @file   InputManager.h
* @Author Maddisen Topaz
* @date   S2, 2016
* @brief  The input manager.
*
* The input manager uses the SDL2 library to create an event queue of mouse button and mouse motion events
* See SDL_MouseButtonEvent or SDL_MouseMotionEvent: 
* https://wiki.libsdl.org/SDL_MouseButtonEvent
* https://wiki.libsdl.org/SDL_MouseMotionEvent
* The state of the keyboard is kept track of so that the input manager may be queried about if a key has been pressed, 
* released or is down.
* 
*/


enum MouseEventType : uint32_t
{
	ME_BUTTON = 0,
	ME_MOTION = 1,
};

/**
* @brief The SDL_MOUSE_EVENT union is used to store a mouse event that could be either a button event or a motion event,
* it uses the SDL_MouseButtonEvent or the SDL_MouseMotionEvent
*/
union SDL_MOUSE_EVENT
{
	SDL_MouseButtonEvent buttonEvent;
	SDL_MouseMotionEvent motionEvent;
};

/**
* @brief A MouseEvent is composed of an event type and an SDL_MOUSE_EVENT
* The MouseEvent struct is designed to handle a mouse motion or mouse button event depending on what it is passed in the 
* SDL_MOUSE_EVENT
*/
struct MouseEvent
{
	MouseEventType eventType;
	SDL_MOUSE_EVENT mouseEvent;

	MouseEvent(SDL_MouseButtonEvent _event)
	{
		eventType = ME_BUTTON;
		mouseEvent.buttonEvent = _event;
	}

	MouseEvent(SDL_MouseMotionEvent _event)
	{
		eventType = ME_MOTION;
		mouseEvent.motionEvent = _event;
	}
};

struct MouseButtonState
{
	bool pressed;
	bool released;
	bool down;
};

class InputManager
{
	std::vector<MouseEvent> eventQueue;
	int keyStateSize = 0;

	void ProcessButtonEvent(SDL_MouseButtonEvent _event);
	void ProcessMotionEvent(SDL_MouseMotionEvent _event);
	void ProcessEventQueue();

public:

	InputManager();

	/**
	* @brief Returns a static reference to the input manager singleton
	*
	* @return static InputManager*
	*/
	static InputManager* GetInputManager();

	uint8_t keyboardState[16384];
	uint8_t lastKeyboardState[16384];

	MouseButtonState mouseButtonStates[4];

	int32_t mouseDeltaX;
	int32_t mouseDeltaY;

	//Updates all the states.

	/**
	* @brief Updates all the states, including the state of the mouse and keyboard.
	*
	* @return void
	*/
	void Update();


	/**
	* @brief Pushes a new event in to the vent queue for processing
	*
	* @param MouseEvent - the event to add to the queue
	*
	* @return void
	*/
	void PushEvent(MouseEvent const& _event);


	/**
	* @brief Checks if the key specified is down
	*
	* @param keyCode - the key being checked
	*
	* @return bool
	*/
	bool IsKeyDown(int keyCode);


	/**
	* @brief Checks if the key specified is up
	*
	* @param keyCode - the key being checked
	*
	* @return bool
	*/
	bool IsKeyUp(int keyCode);

	/**
	* @brief Checks if the key specified is down this frame but up on the last
	*
	* @param keyCode - the key being checked
	*
	* @return bool
	*/
	bool IsKeyPressed(int keyCode); //down this frame but up last

	/**
	* @brief Checks if the key specified is up this frame but down on the last
	*
	* @param keyCode - the key being checked
	*
	* @return bool
	*/
	bool IsKeyReleased(int keyCode); //up this frame but down last

	/**
	* @brief Checks if the left mouse button is down
	*
	* @return bool
	*/
	bool IsMouseDownLeft();

	/**
	* @brief Checks if the mouse button is not down
	*
	* @return bool
	*/
	bool IsMouseUpLeft();

	/**
	* @brief Checks if the key specified is down
	*
	* @return bool
	*/
	bool IsMousePressedLeft();

	/**
	* @brief Checks if the left mouse button is released
	*
	* @return bool
	*/
	bool IsMouseReleasedLeft();

	/**
	* @brief Checks if the right mouse button is down
	*
	* @return bool
	*/
	bool IsMouseDownRight();

	/**
	* @brief Checks if the right mouse button is not down
	*
	* @return bool
	*/
	bool IsMouseUpRight();

	/**
	* @brief Checks if the right mouse button is pressed
	*
	* @return bool
	*/
	bool IsMousePressedRight();

	/**
	* @brief Checks if the right mouse button is released
	*
	* @return bool
	*/
	bool IsMouseReleasedRight();

	int32_t MouseDeltaX();
	int32_t MouseDeltaY();

};
#endif
