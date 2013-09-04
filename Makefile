all:
	cd src ; make
debug:
	cd src ; make debug
clean:
	rm -f *~ ; cd src ; make clean
