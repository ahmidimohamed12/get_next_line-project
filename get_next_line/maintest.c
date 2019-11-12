/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 22:43:51 by helkhatr          #+#    #+#             */
/*   Updated: 2019/11/10 13:24:51 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int ac,char **ag)
{
	    int  fd;
    //char    buff[256];
    char    *line;
    int r = 0;
    //int d = 1;
    //line = NULL;
	if(ac==1)
		return(0);
      fd = open(ag[1],O_RDONLY);
    while ((r=get_next_line(fd,&line)) == 1)
    {  
           printf("%s\n",line);
           free(line);
    }
    close(fd);
}
