> Project overview

```
fptu-robot
├── include
│   ├── controller.hpp
│   ├── globals.hpp
│   ├── motor.hpp
│   └── servo.hpp
├── src
│   ├── controller.cpp
│   ├── globals.cpp
│   ├── motor.cpp
│   └── servo.cpp
└── fptu-robot.ino
```

# fptu-robot

└── include

-     (include directory) Mã nguồn

  ├── globals.hpp

  -     File đựng các biến toàn cục sử dụng bởi mọi file (các trạng thái của robot, đang chạy hay đang thả bóng,...) kèm theo các thông số như số thứ tự chân IO, tốc độ Analog PWM, ...

  ├── \*.hpp

  - File header của các source file, khai báo tên các hàm cho file chính tái sử dụng

└── src

-     (source code) Mã nguồn

  ├── globals.cpp

  -     File khai báo của header biến toàn cục, thông số trên

  ├── controller.cpp

  -     File đựng logic của tay cầm PS2 (điều khiển và thay đổi các giá trị của các biến toàn cục)

  - Các file dưới quyết định trạng thái của các bộ phận của robot dựa vào giá trị của mỗi biến toàn cục

  ├── motor.cpp

  -     File đựng logic của motor (bánh xe lăn và trục kéo ròng rọc)

  ├── servo.cpp

  -     File đựng logic của  servo (thanh chắn bóng)

└── fptu-robot.ino

-     File code chính của Arduino
