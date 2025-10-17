#include "libft.h"

void *memmove(void *dest, const void *src, size_t n)
{
	unsigned char *s;
	unsigned char *d;
	size_t i;

	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	i = 0;
	if (dest >= src)
	{
		while (i < n)
		{
			d[n] = s[n];
			n--;
			i++;
		}
	}
	return (dest);
}
