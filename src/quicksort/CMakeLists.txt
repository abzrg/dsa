# Library
add_library(dsa_quicksort STATIC quicksort.c)
target_include_directories(dsa_quicksort PUBLIC ${CMAKE_CURRENT_LIST_DIR})

# Test
add_executable(dsa_quicksort_test main.c)
target_include_directories(dsa_quicksort_test PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(dsa_quicksort_test PRIVATE dsa_quicksort)
