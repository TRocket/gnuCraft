objects = gnucraft.o window.o
headers = version.h window.h
binary = gnucraft
GIT_VERSION = $(shell sh -c 'git describe --dirty --always')
CPPFLAGS = -g -D__GIT_VERSION=\"$(GIT_VERSION)\"

$(binary): $(objects) 
	g++ -g -o $@ $(objects) -l boost_system `sdl-config --cflags --libs` -lGL

$(objects): $(headers)

.PHONY: clean
clean:
	rm -f $(objects) $(binary)

