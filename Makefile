CC		 = g++
CFLAGS = -Wall -g -O0

VD		 = vetorDes
VO		 = vetorOrd
LD		 = listaDes
LO		 = listaOrd
AB		 = arvoreBin
TR		 = treap
A23	 = arvore23
RN		 = arvoreRN
HS		 = hashTable
RM		 = rm
#-----------------------
ep1: main.o $(VD).o $(LD).o
	$(CC) -o ep1 main.o $(VD).o $(LD).o -lm

main.o: main.cpp  util.hpp
	$(CC) $(CFLAGS) -c main.cpp

vetorDes.o: $(VD)/$(VD).cpp $(VD)/$(VD).hpp node.hpp
	$(CC) $(CFLAGS) -c $(VD)/$(VD).cpp

vetorOrd.o: $(VO)/$(VO).cpp $(VO)/$(VO).hpp node.hpp
	$(CC) $(CFLAGS) -c $(VO)/$(VO).cpp

listaDes.o: $(LD)/$(LD).cpp $(LD)/$(LD).hpp node.hpp
	$(CC) $(CFLAGS) -c $(LD)/$(LD).cpp

# listaOrd.o: $(LO)/$(LO).cpp $(LO)/$(LO).hpp util.hpp node.hpp
# 	$(CC) $(CFLAGS) -c $(LO)/$(LO).cpp

# arvoreBin.o: $(AB)/$(AB).cpp $(AB)/$(AB).hpp util.hpp node.hpp
# 	$(CC) $(CFLAGS) -c $(AB)/$(AB).cpp

# treap.o: $(TR)/$(TR).cpp $(TR)/$(TR).hpp util.hpp node.hpp
# 	$(CC) $(CFLAGS) -c $(TR)/$(TR).cpp

# arvore23.o: $(A23)/$(A23).cpp $(A23)/$(A23).hpp util.hpp node.hpp
# 	$(CC) $(CFLAGS) -c $(A23)/$(A23).cpp

# arvoreRN.o: $(RN)/$(RN).cpp $(RN)/$(RN).hpp util.hpp node.hpp
# 	$(CC) $(CFLAGS) -c $(RN)/$(RN).cpp

# hashTable.o: $(HS)/$(HS).cpp $(HS)/$(HS).hpp util.hpp node.hpp
# 	$(CC) $(CFLAGS) -c $(HS)/$(HS).cpp

clear:
	$(RM) -r *.o && $(RM) -r ep1

# $(VO).o $(LD).o $(LO).o $(AB).o $(TR).o $(A23).o $(RN).o $(HS).o
# $(VO).o $(LD).o $(LO).o $(AB).o $(TR).o $(A23).o $(RN).o $(HS).o