/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 22:24:42 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/05 17:21:23 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Client.hpp"

Client::Client(int fd)
{
	_fd = fd;
	_isRegistered = 0;
	_hasPass = 0;
}

//	Public Functions

//	Getters

bool	Client::getRegistered() const
{
	return (_isRegistered);
}

bool	Client::getHasPass() const
{
	return (_hasPass);
}

const std::string&	Client::getNick() const
{
	return (_nickName);
}

const std::string&	Client::getUser() const
{
	return (_userName);
}

int		Client::getFd() const
{
	return (_fd);
}

//	Setters

void	Client::setRegistered()
{
	_isRegistered = 1;
}

void	Client::setHasPass()
{
	_hasPass = 1;
}

void	Client::setNick(const std::string& nick)
{
	_nickName = nick;
}

void	Client::setUser(const std::string& nick)
{
	_userName = nick;
}

void	Client::setRealName(const std::string& name)
{
	_realName = name;
}

void	Client::setHostName(const std::string& name)
{
	_hostName = name;
}

void	Client::setServerName(const std::string& name)
{
	_serverName = name;
}

Client::~Client()
{
	if (_fd >= 0)
	{
		close (_fd);
		_fd = -1;
	}
}
