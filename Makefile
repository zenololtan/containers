NAME 		= 	containers

SOURCES		= 	main.cpp

OBJDIR		=	./obj/
OBJECTS 	=	$(SOURCES:%.cpp=$(OBJDIR)%.o)

FLAGS 		=	-Wall -Wextra -Werror -std=c++98
COMPILE		=	clang++

INC			=	-Iincludes -Iserver -Isocket

GREEN 		= 	\033[38;5;46m
WHITE 		= 	\033[38;5;15m
GREY 		= 	\033[38;5;8m
ORANGE 		= 	\033[38;5;202m
RED 		= 	\033[38;5;160m

all: $(NAME)

$(OBJDIR)%.o: %.cpp
	@mkdir -p $(@D)
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	@$(COMPILE) $(FLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJECTS)
	@$(COMPILE) $(FLAGS) $(INC) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)Use exe - $(NAME)"

clean:
	@echo "$(RED)Deleting objectfiles"
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@echo "$(RED)Deleting executable"
	@/bin/rm -f $(NAME)

fclena: fclean

re: fclean all

.PHONY: all clean fclean re