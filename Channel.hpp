/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqwa <mqwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:10:58 by mqwa              #+#    #+#             */
/*   Updated: 2025/10/28 03:35:53 by mqwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "include.h"

class Channel
{
		public:
	
		private:
				std::string			_name;
				std::string			_topic;
				std::set<Client*>	_operators;
				std::string			_password;
				std::set<Client*>	_clients;
				int					_limit;
				bool				_inviteMode;
};

#endif