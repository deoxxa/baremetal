ENTRY(_start)

SECTIONS {
  /* 0x10000 is where qemu starts execution */
  . = 0x10000;

  startup : { startup.o(.text) }
  .data   : { *(.data) }
  .bss    : { *(.bss) }

  stack_limit = .;
}
