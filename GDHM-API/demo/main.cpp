#include <Windows.h>
#include <string>
#include <gdhm.h>

static unsigned int counter = 0;
static bool _init = false;
void _main_callback()
{
	// Example of initialising
	if (!_init)
	{
		MessageBoxA(NULL, "Welcome :)", "GDHM API Initialised", NULL);
		_init = true;
	}
	// Example of callback function usage
	++counter;
	if (counter > 360u) counter = 0;
}

void _footer()
{
	// Example of footer label
	GDHM::add_label("Test Footer Label");
	GDHM::add_label("");
	
	// Example of getting windows size
	if (GDHM::add_button("Check Size"))
	{
		const auto _size = GDHM::get_window_size();
		MessageBoxA(NULL, std::to_string(_size.x).c_str(), "x size", NULL);
		MessageBoxA(NULL, std::to_string(_size.y).c_str(), "y size", NULL);
	}

	// Example of getting windows position
	if (GDHM::add_button("Check Position"))
	{
		const auto _size = GDHM::get_window_position();
		MessageBoxA(NULL, std::to_string(_size.x).c_str(), "x position", NULL);
		MessageBoxA(NULL, std::to_string(_size.y).c_str(), "y position", NULL);
	}

	// Example of setting windows position
	if (GDHM::add_button("Set Position"))
	{
		GDHM::set_window_position(0.f, 0.f);
	}

	// Example of setting windows position
	if (GDHM::add_button("Set Size"))
	{
		//GDHM::set_window_size(100.f, 500.f);
		GDHM::set_window_size_y(200.f);
	}
	GDHM::add_label("");

	// Example of showing counter using label
	GDHM::add_label("Counter");
	GDHM::add_label(std::to_string(counter).c_str());
	GDHM::add_label("");
}

void _header()
{
	// Example of label
	GDHM::add_label("Test Label");
	GDHM::add_label("");

	// Example of button
	if (GDHM::add_button("Test Button"))
	{
		MessageBoxA(NULL, "Hello!", "A button", NULL);
	}
	// Example of checkbox
	static bool _checkbox = false;
	if (GDHM::add_checkbox("Test Checkbox", &_checkbox))
	{
		MessageBoxA(NULL, _checkbox ? "True" : "False", "The value is", NULL);
	}
	GDHM::add_label("");

	// Example of text box
	static char _text_box[10];
	GDHM::add_text_box("", _text_box, 10, "TEST_TEXT_BOX");
	if (GDHM::last_item_just_released())
	{
		MessageBoxA(NULL, _text_box, "The value is", NULL);
	}
	GDHM::add_label("");
}

DWORD WINAPI _dll_main(LPVOID lpParam)
{
	// Example of loader
	if (GDHM::is_gdhm_loaded())
	{
		// Example of normal window
		GDHM::add_mod_window(3.f, "GDHM API Demo", "", _main_callback, _header, _footer, 0.f, 400.f);
		// Example of mod window
		GDHM::add_mod_window(4.f, "GDHM API Mod Demo", "dummy.json");
	}
	else
	{
		MessageBoxA(NULL, "ToastedMarshmellow.dll not found.", "Error!", NULL);
	}
	return TRUE;
}