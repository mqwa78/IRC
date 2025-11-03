/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:33:48 by mqwa              #+#    #+#             */
/*   Updated: 2025/11/01 04:41:44 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "include.h"
# include "Client.hpp"
# include "Channel.hpp"
# include "Server.hpp"
# include "replies.hpp"

void	Pass(Server& server, Client& client, const std::vector<std::string>& params);
void	Nick(Server& server, Client& client, const std::vector<std::string>& params);

#endif