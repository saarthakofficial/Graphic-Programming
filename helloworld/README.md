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

## OpenGL Context Initialization

The OpenGL context is made current for the created window using glfwMakeContextCurrent. Additionally, GLAD (GLAD Loader) is used to load the necessary OpenGL function pointers.

```cpp
glfwMakeContextCurrent(window);

if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    // Terminate if GLAD initialization fails
    glfwTerminate();
    return -1;
}
```

## Rendering Loop

The main rendering loop continues until the user closes the window (glfwWindowShouldClose). Inside the loop, the window is cleared with a specified background color (RGB: 0.1, 0.2, 0.3), and the front and back buffers are swapped.

```cpp
while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);

    glfwSwapBuffers(window);
    glfwPollEvents();
}
```

## Termination

Finally, the GLFW library is terminated, and the program returns 0.

```cpp
glfwTerminate();
return 0;
```

This program serves as a basic template for initializing an OpenGL window and setting up a rendering loop. The background color is cleared in each iteration of the loop, creating a simple visual display.
