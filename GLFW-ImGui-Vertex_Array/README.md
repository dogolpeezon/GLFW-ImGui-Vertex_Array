# GLFW-vertex-array

To build.. 

deps:  

-lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl

mkdir build && cd build

cmake .. 

make

You may need to change where your libs are installed in CmakeLists.txt..

or use:

g++ -o run main.cpp anim.cpp input.cpp render.cpp draw.cpp -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl


This could of course have been maanged all in one file.. but i simply made an exercise in abracting out into OOP.
