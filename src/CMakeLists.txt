message("entering src")
project(rabbit_engine)
add_subdirectory(base)
add_subdirectory(lib)
add_subdirectory(third)
add_subdirectory(utils)

set(DIR .)

file(GLOB_RECURSE TMP_FILES
	${DIR}/*.hpp
	${DIR}/*.h
	${DIR}/*.cpp
	${DIR}/*.cc
)

foreach(f ${TMP_FILES})
	file(RELATIVE_PATH PATH ${CMAKE_CURRENT_SOURCE_DIR}  ${f})
	string(REGEX REPLACE "(.*)(/[^/]*)$" "\\1" PATH ${PATH})
	string(REPLACE "/" "\\" PATH ${PATH})
	message("extract dir and file ${PATH} ${f}")
	source_group("${PATH}" FILES ${f})
endforeach()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/base)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

add_library(engine_lib STATIC ${TMP_FILES})


