ironcat:
    push ebp
    mov ebp,esp
    sub esp,0x08
    push ebx

    pop esp,ebp
    mov ebp
    ret 0x08

ironcatsize = $-ironcat

format MS COFF
public iropncat as '_ironcat'
section '.text' readable executable
ironcat:
    funcLoadLibraryA db 'LoadLibraryA',0
    init db 'libInit',0
    irondth db 'ironDTH',0
    kernel32 db 'kernel32.dll',0
ironcatsize = $-ironcat
public icpsize as '_ironcat_size'
section '.data' readable writeable
    icpsize dd ironcatsize

    call @f
@@:
   pop dword [ebp-4]
   sub dword [ebp-4],@b-ironcat

   mov ebx,[ebp-4]
   add ebx,irondth-ironcat
   push ebx
   mov ebx, [ebp-8]
   call dword ebx

struc listentry {
    .flink dd ?
    .blink dd ?
} 

struc icldrdata {
    .length dd ?
    .initialized db ?
                 db ?
                 db ?
                 db ?
                 db ?
    .sshandle dd ?
    .inLoadOrderModuleList listentry
    .inMemoryOrderModuleList listentry
    .inInitializedOrderModuleList listentry
}

struc ldrmodule {
    .inLoadOrderModuleList listentry
    .inMemoryOrderModuleList listentry
    .inInitializedOrderModuleList listentry
    .baseAddress dd ?
    .entryPoint dd ?
    .sizeOfImage dd ?
    .fullDLLName unicode_string
    .baseDLLName unicode_string
    .flags dd ?
    .loadCount dw ?
    .tlsIndex dw ?
    .hashTable listentry
    .timeDateStamp dd ?
}

push dword [ebp+8]
call dword [ebp-12]