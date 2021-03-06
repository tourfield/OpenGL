project(createwindow)
cmake_minimum_required(VERSION 2.6)
#aux_source_directory(. SRC_LIST)
#add_executable(${PROJECT_NAME} ${SRC_LIST})

# CMake entry point

find_package(OpenGL REQUIRED)

# set make to support c++11
#set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
message(STATUS "${CMAKE_CXX_FLAGS}")

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
        message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
        message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies
add_subdirectory (external)
add_subdirectory (common)
# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
        add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
        external/AntTweakBar-1.16/include/
        external/glfw-3.1.2/include/GLFW/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/assimp-3.0.1270/include/
        external/bullet-2.81-rev2613/src/
        .
        common/
)

set(ALL_LIBS
        ${OPENGL_LIBRARY}
        glfw
        GLEW_1130
        common
)

add_definitions(
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

# createwindow
add_executable(createwindow
        createwindow/main.cpp
)
target_link_libraries(createwindow
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(createwindow PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/createwindow/")
create_target_launcher(createwindow WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/createwindow/")

# createvertex
add_executable(createvertex
        createvertex/main.cpp
)
target_link_libraries(createvertex
        ${ALL_LIBS}
)

file(COPY
    ${PROJECT_SOURCE_DIR}/createvertex/SimpleVertexShader.vertexshader
    ${PROJECT_SOURCE_DIR}/createvertex/SimpleFragmentShader.fragmentshader
    DESTINATION
    ${PROJECT_BINARY_DIR}/
)

# Xcode and Visual working directories
set_target_properties(createvertex PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/createvertex/")
create_target_launcher(createvertex WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/createvertex/")

# creatematrices
add_executable(creatematrices
        creatematrices/main.cpp
)
target_link_libraries(creatematrices
        ${ALL_LIBS}
)
file(COPY
    ${PROJECT_SOURCE_DIR}/creatematrices/SimpleTransform.vertexshader
    ${PROJECT_SOURCE_DIR}/creatematrices/SingleColor.fragmentshader
    DESTINATION
    ${PROJECT_BINARY_DIR}/
)
# Xcode and Visual working directories
set_target_properties(creatematrices PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/creatematrices/")
create_target_launcher(creatematrices WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/creatematrices/")


# createcube
add_executable(createcube
        createcube/main.cpp
)
target_link_libraries(createcube
        ${ALL_LIBS}
)
file(COPY
    ${PROJECT_SOURCE_DIR}/createcube/TransformVertexShader.vertexshader
    ${PROJECT_SOURCE_DIR}/createcube/ColorFragmentShader.fragmentshader
    DESTINATION
    ${PROJECT_BINARY_DIR}/
)
# Xcode and Visual working directories
set_target_properties(createcube PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/createcube/")
create_target_launcher(createcube WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/createcube/")

# createtextcube
add_executable(createtextcube
            createtextcube/main.cpp
)
target_link_libraries(createtextcube
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(createtextcube PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/createtextcube/")
create_target_launcher(createtextcube WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/createtextcube/")
