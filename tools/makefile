OBJ = main.o
EXE = main
CXX = g++
CXXFLAGS = -Wall -g -MMD

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)
