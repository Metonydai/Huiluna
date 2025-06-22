#pragma once

namespace Huiluna {

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
#define HL_KEY_SPACE           ::Huiluna::Key::Space
#define HL_KEY_APOSTROPHE      ::Huiluna::Key::Apostrophe    /* ' */
#define HL_KEY_COMMA           ::Huiluna::Key::Comma         /* , */
#define HL_KEY_MINUS           ::Huiluna::Key::Minus         /* - */
#define HL_KEY_PERIOD          ::Huiluna::Key::Period        /* . */
#define HL_KEY_SLASH           ::Huiluna::Key::Slash         /* / */
#define HL_KEY_0               ::Huiluna::Key::D0
#define HL_KEY_1               ::Huiluna::Key::D1
#define HL_KEY_2               ::Huiluna::Key::D2
#define HL_KEY_3               ::Huiluna::Key::D3
#define HL_KEY_4               ::Huiluna::Key::D4
#define HL_KEY_5               ::Huiluna::Key::D5
#define HL_KEY_6               ::Huiluna::Key::D6
#define HL_KEY_7               ::Huiluna::Key::D7
#define HL_KEY_8               ::Huiluna::Key::D8
#define HL_KEY_9               ::Huiluna::Key::D9
#define HL_KEY_SEMICOLON       ::Huiluna::Key::Semicolon     /* ; */
#define HL_KEY_EQUAL           ::Huiluna::Key::Equal         /* = */
#define HL_KEY_A               ::Huiluna::Key::A
#define HL_KEY_B               ::Huiluna::Key::B
#define HL_KEY_C               ::Huiluna::Key::C
#define HL_KEY_D               ::Huiluna::Key::D
#define HL_KEY_E               ::Huiluna::Key::E
#define HL_KEY_F               ::Huiluna::Key::F
#define HL_KEY_G               ::Huiluna::Key::G
#define HL_KEY_H               ::Huiluna::Key::H
#define HL_KEY_I               ::Huiluna::Key::I
#define HL_KEY_J               ::Huiluna::Key::J
#define HL_KEY_K               ::Huiluna::Key::K
#define HL_KEY_L               ::Huiluna::Key::L
#define HL_KEY_M               ::Huiluna::Key::M
#define HL_KEY_N               ::Huiluna::Key::N
#define HL_KEY_O               ::Huiluna::Key::O
#define HL_KEY_P               ::Huiluna::Key::P
#define HL_KEY_Q               ::Huiluna::Key::Q
#define HL_KEY_R               ::Huiluna::Key::R
#define HL_KEY_S               ::Huiluna::Key::S
#define HL_KEY_T               ::Huiluna::Key::T
#define HL_KEY_U               ::Huiluna::Key::U
#define HL_KEY_V               ::Huiluna::Key::V
#define HL_KEY_W               ::Huiluna::Key::W
#define HL_KEY_X               ::Huiluna::Key::X
#define HL_KEY_Y               ::Huiluna::Key::Y
#define HL_KEY_Z               ::Huiluna::Key::Z
#define HL_KEY_LEFT_BRACKET    ::Huiluna::Key::LeftBracket   /* [ */
#define HL_KEY_BACKSLASH       ::Huiluna::Key::Backslash     /* \ */
#define HL_KEY_RIGHT_BRACKET   ::Huiluna::Key::RightBracket  /* ] */
#define HL_KEY_GRAVE_ACCENT    ::Huiluna::Key::GraveAccent   /* ` */
#define HL_KEY_WORLD_1         ::Huiluna::Key::World1        /* non-US #1 */
#define HL_KEY_WORLD_2         ::Huiluna::Key::World2        /* non-US #2 */

/* Function keys */
#define HL_KEY_ESCAPE          ::Huiluna::Key::Escape
#define HL_KEY_ENTER           ::Huiluna::Key::Enter
#define HL_KEY_TAB             ::Huiluna::Key::Tab
#define HL_KEY_BACKSPACE       ::Huiluna::Key::Backspace
#define HL_KEY_INSERT          ::Huiluna::Key::Insert
#define HL_KEY_DELETE          ::Huiluna::Key::Delete
#define HL_KEY_RIGHT           ::Huiluna::Key::Right
#define HL_KEY_LEFT            ::Huiluna::Key::Left
#define HL_KEY_DOWN            ::Huiluna::Key::Down
#define HL_KEY_UP              ::Huiluna::Key::Up
#define HL_KEY_PAGE_UP         ::Huiluna::Key::PageUp
#define HL_KEY_PAGE_DOWN       ::Huiluna::Key::PageDown
#define HL_KEY_HOME            ::Huiluna::Key::Home
#define HL_KEY_END             ::Huiluna::Key::End
#define HL_KEY_CAPS_LOCK       ::Huiluna::Key::CapsLock
#define HL_KEY_SCROLL_LOCK     ::Huiluna::Key::ScrollLock
#define HL_KEY_NUM_LOCK        ::Huiluna::Key::NumLock
#define HL_KEY_PRINT_SCREEN    ::Huiluna::Key::PrintScreen
#define HL_KEY_PAUSE           ::Huiluna::Key::Pause
#define HL_KEY_F1              ::Huiluna::Key::F1
#define HL_KEY_F2              ::Huiluna::Key::F2
#define HL_KEY_F3              ::Huiluna::Key::F3
#define HL_KEY_F4              ::Huiluna::Key::F4
#define HL_KEY_F5              ::Huiluna::Key::F5
#define HL_KEY_F6              ::Huiluna::Key::F6
#define HL_KEY_F7              ::Huiluna::Key::F7
#define HL_KEY_F8              ::Huiluna::Key::F8
#define HL_KEY_F9              ::Huiluna::Key::F9
#define HL_KEY_F10             ::Huiluna::Key::F10
#define HL_KEY_F11             ::Huiluna::Key::F11
#define HL_KEY_F12             ::Huiluna::Key::F12
#define HL_KEY_F13             ::Huiluna::Key::F13
#define HL_KEY_F14             ::Huiluna::Key::F14
#define HL_KEY_F15             ::Huiluna::Key::F15
#define HL_KEY_F16             ::Huiluna::Key::F16
#define HL_KEY_F17             ::Huiluna::Key::F17
#define HL_KEY_F18             ::Huiluna::Key::F18
#define HL_KEY_F19             ::Huiluna::Key::F19
#define HL_KEY_F20             ::Huiluna::Key::F20
#define HL_KEY_F21             ::Huiluna::Key::F21
#define HL_KEY_F22             ::Huiluna::Key::F22
#define HL_KEY_F23             ::Huiluna::Key::F23
#define HL_KEY_F24             ::Huiluna::Key::F24
#define HL_KEY_F25             ::Huiluna::Key::F25

/* Keypad */
#define HL_KEY_KP_0            ::Huiluna::Key::KP0
#define HL_KEY_KP_1            ::Huiluna::Key::KP1
#define HL_KEY_KP_2            ::Huiluna::Key::KP2
#define HL_KEY_KP_3            ::Huiluna::Key::KP3
#define HL_KEY_KP_4            ::Huiluna::Key::KP4
#define HL_KEY_KP_5            ::Huiluna::Key::KP5
#define HL_KEY_KP_6            ::Huiluna::Key::KP6
#define HL_KEY_KP_7            ::Huiluna::Key::KP7
#define HL_KEY_KP_8            ::Huiluna::Key::KP8
#define HL_KEY_KP_9            ::Huiluna::Key::KP9
#define HL_KEY_KP_DECIMAL      ::Huiluna::Key::KPDecimal
#define HL_KEY_KP_DIVIDE       ::Huiluna::Key::KPDivide
#define HL_KEY_KP_MULTIPLY     ::Huiluna::Key::KPMultiply
#define HL_KEY_KP_SUBTRACT     ::Huiluna::Key::KPSubtract
#define HL_KEY_KP_ADD          ::Huiluna::Key::KPAdd
#define HL_KEY_KP_ENTER        ::Huiluna::Key::KPEnter
#define HL_KEY_KP_EQUAL        ::Huiluna::Key::KPEqual

#define HL_KEY_LEFT_SHIFT      ::Huiluna::Key::LeftShift
#define HL_KEY_LEFT_CONTROL    ::Huiluna::Key::LeftControl
#define HL_KEY_LEFT_ALT        ::Huiluna::Key::LeftAlt
#define HL_KEY_LEFT_SUPER      ::Huiluna::Key::LeftSuper
#define HL_KEY_RIGHT_SHIFT     ::Huiluna::Key::RightShift
#define HL_KEY_RIGHT_CONTROL   ::Huiluna::Key::RightControl
#define HL_KEY_RIGHT_ALT       ::Huiluna::Key::RightAlt
#define HL_KEY_RIGHT_SUPER     ::Huiluna::Key::RightSuper
#define HL_KEY_MENU            ::Huiluna::Key::Menu
