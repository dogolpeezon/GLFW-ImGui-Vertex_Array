#include <GLFW/glfw3.h>
#include "../include/anim.h"

Anim::Anim( bool run ):
_run( run ), g_window( glfwGetCurrentContext()),
_render( &Render::getRender()),
_input( &Input::getInput()){}
Anim::~Anim() { Render::destroyRender(); Input::destroyInput(); }

void Anim::loop (){
    std::cout << "In loop..................." << '\n';
    while ( _run ){
        _run = !glfwWindowShouldClose( g_window );
        glfwSetKeyCallback( g_window, Input::keyCallback );
        _render->render();
    }
}

Anim &Anim::getAnim (){
  std::cout << "In getAnim.................." << '\n';
    static Anim *anim = NULL;
    if ( anim == NULL ){
        glfwInit();
        GLFWwindow *window = glfwCreateWindow(800, 600, " window ", NULL, NULL);
        glfwMakeContextCurrent( window );
        ImGui_ImplGlfwGL2_Init(window, true);
        anim = new Anim( true );
    }
    return *anim;
}

void Anim::destroyAnim (){
    std::cout << "In destroyAnim.................." << '\n';
    Anim *anim = &getAnim();
    delete anim;
    GLFWwindow *g_window = glfwGetCurrentContext();
    glfwDestroyWindow( g_window );
    ImGui_ImplGlfwGL2_Shutdown();
    glfwTerminate();
}
