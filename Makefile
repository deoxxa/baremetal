ARCH = arm-none-eabi

CC = $(ARCH)-gcc
OBJCOPY = $(ARCH)-objcopy
OBJDUMP = $(ARCH)-objdump

CFLAGS += -march=armv6zk -mtune=arm1176jzf-s -g -std=c99
LDFLAGS += -nostartfiles -T linker.ld

all: kernel.img

kernel: kernel.c startup.o

kernel.img: kernel
	$(OBJCOPY) -O binary kernel kernel.img

list: kernel
	$(OBJDUMP) -S kernel

qemu: kernel.img
	@echo
	@echo "To exit qemu, use ctrl+a,x"
	@echo
	@qemu-system-arm -cpu arm1176 -m 8 -M versatilepb -nographic -kernel kernel.img

clean:
	rm -f kernel kernel.img startup.o
