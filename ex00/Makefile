.PHONY:	all re clean fclean distclean
.SUFFIX: .cpp .o

SRCS :=	megaphone.cpp
NAME :=	megaphone

ifeq ($(shell uname), Linux)
CXX :=	g++
else
CXX :=	clang++
endif

LD := $(CXX)

LD_FLAGS := -Wall -Wextra -Werror -std=c++98
CXX_FLAGS := -Wall -Wextra -Werror -std=c++98

OBJS :=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(LD) $(LD_FLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

distclean:	fclean

re: distclean all
