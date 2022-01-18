---
layout: default
title: "Assignment 4: Falling Dominoes"
---

Design due in class on **Thursday, April 15th**

Code due **Thursday, April 22nd** by 11:59 PM

*Updated 4/08* &mdash; Changed grading criteria for assign a point value to the design artifact

# Getting Started

Start by downloading [CS101\_Assign04.zip](CS101_Assign04.zip), saving it in the directory **H:\\CS101**.

Then run the commands

```
cd h:
cd CS101
unzip CS101_Assign04.zip
```

You should now have a directory called **CS101\_Assign04** containing the assignment files.

Add your code to the file **FallingDominoes.cpp**.

# Your task

In this assignment, you will write a program that allows the user to simulate falling dominoes.

Your program should start by allowing the user to determine the initial configuration of the "playing field" consisting of 10 positions. Once the configuration has been entered by the user, the program should print a line of text which is a "picture" of the initial configuration.

Next, the program should simulate what happens when the first domino is pushed over: in other words, the simulation begins by changing the domino at position 1 from upright to tipping (if it was initially upright).

After the first domino has been tipped, the simulation should run for exactly **10** time steps.  The rules of the simulation are as follows:

-   There are 10 positions, with position 1 being the leftmost position
-   The simulation begins by changing the domino at position 1 to "tipping"
-   On each timestep, each tipping domino will cause its neighbor to the right to change from upright to tipping (if the neighbor is upright); then the tipping domino will change to horizontal
-   At the end of each timestep, the program should print a picture of the current simulation state.

When printing out the simulation state, each upright domino should be represented by a "\|" character, each tipping domino by "/", each horizontal domino by "\_", and each empty position by a blank space.

Here is an example run (user input in bold):

<pre>
Position 1 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 2 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 3 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 4 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>0</b>
Position 5 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>2</b>
Position 6 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 7 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 8 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>
Position 9 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>0</b>
Position 10 (0=empty, 1=upright, 2=tipping, 3=horizontal): <b>1</b>

Initial configuration:
&vert;&vert;&vert; /&vert;&vert;&vert; &vert;

Tipping over domino 0:
/&vert;&vert; /&vert;&vert;&vert; &vert;

Time step 1:
&#95;/&vert; &#95;/&vert;&vert; &vert;
Time step 2:
&#95;&#95;/ &#95;&#95;/&vert; &vert;
Time step 3:
&#95;&#95;&#95; &#95;&#95;&#95;/ &vert;
Time step 4:
&#95;&#95;&#95; &#95;&#95;&#95;&#95; &vert;
Time step 5:
&#95;&#95;&#95; &#95;&#95;&#95;&#95; &vert;
Time step 6:
&#95;&#95;&#95; &#95;&#95;&#95;&#95; &vert;
Time step 7:
&#95;&#95;&#95; &#95;&#95;&#95;&#95; &vert;
Time step 8:
&#95;&#95;&#95; &#95;&#95;&#95;&#95; &vert;
Time step 9:
&#95;&#95;&#95; &#95;&#95;&#95;&#95; &vert;
Time step 10:
&#95;&#95;&#95; &#95;&#95;&#95;&#95; &vert;
</pre>

### Hints

To represent the simulation data, use an array of integer values to represent the playing field. The element at position 0 is position 1, the element at index 1 is position 2, etc. The value of each element determines what is at that position: 0 for an empty space, 1 for an upright domino, 2 for a tipping domino, 3 for a horizontal domino.

Each iteration of the loop that prints the playing field should print a character representing one position. Print "\|" if the position has an upright domino, "/" if the position has a tipping domino, etc.

To implement the simulation, each time step should be implemented as two **for** loops:

-   The first loop finds each tipping domino, changes its right neighbor to "ready to tip" (if it is upright), and then changes the original domino to horizontal.
-   The second loop finds each "ready to tip" domino and changes it to "tipping".

You should use a value for "ready to tip" positions that is distinct from the values that represent empty, upright, tipping, and horizontal.

Use a third for loop to print out the configuration of the playing field after the simulation of the timestep has completed.

### Grading

Out of 100 points:

-   Design artifact: 10
-   Declaration of an array to represent the playing field: 8
-   Loop to read a value for each position of the playing field: 8
-   Store each position value in the appropriate array element: 8
-   Loop to print a "picture" (line of text) of the playing field: 8
-   Tip first domino, print dominos: 8
-   One timestep:
    -   Loop to change successors of tipping dominoes to "ready to tip": 10
    -   Loop to change "ready to tip" to tipping: 10
    -   Print dominos at end of timestep: 10
-   Loop to simulate 10 timesteps: 20

# Submitting

To submit your work, make sure your **FallingDominos.cpp** file is saved, and in the Cygwin window type the command

    make submit

Enter your Marmoset username and password (which you should have received by email.) Note that your password will not be echoed to the screen. Make sure that after you enter your username and password, you see a message indicating that the submission was successful.

If the **make** command above does not work, you can [submit using the web interface](../submitting.html) (see the link for details).

Make sure that you check the file(s) you submitted to ensure that they are correct.  See the instructions for [Verifying your submission](../submitting.html#verifying-your-submission).

<div class="callout">
<b>Important</b>: It is your responsibility to verify that you submitted the correct files.  You may receive a grade of 0 for incorrectly submitted work.
</div>
