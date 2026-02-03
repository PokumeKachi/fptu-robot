Before you proceed, this project was an absolute dumpster fire.
It was a failure.
Yet I had the most fun I have ever felt in a while working on this.

# Perhaps the real FPTU AI & Robotics Challenge 2025 were the friends we made along the way.




# Project overview

```
fptu-robot
├── include
│   ├── globals.hpp
│   ├── *.hpp (*: controller, servo, motor)
├── src
│   ├── globals.cpp
│   ├── controller.cpp
│   ├── motor.cpp
│   └── servo.cpp
└── fptu-robot.ino
```

# Dependencies

- [The PS2 controller library.](https://github.com/makerviet/Arduino-PS2X-ESP32-Makerbot)

# fptu-robot

└── include

- (include directory) Mã nguồn

  ├── globals.hpp

  - File đựng các biến toàn cục sử dụng bởi mọi file (các trạng thái của robot, đang chạy hay đang thả bóng,...) kèm theo các thông số như số thứ tự chân IO, tốc độ Analog PWM, ...

  ├── \*.hpp

  - File header của các source file, khai báo tên các hàm cho file chính tái sử dụng

└── src

- (source code) Mã nguồn

  ├── globals.cpp

  - File khai báo của header biến toàn cục, thông số trên

  ├── controller.cpp

  - File đựng logic của tay cầm PS2 (điều khiển và thay đổi các giá trị của các biến toàn cục)

  - Các file dưới quyết định trạng thái của các bộ phận của robot dựa vào giá trị của mỗi biến toàn cục

  ├── motor.cpp

  - File đựng logic của motor (bánh xe lăn và trục kéo ròng rọc)

  ├── servo.cpp

  - File đựng logic của servo (thanh chắn bóng)

└── fptu-robot.ino

- File code chính của Arduino
