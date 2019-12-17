//Nikita Game Interface
//NGI exported game interface function: ngiAlloc(size_t param_1)
void * ngiAlloc(size_t param_1) {
  void *pvVar1;
  
                    /* 0x19e50  54  ngiAlloc */
  pvVar1 = _malloc(param_1);
  if (pvVar1 == (void *)0x0) {
    ngiProcessError(&DAT_00000010); //Data is the address of a low value function.
  }
  return pvVar1;
}

//Custom defined type definition: ngiFixedMemMaxBlock(void)
undefined4 ngiFixedMemMaxBlock(void) {
                    /* 0x2a00  47  ngiFixedMemMaxBlock
                       0x2a00  55  ngiGetPalette
                       0x2a00  144  ngiIsBackSurface */
  return 0;
}

void ngiFree(undefined *param_1) { //Undefined (custom defined) type definition
  BOOL BVar1;
  
                    /* 0x19e80  45  ngiFree */
  BVar1 = IsBadWritePtr(param_1,4);
  if (BVar1 == 0) {
    FUN_1002a847(param_1);
/* FUN_1002a847()
Mnemonic: PUSH
Number of Operands: 1
Address: ram:1002a847
Flow Type: FALL_THROUGH
Fallthrough: 1002a848
Delay slot depth: 0
Hash: 40dfd964

    Input Objects:
   EBP, ESP, const:0x4
Result Objects:
   ESP
Constructor Line #'s:
   PUSH(3905), Rmr32(942)

Byte Length : 1
Instr Bytes : 01010101
Mask        : 11111000
Masked Bytes: 01010000

Instr Context:
   opsize(02,03)     == 0x1
   addrsize(01,01)   == 0x1
    */
  }
  return;
} //Free memory function.

void ngiGetMemSize(undefined *param_1) {
                    /* 0x197a0  46  ngiGetMemSize */
  FUN_1002acdc(param_1);
/* FUN_1002acdc()
Mnemonic          : PUSH
Number of Operands: 1
Address           : ram:1002acdc
Flow Type         : FALL_THROUGH
Fallthrough       : 1002acdd
Delay slot depth  : 0
Hash              : 40dfd964

Input Objects:
   EBP, ESP, const:0x4
Result Objects:
   ESP
Constructor Line #'s:
   PUSH(3905), Rmr32(942)

Byte Length : 1
Instr Bytes : 01010101
Mask        : 11111000
Masked Bytes: 01010000

Instr Context:
   opsize(02,03)     == 0x1
   addrsize(01,01)   == 0x1
  */
  return;
} //Useful function to call and check memory.

