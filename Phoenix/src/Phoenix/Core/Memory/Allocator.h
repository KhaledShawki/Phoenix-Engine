#pragma once

#include <cstddef>

namespace Phx {

	class Allocator
	{
	protected:
		void* m_StartPointer;
		std::size_t        m_Size;
		std::size_t        m_UsedMemory;
		std::size_t        m_AllocationsCount;

	public:
		Allocator(std::size_t size,void* startPointer) ;
		virtual ~Allocator();

		virtual void* Allocate(std::size_t size, uint8_t alignment = 0)  = 0;
		virtual void Free(void* p)  = 0;

		//virtual void check(void* p) = 0;

		void* GetStartPointer() const;
		std::size_t GetSize() const;
		std::size_t GetUsedMemory() const;
		std::size_t GetAllocationsCount() const;


		template <class T, class...Args>
		T* AllocateNew(Allocator& allocator, Args&&... args)
		{
			return new (allocator.Allocate(sizeof(T), __alignof(T))) T(std::forward<Args>(args)...);
		}

		template<class T>
		void FreeDelete(Allocator& allocator, T* object)
		{
			object->~T();
			allocator.Free(object);
		}

		template<class T>
		T* AllocateArray(Allocator& allocator, std::size_t length)
		{
			PHX_CORE_ASSERT(length != 0, "");

			uint8_t headerSize = sizeof(std::size_t) / sizeof(T);

			if (sizeof(std::size_t) % sizeof(T) > 0)
				headerSize += 1;

			T* p = ((T*)allocator.Allocate(sizeof(T) * (length + headerSize), __alignof(T))) + headerSize;

			*(((std::size_t*)p) - 1) = length;

			for (std::size_t i = 0; i < length; i++)
				new (&p[i]) T;

			return p;
		}

		template<class T>
		T* AllocateArrayNoConstruct(Allocator& allocator, std::size_t length)
		{
			PHX_CORE_ASSERT(length != 0, "");

			uint8_t headerSize = sizeof(std::size_t) / sizeof(T);

			if (sizeof(std::size_t) % sizeof(T) > 0)
				headerSize += 1;

			T* p = ((T*)allocator.Allocate(sizeof(T) * (length + headerSize), __alignof(T))) + headerSize;

			*(((std::size_t*)p) - 1) = length;

			return p;
		}

		template<class T>
		void FreeArray(Allocator& allocator, T* array)
		{
			PHX_CORE_ASSERT(array != 0, "");

			uint8_t headerSize = sizeof(std::size_t) / sizeof(T);

			if (sizeof(std::size_t) % sizeof(T) > 0)
				headerSize += 1;

			std::size_t length = *(((std::size_t*)array) - 1);

			for (std::size_t i = 0; i < length; i++)
				array[i].~T();

			allocator.Free(array - headerSize);
		}

		template<class T>
		void FreeArrayNoDestruct(Allocator& allocator, T* array)
		{
			PHX_CORE_ASSERT(array != 0, "");

			uint8_t headerSize = sizeof(std::size_t) / sizeof(T);

			if (sizeof(std::size_t) % sizeof(T) > 0)
				headerSize += 1;

			allocator.Free(array - headerSize);
		}
	};
}