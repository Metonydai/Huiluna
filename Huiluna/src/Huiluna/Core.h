#pragma once

#ifdef HL_PLATFORM_WINDOWS
#if HL_DYNAMIC_LINK
	#ifdef HL_BUILD_DLL
		#define HUILUNA_API __declspec(dllexport)
	#else
		#define HUILUNA_API __declspec(dllimport)
	#endif
#else
	#define HUILUNA_API
#endif
#else
	#error Huiluna only supports Windows!
#endif

#ifdef HL_DEBUG
    #define HL_ENABLE_ASSERTS
#endif

#ifdef HL_ENABLE_ASSERTS
	#define HL_ASSERT(x, ...) { if(!(x)) { HL_ERROR("Assertion Falied: {0}", __VA_ARGS__); __debugbreak(); } }
	#define HL_CORE_ASSERT(x, ...) { if(!(x)) { HL_ERROR("Assertion Falied: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HL_ASSERT(x, ...)
	#define HL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)