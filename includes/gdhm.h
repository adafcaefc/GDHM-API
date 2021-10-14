#ifndef GDHM_API_H
#define GDHM_API_H

#if GDHM_API_IMPL == 1
	#define GDHM_API __declspec(dllexport)
#else
	#pragma comment (lib, "ToastedMarshmellow.lib")
	#define GDHM_API __declspec(dllimport)
#endif

namespace gdhm
{
	struct Vec2
	{
		float
			x = 0.f,
			y = 0.f;
		Vec2() { x = y = 0.f; }
		Vec2(const float _x, const float _y) : x(_x), y(_y) {}
		#ifdef GDHM_API_USE_IMGUI
		Vec2(const ImVec2& v) : x(v.x), y(v.y) {}
		#endif
	};

	#if GDHM_API_IMPL != 1
	// This will add a new window in GDHM
	GDHM_API void add_mod_window(
		const char* name,
		const char* mod_file_name,
		const char* tag = nullptr,
		void* callback = nullptr,
		void* header = nullptr,
		void* footer = nullptr,
		bool* handle = nullptr,
		const bool constraint_height = false,
		const float max_height = 0.f);

	// These will add common controls
	GDHM_API bool add_checkbox(const char* label, bool* handle);
	GDHM_API bool add_button(const char* label);
	GDHM_API void add_label(const char* label);
	GDHM_API bool add_text_box(
		const char* label,
		char* buffer,
		const size_t buffer_size,
		const char* tag = nullptr);
	GDHM_API bool add_text_box(
		char* buffer,
		const size_t buffer_size,
		const char* tag = nullptr);
	// drag_float will be changed to add_drag_float on version above v32.62
	GDHM_API void drag_float(
		float* value,
		const float v_speed = 1.0f,
		const float v_min = 0.0f,
		const float v_max = 0.0f,
		const char* label_format = "%.3f",
		const char* tag = nullptr,
		void* on_release = nullptr);
	GDHM_API void drag_float(
		const char* label,
		float* value,
		const float v_speed = 1.0f,
		const float v_min = 0.0f,
		const float v_max = 0.0f,
		const char* label_format = "%.3f",
		const char* tag = nullptr,
		void* on_release = nullptr);

	// This will check whether the last item has just released
	GDHM_API bool last_item_just_released();

	// These will manage window position
	GDHM_API void set_window_position_x(const float x_value);
	GDHM_API void set_window_position_y(const float y_value);
	GDHM_API void set_window_position(const float x_value, const float y_value);
	GDHM_API Vec2 get_window_position();

	// These will manage window size
	GDHM_API Vec2 get_window_size();

	// This will check whether GDHM is loaded
	static inline bool is_gdhm_loaded() { return GetModuleHandle(TEXT("ToastedMarshmellow.dll")); }

	// This will check the current GDHM version
	GDHM_API std::string get_version();
	#endif
}

#undef GDHM_API

#endif // GDHM_API_H