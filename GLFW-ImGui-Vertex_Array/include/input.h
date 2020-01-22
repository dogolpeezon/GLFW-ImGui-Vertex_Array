#ifndef _input_h_
#define _input_h_

#include <GLFW/glfw3.h>

class Input {
private:
    GLFWwindow *g_window;
    Input();
    ~Input();

public:
    static Input &getInput();
    static void destroyInput();
    static void keyCallback( GLFWwindow *g_window, int key, int scancode, int action, int mods );
};
#endif
