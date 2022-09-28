# FdF
All programs that you wrote until now were executed in text mode on your terminal. Now, let’s discover something more exciting: how to open a graphics window and draw inside? To start your journey in graphic programming, FdF offers to represent “iron wire” meshing in 3D.


It’s time for you to create a basic computer graphics project!
You are going to use the school graphical library: the MiniLibX! This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.
This will be the opportunity for you to get familiar with the MiniLibX, to discover the basics of graphics programming, especially how to place points in space, join them and, most important, how to see the scene from a specific viewpoint.

External functs.:
• open, close, read, write, malloc, free, perror, strerror, exit
• All functions of the math library (-lm compiler option, man man 3 math)
• All functions of the MiniLibX
• ft_printf and any equivalent YOU coded

This project is about creating a simple wireframe model representation of a 3D land- scape by linking various points (x, y, z) thanks to line segments (edges).

Your project must comply with the following rules:

• You must use the MiniLibX. Either the version available on the school machines, or installing it using its sources.

• You have to turn in a Makefile which will compile your source files. It must not relink.

• Global variables are forbidden.

Your program has to represent the model in isometric projection.


Each number represents a point in space:

• The horizontal position corresponds to its axis.

• The vertical position corresponds to its ordinate. • The value corresponds to its altitude.


Graphic management

• Your program has to display the image in a window.

• The management of your window must remain smooth (changing to another win-
dow, minimizing, and so forth).

• Pressing ESC must close the window and quit the program in a clean way.

• Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.

• The use of the images of the MiniLibX is mandatory.


Bonus part

Usually, you would be encouraged to develop your own original extra features. However, there will be much more interesting graphic projects later. They are waiting for you!! Don’t lose too much time on this assignment!

You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. Be smart!
You will get some extra points if you can:

• Include one extra projection (such as parallel or conic)! 

• Zoom in and out.

• Translate your model.

• Rotate your model.

• Add one more bonus of your choice.
