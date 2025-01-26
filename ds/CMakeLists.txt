file(GLOB SRC *.c *.cpp)
cmake_minimum_required(VERSION 3.30)
#add_library(IPC ${SRC})
#add_executable(main.c)

foreach (SRC_FILE ${SRC}) 
	get_filename_component(EXE_NAME ${SRC_FILE} NAME_WLE)
	add_executable(${EXE_NAME} ${SRC_FILE})
	add_custom_command(TARGET ${EXE_NAME} POST_BUILD
			COMMAND ${CMAKE_COMMAND} -E copy
			${CMAKE_CURRENT_BINARY_DIR}/${EXE_NAME}
			${CMAKE_BINARY_DIR}/bins/${EXE_NAME})
	message(src_dir="${CMAKE_BINARY_DIR}")
endforeach()
