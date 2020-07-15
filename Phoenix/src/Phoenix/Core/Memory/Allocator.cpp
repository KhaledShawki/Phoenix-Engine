#include "phxpch.h"

#include "Allocator.h"

namespace Phx {

	Allocator::Allocator(std::size_t size, void* startPointer)
		:m_Size(size), m_StartPointer(startPointer), m_UsedMemory(0), m_AllocationsCount(0)
	{
	}

	Allocator::~Allocator()
	{
		PHX_CORE_ASSERT(m_AllocationsCount == 0 && m_UsedMemory == 0, "There are elements that are not deleted!");
		m_StartPointer = nullptr;
		m_Size = 0;
	}

	void* Allocator::GetStartPointer() const
	{
		return m_StartPointer;
	}

	std::size_t  Allocator::GetSize() const
	{
		return m_Size;
	}

	std::size_t Allocator::GetUsedMemory() const
	{
		return m_UsedMemory;
	}

	std::size_t Allocator::GetAllocationsCount() const
	{
		return m_AllocationsCount;
	}
	
}
