#pragma once

namespace Baku
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
#define BK_KEY_SPACE           ::Baku::Key::Space
#define BK_KEY_APOSTROPHE      ::Baku::Key::Apostrophe    /* ' */
#define BK_KEY_COMMA           ::Baku::Key::Comma         /* , */
#define BK_KEY_MINUS           ::Baku::Key::Minus         /* - */
#define BK_KEY_PERIOD          ::Baku::Key::Period        /* . */
#define BK_KEY_SLASH           ::Baku::Key::Slash         /* / */
#define BK_KEY_0               ::Baku::Key::D0
#define BK_KEY_1               ::Baku::Key::D1
#define BK_KEY_2               ::Baku::Key::D2
#define BK_KEY_3               ::Baku::Key::D3
#define BK_KEY_4               ::Baku::Key::D4
#define BK_KEY_5               ::Baku::Key::D5
#define BK_KEY_6               ::Baku::Key::D6
#define BK_KEY_7               ::Baku::Key::D7
#define BK_KEY_8               ::Baku::Key::D8
#define BK_KEY_9               ::Baku::Key::D9
#define BK_KEY_SEMICOLON       ::Baku::Key::Semicolon     /* ; */
#define BK_KEY_EQUAL           ::Baku::Key::Equal         /* = */
#define BK_KEY_A               ::Baku::Key::A
#define BK_KEY_B               ::Baku::Key::B
#define BK_KEY_C               ::Baku::Key::C
#define BK_KEY_D               ::Baku::Key::D
#define BK_KEY_E               ::Baku::Key::E
#define BK_KEY_F               ::Baku::Key::F
#define BK_KEY_G               ::Baku::Key::G
#define BK_KEY_H               ::Baku::Key::H
#define BK_KEY_I               ::Baku::Key::I
#define BK_KEY_J               ::Baku::Key::J
#define BK_KEY_K               ::Baku::Key::K
#define BK_KEY_L               ::Baku::Key::L
#define BK_KEY_M               ::Baku::Key::M
#define BK_KEY_N               ::Baku::Key::N
#define BK_KEY_O               ::Baku::Key::O
#define BK_KEY_P               ::Baku::Key::P
#define BK_KEY_Q               ::Baku::Key::Q
#define BK_KEY_R               ::Baku::Key::R
#define BK_KEY_S               ::Baku::Key::S
#define BK_KEY_T               ::Baku::Key::T
#define BK_KEY_U               ::Baku::Key::U
#define BK_KEY_V               ::Baku::Key::V
#define BK_KEY_W               ::Baku::Key::W
#define BK_KEY_X               ::Baku::Key::X
#define BK_KEY_Y               ::Baku::Key::Y
#define BK_KEY_Z               ::Baku::Key::Z
#define BK_KEY_LEFT_BRACKET    ::Baku::Key::LeftBracket   /* [ */
#define BK_KEY_BACKSLASH       ::Baku::Key::Backslash     /* \ */
#define BK_KEY_RIGHT_BRACKET   ::Baku::Key::RightBracket  /* ] */
#define BK_KEY_GRAVE_ACCENT    ::Baku::Key::GraveAccent   /* ` */
#define BK_KEY_WORLD_1         ::Baku::Key::World1        /* non-US #1 */
#define BK_KEY_WORLD_2         ::Baku::Key::World2        /* non-US #2 */

