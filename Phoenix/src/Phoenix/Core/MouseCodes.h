#pragma once

namespace Phx
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}


#define PHX_MOUSE_BUTTON_1         ::Phx::MouseCode::Button0
#define PHX_MOUSE_BUTTON_2         ::Phx::MouseCode::Button1
#define PHX_MOUSE_BUTTON_3         ::Phx::MouseCode::Button2
#define PHX_MOUSE_BUTTON_4         ::Phx::MouseCode::Button3
#define PHX_MOUSE_BUTTON_5         ::Phx::MouseCode::Button4
#define PHX_MOUSE_BUTTON_6         ::Phx::MouseCode::Button5
#define PHX_MOUSE_BUTTON_7         ::Phx::MouseCode::Button6
#define PHX_MOUSE_BUTTON_8         ::Phx::MouseCode::Button7
#define PHX_MOUSE_BUTTON_LAST      ::Phx::MouseCode::ButtonLast
#define PHX_MOUSE_BUTTON_LEFT      ::Phx::MouseCode::ButtonLeft
#define PHX_MOUSE_BUTTON_RIGHT     ::Phx::MouseCode::ButtonRight
#define PHX_MOUSE_BUTTON_MIDDLE    ::Phx::MouseCode::ButtonMiddle