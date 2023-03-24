cmake_minimum_required(VERSION 3.0.0)
project(stateMachine VERSION 0.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

include(CTest)
enable_testing()

add_executable(stateMachine 
    assetManager.hpp
    definitions.hpp
    game.hpp
    inputManager.hpp
    main.hpp
    stateMachine.hpp
    states/splashState.hpp
    states/state.hpp
    
    assetManager.cpp
    game.cpp
    inputManager.cpp
    main.cpp
    stateMachine.cpp
    states/splashState.cpp
    
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
