#include "../include/anim.h"

int main()
{
   std::cout << "In main.." << std::endl;
   Anim *anim = &Anim::getAnim();
   anim->loop();
   Anim::destroyAnim();
   //Render::destroyRender();
   //Input::destroyInput();
}
