#####################################
### CONFIG
#####################################
#.DELETE_ON_ERROR:

SERVER		= server
CLIENT		= client
TEST		= test
NAME		= $(SERVER) $(CLIENT)

LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a

CC 			= gcc
CFLAGS		= #-Wall -Wextra -Werror -g3

RM			= rm -rf
MKDIR		= mkdir -p

SRC_DIR		= src
SERVER_DIR	= $(SRC_DIR)/server/
CLIENT_DIR	= $(SRC_DIR)/client/
UTILS_DIR	= $(SRC_DIR)/utils/

SERVER_SRC	=	main.c
CLIENT_SRC	=	main.c
TEST_SRC	=	$(SRC_DIR)/test/main.c

SERVER_F 	= $(addprefix $(SERVER_DIR), $(SERVER_SRC))
CLIENT_F	= $(addprefix $(CLIENT_DIR), $(CLIENT_SRC))
UTILS_F		= $(addprefix $(UTILS_DIR), $(UTILS_SRC))

SERVER_O	= $(SERVER_F:%.c=%.o)
CLIENT_O	= $(CLIENT_F:%.c=%.o)
UTILS_O		= $(UTILS_F:%.c=%.o)
OBJS 		= $(SERVER_O) $(CLIENT_O) $(UTILS_O)

INCLUDES 	+= -I ./includes
INCLUDES	+= -I $(LIBFT_DIR)

#####################################
### RULES
#####################################

all: $(SERVER) $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $^

$(LIBFT):
	@make -C libft

$(SERVER): $(LIBFT) $(SERVER_O) ./includes/server.h
	$(CC) $(CFLAGS) $(INCLUDES) $(SERVER_O) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT) $(CLIENT_O) $(UTILS_O) ./includes/client.h
	$(CC) $(CFLAGS) $(INCLUDES) $(CLIENT_O) $(LIBFT) -o $(CLIENT)

$(TEST): $(OBJS) $(LIBFT)
	$(CC) $(DFLAGS) $(TEST_SRC) $(INCLUDES) $(UTILS_O) $(LIBFT) -o $(TEST)

.PHONY:	all clean fclean re retest debug normi

normi: fclean
	@clear
	norminette src/*
	norminette includes/*
	norminette libft/*.c
	norminette libft/*.h

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(SERVER) $(CLIENT) $(TEST)
re: fclean all
retest:
	$(RM) test
	make test
