cmake_minimum_required(VERSION 3.5)
project(example_exec VERSION 0.0.1 LANGUAGES CXX)

file(GLOB COMMANDS
    "src/commands/*.hpp"
    "src/commands/*.cpp"
)

file(GLOB TEST
    "src/test/*.hpp"
    "src/test/*.cpp"
)

file(GLOB MAIN
    "src/core/*.hpp"
    "src/core/*.cpp"
)

add_executable(unitTest ${COMMANDS} ${TEST})
set_target_properties(unitTest PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(hnStat ${COMMANDS} ${MAIN})
set_target_properties(hnStat PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

enable_testing()

add_test( unit_test unitTest )

add_test( distinct_queries  hnStat distinct --from 1438387430  --to 1438387430  ../short_file.tsv )

add_test( top_queries  hnStat top 10 --from 1438387430  --to 1438387430  ../short_file.tsv )