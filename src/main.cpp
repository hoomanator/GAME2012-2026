#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <random>

float RandomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(min, max);
    return dis(gen);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


int main(void)
{

    constexpr int SCREEN_WIDTH = 800;
    constexpr int SCREEN_HEIGHT = 600;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Load OpenGL 4.6*/
    gladLoadGL();

    glfwSetKeyCallback(window, key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glClearColor(0.49f, 0.29f, 0.19f, 1.0f);


		float x = RandomFloat(0, SCREEN_WIDTH);
		float y = RandomFloat(0, SCREEN_HEIGHT);

        glfwSetCursorPos(window,x,y);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	const char* getkeyname = glfwGetKeyName(key, scancode);
    if (action == GLFW_PRESS) printf("%s\n", getkeyname);
    
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
		printf("%s\n", "E key pressed");

    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}