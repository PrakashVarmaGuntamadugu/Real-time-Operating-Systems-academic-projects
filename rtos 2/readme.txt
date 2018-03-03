1) For final values of N to be 520 run tasks in order of Task2, Task1, Task3.
   For final values of Res to be 300 run tasks in order of Task2, Task3, Task1.
   To satisfy both the conditions at a time, run Tasks in order of Task2, Task1, Task3 with change in computation of Task3 as Res = 3 * Res.
   
1b) Gives the modified code that generates final values of N as 520 and Res as 300. 

3)
#define configUSE_TIMERS set to 1 in FreertosConfig.h
timers.c and timers.h must be included in source path before building it.