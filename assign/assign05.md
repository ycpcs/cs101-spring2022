---
layout: default
title: "Assignment 5: Snake"
---

*Update 5/3*: updated grading rubric to include design artifacts

**Due dates**:

Design artifacts due on **Tuesday, Apr 26th**

Code due on **Thursday, Apr 28th**

# Getting Started

Start by downloading [CS101\_Assign05.zip](CS101_Assign05.zip), saving it in the CS101 directory within your home directory.

Start a Cygwin Bash Shell (or Linux terminal, or MacOS terminal) and run the following commands:

    cd h:
    cd CS101
    unzip CS101_Assign05.zip
    cd CS101_Assign05

(Note that you should omit the cd h: step on Linux and MacOS.)

Using a text editor (e.g., Notepad++), open the file 

    CS101/CS101_Assign05/Snake.cpp

You will add your code to this file.

# Your Task

Your task is to implement a [Snake](http://en.wikipedia.org/wiki/Snake_%28video_game%29) game.

The play controls a snake.  The snake consists of some number of segments.  At each time step, the snake's head segment moves up, right, down, or left, and the other segments of the snake follow.  The player can control the direction of the snake's head using the arrow keys.  At all times, there is a piece of fruit on the playing field.  If the snake eats the fruit (i.e., the snake's head segment reaches the fruit), the snake grows by one segment.  When the fruit is eaten, a new piece of fruit appears in a random location.  If the snake's head goes out of bounds, or if the snake's head collides with one of the snake's body segments, the game is over.

Here is an animation showing gameplay:

> ![snake game](images/assign05/snake.gif)

Here is an animation showing the player losing because the snake's head went out of bounds:

> ![snake goes out of bounds](images/assign05/outofbounds.gif)

Here is an animation showing the player losing because the snake's head collided with its body:

> ![snake collides with its body](images/assign05/collideself.gif)

You will use the terminal graphics functions: see [Lab 18](../labs/lab18.html), [Lab 19](../labs/lab19.html), [Lab 21](../labs/lab21.html), and especially [Lab 23](../labs/lab23.html) and [Lab 24](../labs/lab24.html).

# Approach

This is a substantial assignment.  Here is a suggested approach to getting all of the features of the program working:

1. Define `struct Point` and `struct Snake` data types.
2. Add fields to `struct Scene` to represent the snake.
3. Add code to `scene_init` to initialize the snake.
4. Add code to `scene_render` to draw the segments of the snake.  The snake should be visible, but will not move.
5. Add code to `scene_update` to move the snake by adding a new head segment and removing the current tail segment. The snake will now move in one direction.
6. Add code to `scene_update` to check for keypresses, changing the direction of the snake as appropriate when an arrow key is pressed.  Now you should be able to control the snake.
7. Add code to `scene_update` to detect if the snake's head has moved out of bounds, and if so, set a "game over" flag in the `struct Scene`.  Also, add code to `scene_render` to print a game over message when the game over flag is set.
8. Add code to `scene_update` to detect if the snake's head has collided with any of its body segments, and if so, set a game over flag in `struct Scene`.
9. Add code to check whether the snake's head is in the same place as the piece of fruit, and if so, increase the player's score, increase the snake's number of segments by 1, and place a new piece of fruit in a random location.  (Make sure that the new fruit location isn't in the same place as any of the snake's segments.)

Note that only items 1&ndash;8 are required for full credit on the assignment.

# Hints, specifications, and requirements

## Playing field, rendering

The playing field should be 80 characters wide by 23 characters high.  (This leaves one row in the terminal available for displaying the current score and number of segments.)

The `scene_render` function should use the terminal graphics functions to render a visual representation of the game state, including:

* The segments of the snake
* The piece of fruit
* The current score
* The current number of segments

The score and number of segments should be rendered in the last row of the terminal.

## `struct Scene`, `main` function

The starting code has a `struct Scene` data type and an example `main` function.  You should add fields to `struct Scene` to represent the current game state.  **Important**: you may *not* modify the `main` function.  This means that you must define `scene_init`, `scene_render`, and `scene_update` functions that can work with the code in the `main` function.

Here is a possible definition for the `struct Scene` data type:

```c
struct Scene {
    struct Snake snake;
};
```

Note that as you add additional features (fruit, score) you may need to add additional fields to this data type.

## Defining struct types and functions

In addition to the `struct Scene` data type, you should define data types `struct Point` and `struct Snake`.

The `struct Point` data type might be defined as follows:

```c
struct Point {
    int x, y;
};
```

You should define the following functions to operate on instances of `struct Point` and `struct Snake`:

{% highlight cpp %}
void point_init(struct Point *p, int x, int y);
void snake_init(struct Snake *snake);
void snake_append_head(struct Snake *snake, int x, int y);
void snake_remove_tail(struct Snake *snake);
struct Point snake_get_head(const struct Snake *snake);
struct Point snake_get_segment(const struct Snake *snake, int index);
{% endhighlight %}

`point_init` should initialize an instance of `struct Point` by storing the specified x and y coordinate values.

`snake_init` should initialize an instance of `struct Snake`.  The snake should have 8 segments initially.  The snake's initial position, configuration, and direction is up to you.  See the "Implementing the snake" section for more details.

`snake_append_head` should add an additional segment to the snake at the position specified by the `x` and `y` parameters.  The new segment will become the new "head" segment.  All of the existing segments should remain in place.

`snake_remove_tail` should remove the last segment of the snake.

`snake_get_head` should return the `struct Point` corresponding to the "head" of the snake.

## Implementing the snake

A good way to represent the snake is using an array of segments, such that each segment is an x/y coordinate pair (e.g., a `struct Point`).  Because the number of segments varies (increasing each time the snake eats a piece of fruit), the snake struct type should use a counter field to keep track of how many segments there are.  The snake struct type should also keep track of which direction the snake is moving in.  Here is a recommendation for how to define the `struct Snake` data type:

{% highlight cpp %}
struct Snake {
    struct Point segments[MAX_SEGMENTS];
    int num_segments;  // how many segments the snake has
    int dir;           // which direction the snake is moving in
};
{% endhighlight %}

When the game starts, the snake should have 8 segments.

To get a sense of how an 8-segment snake would be represented, please refer to the [Assignment 5 data representation](../design/assign05datarepresentation.pdf) document.

The game should allow the snake to have up to 100 segments, so the `MAX_SEGMENTS` constant should be defined as 100.

Moving the snake is conceptually quite simple: a new head segment is added, based on the location of the current head segment and the snake's direction of motion.  If the length of the snake isn't changing (meaning that the snake did not eat a piece of fruit, or the snake is already at the maximum length), then the "tail" segment should be removed by calling the `snake_remove_tail` function.  Adding a new head segment should be done by calling the `snake_append_head` function.

Moving the snake is conceptually quite simple: just remove the current tail segment by calling `snake_remove_tail` and append a new head segment by calling `snake_append_head`.  The position of the new head can be determined from the position of the current head segment and the snake's direction.

Here is a suggested approach to implementing the `snake_append_head` and `snake_remove_tail` functions:

* `snake_append_head`: Just set the x and y coordinates of the new head segment in the appropriate element of the array of segments (the one just past the last segment), and increment the total number of segments by 1.
* `snake_remove_tail`: The easiest way is to move each segment other than the tail segment back by one position in the array of segments, and then decrement the number of segments.  You will need a loop to move the segments.

If you follow this approach, the tail segment is element 0 in the array of segments, and head segment is the one whose index is one less than the total number of segments.

The `scene_update` function should move the snake each time it is called.  It should also check to see if the snake's head has gone out of bounds or has collided with the snake's body, and should check to see if the piece of fruit was eaten.

Growing the snake (when a piece of fruit is eaten) is easy: just add a new head segment without removing the current tail segment.

## Representing movement direction

The head of the snake is always moving up, down, right, or left.

If you use the suggested definition for the `struct Snake` data type, then you can use the `dir` field to keep track of which direction the snake is moving in.

It will be helpful to define constants for the different possible directions: e.g.:

```c
#define UP    0
#define DOWN  1
#define RIGHT 2
#define LEFT  3
```

Note that there is nothing special about the specific integer values used to represent directions.  The only requirement is that each direction can be distinguished from the other directions.

## Handling user input

In the `scene_update` function, call the `cons_get_keypress()` function.  If it returns one of the arrow keys (`UP_ARROW`, `RIGHT_ARROW`, `DOWN_ARROW`, or `LEFT_ARROW`), then change the direction of the snake as appropriate.  Note that you should not allow the snake to reverse its direction: for example, if the snake's head is currently moving up, then `scene_update` should do nothing if `DOWN_ARROW` is pressed.

If the `q` key is pressed, then `scene_update` should return 0, causing the `main` function to finish (and the program to exit.)   Otherwise, `scene_update` should return 1 (causing `main` to keep running.)

Note that the `cons_get_keypress()` function will return -1 if no key has been pressed.

## Scoring

Each time the snake eats a piece of fruit, the player earns a number of points equal to 10 times the snake's current number of segments.

# Design artifacts

The design artifacts are due in class on **Thursday, April 26th** for the following functions:
* `snake_append_head`
* `snake_remove_tail`

# Grading

Your grade will be determined according to the following criteria:

Standard features (complete these for full credit on the assignment):

* design artifacts: 10
* `struct Scene` has representation of snake: 5
* snake is displayed: 15
* snake moves: 20
* player can control snake: 20
* game ends when snake goes out of bounds: 8
* game ends when snake's head collides with its body: 8
* pressing `q` ends the program: 4
* good coding style: 10

Extra credit features (complete these for up to 40 points of extra credit):

* `struct Scene` has representation of fruit: 5
* fruit is placed randomly and doesn't overlap snake: 5
* snake can eat the fruit: 5
* snake grows by one segment when fruit is eaten: 10
* score increases when fruit is eaten: 5
* score is displayed: 5
* number of segments is displayed: 5

**Important**: Include a comment at the top of your program explaining which extra credit features you implemented.

# Submitting

To submit your work, make sure your **Snake.cpp** file is saved, and in the Cygwin window type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen. Make sure that after you enter your username and password, you see a message indicating that the submission was successful.

If the **make** command above does not work, you can [submit using the web interface](../submitting.html) (see the link for details).

Make sure that you check the file(s) you submitted to ensure that they are correct.  See the instructions for [Verifying your submission](../submitting.html#verifying-your-submission).

<div class="callout">
<b>Important</b>: It is your responsibility to verify that you submitted the correct files.  You may receive a grade of 0 for incorrectly submitted work.
</div>
