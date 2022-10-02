#include "libft.h"

static size_t	int_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	process_while_loop(char *ptr, unsigned int n, size_t len)
{
	while (n > 0)
	{
		ptr[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	size_t			len;
	char			*ptr;
	unsigned int	new_n;

	new_n = n;
	len = int_len(n);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len--] = '\0';
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		new_n = -n;
		ptr[0] = '-';
	}
	process_while_loop(ptr, new_n, len);
	return (ptr);
}
