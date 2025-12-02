#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <iostream>

bool gEndProgram = false;
GLFWwindow *gWindow = nullptr;

void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods) {
  if (key == GLFW_KEY_ESCAPE)
    gEndProgram = true;
}
int main() {
  if (!glfwInit()) {
    std::cerr << "Failed to Initialize GLFW" << std::endl;
    return -1;
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  gWindow = glfwCreateWindow(800, 600, "Marcus The Cube", NULL, NULL);
  if (!gWindow) {
    const char *description;
    if (glfwGetError(&description)) {
      std::cerr << "GLFW Error: " << description << '\n';
    }
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(gWindow);

  glfwSetKeyCallback(gWindow, key_callback);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cerr << "Failed to initialize GLAD" << std::endl;
    return -1;
  }
  while (!glfwWindowShouldClose(gWindow) || gEndProgram) {
    glfwPollEvents();
    glfwSwapBuffers(gWindow);
  }
  glfwTerminate();
  return 0;
}
