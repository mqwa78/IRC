/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 21:38:41 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/05 07:34:59 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "CommandHandler.hpp"
# include "commands.h"

void	CommandHandler::_User(Client& client, const std::vector<std::string>& params)
{
	if (!client.getHasPass())
	{
		sendGenericError(_server, client, "You must enter PASS before using USER\r\n");
		return;
	}
	if (client.getRegistered())
	{
		sendErrorRegistred(_server, client);
		return;
	}
	if (params.size() != 4)
	{
		sendErrorMoreParams(_server, client, "USER");
		return;
	}

	std::string	username = params[0];
	std::string	realname = params[3];

	if (!realname.empty() && realname[0] == ':')
		realname = realname.substr(1);

	client.setUser(username);
	client.setServerName(params[1]);
	client.setHostName(params[2]);
	client.setRealName(realname);

	if (!client.getRegistered() && !client.getNick().empty())
	{
		client.setRegistered();
		sendAllRpl(_server, client);
	}
}
