PHONY_TARGETS := compile upload monitor
.PHONY: $(PHONY_TARGETS)

all:
	@printf '%s\n' $(PHONY_TARGETS) | fzf | xargs -r make

compile:
	arduino-cli compile --build-path ./build --fqbn esp32:esp32:esp32 src

upload: compile
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 src

monitor:
	arduino-cli monitor -p /dev/ttyUSB0 -b esp32:esp32:esp32 --config 115200
