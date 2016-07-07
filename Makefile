NAME		= The_Duck_Reborn

SRCS		= src/main.cpp \
		src/ACharacter.cpp \
		src/Humain.cpp \
		src/AnimatedSprite.cpp \
		src/Animation.cpp \
		src/back.cpp \
		src/AObstacle.cpp \
		src/JumpObstacle.cpp \
		src/JumpDuck.cpp \
		src/DestructibleObstacle.cpp \
		src/PowerEvent.cpp \
		src/JumpRabbitObstacle.cpp \
		src/Rabbit.cpp \
		src/Captain.cpp \
		src/Hulk.cpp \
		src/Duck.cpp

OBJS		= $(SRCS:.cpp=.o)

RM		= rm -rf

GCC		= g++ -o

CXXFLAGS	+= -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -std=gnu++11
CXXFLAGS	+= -Iincludes/

all: $(NAME)

$(NAME): $(OBJS)
	 $(GCC) $(NAME) $(OBJS) $(CXXFLAGS)

debug: CXXFLAGS = -Wall -Wextra -g3 -lsfml-graphics -lsfml-window -lsfml-system -std=gnu++11
debug: CXXFLAGS += -Iincludes/
debug: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
