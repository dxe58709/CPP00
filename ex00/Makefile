# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/31 16:24:39 by nsakanou          #+#    #+#              #
#    Updated: 2024/08/31 16:36:10 by nsakanou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -MMD -MP
RM = rm -rf


SRCS = megaphone.cpp
OBJDIR	= obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
DEPENDS	= $(OBJS:.o=.d)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@


$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
