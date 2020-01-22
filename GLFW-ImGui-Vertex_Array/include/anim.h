#ifndef _anim_h_
#define _anim_h_

#include <iostream>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "render.h"
#include "input.h"

class Anim {
private:
    bool _run;
    Render *_render;
    Input *_input;
    GLFWwindow *g_window;

    Anim( bool run );
    ~Anim();

public:
    void loop();
    static Anim &getAnim();
    static void destroyAnim();
};
#endif
