cmake_minimum_required(VERSION 3.30)
project(EMBEDDED_HELPER)

include_directories(../inc)
add_subdirectory(IPC)
add_subdirectory(utils)
add_subdirectory(algo)
add_subdirectory(companies)
add_subdirectory(leetcode)
add_subdirectory(ds)
add_subdirectory(bit_ops)
add_subdirectory(attr)

if(eH_App)
	add_library(eh_engine STATIC reg_call.c)
	target_include_directories(eh_engine PUBLIC inc ../inc)
	target_link_libraries(eh_engine PUBLIC utils)
endif()
			     
