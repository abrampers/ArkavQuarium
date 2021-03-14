add_subdirectory("${PROJECT_SOURCE_DIR}/vendor/googletest" "vendor/googletest")

macro(package_add_test_with_libraries TESTNAME LIBRARIES)
    add_executable(${TESTNAME} ${ARGN})
    target_link_libraries(${TESTNAME} gtest gmock gtest_main ${LIBRARIES} ${GTEST_LDFLAGS})
    target_compile_options(${TESTNAME} PUBLIC ${GTEST_CFLAGS})
    gtest_discover_tests(${TESTNAME}
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

include_directories(
    ../include
    vendor/googletest/googletest/include
)

package_add_test_with_libraries(
    all_tests
    ArkavQuariumLib
    testaquarium.cpp
    testpiranha.cpp
    testcoin.cpp
    testguppy.cpp
    testpellet.cpp
    testsnail.cpp
)

include(CTest)
add_test(all_tests all_tests)
