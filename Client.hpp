/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:03:44 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/05 07:34:43 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include "include.h"

class Channel;

class Client
{
		public:
				//Constructors
				Client(int fd);
				~Client();

				//Public Functions

				//Getters
				bool				getRegistered() const;
				bool				getHasPass() const;
				const std::string&	getNick() const;
				const std::string&	getUser() const;
				const std::string&	getRealName() const;
				int					getFd() const;
			
				//Setters
				void	setRegistered();
				void	setHasPass();
				void	setNick(const std::string& nick);
				void	setUser(const std::string& user);
				void	setRealName(const std::string& name);
				void	setHostName(const std::string& name);
				void	setServerName(const std::string& name);

		private:
				int					_fd;
				std::string			_nickName;
				std::string			_userName;
				std::string			_realName;
				std::string			_hostName;
				std::string			_serverName;
				bool				_hasPass;
				bool				_isRegistered;
				std::set<Channel*>	_channels;
};

#endif