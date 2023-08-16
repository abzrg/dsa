all:
	make -C build all


%:
	make -C build $@


clean:
	make -C build clean


.PHONY: all clean