/* Function keys */
#define BK_KEY_ESCAPE          ::Baku::Key::Escape
#define BK_KEY_ENTER           ::Baku::Key::Enter
#define BK_KEY_TAB             ::Baku::Key::Tab
#define BK_KEY_BACKSPACE       ::Baku::Key::Backspace
#define BK_KEY_INSERT          ::Baku::Key::Insert
#define BK_KEY_DELETE          ::Baku::Key::Delete
#define BK_KEY_RIGHT           ::Baku::Key::Right
#define BK_KEY_LEFT            ::Baku::Key::Left
#define BK_KEY_DOWN            ::Baku::Key::Down
#define BK_KEY_UP              ::Baku::Key::Up
#define BK_KEY_PAGE_UP         ::Baku::Key::PageUp
#define BK_KEY_PAGE_DOWN       ::Baku::Key::PageDown
#define BK_KEY_HOME            ::Baku::Key::Home
#define BK_KEY_END             ::Baku::Key::End
#define BK_KEY_CAPS_LOCK       ::Baku::Key::CapsLock
#define BK_KEY_SCROLL_LOCK     ::Baku::Key::ScrollLock
#define BK_KEY_NUM_LOCK        ::Baku::Key::NumLock
#define BK_KEY_PRINT_SCREEN    ::Baku::Key::PrintScreen
#define BK_KEY_PAUSE           ::Baku::Key::Pause
#define BK_KEY_F1              ::Baku::Key::F1
#define BK_KEY_F2              ::Baku::Key::F2
#define BK_KEY_F3              ::Baku::Key::F3
#define BK_KEY_F4              ::Baku::Key::F4
#define BK_KEY_F5              ::Baku::Key::F5
#define BK_KEY_F6              ::Baku::Key::F6
#define BK_KEY_F7              ::Baku::Key::F7
#define BK_KEY_F8              ::Baku::Key::F8
#define BK_KEY_F9              ::Baku::Key::F9
#define BK_KEY_F10             ::Baku::Key::F10
#define BK_KEY_F11             ::Baku::Key::F11
#define BK_KEY_F12             ::Baku::Key::F12
#define BK_KEY_F13             ::Baku::Key::F13
#define BK_KEY_F14             ::Baku::Key::F14
#define BK_KEY_F15             ::Baku::Key::F15
#define BK_KEY_F16             ::Baku::Key::F16
#define BK_KEY_F17             ::Baku::Key::F17
#define BK_KEY_F18             ::Baku::Key::F18
#define BK_KEY_F19             ::Baku::Key::F19
#define BK_KEY_F20             ::Baku::Key::F20
#define BK_KEY_F21             ::Baku::Key::F21
#define BK_KEY_F22             ::Baku::Key::F22
#define BK_KEY_F23             ::Baku::Key::F23
#define BK_KEY_F24             ::Baku::Key::F24
#define BK_KEY_F25             ::Baku::Key::F25

/* Keypad */
#define BK_KEY_KP_0            ::Baku::Key::KP0
#define BK_KEY_KP_1            ::Baku::Key::KP1
#define BK_KEY_KP_2            ::Baku::Key::KP2
#define BK_KEY_KP_3            ::Baku::Key::KP3
#define BK_KEY_KP_4            ::Baku::Key::KP4
#define BK_KEY_KP_5            ::Baku::Key::KP5
#define BK_KEY_KP_6            ::Baku::Key::KP6
#define BK_KEY_KP_7            ::Baku::Key::KP7
#define BK_KEY_KP_8            ::Baku::Key::KP8
#define BK_KEY_KP_9            ::Baku::Key::KP9
#define BK_KEY_KP_DECIMAL      ::Baku::Key::KPDecimal
#define BK_KEY_KP_DIVIDE       ::Baku::Key::KPDivide
#define BK_KEY_KP_MULTIPLY     ::Baku::Key::KPMultiply
#define BK_KEY_KP_SUBTRACT     ::Baku::Key::KPSubtract
#define BK_KEY_KP_ADD          ::Baku::Key::KPAdd
#define BK_KEY_KP_ENTER        ::Baku::Key::KPEnter
#define BK_KEY_KP_EQUAL        ::Baku::Key::KPEqual

#define BK_KEY_LEFT_SHIFT      ::Baku::Key::LeftShift
#define BK_KEY_LEFT_CONTROL    ::Baku::Key::LeftControl
#define BK_KEY_LEFT_ALT        ::Baku::Key::LeftAlt
#define BK_KEY_LEFT_SUPER      ::Baku::Key::LeftSuper
#define BK_KEY_RIGHT_SHIFT     ::Baku::Key::RightShift
#define BK_KEY_RIGHT_CONTROL   ::Baku::Key::RightControl
#define BK_KEY_RIGHT_ALT       ::Baku::Key::RightAlt
#define BK_KEY_RIGHT_SUPER     ::Baku::Key::RightSuper
#define BK_KEY_MENU            ::Baku::Key::Menu