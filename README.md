# fptu-robot

    ├── Makefile
    >     File trên chỉ cần cho Linux, không cần để ý.

    └── src
    >     (source code) Mã nguồn

        ├── controller.h
        >     File code của PS2

        ├── def.h
        >     File đựng các thông số như số thứ tự chân IO, tốc độ Analog PWM, ...

        ├── globals.h
        >     File đựng các biến toàn cục sử dụng bởi mọi file (các trạng thái của robot, đang chạy hay đang thả bóng,...)

        ├── globals.c
        >     File khai báo của header biến toàn cục trên

        ├── motor.h
        >     File đựng logic của motor (bánh xe lăn và trục kéo ròng rọc)

        ├── servo.h
        >     File đựng logic của  servo (thanh chắn bóng)

        └── src.ino
        >     File code chính của Arduino
