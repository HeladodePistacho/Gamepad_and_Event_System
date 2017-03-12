
#include "p2Defs.h"
#include "p2Log.h"
#include "j1Fonts.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Window.h"
#include "j1Console.h"
#include "UI_Text_Box.h"
#include "j1Gui.h"
#include "j1GameLayer.h"
#include "Player.h"
#include "InputManager.h"
#include "SDL/include/SDL.h"

#define MAX_KEYS 300

j1Input::j1Input() : j1Module()
{
	name = ("input");

	keyboard = new j1KeyState[MAX_KEYS];
	memset(keyboard, KEY_IDLE, sizeof(j1KeyState) * MAX_KEYS);
	memset(mouse_buttons, KEY_IDLE, sizeof(j1KeyState) * NUM_MOUSE_BUTTONS);
}

// Destructor
j1Input::~j1Input()
{
	delete[] keyboard;
}

// Called before render is available
bool j1Input::Awake(pugi::xml_node& config)
{
	LOG("Init SDL input event system");
	bool ret = true;
	
	//TODO 1 Init SDL_INIT_GAMECONTROLLER


	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called before the first frame
bool j1Input::Start()
{
	//TODO 2 open the game controller pointer
	

	
	return true;
}

// Called each loop iteration
bool j1Input::PreUpdate()
{
	
	static SDL_Event event;	

	for (int i = 0; i < NUM_MOUSE_BUTTONS; ++i)
	{
		if (mouse_buttons[i] == KEY_DOWN)
			mouse_buttons[i] = KEY_REPEAT;

		if (mouse_buttons[i] == KEY_UP)
			mouse_buttons[i] = KEY_IDLE;
	}

	for (int i = 0; i < NUM_CONTROLLER_BUTTONS; ++i)
	{
		//TODO 3 Fill this

		//TODO 5 Call it here too 
	}


	while(SDL_PollEvent(&event) != 0)
	{
		switch(event.type)
		{
			case SDL_QUIT:
				windowEvents[WE_QUIT] = true;
			break;

			case SDL_WINDOWEVENT:
				switch(event.window.event)
				{
					//case SDL_WINDOWEVENT_LEAVE:
					case SDL_WINDOWEVENT_HIDDEN:
					case SDL_WINDOWEVENT_MINIMIZED:
					case SDL_WINDOWEVENT_FOCUS_LOST:
					windowEvents[WE_HIDE] = true;
					break;

					//case SDL_WINDOWEVENT_ENTER:
					case SDL_WINDOWEVENT_SHOWN:
					case SDL_WINDOWEVENT_FOCUS_GAINED:
					case SDL_WINDOWEVENT_MAXIMIZED:
					case SDL_WINDOWEVENT_RESTORED:
					windowEvents[WE_SHOW] = true;
					break;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				mouse_buttons[event.button.button - 1] = KEY_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				mouse_buttons[event.button.button - 1] = KEY_UP;
				break;
			
			case SDL_CONTROLLERBUTTONDOWN:
				//TODO 3 case DOWN
				
				//TODO 5 Call it here
				App->inputM->InputDetected(event.cbutton.button, EVENTSTATE::E_DOWN);
				break;

			case SDL_CONTROLLERBUTTONUP:
				//TODO 3 case UP
				
				//TODO 5 and here
				App->inputM->InputDetected(event.cbutton.button, EVENTSTATE::E_UP);
				break;

	
			case SDL_CONTROLLERDEVICEADDED:
				
				//TODO 2 SPECIAL CASE: check if this is a gamecontroller -> event.cdevice.which ;)
				

				break;

			case SDL_CONTROLLERDEVICEREMOVED:
				//TODO 2 SPECIAL CASE "close" the pointer be polite ;)
				
				break;
		}
	}

	return true;
}

bool j1Input::PostUpdate()
{

	return true;
}

// Called before quitting
bool j1Input::CleanUp()
{
	LOG("Quitting SDL event subsystem");

	//TODO 2 "close" the pointer be polite ;)
	

	//TODO 1 Close it be polite

	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}

// ---------
bool j1Input::GetWindowEvent(j1EventWindow ev)
{
	return windowEvents[ev];
}

void j1Input::GetMousePosition(int& x, int& y)
{
	x = mouse_x;
	y = mouse_y;
}

void j1Input::GetMouseMotion(int& x, int& y)
{

	x = mouse_motion_x;
	y = mouse_motion_y;

}

void j1Input::GetMouseWheel(int& y)
{
	y = mouse_wheel;
}




