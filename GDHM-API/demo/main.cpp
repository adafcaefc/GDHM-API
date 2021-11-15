#include <Windows.h>
#include <string>
#include <gdhm.h>

static unsigned int my_counter = 0;
void _main_callback()
{
	// Example of callback function usage
	++my_counter;
	if (my_counter > 360u) my_counter = 0u;
}

static void callback_1()
{
	// Functions here will be triggered both on click and on hotkey press
	MessageBoxA(NULL, "callback_1", "hello", NULL);
}

static void callback_2()
{
	// Functions here will be triggered both on click and on hotkey press
	MessageBoxA(NULL, "callback_2", "hello", NULL);
}

static void callback_3()
{
	// Functions here will be triggered both on click and on hotkey press
	MessageBoxA(NULL, "callback_3", "hello", NULL);
}

void _footer()
{
	// Example of footer label
	gdhm::gui::label("Test Footer Label");
	gdhm::gui::label("");
	
	// Example of adding buttons using variables
	static std::uint8_t button_1_key = 0;
	gdhm::gui::button(
		gdhm_new_id(),
		"Button 1",
		&button_1_key,
		callback_1,
		"Number one info.");

	// Example of adding buttons using struct with info
	static gdhm::control button_2("Button 2", "Number two info.");
	gdhm::gui::button(
		gdhm_new_id(),
		&button_2,
		callback_2);

	// Example of adding buttons using struct without info
	static gdhm::control button_3("Button 3");
	gdhm::gui::button(
		gdhm_new_id(),
		&button_3,
		callback_3);
	gdhm::gui::label("");

	// Example of showing counter using label
	gdhm::gui::label("Counter");
	gdhm::gui::label(std::to_string(my_counter).c_str());
}

void _header()
{
	// Example of label
	gdhm::gui::label("Test Label");
	gdhm::gui::label("GDHM version:");
	gdhm::gui::label(gdhm::get_version().c_str());
	gdhm::gui::label("");

	static gdhm::control button_1("Test Button");
	// Example of button
	gdhm::gui::button(
		gdhm_new_id(),
		"Test Button",
		nullptr, // no hotkey option is applied by passing nullptr to the hotkey option
		[]() { MessageBoxA(NULL, "Hello!", "A button", NULL); });

	// Example of checkbox
	static bool _checkbox_value = false;
	gdhm::gui::checkbox(
		gdhm_new_id(), 
		"Test Checkbox", 
		&_checkbox_value, 
		nullptr, // no hotkey option is applied by passing nullptr to the hotkey option
		[]() { MessageBoxA(NULL, _checkbox_value ? "True" : "False", "The value is", NULL); });

	// Example of checkbox without callback
	static bool _checkbox_value_2 = false;
	gdhm::gui::checkbox(
		gdhm_new_id(),
		"Test Checkbox 2",
		&_checkbox_value_2);

	gdhm::gui::label("");

	// Example of text box
	static char _text_box[10];
	gdhm::gui::input_text(
		gdhm_new_id(),
		_text_box, 
		sizeof(_text_box),
		[]() { MessageBoxA(NULL, _text_box, "The value is", NULL); });
	gdhm::gui::label("");

	// Example of drag float
	static float _drag_test = 1.f;
	gdhm::gui::input_float(
		gdhm_new_id(), 
		&_drag_test,
		"Float Input %.2f",
		1.f,
		0.f,
		0.f,
		[&]() { MessageBoxA(NULL, std::to_string(_drag_test).c_str(), "The value is", NULL); });
	gdhm::gui::label("");

	// Example of list box
	static std::vector<std::string> items = { "Item 1", "Item 2", "Item 3" };
	static std::uint8_t selected = NULL;
	gdhm::gui::list_box(
		gdhm_new_id(), 
		&selected, items, 
		[&]() { MessageBoxA(NULL, items.at(selected).c_str(), "You selected", NULL); });
	gdhm::gui::label("");
}

DWORD WINAPI _dll_main(LPVOID lpParam)
{
	// Example of loader
	if (gdhm::is_loaded())
	{
		// Example of normal window
		gdhm::gui::window("GDHM API DEMO", "", nullptr, _main_callback, _header, _footer);

		// Example of mod window
		gdhm::gui::window("GDHM API MOD DEMO", "dummy.json", nullptr);
	}
	else
	{
		MessageBoxA(NULL, "ToastedMarshmellow.dll not found.", "Error!", NULL);
	}
	return TRUE;
}