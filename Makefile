PHONY_TARGETS := compile upload monitor
.PHONY: $(PHONY_TARGETS)

all:
	@printf '%s\n' $(PHONY_TARGETS) | fzf | xargs -r make

compile:
	arduino-cli compile --libraries ~/Arduino/libraries --build-path ./build --fqbn esp32:esp32:esp32 src

upload: compile
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 src

monitor:
	arduino-cli monitor -p /dev/ttyUSB0 -b esp32:esp32:esp32 --config 115200

deps:
	arduino-cli lib install "Adafruit PWM Servo Driver Library"

update: git
	git fetch
	git pull

git:
	git add .
	git commit
	git push
