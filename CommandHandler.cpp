/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 04:38:02 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/05 06:34:40 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "CommandHandler.hpp"
# include "Server.hpp"
# include "replies.hpp"

CommandHandler::CommandHandler(Server& server) : _server(server) 
{
	_initializeCommands();
}

void	CommandHandler::_initializeCommands()
{
	_commands["PASS"] = &CommandHandler::_Pass;
	_commands["NICK"] = &CommandHandler::_Nick;
	_commands["USER"] = &CommandHandler::_User;
}

bool	CommandHandler::_checkRegistered(Client& client, const std::string& cmd) const
{
	if (cmd == "PASS" || cmd == "NICK" || cmd == "USER")
		return (1);
	return (client.getRegistered());
}

void	CommandHandler::handleRequest(int fd)
{
	char buffer[512];
	memset(buffer, 0, sizeof(buffer));
	ssize_t bytesRead = recv(fd, buffer, sizeof(buffer) - 1, 0);

	if (bytesRead <= 0)
	{
		Client *client = _server.getClient(fd);
		_server.disconnectClient(*client);
		return;
	}
	std::string input(buffer);
	input.erase(input.find_last_not_of("\r\n") + 1); // nettoyage \r\n

	std::cout << "Client " << fd << " sent: " << input << std::endl;

	// === Découpage simple ===
	std::istringstream iss(input);
	std::string command;
	iss >> command;

	std::vector<std::string> params;
	std::string param;
	while (iss >> param)
		params.push_back(param);

	//	APPELS DES CMD
	if (command == "QUIT")
		_server.setLoop();
	Client *client = _server.getClient(fd);
	std::map<std::string, CommandFunc>::iterator it = _commands.find(command);
	if (it != _commands.end())
	{
		if (!_checkRegistered(*client, command))
			sendErrorNotRegister(_server, *client);
		else
		{
			CommandFunc	func = it->second;
			(this->*func)(*client, params);
		}
	}
	else
		sendErrorCommand(_server, *client, command);
}

CommandHandler::~CommandHandler() {}
