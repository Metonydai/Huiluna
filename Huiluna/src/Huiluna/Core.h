#pragma once

#ifdef HL_PLATFORM_WINDOWS
	#ifdef HL_BUILD_DLL
		#define HUILUNA_API __declspec(dllexport)
	#else
		#define HUILUNA_API __declspec(dllimport)
	#endif
#else
	#error Huiluna only supports Windows!
#endif