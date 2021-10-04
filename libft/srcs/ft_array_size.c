#include "libft.h"

int	ft_array_size(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while(array[i])
		i++;
	return (i);
}
