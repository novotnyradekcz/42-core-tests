# 42 core tests
My tests for the various projects in the 42 core curriculum. Created during my studies at 42 Prague in 2023.

## ft_printf
SImply compile the `main.c` file together with your `ft_printf` `*.c` files or with your compiled `libftprintf.a` library. As indicated by the comment inside the file, the `longhex` and `ulonghex` variables will raise warnings during comilation; if you compile withouth the usual `Wall -Wextra -Werror`, you can ignore the warnings. The purpose of these variables is to test that your `ft_printf` truncates large hexadecimal numbers in the same way as the original `printf`; however, moulinette does not seem to check such large numbers, so you can also safely comment out these two variables (and the section of the file where they are printed) and compile without them (and without warnings).
