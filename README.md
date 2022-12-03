# Cub3d
3D game using minilibx library



## AIM
To create 3D projection of a 2D map using raycasting and DDA algorithm.

## REFERENCES

1. The calculations used in the program are based on the [permadi's raycasting tutorial](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/). We have used the images from the same article for better understanding.

2. [Abrar's raycasting tutorial](https://github.com/Saxsori/ray-cast)

3. For textures [Lode's tutorial](https://lodev.org/cgtutor/raycasting.html)


## WALL RENDERING CALCULATIONS

To apply raycasting we divide the player's view into multiple segments and find the distance at which the corresponding ray in each segment hits a wall. Using this information we create projections.

Considerations:

* Screenwidth = 640
* Screenheight = 400
* FOV = 60
* GRID = 64
* alpha = angle each ray forms with the x axis.

By knowing the field of view and width of the projection plane we can calculate the **distance between player and the projection plane** and **angle between subsequent rays**.

<img width="242" alt="Screen Shot 2022-12-03 at 3 06 05 PM" src="https://user-images.githubusercontent.com/66158938/205437887-beddb09c-9104-41e9-8e1f-7723017491a0.png">


(half of screenwidth) / distance to projection plane = tan(30°)

**distance to projection plane** = 320 /tan(30°)

**Angle between subsequent rays** = fov / screenwidth = 60/640



## FINDING WALLS USING DDA ALGORITHM

If the person is facing NORTH(90°), then the leftmost ray will be at an angle (90°+30°) and the rightmost ray will be at an angle(90°-30°)
We start from the leftmost ray.

![alt text](https://permadi.com/tutorial/raycast/images/figure15.gif)

**STEP 1** :Find coordinates of first hit on y axis (A.x,A.y):

**A.y = floor(P.y/GRID) * GRID - 1**   (If the ray is facing UP)

- P.y is distance of player in y direction
- floor(P.y/GRID) -> gives closest y coordinate
- floor(P.y/GRID) * GRID  -> gives distance to closest y coordinate
- floor(P.y/GRID) * GRID - 1  -> we do not want the value to be on the grid line

**A.x = P.x + dist between P.x and A.x**

**A.x = P.x + (P.y - A.y)/tan(alpha)**

**STEP 2** : check if (A.x,A.y)is a wall. If yes, got to step 4.

**STEP 3** : Increament A.y in steps, find coressponding A.x. Continue this till it hits a wall.

  C.y = A.y - GRID
  
  C.x = A.x + GRID/tan(alpha)
  
  (C.x,C.y)is not a wall so find (D.x, D.y)
  
   D.y = C.y - GRID
  
  D.x = C.x + GRID/tan(alpha)
  
**STEP 4** : Once a wall is hit, we can calculate the distance to the point D using pythagorean theorem

PD = sqrt((P.x - D.x)(P.x - D.x) + (P.y - D.y)(P.y - D.y))


**STEP 5** :Now find coordinates of first hit on x axis (B.x,B.y) and repeat the steps above to get distance PE

![alt text](https://permadi.com/tutorial/raycast/images/figure16.gif)





  

















