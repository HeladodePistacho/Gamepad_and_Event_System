#include "InputManager.h"
#include "j1App.h"
#include "p2Defs.h"
#include "p2Log.h"
#include "j1FileSystem.h"
#include "j1Input.h"
#include "j1Fonts.h"
#include "j1Audio.h"
#include "SDL\include\SDL.h"

InputManager::InputManager() : j1Module()
{
	name = "inputManager";
}

// Destructor
InputManager::~InputManager()
{}

// Called when before render is available
bool InputManager::Awake(pugi::xml_node& conf)
{
	bool ret = true;

	//Load All actions
	//TODO 4 quit the comment when doned
	/*
	for (pugi::xml_node tmp = conf.child("action"); tmp != nullptr; tmp = tmp.next_sibling())
	{
		std::pair<int, INPUTEVENT> new_action;
		new_action.first = tmp.attribute("button").as_int();
		new_action.second = (INPUTEVENT)tmp.attribute("event").as_int();

		//change this if your map name is diferent -> actions.insert(new_action);
	}
	*/
 	
	return ret;
}

// Called before all Updates
bool InputManager::PreUpdate()
{
	bool ret = true;
	return ret;
}

bool InputManager::Update(float dt)
{
	//CallListeners();

	//TODO 7 uncommnet this after doned
	/*
	if (EventPressed(PAUSE) == E_DOWN)
	{
		ChangeInputEvent(MUP);
	}
	*/

	return true;
}

// Called after all Updates
bool InputManager::PostUpdate()
{
	//TODO 6 frame has gone clean your actions
	

	return true;
}

// Called before quitting
bool InputManager::CleanUp()
{
	bool ret = true;

	

	return ret;
}

void InputManager::InputDetected(int button, EVENTSTATE state)
{
	if (next_input_change == false)
	{
		//TODO 5 goes here

	}
	else
	{
		ChangeEventButton(button);
	}
}

void InputManager::ChangeInputEvent(INPUTEVENT change_ev)
{
	next_input_change = true;
	event_to_change = change_ev;
}

bool InputManager::ChangeEventButton(int new_button)
{
		bool ret = false;

		//TODO 7
		//Look if the new button is actually asigned
		
		
		//Look for the event to erase it
		

		//Add the event with the new button
		

		//Reset the variables
		

		ret = true;
	

	return ret;
}

EVENTSTATE InputManager::EventPressed(INPUTEVENT action) const
{
	//TODO 6 Look if the "action" have been activated
	
	return E_NOTHING;
}


