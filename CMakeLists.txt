cmake_minimum_required(VERSION 3.14)

project(winrt-playground)

SET(CPPWINRT_REQUIRED_COMPILER_FLAGS "/std:c++17 /bigobj /await /permissive-")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPPWINRT_REQUIRED_COMPILER_FLAGS}")

# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

# set_property(TARGET ${PROJECT_NAME} PROPERTY
#   MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  
# set_target_properties(${PROJECT_NAME} PROPERTIES VS_GLOBAL_ROOTNAMESPACE ${PROJECT_NAME})
# set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
# set_target_properties(${PROJECT_NAME} PROPERTIES VS_CPPWINRT true)
# set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
# # target_link_libraries(${PROJECT_NAME})