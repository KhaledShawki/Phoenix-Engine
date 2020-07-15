#pragma once
// #include "Phoenix/Core/Memory/StackAllocator.h"
// #include "Phoenix/Core/Memory/PoolAllocator.h"

// class Person
// {
// public:
// 	Person(char* name, int age)
// 		:m_Name(name),m_Age(age)
// 	{
// 	}
// 	char* getName()
// 	{
// 		return m_Name;
// 	}
// 	int getAge()
// 	{
// 		return m_Age;
// 	}
// private:
// 	char* m_Name;
// 	int m_Age;
// 
// };


#ifdef PHX_PLATFORM_WINDOWS
	extern Phx::Application* Phx::CreateApplication();

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	int main(int argc, char** argv)
	{
		std::vector<ProfileResult> m_ProfileResults;
		Phx::Log::Init();

// 		PHX_PROFILE_BEGIN_SESSION("Memory", "PhoenixProfile-MemoryTest-Startup.json");
// 
// 		void* stsp = malloc(321);
// 		void* plsp = malloc(161);
// 		Phx::StackAllocator st = Phx::StackAllocator(321, stsp);
// 		Phx::PoolAllocator pl = Phx::PoolAllocator(161, 16, plsp);
// 		
// 		{
// 			PHX_PROFILE_SCOPE("Stack Allocator");
// 			for (int i = 0; i < 1000000; i++)
// 			{
// 				Person* p0 = new(&st, alignof(Person))Person("P0", 20);
// 				st.Free(p0);
// 			}
// 		}
// 		{
// 			PHX_PROFILE_SCOPE("Pool Allocator");
// 			for (int i = 0; i < 1000000; i++)
// 			{
// 				Person* p0 = new(&pl)Person("P0", 20);
// 				pl.Free(p0);
// 
// 			}
// 		}
// 
// 		{
// 			PHX_PROFILE_SCOPE("C++ New Alloc");
// 			for (int i = 0; i < 1000000; i++)
// 			{
// 				Person* p0 = new Person("P0", 20);
// 				delete p0;
// 			}
// 		}
// 		PHX_PROFILE_END_SESSION();
	
		PHX_CORE_INFO("Welcome to Phoenix engine.");
		PHX_CORE_INFO("Initialized Log.");

		PHX_PROFILE_BEGIN_SESSION("Runtime", "PhoenixProfile-Startup.json");
		auto app = Phx::CreateApplication();
		PHX_PROFILE_END_SESSION();

		PHX_PROFILE_BEGIN_SESSION("Runtime", "PhoenixProfile-Runtime.json");
		app->Run();
		PHX_PROFILE_END_SESSION();

		PHX_PROFILE_BEGIN_SESSION("Runtime", "PhoenixProfile-Shutdown.json");
// 		delete stsp;
// 		delete plsp;
		delete app;
		PHX_PROFILE_END_SESSION();


	}
#endif