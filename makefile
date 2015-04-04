IFLAGS= -I/usr/include/OGRE -I/usr/include/boost/
LDFLAGS=  -L/usr/lib/x86_64-linux-gnu -lboost_system -lOgreMain -lOIS -lpthread

all:
	g++  main.cpp -o test $(IFLAGS) $(LDFLAGS)
