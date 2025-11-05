/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:17:53 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/05 06:12:21 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDHANDLER_HPP
# define COMMANDHANDLER_HPP

# include "include.h"

class Server;
class Client;

class CommandHandler
{
		public:
					CommandHandler(Server &server);
					~CommandHandler();

					void		handleRequest(int fd);

		private:
					Server&		_server;

					typedef void (CommandHandler::*CommandFunc)(Client&, const std::vector<std::string>&);
					std::map<std::string, CommandFunc>	_commands;

					void		_initializeCommands();
					bool		_checkRegistered(Client& client, const std::string& cmd) const;

					void		_Pass(Client& client, const std::vector<std::string>& params);
					void		_Nick(Client& client, const std::vector<std::string>& params);
					void		_User(Client& client, const std::vector<std::string>& params);

};

#endif