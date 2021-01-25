.syntax unified

.code 32

.global start
.section .text.start
start:
    mov r3, pc
    add r3, 5
    bx r3
