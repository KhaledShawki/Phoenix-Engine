#pragma once
#include "MemoryManager.h"

void* operator new(size_t size)
{
	Phx::MemoryManager::Get()->GetMemoryState()->totalAllocated += size;
	Phx::MemoryManager::Get()->GetMemoryState()->currentUsed += size;
	Phx::MemoryManager::Get()->GetMemoryState()->totalAllocations++;

	return malloc(size);
}

void operator delete(void* memory, size_t size)
{

	Phx::MemoryManager::Get()->GetMemoryState()->totalFreed += size;
	Phx::MemoryManager::Get()->GetMemoryState()->currentUsed -= size;	

	free(memory);
}