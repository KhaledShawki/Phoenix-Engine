#pragma once

namespace Phx
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}


// From glfw3.h
#define PHX_KEY_SPACE              ::Phx::Key::Space
#define PHX_KEY_APOSTROPHE         ::Phx::Key::Apostrophe    /* ' */
#define PHX_KEY_COMMA              ::Phx::Key::Comma         /* , */
#define PHX_KEY_MINUS              ::Phx::Key::Minus         /* - */
#define PHX_KEY_PERIOD             ::Phx::Key::Period        /* . */
#define PHX_KEY_SLASH              ::Phx::Key::Slash         /* / */
#define PHX_KEY_0                  ::Phx::Key::D0
#define PHX_KEY_1                  ::Phx::Key::D1
#define PHX_KEY_2                  ::Phx::Key::D2
#define PHX_KEY_3                  ::Phx::Key::D3
#define PHX_KEY_4                  ::Phx::Key::D4
#define PHX_KEY_5                  ::Phx::Key::D5
#define PHX_KEY_6                  ::Phx::Key::D6
#define PHX_KEY_7                  ::Phx::Key::D7
#define PHX_KEY_8                  ::Phx::Key::D8
#define PHX_KEY_9                  ::Phx::Key::D9
#define PHX_KEY_SEMICOLON          ::Phx::Key::Semicolon     /* ; */
#define PHX_KEY_EQUAL              ::Phx::Key::Equal         /* = */
#define PHX_KEY_A                  ::Phx::Key::A
#define PHX_KEY_B                  ::Phx::Key::B
#define PHX_KEY_C                  ::Phx::Key::C
#define PHX_KEY_D                  ::Phx::Key::D
#define PHX_KEY_E                  ::Phx::Key::E
#define PHX_KEY_F                  ::Phx::Key::F
#define PHX_KEY_G                  ::Phx::Key::G
#define PHX_KEY_H                  ::Phx::Key::H
#define PHX_KEY_I                  ::Phx::Key::I
#define PHX_KEY_J                  ::Phx::Key::J
#define PHX_KEY_K                  ::Phx::Key::K
#define PHX_KEY_L                  ::Phx::Key::L
#define PHX_KEY_M                  ::Phx::Key::M
#define PHX_KEY_N                  ::Phx::Key::N
#define PHX_KEY_O                  ::Phx::Key::O
#define PHX_KEY_P                  ::Phx::Key::P
#define PHX_KEY_Q                  ::Phx::Key::Q
#define PHX_KEY_R                  ::Phx::Key::R
#define PHX_KEY_S                  ::Phx::Key::S
#define PHX_KEY_T                  ::Phx::Key::T
#define PHX_KEY_U                  ::Phx::Key::U
#define PHX_KEY_V                  ::Phx::Key::V
#define PHX_KEY_W                  ::Phx::Key::W
#define PHX_KEY_X                  ::Phx::Key::X
#define PHX_KEY_Y                  ::Phx::Key::Y
#define PHX_KEY_Z                  ::Phx::Key::Z
#define PHX_KEY_LEFT_BRACKET       ::Phx::Key::LeftBracket   /* [ */
#define PHX_KEY_BACKSLASH          ::Phx::Key::Backslash     /* \ */
#define PHX_KEY_RIGHT_BRACKET      ::Phx::Key::RightBracket  /* ] */
#define PHX_KEY_GRAVE_ACCENT       ::Phx::Key::GraveAccent   /* ` */
#define PHX_KEY_WORLD_1            ::Phx::Key::World1        /* non-US #1 */
#define PHX_KEY_WORLD_2            ::Phx::Key::World2        /* non-US #2 */


