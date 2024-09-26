#  =============================================
#  	NOTE!!!!
#  I'm not maintaing this Makefile anymore, 
#  it's just here for reference to how it works
#  with project file.
#  
#  This is not a good or an optimal approach to 
#  do things using Makefile.
#  
#  Here if you want to continue using this try 
#  modifiying it to use "foreach dir" with 
#  "wildcard".
#  =============================================


CC = clang

C_SRC = c_array/lineararray.c c_array/dynamicarray.c c_array/test_for_nix.c main.c

C_EXEC = main 

build: $(C_SRC)
	@$(CC) $(C_SRC) -o $(C_EXEC)
	@echo "Build Success!"
	
run: $(C_EXEC)
	@./$(C_EXEC)

$(C_EXEC): $(C_SRC)
	@$(CC) $(C_SRC) -o $(C_EXEC)


#  ==========================================
#  EVERTHING HERE IS SHIFTED TO "FLAKE.nix"
#  ==========================================
