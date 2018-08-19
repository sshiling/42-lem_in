# 42-lem_in
## Algorithmic project

Lem-In is the fourth project of algorithm branch in the study program at School 42 (UNIT Factory). <br>

The main goal of this project is to find the quickest way to get n ants across the ant farm.

All functions are created in accordance with Norm - the bunch of rules how code should be formatted.

**!NOTE** <br />
Because of 42 School norm requirements: <br />
* All variables are declared and aligned at the top of each function <br />
* Each function can't have more then 25 lines of code <br />
* C++ style code commenting is forbidden <br />
* Project should be created just with allowed functions otherwise it's cheating. <br />

### Main rules:
* Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.
* At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)
* We consider that all the ants are in the room ##start at the beginning of the game.
* At each turn you will only display the ants that moved.
* At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).

<b>Results should be displayed on the standard output in the following format:</b>

number_of_ants
the_rooms
the_links
Lx-y Lz-w Lr-o ...

x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.

#### Example #1:
[0]-[2]-[3]-[1]

```
zaz@blackjack /tmp/lem-in $ ./lem-in < subjet1.map
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1
L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
zaz@blackjack /tmp/lem-in $
```

#### Example #2:
```
   [2]
  / | \
[0] | [1]
  \ | /
   [3]
```
```
zaz@blackjack /tmp/lem-in $ ./lem-in < subjet2.map
3
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
0-2
0-3
2-1
3-1
2-3
L1-3 L2-2
L1-1 L2-1 L3-3
L3-1
zaz@blackjack /tmp/lem-in $
```

#### More about School 42 you can find here: https://en.wikipedia.org/wiki/42_(school)
