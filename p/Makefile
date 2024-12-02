MAKE=make
DIRECTORIES := ${sort ${shell find . -maxdepth 1 -type d ! -name '.*' -printf '%f '}}


all:
	$(foreach path,$(DIRECTORIES),$(MAKE) V=0 -C $(path) all ;)


txz: clean
	$(foreach path,$(DIRECTORIES),tar cf - $(path) | xz -z - > $(path).txz;)


.PHONY: clean
clean:
	$(foreach path,$(DIRECTORIES),rm $(path).txz;)
	$(foreach path,$(DIRECTORIES),$(MAKE) V=0 -C $(path) clean ;)
