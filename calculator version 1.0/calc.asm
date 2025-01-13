section .data
    menu db "Menu:", 0xA, "1. Add", 0xA, "2. Subtract", 0xA, "3. Multiply", 0xA, "4. Divide", 0xA, "5. Exit", 0xA, "Choose an option: ", 0
    invalid_choice db "Invalid choice. Please try again.", 0xA, 0
    prompt1 db "Enter first number: ", 0
    prompt2 db "Enter second number: ", 0
    result_msg db "Result: ", 0
    error_msg db "Error: Division by zero!", 0xA, 0
    newline db 0xA, 0
    buffer1 db 0
    buffer2 db 0
    buffer_op db 0

section .bss
    num1 resb 4
    num2 resb 4
    result resb 4
    choice resb 1

section .text
    global _start

_start:
menu_loop:
    ; Display menu
    mov rax, 1
    mov rdi, 1
    mov rsi, menu
    mov rdx, 52
    syscall

    ; Read user choice
    mov rax, 0
    mov rdi, 0
    mov rsi, choice
    mov rdx, 2          ; Read 2 bytes to account for the newline
    syscall
    mov al, [choice]    ; Load the choice
    cmp al, 0xA         ; Check for newline
    je menu_loop        ; If only newline entered, redisplay menu
    sub al, '0'         ; Convert ASCII to integer

    ; Validate choice
    cmp al, 1
    je operation_input
    cmp al, 2
    je operation_input
    cmp al, 3
    je operation_input
    cmp al, 4
    je operation_input
    cmp al, 5
    je exit

    ; Invalid choice
    mov rax, 1
    mov rdi, 1
    mov rsi, invalid_choice
    mov rdx, 36
    syscall
    jmp menu_loop

operation_input:
    ; Prompt for the first number
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt1
    mov rdx, 21
    syscall

    ; Read first number
    mov rax, 0
    mov rdi, 0
    mov rsi, num1
    mov rdx, 4
    syscall
    ; Convert ASCII to integer
    mov rax, 0
    mov rsi, num1
    sub byte [rsi], '0'
    movzx rax, byte [rsi]
    mov [buffer1], rax

    ; Prompt for the second number
    mov rax, 1
    mov rdi, 1
    mov rsi, prompt2
    mov rdx, 22
    syscall

    ; Read second number
    mov rax, 0
    mov rdi, 0
    mov rsi, num2
    mov rdx, 4
    syscall
    ; Convert ASCII to integer
    mov rax, 0
    mov rsi, num2
    sub byte [rsi], '0'
    movzx rax, byte [rsi]
    mov [buffer2], rax

    ; Perform selected operation
    mov al, [choice]
    cmp al, 1
    je add
    cmp al, 2
    je subtract
    cmp al, 3
    je multiply
    cmp al, 4
    je divide

add:
    mov al, [buffer1]
    add al, [buffer2]
    jmp print_result

subtract:
    mov al, [buffer1]
    sub al, [buffer2]
    jmp print_result

multiply:
    mov al, [buffer1]
    imul al, [buffer2]
    jmp print_result

divide:
    mov al, [buffer2]
    cmp al, 0
    je division_error
    mov al, [buffer1]
    xor ah, ah          ; Clear upper byte
    div byte [buffer2]
    jmp print_result

division_error:
    mov rax, 1
    mov rdi, 1
    mov rsi, error_msg
    mov rdx, 27
    syscall
    jmp menu_loop

print_result:
    mov [result], al
    add byte [result], '0'  ; Convert integer to ASCII

    mov rax, 1
    mov rdi, 1
    mov rsi, result_msg
    mov rdx, 8
    syscall

    mov rax, 1
    mov rdi, 1
    lea rsi, [result]
    mov rdx, 1
    syscall

    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall

    jmp menu_loop

exit:
    mov rax, 60
    xor rdi, rdi
    syscall
