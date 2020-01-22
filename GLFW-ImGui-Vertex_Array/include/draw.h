#ifndef _draw_h_
#define _draw_h_

//#include "include.h"

class Draw{
private:
    Draw();
    ~Draw();
public:
    void drawCube();
    static Draw &getDraw();
    static void destroyDraw();
    void Gui();
};

#endif
