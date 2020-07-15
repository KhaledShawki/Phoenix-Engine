workspace "Phoenix"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	-- Include directories relative to root folder (soulution directory)
	IncludeDir ={}
	IncludeDir["spdlog"] = "Phoenix/lib/spdlog/include"
	IncludeDir["GLFW"] = "Phoenix/lib/GLFW/include"
	IncludeDir["Glad"] = "Phoenix/lib/Glad/include"
	IncludeDir["ImGui"] = "Phoenix/lib/ImGui"
	IncludeDir["glm"] = "Phoenix/lib/glm"
	IncludeDir["stb_image"] = "Phoenix/lib/stb_image"
	IncludeDir["vulkan"] = "Phoenix/lib/Vulkan/Include"
	IncludeDir["OpenAL"] = "Phoenix/lib/OpenAL-Soft/include"
	IncludeDir["libogg"] = "Phoenix/lib/libogg/include"
	IncludeDir["Vorbis"] = "Phoenix/lib/Vorbis/include"
	IncludeDir["minimp3"] = "Phoenix/lib/minimp3"

	include "Phoenix/lib/GLFW"
	include "Phoenix/lib/Glad"
	include "Phoenix/lib/ImGui"
	include "Phoenix/lib/OpenAL-Soft"
	include "Phoenix/lib/libogg"
	include "Phoenix/lib/Vorbis"

	project "Phoenix"
		location "Phoenix"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		pchheader "phxpch.h"
		pchsource "Phoenix/src/phxpch.cpp"
	
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/lib/stb_image/**.h",
			"%{prj.name}/lib/stb_image/**.cpp",
			"%{prj.name}/lib/glm/glm/**.hpp",
			"%{prj.name}/lib/glm/glm/**.inl"
		}
		
		defines
		{
			"PHX_PLATFORM_WINDOWS",
			"_CRT_SECURE_NO_WARNINGS"
		}

		includedirs
		{
			"%{prj.name}/src",
			"%{IncludeDir.spdlog}",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.ImGui}",
			"%{IncludeDir.glm}",
			"%{IncludeDir.stb_image}",
			"%{IncludeDir.vulkan}",
			"%{IncludeDir.OpenAL}",
			"%{IncludeDir.libogg}",
			"%{IncludeDir.Vorbis}",
			"%{IncludeDir.minimp3}"
		
		}

		links{
			"GLFW",
			"Glad",
			"ImGui",
			"opengl32.lib",
			"Phoenix/lib/Vulkan/Lib/vulkan-1.lib",
			"OpenAL-Soft",
			"Vorbis"
		}

		filter "system:windows"
			systemversion "latest"

			defines
			{
				"PHX_PLATFORM_WINDOWS",
				"GLFW_INCLUDE_NONE"
			}

		filter "configurations:Debug"
			defines "PHX_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "PHX_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "PHX_DIST"
			runtime "Release"
			optimize "on"

	project "Sandbox"
		location "Sandbox"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" .. outputdir .. "/%{prj.name}")
		objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
		files
		{
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs
		{
			"Phoenix/src",
			"Phoenix/lib",
			"%{IncludeDir.spdlog}",
			"%{IncludeDir.glm}"
		
		}

		links
		{
			"Phoenix"
		}

		filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"

			defines
			{
				"PHX_PLATFORM_WINDOWS"
			}

		filter "configurations:Debug"
			defines "PHX_DEBUG"
			runtime "Debug"
			symbols "on"

		filter "configurations:Release"
			defines "PHX_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "PHX_DIST"
			runtime "Release"
			optimize "on" 