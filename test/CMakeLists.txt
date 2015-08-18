message("entering src/test")
set(SRC
	main.cc
)
add_executable(main ${SRC})
set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(main LINK_PUBLIC engine_lib)