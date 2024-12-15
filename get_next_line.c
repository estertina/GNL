/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etina <etina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:56:09 by etina             #+#    #+#             */
/*   Updated: 2024/12/14 03:22:07 by etina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>

char *get_next_line(int fd)
{
	static char remainder[BUFFER_SIZE + 1];
	char		*str;
	int			pos;
	int			bytes_read;
	int			line_len;

	//remainder has to be at beginning of line once
	//create buffer for line
	//bool	extend_buffer(char **str, int *len)
	str = (char *)malloc(213091823);
	if (!str)
		return (NULL);

	//read	until we find nl or eof reached
	//track string pos with pos value
	//is buffer large enugh? if not make it greater
	bytes_read = read(fd, &str[pos], BUFFER_SIZE);
	if (bytes_read == -1)
		//handle err
	
	//search for new_line and save remainder in static variable

	//return new line
}