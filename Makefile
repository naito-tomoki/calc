NAME				=	calc

CC					=	cc
CFLAGS				?=	-Wall -Wextra -Werror

override DIR_OBJ	=	build
override DIR_INC	=	include
override DIR_SRC	=	src

SRCS				=	$(wildcard $(DIR_SRC)/*.c)
OBJS				=	$(SRCS:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)
INCS				=	$(foreach d, $(wildcard $(DIR_INC)/*.h), -I $(d))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $^ -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean
