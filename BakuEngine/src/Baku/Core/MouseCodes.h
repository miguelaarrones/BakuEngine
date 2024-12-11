#pragma once

namespace Baku
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

#define BK_MOUSE_BUTTON_0      ::Baku::Mouse::Button0
#define BK_MOUSE_BUTTON_1      ::Baku::Mouse::Button1
#define BK_MOUSE_BUTTON_2      ::Baku::Mouse::Button2
#define BK_MOUSE_BUTTON_3      ::Baku::Mouse::Button3
#define BK_MOUSE_BUTTON_4      ::Baku::Mouse::Button4
#define BK_MOUSE_BUTTON_5      ::Baku::Mouse::Button5
#define BK_MOUSE_BUTTON_6      ::Baku::Mouse::Button6
#define BK_MOUSE_BUTTON_7      ::Baku::Mouse::Button7
#define BK_MOUSE_BUTTON_LAST   ::Baku::Mouse::ButtonLast
#define BK_MOUSE_BUTTON_LEFT   ::Baku::Mouse::ButtonLeft
#define BK_MOUSE_BUTTON_RIGHT  ::Baku::Mouse::ButtonRight
#define BK_MOUSE_BUTTON_MIDDLE ::Baku::Mouse::ButtonMiddle