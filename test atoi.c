#include "libft/libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		printf("%d\n", ft_atoi(av[i]));
		i++;
	}
	return (0);
}