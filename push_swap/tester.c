/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 07:09:54 by rnovotny          #+#    #+#             */
/*   Updated: 2023/11/11 15:29:26 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	print(int *numbers, int amount)
{
	int		i;
	int		j;
	int 	number;
	char	output[11];

	i = 0;
	output[10] = '\0';
	while (i < amount)
	{
		if (numbers[i] < 0)
		{
			number = -numbers[i];
			write(1, "-", 1);
		}
		else
			number = numbers[i];
		j = 9;
		if (number == 0)
		{
			output[j] = '0';
			j--;
		}
		while (number > 0)
		{
			output[j] = number % 10 + '0';
			number /= 10;
			j--;
		}
		write(1, &output[j + 1], 9 - j);
		i++;
		if (i != amount)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

void	generate(int *numbers, int amount, int seed)
{
	int i;
	int	temp;

	i = 0;
	while (i < amount)
	{
		numbers[i] = i * (i + seed) + seed;
		if (!(i % 3))
			numbers[i] *= -1;
		i++;
	}
	while (i > 1)
	{
		i -= 2;
		temp = numbers[i];
		numbers[i] = numbers[amount - i - 1];
		numbers[amount - i - 1] = temp;
	}
	if (amount > 2)
	{
		temp = numbers[0];
		numbers[0] = numbers[1];
		numbers[1] = temp;
	}
}

int	convert(char *input)
{
	int	i;
	int	length;
	int	tens;
	int output;

	i = 0;
	tens = 1;
	while (input[i])
	{
		i++;
		tens *= 10;
	}
	length = i;
	output = 0;
	while (i > 0)
	{
		tens /= 10;
		output += tens * (input[length - i] - '0');
		i--;
	}
	return (output);
}

int	check(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
		{
			write(2, "First argument is not a valid number, try again.\n", 49);
			return (1);
		}
		i++;
	}
	if (i > 9)
	{
		write(2, "That is too many numbers for push_swap to handle, try again.\n", 61);
		return (1);
	}
	if (argc == 3)
	{
		if (argv[2][0] != '-' && (argv[2][0] < '0' || argv[2][1] > '9'))
		{
			write(2, "Second argument is not a valid number, try again.\n", 50);
			return (1);
		}
		i = 0;
		while (argv[2][i])
		{
			if (argv[2][i] < '0' || argv[2][i] > '9')
			{
				write(2, "Second argument is not a valid number, try again.\n", 50);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int *numbers;
	int amount;
	int	seed;

	if ((argc != 2 && argc != 3) || check(argc, argv))
	{
		write(2, "Use: ./tester <amount of integers to generate> <seed (optional, default=42)>\n", 77);
		return (1);
	}
	amount = convert(argv[1]);
	if (argc == 2)
		seed = 42;
	else
		seed = convert(argv[2]);
	numbers = (int *) malloc(amount * sizeof(int));
	generate(numbers, amount, seed);
	print(numbers, amount);
	free(numbers);
	return (0);
}