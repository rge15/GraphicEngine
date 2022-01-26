APP 	:= opengl
CCFLAGS	:= -Wall -g -ggdb3 -pedantic
CC		:= g++
MKDIR	:= mkdir -p
SRC 	:= src
OBJ 	:= obj
LIBS	:= -lGL -ldl -lglfw -lassimp

SUBDIRS		:= $(shell find $(SRC) -type d)
OBJSUBDIRS	:= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
ALLCPPS		:= $(shell find src/ -type f -iname *.cpp)
ALLCPPOS	:= $(patsubst %.cpp, %.o, $(ALLCPPS))

.PHONY:	dir

$(APP)	: $(SRC)/main.cpp $(OBJSUBDIRS) $(ALLCPPOS)
	$(CC) -o $(APP) $(patsubst $(SRC)%, $(OBJ)%,$(ALLCPPOS)) glad.c $(LIBS)

%.o : %.cpp
	$(CC) -o $(patsubst $(SRC)%,$(OBJ)%,$@) -c $^ $(CCFLAGS)

dir		:
	$(info $(SUBDIRS))
	$(info $(OBJSUBDIRS))
	$(info $(ALLCPPS))
	$(info $(ALLOS))

$(OBJSUBDIRS)	:
	$(MKDIR) $(OBJSUBDIRS)

clean :
	rm -fr $(OBJ)