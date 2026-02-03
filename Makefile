PHONY_TARGETS := compile git watch upload monitor
.PHONY: $(PHONY_TARGETS)

all:
	@printf '%s\n' $(PHONY_TARGETS) | fzf | xargs -r make
