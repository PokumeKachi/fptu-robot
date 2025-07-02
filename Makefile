PHONY_TARGETS := compile git watch upload monitor
.PHONY: $(PHONY_TARGETS)

all:
	@printf '%s\n' $(PHONY_TARGETS) | fzf | xargs -r make

compile:
	arduino-cli compile --libraries ~/Arduino/libraries --build-path ./build --fqbn esp32:esp32:esp32

upload: compile
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 src

monitor:
	arduino-cli monitor -p /dev/ttyUSB0 -b esp32:esp32:esp32 --config 115200

deps:
	arduino-cli lib install "Adafruit PWM Servo Driver Library"
	arduino-cli lib install ESP32Servo

git:
	git pull
	git add .
	git commit
	git push

watch:
	watchexec -e ino,cpp,hpp,h,c "make compile"
