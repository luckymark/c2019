# Gomoku

An AI playing Gomoku.

## To-do List

Task|Value|Expected Time|Practical Time|Finished?|
----|-----|-------------|--------------|---------|
game running|20|3H|so long|Yes|
find arbitary legal move|20|2H|2H|Yes|
build move-value tree|20|3H|so long|Yes|
cut branches|20|5H|so long|Yes
calculate for kill|20|3H||No|

## Score Table  

![score table](\score_table.jpg)

## Current bugs

1. Can't defend and attack 3- or 4-in-a-line conciously. If there is a 3- or 4-in-line, it may not see, which cause lose directly or don't win.   
  Need to find and save such.
2. Score() can be updated less times. Scores can be stored, when a piece is put or removed, just update related pieces' score. [Reference](https://github.com/lihongxun945/myblog/issues/19)
