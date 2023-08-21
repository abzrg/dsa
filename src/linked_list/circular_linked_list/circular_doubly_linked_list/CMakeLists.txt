# Library
add_library(circ_dll STATIC circ_dll.c)
target_include_directories(circ_dll PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# Test
add_executable(test_circ_dll test_circ_dll.c)
target_include_directories(test_circ_dll PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(test_circ_dll PRIVATE circ_dll)
