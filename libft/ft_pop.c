/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:24:31 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/27 14:42:19 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pop(t_list **stack, void *data, size_t *data_size)
{
	t_list *temp;

	ft_memcpy(data, (*stack)->content, *data_size);
	*data_size = (*stack)->content_size;
	temp = (*stack)->next;
	free((*stack)->content);
	free(*stack);
	(*stack) = temp;
}
