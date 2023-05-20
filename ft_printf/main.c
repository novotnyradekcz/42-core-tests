/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:53:28 by rnovotny          #+#    #+#             */
/*   Updated: 2023/05/17 15:27:24 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


int	main()
{
	int		counter;
	char	*name = "Person McPersonface";
	int		school = -2147483648;
	int	dec1 = -654540;
	unsigned int	dec2 = 54540;
	int		hex = 25455774;
	void	*data1 = "gjkgjh";
	void	*data2 = &school;
	void	*data3 = &dec1;
	char 	c = 'A';
	char	*nullstr = 0;
	/* these trigger warnings when compiling,
		printf will want to use %llx instead of %x:	*/
	long long longhex = 9223372036854775807LL;
	unsigned long long ulonghex = 18446744073709551615ULL;

	counter = printf("Hello, %s. Welcome to %i :)\n", name, school);
	printf("%d\n", counter);
	counter = ft_printf("Hello, %s. Welcome to %i :)\n", name, school);
	printf("%d\n", counter);

	counter = printf("Some data: %p %p %p\n", data1, data2, data3);
	printf("%d\n", counter);
	counter = ft_printf("Some data: %p %p %p\n", data1, data2, data3);
	printf("%d\n", counter);

	counter = printf("Some signed and unsigned numbers: %d %u\n", dec1, dec2);
	printf("%d\n", counter);
	counter = ft_printf("Some signed and unsigned numbers: %d %u\n", dec1, dec2);
	printf("%d\n", counter);

	counter = printf("Some hexadecimal number: %x %X\n", hex, hex);
	printf("%d\n", counter);
	counter = ft_printf("Some hexadecimal number: %x %X\n", hex, hex);
	printf("%d\n", counter);
	
	counter = printf("Some long hexadecimal number: %x %X\n", longhex, ulonghex);
	printf("%d\n", counter);
	counter = ft_printf("Some long hexadecimal number: %x %X\n", longhex, ulonghex);
	printf("%d\n", counter);

	counter = printf("Percent sign: %% and a char: %c.\n", c);
	printf("%d\n", counter);
	counter = ft_printf("Percent sign: %% and a char: %c.\n", c);
	printf("%d\n", counter);

	counter = printf("A null string: %s\n", nullstr);
	printf("%d\n", counter);
	counter = ft_printf("A null string: %s\n", nullstr);
	printf("%d\n", counter);
	
	counter = printf("A null pointer: %p\n", nullstr);
	printf("%d\n", counter);
	counter = ft_printf("A null pointer: %p\n", nullstr);
	printf("%d\n", counter);
}
