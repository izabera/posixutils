BITS 32
  
                org     0x08048000
  
  ehdr:                                                 ; Elf32_Ehdr
                db      0x7F, "ELF", 1, 1, 1, 0         ;   e_ident
        times 8 db      0
                dw      2                               ;   e_type
                dw      3                               ;   e_machine
                dd      1                               ;   e_version
                dd      _start                          ;   e_entry
                dd      phdr - $$                       ;   e_phoff
                dd      0                               ;   e_shoff
                dd      0                               ;   e_flags
                dw      ehdrsize                        ;   e_ehsize
                dw      phdrsize                        ;   e_phentsize
                dw      1                               ;   e_phnum
                dw      0                               ;   e_shentsize
                dw      0                               ;   e_shnum
                dw      0                               ;   e_shstrndx
  
  ehdrsize      equ     $ - ehdr
  
  phdr:                                                 ; Elf32_Phdr
                dd      1                               ;   p_type
                dd      0                               ;   p_offset
                dd      $$                              ;   p_vaddr
                dd      $$                              ;   p_paddr
                dd      filesize                        ;   p_filesz
                dd      filesize                        ;   p_memsz
                dd      5                               ;   p_flags
                dd      0x1000                          ;   p_align
  
  phdrsize      equ     $ - phdr
  





  _start:
  
                                    ; write: 
                                    ; eax = 4
                                    ; ebx = file descriptor 
                                    ; ecx = lenght
                                    ; edx = address

        mov     ecx, str
        mov     dl, 14              ; setting dl instead of the full edx saves 3 bytes
        inc     ebx                 ; 1 = stdout
        mov     al, 4               ; same as before
        int     0x80    


                                    ; exit: 
                                    ; eax = 1
                                    ; ebx = return code

        xor     ebx, ebx            ; xor with itself is shorter than mov ebx, 0
        mov     al, 1
        int     0x80
  
  str:  db      'Hello, world!',0xA






  filesize      equ     $ - $$





