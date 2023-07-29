# CUB3D
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It made me explore ray-casting. The goal is to make a dynamic view inside a maze.

# Goals
- You must create a “realistic” 3D graphicalrepresentation of the inside of a maze from a first-person perspective. You have to create this representation using the Ray-Casting principles.
- This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use
of basic algorithms, information research etc..
- As a graphic design project, cub3D will enable you to improve your skills in these
areas: windows, colors, events, fill shapes, etc.
- To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
- With the help of the numerous documents available on the internet, you will use
mathematics as a tool to create elegant and efficient algorithms.

# Rules
- You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part.
- The management of your window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).
- Your program must be able to set the floor and ceiling colors to two different ones.
- The program displays the image in a window and respects the following rules:
  - The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
  - The W, A, S, and D keys must allow you to move the point of view through the maze.
  - Pressing ESC must close the window and quit the program cleanly.
  - Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
  - The use of images of the minilibX is strongly recommended.
- Your program must take as a first argument a scene description file with the .cub extension.

# Available Functions
- open, close, read, write,printf, malloc, free, perror,strerror, exit
-  All functions of the math library (-lm man man 3 math)
-  All functions of the MinilibX
