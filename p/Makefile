MAKE=make
DIRECTORIES = $(wildcard */)

all:
	$(foreach path,$(DIRECTORIES),$(MAKE) V=0 -C $(path) all ;)

.PHONY: clean
clean:
	$(foreach path,$(DIRECTORIES),$(MAKE) V=0 -C $(path) clean ;)
