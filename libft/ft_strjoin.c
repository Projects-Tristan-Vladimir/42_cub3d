#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_calloc((len_s1 + len_s2 + 1), sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
