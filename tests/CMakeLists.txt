set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.hpp *.cpp)

set(SOURCES ${TEST_SOURCES})

include(FetchContent)
set (FETCHCONTENT_QUIET FALSE)

# GTest
message (STATUS "Adding GTest")
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG e2239ee6043f73722e7aa812a459f54a28552929
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${BINARY} ${TEST_SOURCES})

target_link_libraries(
    ${BINARY} PUBLIC
    ${CMAKE_PROJECT_NAME}_lib
    gtest_main
)

include(GoogleTest)