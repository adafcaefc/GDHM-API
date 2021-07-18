#ifndef GDHM_API_H
#define GDHM_API_H

#include <functional>
#pragma comment (lib, "ToastedMarshmellow.lib")
#define GDHM_API __declspec(dllimport)

struct ImVec2
{
	float x, y;
	ImVec2()
	{
		x = y = 0.f;
	}
	ImVec2(
		float _x, 
		float _y)
	{ 
		x = _x; 
		y = _y; 
	}
};

namespace GDHM
{
	GDHM_API void add_mod_window(
		const float _index,
		const char* name,
		const char* mod_file_name = "",
		const std::function<void()>& callback = []() {},
		const std::function<void()>& header = []() {},
		const std::function<void()>& footer = []() {},
		const float extra_width = 0.f,
		const float extra_height = 0.f);

	GDHM_API bool add_checkbox(const char* label, bool* handle);
	GDHM_API bool add_button(const char* label);
	GDHM_API void add_label(const char* label);

	GDHM_API bool add_text_box(
		const char* label,
		char* buffer,
		const size_t buffer_size,
		const char* tag = nullptr);

	GDHM_API bool last_item_just_released();

	GDHM_API void set_window_position_x(const float x_value);
	GDHM_API void set_window_position_y(const float y_value);
	GDHM_API void set_window_position(const float x_value, const float y_value);
	GDHM_API ImVec2 get_window_position();

	GDHM_API void set_window_size_x(const float x_value);
	GDHM_API void set_window_size_y(const float y_value);
	GDHM_API void set_window_size(const float x_value, const float y_value);
	GDHM_API ImVec2 get_window_size();

	static bool is_gdhm_loaded()
	{
		return GetModuleHandle(TEXT("ToastedMarshmellow.dll"));
	}
}

#undef GDHM_API

#endif // GDHM_API_H