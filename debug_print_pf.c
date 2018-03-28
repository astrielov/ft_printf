#include "includes/ft_printf.h"
#include "libft/libft.h"

void	debug_print_pf(t_pf *pf)
{
	char 	**flags = (char **)ft_memalloc(sizeof(char *) * 8);
	char 	**length = (char **)ft_memalloc(sizeof(char *) * 7);

	flags[0] = pf->flags & FLAG_GOT_PRECISION ? "GOT_PRECISION" : NULL;
	flags[1] = pf->flags & FLAG_MINUS ? "MINUS" : NULL;
	flags[2] = pf->flags & FLAG_ZERO ? "ZERO" : NULL;
	flags[3] = pf->flags & FLAG_PLUS ? "PLUS" : NULL;
	flags[4] = pf->flags & FLAG_HASH ? "HASH" : NULL;
	flags[5] = pf->flags & FLAG_SPACE ? "SPACE" : NULL;
	flags[6] = pf->flags & FLAG_UPPERCASE ? "UPPERCASE" : NULL;
	flags[7] = pf->flags ? NULL : "";

	length[0] = pf->length & LENGTH_SHORT_SHORT ? "SHORT_SHORT" : NULL;
	length[1] = pf->length & LENGTH_SHORT ? "SHORT" : NULL;
	length[2] = pf->length & LENGTH_LONG_LONG ? "LONG_LONG" : NULL;
	length[3] = pf->length & LENGTH_LONG ? "LONG" : NULL;
	length[4] = pf->length & LENGTH_SIZE_T ? "SIZE_T" : NULL;
	length[5] = pf->length & LENGTH_INTMAX ? "INTMAX" : NULL;
	length[6] = pf->length ? NULL : "";

	for (int i = 0; i < 8; i++)
		if (flags[i])
			printf("\tFLAG: %s \n", flags[i]);
//			printf("\x1B[A\033[32;1m \tFLAG: %s \n", flags[i]);

	for (int i = 0; i < 7; i++)
		if (length[i])
			printf("\tLENGTH: %s \n", length[i]);

	free(flags);
	free(length);

	printf("\tflag = %u, width = %u, presicion = %u, length = %u, specifier = %c \n",
				 pf->flags, pf->width, pf->precision, pf->length, pf->specifier);
}