#include "phxpch.h"

#include "StackAllocator.h"

#include "util/PointerUtil.h"

namespace Phx {


	StackAllocator::StackAllocator(const std::size_t size, void* startPointer)
		:Allocator(size, startPointer)/*, m_PrevPointer(nullptr)*/, m_CurrentPointer(startPointer),m_HeaderSize(sizeof(Header))
	{
	}

	StackAllocator::~StackAllocator()
	{
		m_CurrentPointer = nullptr;
		//m_PrevPointer = nullptr;
	}

	void* StackAllocator::Allocate(const std::size_t size, const uint8_t alignment)
	{
		uint8_t offset = alignForwardOffsetWithHeader(m_CurrentPointer, alignment, m_HeaderSize);
		
		PHX_CORE_ASSERT(m_UsedMemory + offset + size < m_Size, "No free memory available!");
		if ((m_UsedMemory + offset + size) > m_Size) return nullptr;

		void* newPointer = add(m_CurrentPointer, offset);
		
		Header* header = (Header*)(subtract(newPointer, m_HeaderSize));

// 		header->m_PrevPointer = m_CurrentPointer;
		header->m_Size = size;
		header->m_Offset = offset;
		m_CurrentPointer = newPointer;

		m_UsedMemory += size + offset;
		m_AllocationsCount++;
		return newPointer;
	}

	void StackAllocator::Free(void* ptr)
	{
		Header* header = (Header*)subtract(ptr, m_HeaderSize);

		m_UsedMemory -= header->m_Size + header->m_Offset;
		m_CurrentPointer = subtract(ptr, header->m_Offset);

		//m_PrevPointer = header->m_PrevPointer;		
		m_AllocationsCount--;
	}

}