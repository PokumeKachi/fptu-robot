_default:
    @just --choose

todo:
    taskwarrior-tui --taskdata .task

compile:
    printf "\033[31mRUN 'just deps' FIRST IF YOU HAVEN'T\033[0m\n"
    arduino-cli compile --libraries ~/Arduino/libraries --build-path ./build --fqbn esp32:esp32:esp32

upload: compile
	arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 src

monitor:
	arduino-cli monitor -p /dev/ttyUSB0 -b esp32:esp32:esp32 --config 115200

deps:
    arduino-cli lib install "Adafruit PWM Servo Driver Library"
    arduino-cli lib install ESP32Servo
    arduino-cli core update-index
    arduino-cli core install esp32:esp32 || true

git:
    gitui


watch:
	watchexec -e ino,cpp,hpp,h,c "just compile"
