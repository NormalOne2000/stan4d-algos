assn : assn4.cpp graph.o uf.o
			g++ -o assn assn4.cpp graph.o uf.o
graph.o : graph.cpp libUF.hpp libGraph.hpp
				g++ -c graph.cpp
uf.o : uf.cpp libUF.hpp
			g++ -c uf.cpp
clean :
			rm assn graph.o uf.o
