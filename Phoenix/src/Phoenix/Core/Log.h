#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Phx {

	class Test {
	private:
		int  m_name;
	public:
		Test(int name) :m_name(name) {

		}
		int getName()
		{
			return m_name;
		}
	};


	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;

	};
}
// Core log macros
#define PHX_CORE_TRACE(...)    ::Phx::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PHX_CORE_INFO(...)     ::Phx::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PHX_CORE_WARN(...)     ::Phx::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PHX_CORE_ERROR(...)    ::Phx::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PHX_CORE_CRITICAL(...) ::Phx::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PHX_TRACE(...)         ::Phx::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PHX_INFO(...)          ::Phx::Log::GetClientLogger()->info(__VA_ARGS__)
#define PHX_WARN(...)          ::Phx::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PHX_ERROR(...)         ::Phx::Log::GetClientLogger()->error(__VA_ARGS__)
#define PHX_CRITICAL(...)      ::Phx::Log::GetClientLogger()->critical(__VA_ARGS__)