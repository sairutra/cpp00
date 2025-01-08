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
CFLAGS      := -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow -Werror -std=c++98
#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := megaphone.cpp
OBJECTS     := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
DEPS        := $(OBJECTS:.o=.d)

#Default Make

all: $(TARGETDIR)/$(TARGET) 

#Remake
re: fclean all

# Dependencies
-include $(DEPS)

#Clean only Objects
clean:
	@$(RM) -rf *.d
	@$(RM) -rf *.$(OBJEXT)

#Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGET)

$(TARGETDIR)/$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)  

#Compile
%.$(OBJEXT): %.$(SRCEXT)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ 