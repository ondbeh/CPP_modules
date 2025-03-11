# Name of the program
NAME		=	a.out

# Directories
SRC_DIR		=	src
OBJ_DIR		=	obj
HDR_DIR		=	inc

# Compiler and flags
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++17
RM			=	rm -f
INCLUDES	=	-I./$(HDR_DIR)/

# Source files and corresponding object files
SRCS		=	main.cpp Bureaucrat.cpp AForm.cpp \
 				ShrubberyCreationForm.cpp \
 				RobotomyRequestForm.cpp \
 				PresidentialPardonForm.cpp \
 				Intern.cpp

SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		=	$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Rules
all: $(NAME)

# Link object files create the final executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES)
	@echo "Compiling $(NAME) project"

# Compile source files into object files in the obj/ folder
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	@echo "Compiling $<"

# Create the obj/ directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Creating folder for object files"

# Run the executable

run: $(NAME)
	@./$(NAME)

# Clean object files
clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "Deleting $(NAME) objects"

# Full clean: also remove the executable
fclean: clean
	@$(RM) $(NAME)
	@echo "Deleting $(NAME) executable"

# Rebuild everything
re: fclean all

# PHONY prevents conflicts with files named like the targets
.PHONY: all clean fclean re