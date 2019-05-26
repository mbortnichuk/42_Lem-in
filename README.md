# 42_Lem-in
This project is meant to make you code an ant farm manager. You must move your ant colony from one point to another in the least amount of time. Through this project, you will explore graph traversal algorithms: your program will have to choose the paths and moves to be taken by the ants.

## Compile and run
```
git clone https://github.com/mbortnichuk/42_Lem-in.git
cd 42_Lem-in
```
```
make
./lem-in < map1
```

Testing maps located in `lem-im_test-master/lem-in_maps` folder.

## Map example & explanation
```
42
##start
1 23 3
2 16 7
3 16 3
4 16 5
5 3 9
6 1 0
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
4-2
2-1
7-6
7-2
7-4
6-5
```
Map consist of:
1. Ants amount/number
     - Number must be only positive number.
2. Comments: 
     - "##start" and "##end" are provided to show the start and end room.
     - Any other comments we shouldn't be taken into account.
3. Rooms:
     - All rooms defined as: [room name][x_coord][y_coord]
     - Room name cannot start with "L" or space.
     - Room's coordinates always will be integers and cannot be identical.
4. Links:
     - Links defines as: [room_name1]-[room_name2]

## Output example
```
42
##start
1 23 3
2 16 7
3 16 3
4 16 5
5 3 9
6 1 0
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
4-2
2-1
7-6
7-2
7-4
6-5

L1-2
L2-2 L1-4
L3-2 L2-4 L1-0
L4-2 L3-4 L2-0
L5-2 L4-4 L3-0
L6-2 L5-4 L4-0
L7-2 L6-4 L5-0
L8-2 L7-4 L6-0
L9-2 L8-4 L7-0
L10-2 L9-4 L8-0
L11-2 L10-4 L9-0
L12-2 L11-4 L10-0
L13-2 L12-4 L11-0
L14-2 L13-4 L12-0
L15-2 L14-4 L13-0
L16-2 L15-4 L14-0
L17-2 L16-4 L15-0
L18-2 L17-4 L16-0
L19-2 L18-4 L17-0
L20-2 L19-4 L18-0
L21-2 L20-4 L19-0
L22-2 L21-4 L20-0
L23-2 L22-4 L21-0
L24-2 L23-4 L22-0
L25-2 L24-4 L23-0
L26-2 L25-4 L24-0
L27-2 L26-4 L25-0
L28-2 L27-4 L26-0
L29-2 L28-4 L27-0
L30-2 L29-4 L28-0
L31-2 L30-4 L29-0
L32-2 L31-4 L30-0
L33-2 L32-4 L31-0
L34-2 L33-4 L32-0
L35-2 L34-4 L33-0
L36-2 L35-4 L34-0
L37-2 L36-4 L35-0
L38-2 L37-4 L36-0
L39-2 L38-4 L37-0
L40-2 L39-4 L38-0
L41-2 L40-4 L39-0
L42-2 L41-4 L40-0
L42-4 L41-0
L42-0
```

## Author
- Mariana Bortnichuk - [mbortnic](https://github.com/mbortnichuk "mbortnic")
