#	Sudoku-Solver
Fast sudoku solver using basic logic in combination with optimized backtracking. This has the advantage of being able to solve any valid sudoku puzzle, and do it very quickly. Backtracking becomes exponentially faster with each added clue so the initial basic clue search speeds up most puzzles by an order of magnitude.

##	Usage:
1. Firstly you should build the program using `make`.
>Note: The Makefile is written for [Clang](https://clang.llvm.org/). If you wish to use GCC(or something else), then just change the `CC` variable.

2. Next, simply execute sudoku-solver with the input file name as the first(and only) argument. For example: `./sudoku-solver sudoku.txt`.

Note: If you simply wish to test the project, you can use `make run` and it will automatically use the included `sudoku.txt`.

##	Input file format:
This program uses a input file in plain text. Error checking/correcting is not yet implemented. The input file is 9 lines each representing one row of the sudoku puzzle with `.` representing a blank block.

##	How does it work?
My sudoku solver is a combination of backtracking and extremely rudimentary logic. It will initially look for [full houses, hidden singles, and naked singles](http://hodoku.sourceforge.net/en/tech_singles.php) ;-). Many simple puzzles can be solved purely using these methods. However, the vast majority of more difficult puzzles will be unsolveable if relying on these methods alone. In these cases, the remainder of the puzzle will be solved using backtracking. However, the backtracking will continue even if a solution is found, to verify that there is only one solution to the puzzle. 

##	What is the included puzzle?
The included puzzle is designed specifically to be extremely slow/difficult to solve using a bruteforce attack(very few clues, large gap at beginning of puzzle). This puzzle was found [here](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms#Backtracking). 