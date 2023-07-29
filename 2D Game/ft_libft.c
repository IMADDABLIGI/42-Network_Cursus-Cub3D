/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:02:14 by idabligi          #+#    #+#             */
/*   Updated: 2023/06/17 14:08:27 by idabligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
    if (!s)
        return 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

//----------------------------------------------------------------------------//

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dst)
		return (dst);
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*((unsigned char *)dst + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dst);
}

//----------------------------------------------------------------------------//

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	size;
	char	*ptr;

	i = 0;
	size = ft_strlen(s1);
	ptr = (char *)malloc((size + 1) * sizeof(char));
	if (!ptr)
		ft_abort (1);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}
