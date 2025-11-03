/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:32:17 by mqwa              #+#    #+#             */
/*   Updated: 2025/10/31 23:13:19 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands.h"

void	Pass(Server& server, Client& client, const std::vector<std::string>& params)
{
	if (client.getRegistered())
	{
		sendErrorRegistred(server, client, "PASS");
		return;
	}
	if (client.getHasPass())
	{
		server.sendToClient(client, "error: password already sent\n");
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
	{
		client.incrementeFailsAttempts();
		if (client.getFailsAttempts() >= 3)
		{
			server.sendToClient(client, "third fail attempts, bye bye\n");
			server.disconnectClient(client);
		}
		else
			sendFailsAttempts(server, client);
	}
}
