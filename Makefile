main: main.cpp
	g++ -o skfp main.cpp
clean:
	rm -f skfp
install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f skfp ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/skfp
uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/skfp
