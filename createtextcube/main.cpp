/******************************************************************
*
*   Author : Geary Young
*   Description : Create a cube covered with number text .
*   Date : 2016.09.26
*
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include <shader.hpp>
#include <texture.hpp>

using namespace glm;
using namespace std;

GLFWwindow *window = NULL;

int main(void) {
  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW !\n");
    return -1;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(1024, 768, "TextureCube", NULL, NULL);

  return 0;
}
