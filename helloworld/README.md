# OpenGL Hello World

This is a minimalistic OpenGL program that creates a window using GLFW and clears the window with a specified background color.

## Initialization

The program begins by initializing the GLFW library and creating a windowed mode window with a specified size (640x480 pixels) and title ("Hello World"). If the initialization or window creation fails, the program terminates.

```cpp
if (!glfwInit())
    return -1;

GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
if (!window) {
    glfwTerminate();
    return -1;
}
```