void ngiProcessError(LPCSTR param_1) { //Employs BaseTsd.h
  char cVar1;
  HANDLE hFile;
  uint uVar2;
  char *pcVar3;
  DWORD local_204;
  CHAR local_200 [512];
  
                    /* 0x4340  31  ngiProcessError */
  if (param_1 < (LPCSTR)0x1f4) {
    wsprintfA(local_200,s_Error_No.%ld_1003432c);
  }
  else {
    lstrcpyA(local_200,param_1);
  }
  FUN_10004990();
  /* FUN_10004990()
Instruction Summary
-------------------
Mnemonic          : MOV
Number of Operands: 2
Address           : ram:10004990
Flow Type         : FALL_THROUGH
Fallthrough       : 10004996
Delay slot depth  : 0
Hash              : 70cb1935

Input Objects:
   ram:1003a460
Result Objects:
   ECX
Constructor Line #'s:
   MOV(3619), rm32(1359), Mem(1093), segWide(1060), 
   addr32(1014), Reg32(937), check_Reg32_dest(1385)

Byte Length : 6
Instr Bytes : 10001011 00001101 01100000 10100100 00000011 00010000
Mask        : 11111111 11000111 00000000 00000000 00000000 00000000
Masked Bytes: 10001011 00000101 00000000 00000000 00000000 00000000

Instr Context:
   opsize(02,03)     == 0x1
   addrsize(01,01)   == 0x1
*/
  FUN_1000c1e0();
/* FUN_1000c1e0()
Mnemonic          : MOV
Number of Operands: 2
Address           : ram:1000c1e0
Flow Type         : FALL_THROUGH
Fallthrough       : 1000c1e6
Delay slot depth  : 0
Hash              : 70cb1935

Input Objects:
   ram:1003a580
Result Objects:
   ECX
Constructor Line #'s:
   MOV(3619), rm32(1359), Mem(1093), segWide(1060), 
   addr32(1014), Reg32(937), check_Reg32_dest(1385)

Byte Length : 6
Instr Bytes : 10001011 00001101 10000000 10100101 00000011 00010000
Mask        : 11111111 11000111 00000000 00000000 00000000 00000000
Masked Bytes: 10001011 00000101 00000000 00000000 00000000 00000000

Instr Context:
   opsize(02,03)     == 0x1
   addrsize(01,01)   == 0x1
*/
  FUN_100049d0();
/* FUN_100049d0()
Mnemonic          : MOV
Number of Operands: 2
Address           : ram:100049d0
Flow Type         : FALL_THROUGH
Fallthrough       : 100049d5
Delay slot depth  : 0
Hash              : 4d76e2be

Input Objects:
   ram:1003a474
Result Objects:
   EAX
Constructor Line #'s:
   MOV(3627), check_EAX_dest(1388), moffs32(1302), 
   segWide(1060)

Byte Length : 5
Instr Bytes : 10100001 01110100 10100100 00000011 00010000
Mask        : 11111111 00000000 00000000 00000000 00000000
Masked Bytes: 10100001 00000000 00000000 00000000 00000000

Instr Context:
   opsize(02,03)     == 0x1
   addrsize(01,01)   == 0x1
*/
  FUN_100119f0();
/* FUN_100119f0()
Mnemonic          : PUSH
Number of Operands: 1
Address           : ram:100119f0
Flow Type         : FALL_THROUGH
Fallthrough       : 100119f1
Delay slot depth  : 0
Hash              : 40dfd964

Input Objects:
   ESI, ESP, const:0x4
Result Objects:
   ESP
Constructor Line #'s:
   PUSH(3905), Rmr32(942)

Byte Length : 1
Instr Bytes : 01010110
Mask        : 11111000
Masked Bytes: 01010000

Instr Context:
   opsize(02,03)     == 0x1
   addrsize(01,01)   == 0x1
*/
  FUN_10011750();
/* FUN_10011750()
Mnemonic          : MOV
Number of Operands: 2
Address           : ram:10011750
Flow Type         : FALL_THROUGH
Fallthrough       : 10011756
Delay slot depth  : 0
Hash              : 70cb1935

Input Objects:
   ram:1003a668
Result Objects:
   ECX
Constructor Line #'s:
   MOV(3619), rm32(1359), Mem(1093), segWide(1060), 
   addr32(1014), Reg32(937), check_Reg32_dest(1385)

Byte Length : 6
Instr Bytes : 10001011 00001101 01101000 10100110 00000011 00010000
Mask        : 11111111 11000111 00000000 00000000 00000000 00000000
Masked Bytes: 10001011 00000101 00000000 00000000 00000000 00000000

Instr Context:
   opsize(02,03)     == 0x1
   addrsize(01,01)   == 0x1
*/
  if (DAT_1003a18c != (HMODULE)0x0) {
    FreeLibrary(DAT_1003a18c);
    DAT_1003a18c = (HMODULE)0x0;
  }
  if (DAT_1003a190 != (HMODULE)0x0) {
    FreeLibrary(DAT_1003a190);
    DAT_1003a190 = (HMODULE)0x0;
  }
  FUN_1002a78a(DAT_1003a384);
  DAT_1003a384 = (undefined *)0x0;
  hFile =CreateFileA(s_\\.\mailslot\ndebug_100342fc,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    uVar2 = 0xffffffff;
    pcVar3 = local_200;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');//To
    WriteFile(hFile,local_200,~uVar2 - 1,&local_204,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
  }
  if ((DAT_1003a188 == 0) && (DAT_1003a384 == (undefined *)0x0)) {
    MessageBoxA((HWND)0x0,local_200,s_Nikita_Game_Interface_Error_10034310,0x2010);
  }
  ExitProcess(4);
  return;
} //DLL process function.

void ngiSetDebugOutput(LPCSTR param_1) { //Maybe self utilize this function for custom debug output.
  int iVar1;
  
                    /* 0x4170  59  ngiSetDebugOutput */
  if (param_1 == (LPCSTR)0x0) {
    FUN_1002a78a(DAT_1003a384);
    DAT_1003a188 = param_1;
    DAT_1003a384 = param_1;
    return;
  }
  if (param_1 == (LPCSTR)0x1) {
    DAT_1003a188 = param_1;
    return;
  }
  iVar1 = lstrlenA(param_1);
  DAT_1003a384 = (LPCSTR)operator_new(iVar1 + 1);
  lstrcpyA(DAT_1003a384,param_1);
  DAT_1003a188 = (LPCSTR)0x0;
  return;
}

undefined4 niGetProcAddress(int param_1) {
                    /* 0x45f0  307  niGetProcAddress */
  return *(undefined4 *)(&g_FastProc + param_1 * 4);
} //Could be a good function for combos.

void niOutputDebugString(char *param_1) {
  char cVar1;
  HANDLE hFile;
  uint uVar2;
  char *pcVar3;
  
                    /* 0x29a0  318  niOutputDebugString */
  hFile =CreateFileA(s_\\.\mailslot\ndebug_100342fc,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    uVar2 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    WriteFile(hFile,param_1,~uVar2 - 1,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
  }
  return;
} //More debugging functions, could be an output for files in String types.