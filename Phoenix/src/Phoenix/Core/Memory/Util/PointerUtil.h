#pragma once
#include <memory>
namespace Phx {

	inline void* alignForward(void* address, uint8_t  alignment)
	{
		return (void*)((reinterpret_cast<uintptr_t >(address) + static_cast<uintptr_t >(alignment - 1))& static_cast<uintptr_t >(~(alignment - 1)));
	}

	inline const void* alignForward(const void* address, uint8_t  alignment)
	{
		return (void*)((reinterpret_cast<uintptr_t >(address) + static_cast<uintptr_t >(alignment - 1))& static_cast<uintptr_t >(~(alignment - 1)));
	}

	inline void* alignBackward(void* address, uint8_t  alignment)
	{
		return (void*)(reinterpret_cast<uintptr_t >(address)& static_cast<uintptr_t >(~(alignment - 1)));
	}

	inline const void* alignBackward(const void* address, uint8_t  alignment)
	{
		return (void*)(reinterpret_cast<uintptr_t >(address)& static_cast<uintptr_t >(~(alignment - 1)));
	}

	inline uint8_t alignForwardOffset(const void* address, uint8_t  alignment)
	{
		uint8_t  offset = alignment - (reinterpret_cast<uintptr_t >(address)& static_cast<uintptr_t >(alignment - 1));

		if (offset == alignment)
			return 0; //already aligned

		return offset;
	}

	inline uint8_t alignForwardOffsetWithHeader(const void* address, uint8_t  alignment, uint8_t  headerSize)
	{
		uint8_t  offset = alignForwardOffset(address, alignment);
		uint8_t  needed_space = headerSize;
		if(offset < needed_space)
		{
			needed_space -= offset;
			//Increase offset to fit header
			offset += alignment * (needed_space / alignment);
			if(needed_space % alignment > 0)
				offset += alignment;
		}
		return offset;
	}
	

	inline uint8_t alignBackwardOffset(const void* address, uint8_t alignment)
	{
		uint8_t offset = reinterpret_cast<uintptr_t>(address)& static_cast<uintptr_t>(alignment - 1);

		if (offset == alignment)
			return 0; //already aligned

		return offset;
	}

	inline void* add(void* p, size_t x)
	{
		return (void*)(reinterpret_cast<uintptr_t>(p) + x);
	}

// 	inline const void* add(const void* p, size_t x)
// 	{
// 		return (const void*)(reinterpret_cast<uintptr_t>(p) + x);
// 	}

	inline void* subtract(void* p, size_t x)
	{
		return (void*)(reinterpret_cast<uintptr_t>(p) - x);
	}

// 	inline const void* subtract(const void* p, size_t x)
// 	{
// 		return (const void*)(reinterpret_cast<uintptr_t>(p) - x);
// 	}
}