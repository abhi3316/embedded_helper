
cmake_minimum_required(VERSION 3.30)
project(EMBEDDED_HELPER)


add_subdirectory(IPC)
add_subdirectory(companies)
add_subdirectory(leetcode)
add_subdirectory(ds)
add_subdirectory(bit_ops)



file(GLOB SRC *.c *.cpp)


foreach (SRC_FILE ${SRC})
        get_filename_component(EXE_NAME ${SRC_FILE} NAME_WLE)
        add_executable(${EXE_NAME} ${SRC_FILE})
	set_target_properties(${EXE_NAME}
    				PROPERTIES
				RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bins"
	)
	
endforeach()

