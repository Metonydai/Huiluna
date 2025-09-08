#pragma once

#include "Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"
#pragma warning(pop)


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

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

namespace fmt {
    template <glm::length_t L, typename T, glm::qualifier Q>
    struct formatter<glm::vec<L, T, Q>> {
        constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

        template <typename FormatContext>
        auto format(const glm::vec<L, T, Q>& v, FormatContext& ctx) const {
            return fmt::format_to(ctx.out(), "{}", glm::to_string(v));
        }
    };

    template <glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
    struct formatter<glm::mat<C, R, T, Q>> {
        constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

        template <typename FormatContext>
        auto format(const glm::mat<C, R, T, Q>& matrix, FormatContext& ctx) const {
            return fmt::format_to(ctx.out(), "{}", glm::to_string(matrix));
        }
    };

    template <typename T, glm::qualifier Q>
    struct formatter<glm::qua<T, Q>> {
        constexpr auto parse(format_parse_context& ctx) { return ctx.begin(); }

        template <typename FormatContext>
        auto format(const glm::qua<T, Q>& quaternion, FormatContext& ctx) const {
            return fmt::format_to(ctx.out(), "{}", glm::to_string(quaternion));
        }
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
