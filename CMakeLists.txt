cmake_minimum_required(VERSION 2.6)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(kiss
    src/logger
    src/path
    src/string
    src/uuid
)

INSTALL(TARGETS kiss DESTINATION lib)
INSTALL(DIRECTORY include/ DESTINATION include FILES_MATCHING PATTERN "*.h")

# GTest needed for testing
find_package(GTest)
if (GTEST_FOUND)
    enable_testing()

    add_executable(test_uuid test/test_uuid.cpp)
    target_link_libraries(test_uuid kiss ${GTEST_LIBRARIES})
    add_test(test_uuid test_uuid)
endif (GTEST_FOUND)
