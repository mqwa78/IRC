/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:32:17 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/05 00:29:36 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands.h"

void	Pass(Server& server, Client& client, const std::vector<std::string>& params)
{
	if (client.getRegistered())
	{
		sendErrorRegistred(server, client);
		return;
	}
	if (client.getHasPass())
	{
		sendGenericError(server, client, "Password already sent\r\n");
		return;
	}
	if (params.size() != 1)
	{
		sendErrorMoreParams(server, client, "PASS");
		return;
	}
	const std::string&	password = params[0];
	if (password == server.getPass())
		client.setHasPass();
	else
		sendErrorPass(server, client);
}
