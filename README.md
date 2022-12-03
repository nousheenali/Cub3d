# Cub3d
3D game using minilibx library



### AIM
To create 3D projection of a 2D map using DDA algorithm

### REFERENCES

1. The calculations used in the program are based on the [permadi's raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/). We have used the images from the same article for better understanding.

2. [Abrar's raycasting tutorial](https://github.com/Saxsori/ray-cast)

3. For textures [Lode's tutorial](https://lodev.org/cgtutor/raycasting.html)


### WALL RENDERING CALCULATIONS

To apply raycasting we divide the player's view into multiple segments and find the distance at which the corresponding ray in each segment hits a wall. Using this information we create projections.

Considerations:

* Screenwidth = 640
* Screenheight = 400
* FOV = 60

If the person is facing NORTH(90°), then the leftmost ray will be at an angle (90°+30°) and the rightmost ray will be at an angle(90°-30°)

By knowing the field of view and width of the projection plane we can calculate the **distance between player and the projection plane** and **angle between subsequent rays**.

<img width="242" alt="Screen Shot 2022-12-03 at 3 06 05 PM" src="https://user-images.githubusercontent.com/66158938/205437887-beddb09c-9104-41e9-8e1f-7723017491a0.png">


(half of screenwidth) / distance to projection plane = tan(30°)

**distance to projection plane** = 320 /tan(30°)

**Angle between subsequent rays** = fov / screenwidth = 60/640

![alt text](https://permadi.com/tutorial/raycast/images/figure15.gif)











