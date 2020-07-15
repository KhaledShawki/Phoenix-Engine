#include "phxpch.h"
#include "MemoryManager.h"

namespace Phx {
	MemoryManager* MemoryManager::s_Instance = nullptr;

	void MemoryManager::Init()
	{
		m_SystemMemoryInfo = (SystemMemoryInfo*)malloc((size_t)sizeof(SystemMemoryInfo));
		m_SystemMemoryInfo->Init();
		m_MemoryState = (MemoryStats*)malloc(sizeof(MemoryStats));
		m_MemoryState->Init();
	}

	void MemoryManager::Shutdown()
	{

		free(m_MemoryState);
		free(m_SystemMemoryInfo);
		free(s_Instance);

	
	}

	MemoryManager* MemoryManager::Get()
	{
		if (s_Instance == nullptr)
		{
			s_Instance = (MemoryManager*) malloc(sizeof(MemoryManager));
			s_Instance->Init();
		}

		return s_Instance;
	}

	Phx::MemoryStats* MemoryManager::GetMemoryState() const
	{
		 return m_MemoryState;
	}

	SystemMemoryInfo* MemoryManager::GetSystemMemoryInfo() const
	{
#ifdef PHX_PLATFORM_WINDOWS

		MEMORYSTATUSEX statex;

		statex.dwLength = sizeof(statex);

		GlobalMemoryStatusEx(&statex);

		m_SystemMemoryInfo->totalPhysicalMemory = statex.ullTotalPhys ;
		m_SystemMemoryInfo->availablePhysicalMemory = statex.ullAvailPhys ;
		m_SystemMemoryInfo->totalVirtualMemory = statex.ullTotalVirtual;
		m_SystemMemoryInfo->availableVirtualMemory = statex.ullAvailVirtual;
#endif
		return m_SystemMemoryInfo;
	}

	void SystemMemoryInfo::Init()
	{
		availablePhysicalMemory = 0;
		totalPhysicalMemory = 0;
		availableVirtualMemory = 0;
		totalVirtualMemory = 0;
	}

	void MemoryStats::Init()
	{
		currentUsed = 0;
		totalAllocated = 0;
		totalFreed = 0;
		totalAllocations = 0;
	}

}
