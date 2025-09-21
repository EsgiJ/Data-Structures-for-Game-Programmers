workspace "DataStructures"
    architecture "x64"
    configurations {"Debug", "Release"}
    startproject "DataStructures"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--------------------------------------------------------------------
-- DATA STRUCTURES PROJECT 
--------------------------------------------------------------------
project "DataStructures"
    location "DataStructures"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("bin/" ..outputdir.. "/%{prj.name}")

    files 
    {
        "DataStructures/**.h",
        "DataStructures/**.cpp"
    }

    includedirs
    {
        "DataStructures/include"
    }