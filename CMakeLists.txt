
cmake_minimum_required(VERSION 3.30)
project(EMBEDDED_HELPER)


add_subdirectory(libs)

option(eH_App "Build the app" OFF) 

if(eH_App)
	add_executable(app app.c)
	target_include_directories(app PUBLIC inc)
	target_link_libraries(app PUBLIC eh_engine utils) 
endif()

