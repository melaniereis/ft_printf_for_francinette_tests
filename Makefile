#==============================================================================#
#                                   LIBFT PROJECT                              #
#==============================================================================#

# Main target names
NAME = libftprintf.a
EXEC = libftprintf.out

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                               #
#------------------------------------------------------------------------------#

# ANSI color codes for prettier output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Text style codes
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m

# Emojis for visual feedback
CHECK = ✓
CLEAN = 🧹
BUILD = 🔨
ROCKET = 🚀
BOOK = 📚
SPARKLES = ✨

#------------------------------------------------------------------------------#
#                            	  NAMES AND PATHS                              #
#------------------------------------------------------------------------------#

# Directory structure
BUILD_PATH = .build
SRC_PATH = .
INC_PATH = .
HEADERS = ${INC_PATH}/ft_printf.h

# Source files for main library
SRCS = ${addprefix ${SRC_PATH}/, ft_printchar.c ft_printhexa.c ft_printstring.c \
	ft_putnbr_fd.c ft_printf.c ft_printnum.c ft_printunsigned.c \
	ft_putstr_fd.c ft_printpointer.c ft_putchar_fd.c ft_strlen.c}

# Object files derived from source files
OBJS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS:.c=.o}}}

#------------------------------------------------------------------------------#
#                            	   FLAGS & COMMANDS                            #
#------------------------------------------------------------------------------#

CC = cc                           # Compiler to use
CCFLAGS = -Wall -Wextra -Werror   # Compiler flags for warnings and errors
LDFLAGS = -L${LIBFT_PATH} -lft
AR = ar rcs                       # Archive command to create static libraries
RM = rm -fr                       # Command to remove files/directories forcefully
MKDIR_P = mkdir -p                # Command to create directories (with parent)
INC = -I ${INC_PATH}              # Include path for header file
MAKE = make --no-print-directory -C
MAKE_BONUS = make bonus --no-print-directory -C
TMUX = tmux                       # Tmux command for terminal multiplexing

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

##  Compilation Rules for Libft  ##

all: ${NAME}                  # Default target: build the ft_printflibft

${NAME}: ${BUILD_PATH} ${OBJS}
	@printf "\n${YELLOW}${BOLD}${BUILD} Assembling ${WHITE}${NAME}${YELLOW}...${RESET}\n"
	@${AR} ${NAME} ${OBJS}
	@printf "${GREEN}${BOLD}${ROCKET} ${WHITE}${NAME}${GREEN} created successfully!${RESET}\n"

${BUILD_PATH}:
	@printf "\n${BLUE}${BOLD}Creating build directory...${RESET}\n"
	@${MKDIR_P} ${BUILD_PATH}
	@printf "${GREEN}${BOLD}${CHECK} Build directory created successfully!${RESET}\n"


${BUILD_PATH}/%.o: ${SRC_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${INC} -c $< -o $@

##  Norms Rules  ##

norm:                # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette ${SRC_PATH}/*.c ${INC_PATH}/*.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"


##   Check for external functions  ##
check_external_functions: all               # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking External Functions...${RESET}\n"
	nm ./${NAME} | grep "U" | grep -v "__"
	@printf "${GREEN}${BOLD}${CHECK} External functions check completed!${RESET}\n"
	
##  Cleaning Rules  ##

clean:                       # Clean up object files and temporary build files 
	@printf "\n${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@${RM} ${OBJS}
	@printf "${GREEN}${BOLD}${CHECK} Object files cleaned!${RESET}\n"

fclean: clean               # Fully clean up by removing executables and build directories 
	@printf "${YELLOW}${BOLD}${CLEAN} Removing executable, libft.a and build files...${RESET}\n"
	@${RM} ${NAME}
	@${RM} ${BUILD_PATH}
	@${RM} ${EXEC}
	@printf "${GREEN}${BOLD}${CHECK} All files cleaned!${RESET}\n"

re: fclean ${NAME}          # Rebuild everything from scratch 

.PHONY: all test clean fclean re norm 
# Declare phony targets
