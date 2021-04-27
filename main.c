#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	char *c = "lolcat";
	int i = -15;
	int ft_ptf;
	int ptf;

	ft_ptf = ft_printf("%u et %p ok\n", i, i);
	ptf = printf("%u et %p ok\n", i, i);


	printf("\n return value of ft_ptf = %d", ft_ptf);
	printf("\n return value of ptf = %d", ptf);
	return (1);
}
