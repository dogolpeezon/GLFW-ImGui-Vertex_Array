#ifndef _render_h_
#define _render_h_

#include <GLFW/glfw3.h>
#include "draw.h"

class Render {
private:
    GLFWwindow *g_window;
    Draw *_draw;
    Render();
    ~Render();

public:
    void render();
    static Render &getRender();
    static void destroyRender();
};
#endif
