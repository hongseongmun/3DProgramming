#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
//#include <GL/glut.h>

#pragma comment(lib, "OpenGL32")

//void changeSize(int w, int h);

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

}


/* void changeSize(int w, int h)
{
    glViewport(0, 0, w, h);

    GLfloat widthFactor = (GLfloat)w / (GLfloat)640;
    GLfloat heightFactor = (GLfloat)h / (GLfloat)640;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * widthFactor, 1.0 * widthFactor, -1.0 * heightFactor, 1.0 * heightFactor, -1.0, 1.0);
}
*/

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(800, 800, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        double radius = 1.0f;
        double angle = 3.14152 / 180;
        double angle2 = 3.14152;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;
        

        
        glClearColor(0.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINE_STRIP);

      // for (int k = 0; k <= 120; k++)
      //  {
      //      glVertex2f(glm::cos(glm::radians(angle2*radius)*k),glm::sin(glm::radians(angle2*radius)*k));
     //  }
        
        
       for (int i = 0; i <= 360; i++)
       {
           glVertex2f(glm::cos((angle*radius)*i),glm::sin((angle*radius)*i));
       }
      

        glEnd();
        //glutReshapeFunc(changeSize);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    exit(EXIT_SUCCESS);
}
