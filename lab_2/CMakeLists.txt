cmake_minimum_required(VERSION 3.16)
project(OOPLAB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#### GTest
option(FETCH_GOOGLETEST "Download googletest source" ON)
if(FETCH_GOOGLETEST)
    # reference: https://google.github.io/googletest/quickstart-cmake.html
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
else()
    message("Using custom googletest installation")
    # reference: https://cmake.org/cmake/help/latest/module/FindGTest.html
    find_package(GTest REQUIRED)
endif()

include(files.cmake)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)
list(TRANSFORM SRC_FILES PREPEND ${SRC_DIR}/)
list(TRANSFORM INCLUDE_FILES PREPEND ${INCLUDE_DIR}/)
list(TRANSFORM TEST_FILES PREPEND ${TEST_DIR}/)

# file(GLOB_RECURSE SRC_FILES src/*)
# file(GLOB_RECURSE HEADER_FILES include/*)
include(CTest)


option(COVERAGE "Enable coverage" OFF)

if(COVERAGE)
    set(CMAKE_C_FLAGS "--coverage -g -O0")
    set(CMAKE_CXX_FLAGS "--coverage -g -O0")

    include(scripts/CodeCoverage.cmake)
    set(CODE_COVERAGE_VERBOSE ON)
    set(COVERAGE_EXCLUDE
        ${CMAKE_BINARY_DIR}/_deps/*
        ${PROJECT_SOURCE_DIR}/test/*
    )

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(GCOVR_ADDITIONAL_ARGS
            --gcov-executable "llvm-cov gcov"
        )
    endif()

    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_html(
        NAME ut_all_coverage
        DEPENDENCIES ut_all
        EXCLUDE ${COVERAGE_EXCLUDE}
    )
endif()

if(MSVC)
    set(TARGET_COMPILER_OPTIONS
        /W4
    )
else()
    set(TARGET_COMPILER_OPTIONS
        -Wall -pedantic
    )
endif()

add_executable(${PROJECT_NAME}
        runtime/main.cpp
        runtime/Runtime.cpp
        ${SRC_FILES}
        ${INCLUDE_DIR}
        runtime/Runtime.cpp
        runtime/Runtime.cpp
        runtime/Runtime.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${INCLUDE_DIR}
)

add_executable(ut_all
        ${SRC_FILES}
        ${INCLUDE_DIR}
        ${TEST_FILES}
        runtime/Runtime.cpp
        runtime/Runtime.cpp
        runtime/Runtime.cpp
)

target_link_libraries(ut_all
    GTest::gtest_main
)

target_include_directories(ut_all PRIVATE
        ${INCLUDE_DIR}
) 

target_compile_options(ut_all PRIVATE
    ${TARGET_COMPILER_OPTIONS}
)
# include(GoogleTest)
# gtest_discover_tests(ut_all)