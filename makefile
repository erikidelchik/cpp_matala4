tree: Makefile.project1
	$(MAKE) -f Makefile.project1
	
test: Makefile.project2
	$(MAKE) -f Makefile.project2

Makefile.project2: project2.pro
	qmake project2.pro -o Makefile.project2
	
Makefile.project1: project2.pro
	qmake project2.pro -o Makefile.project2	

Makefile.project1: project1.pro
	qmake project1.pro -o Makefile.project1
	
Makefile.project1: project1.pro
	qmake project1.pro -o Makefile.project1

clean:
	
	rm -f *.o Makefile.project1 Makefile.project2 tree test
