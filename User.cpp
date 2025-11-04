/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:38:41 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/03 23:09:42 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands.h"

void	User(Server& server, Client& client, const std::vector<std::string>& params)
{
	if (!client.getHasPass())
	{
		sendGenericError(server, client, "You must enter PASS before using NICK\r\n");
		return;
	}
}
