/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 05:33:08 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/01 04:44:04 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLIES_HPP
# define REPLIES_HPP

# include "include.h"
# include "Server.hpp"
# include "Client.hpp"
# include "Channel.hpp"

//  Errors
void	sendFailsAttempts(Server& server, Client& client);
void    sendErrorMoreParams(Server& server, Client& client, const std::string& cmd);
void    sendErrorRegistred(Server& server, Client& client, const std::string& cmd);
void    sendErrorNoNick(Server& server, Client& client, const std::string& cmd);
void    sendErrorUnvalidNick(Server& server, Client& client, const std::string& nick);
void    sendErrorNickUse(Server& server, Client& client, const std::string& nick);

//  RPL
void    sendAllRpl(Server& server, Client& client);
void    sendWelcome(Server& server, Client& client);
void    sendYourHost(Server& server, Client& client);
void    sendCreated(Server& server, Client& client);
void    sendMyInfo(Server& server, Client& client);

#endif