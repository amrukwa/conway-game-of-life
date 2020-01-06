# Conway - game of life

[![Build status](https://ci.appveyor.com/api/projects/status/54toka2m07mqg3uk/branch/master?svg=true)](https://ci.appveyor.com/project/amrukwa/conway-game-of-life/branch/master)

## Classic Conway game of life simulation


![image](https://user-images.githubusercontent.com/57860857/71854230-d18ff680-30dd-11ea-97b0-416e14a23848.png)
----

It is a program that simulates a living group of cells in two-dimensional laboratory. The grid's size is adjustable by user. 
Every cell can be in one of two states - alive (indicated by 'o') or dead (indicated by ' '). All of them are identical and run by the same rules, previously stated.
At first, living cells are distributed randomly in the laboratory while probability that the cell is alive at the beginning is adjustable by player.

## Rules 

1. A living cell with only 0 or 1 living neighbours dies from isolation.
2. A living cell with 4 or more living neighbours dies from overcrowding.
3. A dead cell with exactly 3 living neighbours becomes alive.
4. All other cells remain unchanged.

These rules influence whether the cell will be alive in next generation or not.They are applied to all cells simultaneously. Every such application is called a generation.

## The outcome

After seeing the first generation player decides after how many more generations they'd like to see the lab again. All the decisions together with outcomes - first and last generation - is stored in output file.

## The program

You can download the program [here](https://github.com/amrukwa/conway-game-of-life/releases).

The actual version of the program is marked as _Latest release_.
To download the code, click `Source code (zip)` or `Source code (tar.gz)` and save it on your computer.
To download the executable file, click `conway-game-of-life.exe` and save it on your computer. The output file storing the parameters given by the player and the laboratories will be created in the same folder as saved `.exe` file.