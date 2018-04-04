compile:
	c++ -o getip getip.cpp

check:
	@echo This should be your external IP-Address
	./getip

remove:
	rm getip

install:
	cp getip /usr/bin/getip

uninstall:
	rm /usr/bin/getip
