#pragma once

#include <memory>

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

//#define HL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#define HL_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Huiluna {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}