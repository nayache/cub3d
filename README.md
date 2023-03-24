**cub3d** 42 project

reproduce a 3d environment from a 2d map using raycasting(like a wolfenstein) and minilibx.

* keyboard key moves: <kbd>W</kbd> <kbd>A</kbd> <kbd>S</kbd> <kbd>D</kbd>
* camera move: <kbd>&#8592;</kbd> <kbd>&#8594;</kbd>

Running: ```- make && ./Cub3d <file.cub> <--save>```<br/>
+ *<--save> option make a bmp screenshot.<br/>*
+ *<file.cub> example:*<br/>
  + R: Resolution<br/>
  + F: floor RGB<br/>
  + C: ceiling RGB<br/>
  + NO: north wall texture</br>
  + SO: south wall texture</br>
  + EA: east wall texture</br>
  + WE: west wall texture</br>
  + S: sprite texture</br>
  + map:</br>
     - 0 (empty space) </br>
     - 1 (wall) </br>
     - 2 (sprite) </br>
```
R  1600 1050
F  40,80,60
C  0,110,130
NO pics/Brown10_1.xpm
SO pics/bricks.xpm
EA pics/colorstone.xpm
WE pics/Black5.xpm
S  pics/barrel.xpm

111111111111111111111111111111111111111
100000000000000000000000000000000000001
100000000000000200000000000000000000001
100000000000000200000000000000000000001
100000E00000000000000000000000000000001
100000000000000000000000000000000000001
100000000000000000000000000000000000001
111111111111111111111111111111111111111
```




*Screenshots:*
![cub3dscreenshot](https://user-images.githubusercontent.com/58054839/227414070-0be0d50b-db16-41e5-855c-997088bbf892.jpg)
![cub3dscreenshot2](https://user-images.githubusercontent.com/58054839/227414098-adf2949d-db4c-4202-b3db-dd5e03631be7.jpg)
![cub2dscreenshot3](https://user-images.githubusercontent.com/58054839/227414110-7f3d002a-6f4c-4f5f-961b-0d681679c989.jpg)
![cub3dscreenshot4](https://user-images.githubusercontent.com/58054839/227414118-c6054655-28f5-4ebc-bb9c-86f49d83885b.jpg)
