#pragma once

#include "Allocator.h"
#include "stack.h"

namespace Phx {

	class PoolAllocator : public Allocator
	{
	public:
		PoolAllocator(const std::size_t size, const std::size_t chunkSize, void* startPointer);
		virtual ~PoolAllocator();

		virtual void* Allocate( std::size_t size,  uint8_t alignment = 0)  override;
		virtual void Free(void* p)  override;

	private:

		PoolAllocator(const PoolAllocator&) = delete;
		PoolAllocator& operator=(const PoolAllocator&) = delete;

		size_t m_ChunkSize;
		Stack<void*> m_FreeList;
	};
}