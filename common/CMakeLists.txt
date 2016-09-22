add_library(common controls.cpp   quaternion_utils.cpp  tangentspace.cpp  texture.cpp objloader.cpp  shader.cpp text2D.cpp vboindexer.cpp )

include_directories(
        ${PROJECT_SOURCE_DIR}/external/AntTweakBar-1.16/include/
        ${PROJECT_SOURCE_DIR}/external/glfw-3.1.2/include/GLFW/
        ${PROJECT_SOURCE_DIR}/external/glm-0.9.7.1/
        ${PROJECT_SOURCE_DIR}/external/glew-1.13.0/include/
        ${PROJECT_SOURCE_DIR}/external/assimp-3.0.1270/include/
        ${PROJECT_SOURCE_DIR}/external/bullet-2.81-rev2613/src/
        ${PROJECT_SOURCE_DIR}/common/
)
