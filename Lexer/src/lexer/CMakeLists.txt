add_library(lexer lexer.cpp)

target_link_libraries(lexer PUBLIC token)

target_include_directories(lexer PUBLIC .)
