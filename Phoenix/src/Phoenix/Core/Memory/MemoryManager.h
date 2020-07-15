#pragma once

namespace Phx {

	struct  SystemMemoryInfo
	{
		uint64_t availablePhysicalMemory;
		uint64_t totalPhysicalMemory;

		uint64_t availableVirtualMemory;
		uint64_t totalVirtualMemory;

		void Init();
	};

	struct  MemoryStats
	{
		uint64_t totalAllocated;
		uint64_t totalFreed;
		uint64_t currentUsed;
		uint64_t totalAllocations;
		void Init();
		// 
// 		MemoryStats()
// 			: totalAllocated(0), totalFreed(0), currentUsed(0), totalAllocations(0)
// 		{
// 		}
	};

	class MemoryManager
	{
	public:
		MemoryManager()= default;
		~MemoryManager() = default;

		void Init();
		void Shutdown();
		static MemoryManager* Get();
		MemoryStats* GetMemoryState() const;
		SystemMemoryInfo* GetSystemMemoryInfo() const;

	private:
		static MemoryManager* s_Instance;
		MemoryStats* m_MemoryState;
		SystemMemoryInfo* m_SystemMemoryInfo;
	};
}