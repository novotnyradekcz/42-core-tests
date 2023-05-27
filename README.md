# 42 core tests
My tests for the various projects in the 42 core curriculum. Created during my studies at 42 Prague in 2023.

## ft_printf
Simply compile the `main.c` file together with your `ft_printf*.c` files or with your compiled `libftprintf.a` library. As indicated by the comment inside the file, the `longhex` and `ulonghex` variables will raise warnings during comilation; if you compile withouth the usual `Wall -Wextra -Werror`, you can ignore the warnings. The purpose of these variables is to test that your `ft_printf` truncates large hexadecimal numbers in the same way as the original `printf`; however, moulinette does not seem to check such large numbers, so you can also safely comment out these two variables (and the section of the file where they are printed) and compile without them (and without warnings). This file only tests the mandatory part of the project.

## get_next_line
As the names sugest, `main.c` serves for checking the mandatory part and `main_bonus.c` for checking the bonus part of the assignment. Compile them together with your `get_nex_line*.c` files (or `get_next_line*_bonus.c` respectively). When executing, you will need to supply the texting files as arguments, one file for the mandatory part, three files for the bonus part:
```
./a.out test.txt
```
or
```
./a.out test1.txt test2.txt test3.txt
```

In the bonus part, the files are read and printed one line at a time, so the output should look like this:
```
first line of first file
first line of second file
first line of third file
second line of first file
second line of second file
second line of third file
...
```

In case of the mandatory test, you can also skip the argument and the program will then read from the standard input, printing each line back to the standard output after you hit `Enter`.
