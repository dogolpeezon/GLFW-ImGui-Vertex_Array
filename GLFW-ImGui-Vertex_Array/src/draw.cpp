#include "../include/draw.h"
#include "../include/anim.h"

Draw::Draw(){}
Draw::~Draw(){}

static GLfloat x = 0.5f;
static GLfloat y = 0.5f;
static GLfloat z = 0.5f;
float xRot = 0;
float yRot = 0;
float zRot = 0;
float xTran = 0;
float yTran = 0;
float zTran = 0;
float vInit(GLfloat vertices[], GLfloat colors[]);

void Draw::drawCube(){
    static bool dCount = true;
    if (dCount) {
      std::cout << "In drawCube......................." << '\n';
      dCount = false;
      //std::cout << "dCount = " << dCount << '\n';
    }

    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0, -0.5, -10);

     GLfloat vertices[] =
    {
		-x, -y, -z,   -x, -y,  z,   -x,  y,  z,   -x,  y, -z,
		x, -y, -z,    x, -y,  z,    x,  y,  z,    x,  y, -z,
		-x, -y, -z,   -x, -y,  z,    x, -y,  z,    x, -y, -z,
		-z,  y, -z,   -x,  y,  z,    x,  y,  z,    x,  y, -z,
		-x, -y, -z,   -x,  y, -z,    x,  y, -z,    x, -y, -z,
		-z, -y,  z,   -x,  y,  z,    x,  y,  z,    x, -y,  z
    };

    GLfloat colors[] =
    {
        0, 0, 0,   0, 0, 1,   0, 1, 1,   0, 1, 0,
        1, 0, 0,   1, 0, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 0, 1,   1, 0, 1,   1, 0, 0,
        0, 1, 0,   0, 1, 1,   1, 1, 1,   1, 1, 0,
        0, 0, 0,   0, 1, 0,   1, 1, 0,   1, 0, 0,
        0, 0, 1,   0, 1, 1,   1, 1, 1,   1, 0, 1
    };

    glPopMatrix();
    glFlush();

    glRotated(xRot, 1.0, 0.0, 0.0);
    glRotated(yRot, 0.0, 1.0, 0.0);
    glRotated(zRot, 0.0, 0.0, 1.0);

    vInit(vertices, colors);
    Gui();
    //vRot += 1;

}

float vInit(GLfloat *vertices, GLfloat *colors){
  static bool vCount = true;
  if (vCount) {
    std::cout << "In vInit......................." << '\n';
    vCount = false;
    //std::cout << "dCount = " << dCount << '\n';
  }

    // Enable state for vertex and color
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    // Send data : 24 vertices
    glDrawArrays(GL_QUADS, 0, 24);

    // Cleanup states
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    return 0;
}

void Draw::Gui() {
    ImGui_ImplGlfwGL2_NewFrame();
    ImGui::Begin("Vertex Array");
    ImGui::Text("Average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::Text("Cube Rotate");
    ImGui::SliderFloat("Rotate X", &xRot, 0.0f, 360.0f);
    ImGui::SliderFloat("Rotate Y", &yRot, 0.0f, 360.0f);
    ImGui::SliderFloat("Rotate Z", &zRot, 0.0f, 360.0f);
    ImGui::Separator();
    ImGui::End();
    ImGui::Render();
}

Draw &Draw::getDraw(){
    static bool gdCount = true;
    if (gdCount) {
      std::cout << "In getDraw......................." << '\n';
      gdCount = false;
      //std::cout << "dCount = " << dCount << '\n';
    }

    static Draw *draw = 0;
    if( draw == NULL ){
        draw = new Draw();
    }
    return *draw;
}

void Draw::destroyDraw(){

    Draw *draw = &getDraw();
    delete draw;
}
