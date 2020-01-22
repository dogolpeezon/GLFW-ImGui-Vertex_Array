#include <iostream>
#include <GLFW/glfw3.h>
#include "../include/input.h"

bool keys[1024];

Input::Input(): g_window(glfwGetCurrentContext()){}
Input::~Input(){}

void Input::keyCallback( GLFWwindow *g_window, int key, int scancode, int action, int mods ){
  std::cout << "In keyCallback................." << '\n';
    // Check if user presses escape.. if do close
  if ( key == GLFW_KEY_ESCAPE && action == GLFW_PRESS ){
        glfwSetWindowShouldClose( g_window, GL_TRUE );
    }

  if ( action == GLFW_PRESS || action == GLFW_RELEASE ) {
      switch ( key ) {
          case GLFW_KEY_UP:
              std::cout << "Up pressed.." << '\n';
              break;
          case GLFW_KEY_DOWN:
              std::cout << "Down pressed.." << '\n';
              break;
          case GLFW_KEY_LEFT:
              std::cout << "Left pressed.." << '\n';
              break;
          case GLFW_KEY_RIGHT:
              std::cout << "Right pressed.." << '\n';
              break;
          case GLFW_KEY_SPACE:
              std::cout << "Space pressed.." << '\n';
              break;
      }

  }
}

Input &Input::getInput(){
    std::cout << "In getInput...................." << '\n';
    static Input *input;
    if ( input == NULL ){
        glfwSetInputMode( glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL );
        input = new Input();
    }
    return *input;
}

void Input::destroyInput(){
    std::cout << "In destroyInput.................." << '\n';
    Input *input = &getInput();
    delete input;
}
