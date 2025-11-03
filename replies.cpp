/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 20:09:48 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/02 21:28:54 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "replies.hpp"

//	ERRORS

void    sendErrorMoreParams(Server& server, Client& client, const std::string& cmd)
{
	std::string nick = client.getNick();
	if (nick.empty())
		nick = "*";
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 461 " << nick << " " << cmd << " :Not enough parameters\r\n";
	server.sendToClient(client, ss.str());
}

void    sendErrorRegistred(Server& server, Client& client, const std::string& cmd)
{
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 462 " << client.getNick() << " " << cmd << " :Unauthorized command (already registered)\r\n";
	server.sendToClient(client, ss.str());
}

void	sendFailsAttempts(Server& server, Client& client)
{
	std::stringstream	ss;
	ss << "bad password, you have " << 3 - client.getFailsAttempts() << " try left\n";
	server.sendToClient(client, ss.str());
}

void    sendErrorNoNick(Server& server, Client& client, const std::string& cmd)
{
	std::string nick = client.getNick();
	if (nick.empty())
		nick = "*";
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 431 " << nick << " " << cmd << " :No nickname given\r\n";
	server.sendToClient(client, ss.str());
}

void    sendErrorUnvalidNick(Server& server, Client& client, const std::string& nick)
{
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 432 " << nick << " :Erroneous nickname\r\n";
	server.sendToClient(client, ss.str());
}

void    sendErrorNickUse(Server& server, Client& client, const std::string& nick)
{
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 433 " << nick << " :Nickname is already in use\r\n";
	server.sendToClient(client, ss.str());
}

//	RPL

void    sendAllRpl(Server& server, Client& client)
{
	sendWelcome(server, client);
	sendYourHost(server, client);
	sendCreated(server, client);
	sendMyInfo(server, client);
}

void    sendWelcome(Server& server, Client& client)
{
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 001 " << client.getNick() << " :Welcome to the Internet Relay Network "
		<< client.getNick() << "!" << client.getUser() << "@localhost\r\n";
	server.sendToClient(client, ss.str());
}

void    sendYourHost(Server& server, Client& client)
{
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 002 " << client.getNick() << " :Your host is " << SERVER_NAME
		<< ", running version " << VER << "\r\n";
	server.sendToClient(client, ss.str());
}

void    sendCreated(Server& server, Client& client)
{
	std::stringstream	ss;
	ss << ":" << SERVER_NAME << " 003 " << client.getNick() << " :This server was created "
		<< DATE << "\r\n";
	server.sendToClient(client, ss.str());
}

void sendMyInfo(Server& server, Client& client)
{
	std::stringstream ss;
	ss << ":" << SERVER_NAME << " 004 " << client.getNick() << " "
		<< SERVER_NAME << " " << VER << " o itklo\r\n";
	server.sendToClient(client, ss.str());
}
