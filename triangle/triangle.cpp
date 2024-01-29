#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

float vertices[]={
    //Positions
    -0.5f, -0.5f, 0.0f, //Bottom Left
    0.5f, -0.5f, 0.0f, //Bottom Right
    0.0f, 0.5f, 0.0f //Up Center
};

int main(){

    //Initializing the library
    if (!glfwInit())
        return -1;

    // Creating a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Making the window's context current
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // If it crashed that means you need build on your pc
        glfwTerminate();
        return -1;
    }

    // Buffers
    unsigned int VBO, VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

    //Position Attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glEnableVertexAttribArray(0);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Rendering
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        
        //Draw
        
        // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swapping front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}