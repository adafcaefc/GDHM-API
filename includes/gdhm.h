#ifndef GDHM_API_H
#define GDHM_API_H

#pragma comment (lib, "ToastedMarshmellow.lib")
#define GDHM_API __declspec(dllimport)

namespace GDHM
{
	struct TMVec2
	{
		float x, y;
		TMVec2() { x = y = 0.f; }
		TMVec2(const float _x, const float _y) : x(_x), y(_y) {}
	};

	// This will add a new window in GDHM
	GDHM_API void add_mod_window(
		const char* name,
		const float _index = 0.f,
		const char* mod_file_name = "",
		void* callback = nullptr,
		void* header = nullptr,
		void* footer = nullptr,
		const float extra_width = 0.f,
		const float extra_height = 0.f);

	// These will add common controls
	GDHM_API bool add_checkbox(const char* label, bool* handle);
	GDHM_API bool add_button(const char* label);
	GDHM_API void add_label(const char* label);
	GDHM_API bool add_text_box(
		const char* label,
		char* buffer,
		const size_t buffer_size,
		const char* tag = nullptr);

	// This will check whether the last item has just released
	GDHM_API bool last_item_just_released();

	// These will set window position
	GDHM_API void set_window_position_x(const float x_value);
	GDHM_API void set_window_position_y(const float y_value);
	GDHM_API void set_window_position(const float x_value, const float y_value);
	GDHM_API TMVec2 get_window_position();

	// These will set window size
	GDHM_API void set_window_size_x(const float x_value);
	GDHM_API void set_window_size_y(const float y_value);
	GDHM_API void set_window_size(const float x_value, const float y_value);
	GDHM_API TMVec2 get_window_size();

	// This will check whether GDHM is loaded
	static bool is_gdhm_loaded()
	{
		return GetModuleHandle(TEXT("ToastedMarshmellow.dll"));
	}
}

#undef GDHM_API

#endif // GDHM_API_H