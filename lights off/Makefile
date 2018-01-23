CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD 
EXEC = a4q2b
OBJECTS = main.o window.o textdisplay.o grid.o cell.o subject.o graphicsdisplay.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
