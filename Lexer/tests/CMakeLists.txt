
include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG origin/devel
    )
    
FetchContent_MakeAvailable(Catch2)    
    
add_executable(lexer_tests lexer_test.cpp)

target_link_libraries(lexer_tests PRIVATE Catch2::Catch2WithMain lexer)

include(CTest)
enable_testing()
add_test(lexer_tests lexer_tests) 