/* Function keys */
#define PHX_KEY_ESCAPE             ::Phx::Key::Escape
#define PHX_KEY_ENTER              ::Phx::Key::Enter
#define PHX_KEY_TAB                ::Phx::Key::Tab
#define PHX_KEY_BACKSPACE          ::Phx::Key::Backspace
#define PHX_KEY_INSERT             ::Phx::Key::Insert
#define PHX_KEY_DELETE             ::Phx::Key::Delete
#define PHX_KEY_RIGHT              ::Phx::Key::Right
#define PHX_KEY_LEFT               ::Phx::Key::Left
#define PHX_KEY_DOWN               ::Phx::Key::Down
#define PHX_KEY_UP                 ::Phx::Key::Up
#define PHX_KEY_PAGE_UP            ::Phx::Key::PageUp
#define PHX_KEY_PAGE_DOWN          ::Phx::Key::PageDown
#define PHX_KEY_HOME               ::Phx::Key::Home
#define PHX_KEY_END                ::Phx::Key::End
#define PHX_KEY_CAPS_LOCK          ::Phx::Key::CapsLock
#define PHX_KEY_SCROLL_LOCK        ::Phx::Key::ScrollLock
#define PHX_KEY_NUM_LOCK           ::Phx::Key::NumLock
#define PHX_KEY_PRINT_SCREEN       ::Phx::Key::PrintScreen
#define PHX_KEY_PAUSE              ::Phx::Key::Pause
#define PHX_KEY_F1                 ::Phx::Key::F1
#define PHX_KEY_F2                 ::Phx::Key::F2
#define PHX_KEY_F3                 ::Phx::Key::F3
#define PHX_KEY_F4                 ::Phx::Key::F4
#define PHX_KEY_F5                 ::Phx::Key::F5
#define PHX_KEY_F6                 ::Phx::Key::F6
#define PHX_KEY_F7                 ::Phx::Key::F7
#define PHX_KEY_F8                 ::Phx::Key::F8
#define PHX_KEY_F9                 ::Phx::Key::F9
#define PHX_KEY_F10                ::Phx::Key::F10
#define PHX_KEY_F11                ::Phx::Key::F11
#define PHX_KEY_F12                ::Phx::Key::F12
#define PHX_KEY_F13                ::Phx::Key::F13
#define PHX_KEY_F14                ::Phx::Key::F14
#define PHX_KEY_F15                ::Phx::Key::F15
#define PHX_KEY_F16                ::Phx::Key::F16
#define PHX_KEY_F17                ::Phx::Key::F17
#define PHX_KEY_F18                ::Phx::Key::F18
#define PHX_KEY_F19                ::Phx::Key::F19
#define PHX_KEY_F20                ::Phx::Key::F20
#define PHX_KEY_F21                ::Phx::Key::F21
#define PHX_KEY_F22                ::Phx::Key::F22
#define PHX_KEY_F23                ::Phx::Key::F23
#define PHX_KEY_F24                ::Phx::Key::F24
#define PHX_KEY_F25                ::Phx::Key::F25

/* Keypad */
#define PHX_KEY_KP_0               ::Phx::Key::KP0
#define PHX_KEY_KP_1               ::Phx::Key::KP1
#define PHX_KEY_KP_2               ::Phx::Key::KP2
#define PHX_KEY_KP_3               ::Phx::Key::KP3
#define PHX_KEY_KP_4               ::Phx::Key::KP4
#define PHX_KEY_KP_5               ::Phx::Key::KP5
#define PHX_KEY_KP_6               ::Phx::Key::KP6
#define PHX_KEY_KP_7               ::Phx::Key::KP7
#define PHX_KEY_KP_8               ::Phx::Key::KP8
#define PHX_KEY_KP_9               ::Phx::Key::KP9
#define PHX_KEY_KP_DECIMAL         ::Phx::Key::KPDecimal
#define PHX_KEY_KP_DIVIDE          ::Phx::Key::KPDivide
#define PHX_KEY_KP_MULTIPLY        ::Phx::Key::KPMultiply
#define PHX_KEY_KP_SUBTRACT        ::Phx::Key::KPSubtract
#define PHX_KEY_KP_ADD             ::Phx::Key::KPAdd
#define PHX_KEY_KP_ENTER           ::Phx::Key::KPEnter
#define PHX_KEY_KP_EQUAL           ::Phx::Key::KPEqual

#define PHX_KEY_LEFT_SHIFT         ::Phx::Key::LeftShift
#define PHX_KEY_LEFT_CONTROL       ::Phx::Key::LeftControl
#define PHX_KEY_LEFT_ALT           ::Phx::Key::LeftAlt
#define PHX_KEY_LEFT_SUPER         ::Phx::Key::LeftSuper
#define PHX_KEY_RIGHT_SHIFT        ::Phx::Key::RightShift
#define PHX_KEY_RIGHT_CONTROL      ::Phx::Key::RightControl
#define PHX_KEY_RIGHT_ALT          ::Phx::Key::RightAlt
#define PHX_KEY_RIGHT_SUPER        ::Phx::Key::RightSuper
#define PHX_KEY_MENU               ::Phx::Key::Menu