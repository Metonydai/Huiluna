#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Huiluna {

	class HUILUNA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define HL_CORE_TRACE(...)     ::Huiluna::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HL_CORE_INFO(...)      ::Huiluna::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HL_CORE_WARN(...)      ::Huiluna::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HL_CORE_ERROR(...)     ::Huiluna::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HL_CORE_FATAL(...)     ::Huiluna::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HL_TRACE(...)          ::Huiluna::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HL_INFO(...)           ::Huiluna::Log::GetClientLogger()->info(__VA_ARGS__)
#define HL_WARN(...)		   ::Huiluna::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HL_ERROR(...)	       ::Huiluna::Log::GetClientLogger()->error(__VA_ARGS__)
#define HL_FATAL(...)          ::Huiluna::Log::GetClientLogger()->fatal(__VA_ARGS__)
