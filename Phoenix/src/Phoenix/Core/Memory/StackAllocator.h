#pragma once

#include "Allocator.h"

namespace Phx {

	class StackAllocator : public Allocator
	{
	public:
		StackAllocator(const std::size_t size, void* startPointer);
		virtual ~StackAllocator();

		virtual void* Allocate(std::size_t size, uint8_t alignment = 1)  override;
		virtual void Free(void* p)  override;

	private:
		StackAllocator(const StackAllocator&) = delete;
		StackAllocator& operator=(const StackAllocator&) = delete;
	private:
		struct Header
		{
			//void* m_PrevPointer;
			size_t m_Size;
			uint8_t m_Offset;
		};
		void* m_CurrentPointer;
		//void* m_PrevPointer;
	private:
		const size_t m_HeaderSize;
	};
}
