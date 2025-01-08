#Compiler and Linker
CC          := g++ 

#The Target Binary Program
TARGET      := megaphone

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := ./
TARGETDIR   := ./
SRCEXT      := cpp
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wall -Werror -Wextra -std=c++98
#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := megaphone.cpp
OBJECTS     := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make

all: $(TARGETDIR)/$(TARGET) 

#Remake
re: fclean all

#Clean only Objects
clean:
	@$(RM) -rf *.$(OBJEXT)

#Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGET)

$(TARGETDIR)/$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)  

#Compile
%.$(OBJEXT): %.$(SRCEXT)
	$(CC) $(CFLAGS) -c -o $@ $^ 
