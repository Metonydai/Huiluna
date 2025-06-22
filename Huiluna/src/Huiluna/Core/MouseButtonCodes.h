#pragma once

#pragma once

namespace Huiluna
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

#define HL_MOUSE_BUTTON_0      ::Huiluna::Mouse::Button0
#define HL_MOUSE_BUTTON_1      ::Huiluna::Mouse::Button1
#define HL_MOUSE_BUTTON_2      ::Huiluna::Mouse::Button2
#define HL_MOUSE_BUTTON_3      ::Huiluna::Mouse::Button3
#define HL_MOUSE_BUTTON_4      ::Huiluna::Mouse::Button4
#define HL_MOUSE_BUTTON_5      ::Huiluna::Mouse::Button5
#define HL_MOUSE_BUTTON_6      ::Huiluna::Mouse::Button6
#define HL_MOUSE_BUTTON_7      ::Huiluna::Mouse::Button7
#define HL_MOUSE_BUTTON_LAST   ::Huiluna::Mouse::ButtonLast
#define HL_MOUSE_BUTTON_LEFT   ::Huiluna::Mouse::ButtonLeft
#define HL_MOUSE_BUTTON_RIGHT  ::Huiluna::Mouse::ButtonRight
#define HL_MOUSE_BUTTON_MIDDLE ::Huiluna::Mouse::ButtonMiddle
