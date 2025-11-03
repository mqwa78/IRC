/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandHandler.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:17:53 by mqwa              #+#    #+#             */
/*   Updated: 2025/10/29 04:40:07 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDHANDLER_HPP
# define COMMANDHANDLER_HPP

# include "include.h"

class Server;

class CommandHandler
{
		public:
					CommandHandler(Server &server);

		private:
					Server&		_server;
};

#endif