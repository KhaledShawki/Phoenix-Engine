#include "phxpch.h"

#include "PoolAllocator.h"


namespace Phx {

	PoolAllocator::PoolAllocator(const size_t size, const size_t chunkSize, void* startPointer)
		:Allocator(size, startPointer), m_ChunkSize(chunkSize), m_FreeList(Stack<void*>())
	{
		const int chunksNumber = size / chunkSize;
		for (int i = 0; i < chunksNumber; ++i) 
		{
			size_t address = (size_t) startPointer + i * chunkSize;
			m_FreeList.push((Stack<void*>::Node*)address);
		}
	}

	PoolAllocator::~PoolAllocator()
	{
	}

	void* PoolAllocator::Allocate(size_t size, uint8_t alignment)
	{
		PHX_CORE_ASSERT(m_UsedMemory + size < m_Size, "No free memory available!");
		if (m_FreeList.Peak() == nullptr || (m_UsedMemory + size) > m_Size)
			return nullptr;

		m_UsedMemory += size;
		m_AllocationsCount++;

		return m_FreeList.pop();
	}

	void PoolAllocator::Free(void* ptr) 
	{
		m_UsedMemory -= m_ChunkSize;
		m_AllocationsCount--;

		m_FreeList.push((Stack<void*>::Node*)ptr);
	}


}