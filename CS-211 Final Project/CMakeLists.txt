cmake_minimum_required(VERSION 3.3)
# TODO: CHANGE THE NEXT LINE TO THE INCLUDE THE TITLE OF YOUR GAME:
project(ludo CXX)
include(.cs211/cmake/CMakeLists.txt)

set(OT_MODEL src/model.cxx)

add_program(ludo
        ${OT_MODEL}
        src/view.cxx
        src/controller.cxx
        src/main.cxx)
target_link_libraries(ludo ge211)

add_test_program(ludo_tests
        ${OT_MODEL}
        test/model_test.cxx)

