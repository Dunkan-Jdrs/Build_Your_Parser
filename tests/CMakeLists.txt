set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(Unit_Tests
  ${SOURCES})

target_include_directories(Unit_Tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Unit_Tests PRIVATE
  My_Own_Parser
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Unit_Tests)
