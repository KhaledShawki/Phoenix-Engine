#pragma once

#include <memory>

#ifdef PHX_PLATFORM_WINDOWS
// For OpenAL
#define WIN32
#define _WINDOWS
#define _WIN32_WINNT  0x0502 
#else
#error PHX only supports Windows!
#endif 
#ifdef PHX_DEBUG
#define PHX_ENABLE_ASSERTS
#endif

#ifdef PHX_ENABLE_ASSERTS
#define PHX_ASSERT(x, ...) { if(!(x)) { PHX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define PHX_CORE_ASSERT(x, ...) { if(!(x)) { PHX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define PHX_VK_ASSERT(x,...) { if(!(VK_SUCCESS)) { PHX_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define PHX_ASSERT(x, ...)
#define PHX_CORE_ASSERT(x, ...)
#define PHX_VK_ASSERT(x,...) 
#endif

#define BIT(x) (1 << x)

#define PHX_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)


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

