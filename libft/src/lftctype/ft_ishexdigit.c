/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishexdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:43:46 by efouille          #+#    #+#             */
/*   Updated: 2018/10/18 14:45:48 by efouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ishexdigit(int c, int uppercase)
{
	int	is_hex_letter;

	is_hex_letter = uppercase ? (c >= 'A' && c <= 'F') : (c >= 'a' && c <= 'f');
	return ((c >= '0' && c <= '9') || c == 'x' || is_hex_letter);
}
