# Library
add_library(dsa_queue_linked_list INTERFACE)
target_include_directories(dsa_queue_linked_list INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Test
add_executable(dsa_queue_linked_list_test main.c)
target_include_directories(dsa_queue_linked_list_test PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(dsa_queue_linked_list_test PRIVATE dsa_queue_linked_list)
