.syntax unified

.code 32

.global start
.section .text.start
start:
    ldr r3, =main
    bx r3
