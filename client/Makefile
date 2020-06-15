FILE_EXTENSION = .cpp #Extension del archivo
COMPILER = g++ #Compilador usado
COMPILER_FLAG = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SCR_FILES = $(wildcard *$(FILE_EXTENSION)) # Selecciona todos los archivos .cpp
OBJ_FILES = $(SCR_FILES:$(FILE_EXTENSION)=.o) # Todos los archivos de SCR_FILES pero con .o

#$@ El objetivo
#$< Lo que se esta convirtiendo actualmente
#$^ Toda la lista de objetos_files
main: $(OBJ_FILES)
	$(COMPILER) $(COMPILER_FLAG) -o $@ $^
	@echo YA TA!

$(OBJ): %.o: %.cpp
	$(COMPILER) $(COMPILER_FLAG) -o $@ $<
