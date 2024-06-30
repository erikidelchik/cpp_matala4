tree: Makefile.project
	$(MAKE) -f Makefile.project

Makefile.project: project.pro
	qmake project.pro -o Makefile.project

clean:
	$(MAKE) -f Makefile.project clean
	rm -f Makefile.project tree
