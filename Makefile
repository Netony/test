NAME = a.o b.o c.o
LIBS = libft.a libgnl.a libftprintf.a

all : $(NAME)

$(NAME) : $(LIB)
	mv $(@:.o=.c) $@

$(LIBFT) : $(LIBS)

$(LIBS) : 
	make $(@: 

fclean : 
	rm -rf $(LIB) $(NAME)
