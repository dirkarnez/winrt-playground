cmake_minimum_required(VERSION 3.14)

set (CMAKE_SYSTEM_VERSION 10.0.19041.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(winrt-playground)

macro(intall_nuget_package_to_target target id version)
    if (CMAKE_GENERATOR MATCHES "Visual Studio.*")
        unset(nuget_cmd)
        message("execute nuget install: ${nuget_cmd}")
        find_program(NUGET nuget)

        if(NOT NUGET)
            message(FATAL "Cannot find nuget command line tool.\nInstall it with e.g. choco install nuget.commandline")
        else()
            execute_process(COMMAND NUGET install ${id} -Version ${version} -ExcludeVersion -OutputDirectory ${CMAKE_BINARY_DIR}/packages ENCODING AUTO)
            
            set_target_properties(${target} PROPERTIES
                VS_PROJECT_IMPORT ${CMAKE_BINARY_DIR}/packages/${id}/build/native/${id}.props
            )

            target_link_libraries(${target} PRIVATE ${CMAKE_BINARY_DIR}/packages/${id}/build/native/${id}.targets)
        endif()
    else()
        message(FATAL_ERROR "intall_nuget_package_to_target only use in Visual Studio")
    endif()

endmacro()

SET(CPPWINRT_REQUIRED_COMPILER_FLAGS "/std:c++17 /bigobj /await /permissive-")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPPWINRT_REQUIRED_COMPILER_FLAGS}")

if (CMAKE_GENERATOR MATCHES "Visual Studio.*")
    add_executable(${PROJECT_NAME}
        "src/main.cpp"
    )

    intall_nuget_package_to_target(${PROJECT_NAME} Microsoft.Windows.CppWinRT 2.0.220608.4)
else()
    message(FATAL_ERROR "Only MSVC")
endif()

# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# set_property(TARGET ${PROJECT_NAME} PROPERTY
#   MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  
# set_target_properties(${PROJECT_NAME} PROPERTIES VS_GLOBAL_ROOTNAMESPACE ${PROJECT_NAME})
# set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
# set_target_properties(${PROJECT_NAME} PROPERTIES VS_CPPWINRT true)
# set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
# # target_link_libraries(${PROJECT_NAME})