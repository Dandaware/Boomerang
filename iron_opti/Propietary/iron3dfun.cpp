void __cdecl FUN_1002a847(undefined *param_1) {
  undefined *lpMem;
  uint *puVar1;
  byte *pbVar2;
  int *local_8;
  
  lpMem = param_1;
  if (param_1 != (undefined *)0x0) {
    if (DAT_1003e604 == 3) {
      puVar1 = (uint *)FUN_1002b9f6((int)param_1);
      if (puVar1 != (uint *)0x0) {
        FUN_1002ba21(puVar1,(int)lpMem);
        return;
      }
    }
    else {
      if ((DAT_1003e604 == 2) &&
         (pbVar2 = (byte *)FUN_1002c751(param_1,&local_8,(uint *)&param_1), pbVar2 != (byte*)0x0))
      {
        FUN_1002c7a8((int)local_8,(int)param_1,pbVar2);
        return;
      }
    }
    HeapFree(DAT_1003e600,0,lpMem);
  }
  return;
}

SIZE_T __cdecl FUN_1002acdc(undefined *param_1) {
  uint uVar1;
  byte *pbVar2;
  SIZE_T SVar3;
  int *local_c;
  uint local_8;
  
  if (DAT_1003e604 == 3) {
    uVar1 = FUN_1002b9f6((int)param_1);
    if (uVar1 != 0) {
      return *(int *)(param_1 + -4) - 9;
    }
  }
  else {
    if ((DAT_1003e604 == 2) &&
       (pbVar2 = (byte *)FUN_1002c751(param_1,&local_c,&local_8), pbVar2 != (byte *)0x0)) {
      return (uint)*pbVar2 << 4;
    }
  }
  SVar3 = HeapSize(DAT_1003e600,0,param_1);
  return SVar3;
}

void FUN_100049d0(void) {
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  puVar3 = DAT_1003a474;
  if (DAT_1003a474 != (undefined *)0x0) {
    do {
      puVar1 = *(undefined **)(puVar3 + 0x514);
      DAT_1003a474 = *(undefined **)(puVar3 + 0x518);
      *(undefined4 *)(puVar3 + 0x514) = 0;
      while (puVar1 != (undefined *)0x0) {
        puVar2 = *(undefined **)(puVar1 + 0x80);
        FUN_1002a78a(puVar1);
        puVar1 = puVar2;
      }
      FUN_1002a78a(puVar3);
      puVar3 = DAT_1003a474;
    } while (DAT_1003a474 != (undefined *)0x0);
  }
  puVar3 = DAT_1003a470;
  if (DAT_1003a470 != (undefined *)0x0) {
    puVar1 = *(undefined **)(DAT_1003a470 + 0x514);
    *(undefined4 *)(DAT_1003a470 + 0x514) = 0;
    while (puVar1 != (undefined *)0x0) {
      puVar3 = *(undefined **)(puVar1 + 0x80);
      FUN_1002a78a(puVar1);
      puVar1 = puVar3;
      puVar3 = DAT_1003a470;
    }
    FUN_1002a78a(puVar3);
    DAT_1003a470 = (undefined *)0x0;
  }
  DAT_1003a478 = 0;
  DAT_1003a49c = 0;
  return;
}

void FUN_1000c1e0(void) {
  if (DAT_1003a580 != (int *)0x0) {
    do {
      (**(code **)(*DAT_1003a580 + 4))();
    } while (DAT_1003a580 != (int *)0x0);
  }
  return;
}

void FUN_10004990(void) {
  if (DAT_1003a460 != (int *)0x0) {
    if (DAT_1003a480 != (int *)0x0) {
      (**(code **)(*DAT_1003a480 + 0x28))(DAT_1003a480);
    }
    while (DAT_1003a460 != (int *)0x0) {
      (**(code **)(*DAT_1003a460 + 4))();
    }
  }
  return;
}

void FUN_100119f0(void) {
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (DAT_1003a66c != (undefined4 *)0x0) {
    do {
      puVar3 = DAT_1003a66c;
      puVar1 = DAT_1003a66c + 4;
      *DAT_1003a66c = 0x100318bc;
      if ((undefined *)*puVar1 == (undefined *)0x0) {
LAB_10011a28:
        DAT_1003a66c = (undefined4 *)puVar3[0x17];
      }
      else {
        FUN_1002a847((undefined *)*puVar1);
        UnmapViewOfFile((LPCVOID)puVar3[2]);
        if (DAT_1003a66c == puVar3) goto LAB_10011a28;
        puVar4 = (undefined4 *)DAT_1003a66c[0x17];
        puVar1 = DAT_1003a66c;
        while (puVar2 = puVar4, puVar2 != puVar3) {
          puVar4 = (undefined4 *)puVar2[0x17];
          puVar1 = puVar2;
        }
        puVar1[0x17] = puVar3[0x17];
      }
      puVar3[0x17] = 0;
      FUN_1002a78a((undefined *)puVar3);
    } while (DAT_1003a66c != (undefined4 *)0x0);
  }
  return;
}

void FUN_10011750(void) {
  if (DAT_1003a668 != (int *)0x0) {
    do {
      (**(code **)(*DAT_1003a668 + 4))();
    } while (DAT_1003a668 != (int *)0x0);
  }
  return;
}