#			-->|   Files to Compile   |<--
FILES		=		get_next_line_utils get_next_line

FILES_B		=		get_next_line_utils_bonus get_next_line_bonus

#			-->|   Titles   |<--
HEAD		=		"42 Get Next Line"
HEAD_B		=		"42 Get Next Line Bonus"
NAME		=		get_next_line.a

#			-->|   Command Definitions   |<--
INC_DIR		=		./
SRC_DIR		=		./
OBJ_DIR		=		obj/

SRC			=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ			=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))
SRC_B		=		$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES_B)))
OBJ_B		=		$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_B)))

FLAGS		=		-Wall -Wextra -Werror -g -I
BUFFER		=		-D BUFFER_SIZE=1
COMPILE		=		@cc $(FLAGS) $(INC_DIR) -c $< -o $@
RMV			=		@rm -rf $(OBJ_DIR)
CRT			=		@ar -rcs $(NAME)
AR			=		@ar -rcs $(NAME) $(OBJ)
AR_B		=		@ar -rcs $(NAME) $(OBJ_B)

EXE			=		@cc $(FLAGS) $(INC_DIR) -o get_next_line.exe .main.c $(NAME) && ./get_next_line.exe
RMV_E		=		@rm -f get_next_line.exe

#			-->|   Colors & Messages   |<--
START		=		start
START_B		=		start_b

GRAY		=		\033[0;30m
GREEN		=		\033[0;32m
YELLOW		=		\033[0;33m
BLUE		=		\033[0;34m
MAGENTA		=		\033[0;35m
CYAN		=		\033[0;36m
WHITE		=		\033[0;37m
DEF			=		\033[0;39m

BGREEN		=		\033[1;32m
BYELLOW		=		\033[1;33m
BBLUE		=		\033[1;34m
BMAGENTA	=		\033[1;35m
BCYAN		=		\033[1;36m

T_CREATING	=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD) at $(NAME) $(GRAY)...\n"
T_CREATING_B=		@echo "$(GRAY)-->|	$(BBLUE)Creating $(HEAD_B) at $(NAME) $(GRAY)...\n"
T_BUILDING	=		@echo "	$(GRAY)... $(BYELLOW)Building $(NAME) $(GRAY)... \n"
T_COMPILING	=		@echo "	$(GRAY)... $(YELLOW)Compiling $< with $(FLAGS) $(GRAY)..."
T_REMOVE_O	=		@echo "$(MAGENTA)$(HEAD): Objects Removed!$(DEF)\n"
T_REMOVE_A	=		@echo "$(BMAGENTA)$(HEAD): All Files Removed!$(DEF)\n"
T_COMPILED	=		@echo "\n$(BGREEN)	     $(HEAD) Compiled!   $(GRAY)|<--$(DEF)\n"
T_EXECUTING	=		@echo "\n$(GRAY)-->|	$(BLUE)Executing: $(BCYAN)$(NAME) - main.c $(BLUE)at $(WHITE)exe $(GRAY)...$(DEF)"
T_EXECUTED	=		@echo "$(GRAY)	...$(BGREEN)Execution Ended!   $(GRAY)|<--$(DEF)\n"

#			-->|   Rules   |<--
.PHONY: all bonus clean fclean re exe

all: $(START) $(NAME) $(OBJ)
	$(AR)
	$(T_COMPILED)


bonus: $(START_B) $(NAME) $(OBJ_B)
	$(AR_B)
	$(T_COMPILED)

clean:
	$(M_C)
	$(RMV)
	$(T_REMOVE_O)

fclean:
	$(M_F)
	$(RMV) $(NAME)
	$(RMV_E)\\\\\\\
	$(T_REMOVE_A)

re: fclean all

exe: re
	$(T_EXECUTING)
	$(EXE)
	$(T_EXECUTED)

#			-->|   File Dependencies   |<--
$(START):
	$(T_CREATING)
	$(T_BUILDING)

$(START_B):
	$(T_CREATING_B)
	$(T_BUILDING)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(T_COMPILING)
	$(COMPILE)

$(NAME):
	$(CRT)