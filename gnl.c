/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etina <etina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:50:04 by etina             #+#    #+#             */
/*   Updated: 2024/12/20 16:27:31 by etina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

// append everything from buffer to remainder until \n or EOF encountered
// EOF is encountered when bytes_read is 0 or < BUFFER_SIZE

char *get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		buffer[BUFFER_SIZE + 1];
	// char 		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(remainder), NULL);
	bytes_read = 1;
	// loop that reads in until \n encountered
	while (bytes_read > 0)
	{
		// read from fd into (buffer should be clean to avoid garbage string)
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// handle read errors
		if (ft_handle_errors(bytes_read, buffer, &remainder))
			return (NULL);
		// take input in buffer, and append to remainder
		// 1. case: read too much
		//    -> read from buffer until \n encountered
		//    -> save remainder in static variable
		if (ft_append_to_remainder(&remainder, buffer))
			return (NULL);
		// 2. case: read too little
		//    -> continue reading until \n encountered
		// 3. case: \n or EOF found
		if (ft_newline_found(remainder))
			break ;
	}

	// return line
	return (ft_next_line(&remainder));
}

// appends string from buffer to remainder;
// returns true if errors, else false
bool ft_append_to_remainder(char **remainder, char *buffer);

// handles read errors; returns true if errors, else false
bool ft_handle_errors(int bytes_read, char *buffer, char **remainder);

// return line, trims remainder
char *ft_next_line(char **remainder);