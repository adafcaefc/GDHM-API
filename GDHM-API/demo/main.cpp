#include <Windows.h>
#include <string>
#include <gdhm.h>

static unsigned int counter = 0;

void _main_callback()
{
	// Example of initialising
	static bool _init = false;
	if (!_init)
	{
		MessageBoxA(NULL, "Welcome :)", "gdhm API Initialised", NULL);
		_init = true;
	}

	// Example of callback function usage
	++counter;
	if (counter > 360u) counter = 0;
}

void _footer()
{
	// Example of footer label
	gdhm::add_label("Test Footer Label");
	gdhm::add_label("");
	
	// Example of getting windows size
	if (gdhm::add_button("Check Size"))
	{
		const auto _size = gdhm::get_window_size();
		MessageBoxA(NULL, std::to_string(_size.x).c_str(), "x size", NULL);
		MessageBoxA(NULL, std::to_string(_size.y).c_str(), "y size", NULL);
	}

	// Example of getting windows position
	if (gdhm::add_button("Check Position"))
	{
		const auto _size = gdhm::get_window_position();
		MessageBoxA(NULL, std::to_string(_size.x).c_str(), "x position", NULL);
		MessageBoxA(NULL, std::to_string(_size.y).c_str(), "y position", NULL);
	}

	// Example of setting windows position
	if (gdhm::add_button("Set Position"))
	{
		gdhm::set_window_position(0.f, 0.f);
	}
	gdhm::add_label("");

	// Example of showing counter using label
	gdhm::add_label("Counter");
	gdhm::add_label(std::to_string(counter).c_str());
	gdhm::add_label("");
}

void _header()
{
	// Example of label
	gdhm::add_label("Test Label");
	gdhm::add_label("GDHM version:");
	gdhm::add_label(gdhm::get_version().c_str());
	gdhm::add_label("");

	// Example of button
	if (gdhm::add_button("Test Button"))
	{
		MessageBoxA(NULL, "Hello!", "A button", NULL);
	}

	// Example of checkbox
	static bool _checkbox = false;
	if (gdhm::add_checkbox("Test Checkbox", &_checkbox))
	{
		MessageBoxA(NULL, _checkbox ? "True" : "False", "The value is", NULL);
	}
	gdhm::add_label("");

	// Example of text box
	static char _text_box[10];
	gdhm::add_text_box("", _text_box, 10, "TEST_TEXT_BOX");
	if (gdhm::last_item_just_released())
	{
		MessageBoxA(NULL, _text_box, "The value is", NULL);
	}
	gdhm::add_label("");

	// Example of drag float
	static float _drag_test = 1.f;
	gdhm::add_drag_float(&_drag_test);
	if (gdhm::last_item_just_released())
	{
		MessageBoxA(NULL, std::to_string(_drag_test).c_str(), "The value is", NULL);
	}
	gdhm::add_label("");
}

DWORD WINAPI _dll_main(LPVOID lpParam)
{
	// Example of loader
	if (gdhm::is_gdhm_loaded())
	{
		// Example of normal window
		gdhm::add_mod_window("GDHM API DEMO", "", nullptr, _main_callback, _header, _footer);
		// Example of mod window
		gdhm::add_mod_window("GDHM API MOD DEMO", "dummy.json", nullptr);
	}
	else
	{
		MessageBoxA(NULL, "ToastedMarshmellow.dll not found.", "Error!", NULL);
	}
	return TRUE;
}