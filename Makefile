ARCH = arm-none-eabi

CC = ${ARCH}-gcc
OBJCOPY = ${ARCH}-objcopy

CFLAGS += -mfpu=vfp -mfloat-abi=hard -march=armv6zk -mtune=arm1176jzf-s -nostartfiles

all: kernel.img

kernel.img: kernel
	${OBJCOPY} kernel -O binary kernel.img

kernel: kernel.o cstartup.o cstubs.o start.o
	${CC} ${CFLAGS} -o kernel -T rpi.x kernel.o cstartup.o cstubs.o start.o

clean:
	rm -f *.o kernel kernel.img
