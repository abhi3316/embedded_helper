cmake_minimum_required(VERSION 3.30)

if(eH_App)
	add_library(utils STATIC endianness.c)
	target_compile_definitions(utils PUBLIC -D__EH_APP__)
	target_include_directories(utils PUBLIC ../inc ../../inc)
else()
	file(GLOB SRC *.c *.cpp)
	foreach (SRC_FILE ${SRC})
	       get_filename_component(EXE_NAME ${SRC_FILE} NAME_WLE)
	       add_executable(${EXE_NAME} ${SRC_FILE})
	       set_target_properties(${EXE_NAME}
	                              PROPERTIES
	                              RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bins")
endforeach()
endif()
