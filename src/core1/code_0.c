#include <ultra64.h>
#include "functions.h"
#include "variables.h"

#include "gc/gctransition.h"


void func_8023E00C(s32);
void func_8023DFF0(s32);


extern s32 D_80275610;
extern u32 D_80275618;
extern u32 D_8027A130;
extern OSThread D_8027BD38;
extern s32 D_8027BEE8;
extern s32 D_8027BEEC;
u64 D_8027BEF0;
u64 D_8027A538;
extern u8 D_80286F90;

void func_8023DA20(s32 arg0){
    bzero(&D_8027A130, &D_80286F90 - (u8*)&D_8027A130);
    osWriteBackDCacheAll();
    sns_find_and_parse_payload();
    osInitialize();
    func_80240BE0();
}

void func_8023DA74(void){
    func_8033BD6C();
    func_80255198();
}

void func_8023DA9C(s32 arg0){
    func_80254008();
    func_8024C428();
    if (D_8027A130 == 4){
        func_802E3580();
    }
    if (D_8027A130 == 3){
        func_802E4170();
    }
    func_8023DA74();
    D_8027A130 = arg0;
    if (D_8027A130 == 3){
        func_802E4214(D_8027BEE8);
    }
    if (D_8027A130 == 4){
        func_802E35D0();
    }
    func_80255CD8();
}

u32 func_8023DB4C(u32 arg0){
    return D_80275618 & arg0;
}

u32 func_8023DB5C(void){
    return D_80275618;
}

void func_8023DB68(void){
    D_80275618 = 0;
}

s32 func_8023DB74(void){
    return (DEBUG_use_special_bootmap())? 0x80 : 0x91;
}

s32 func_8023DBA4(void){
    return 0x1F;
}

void func_8023DBAC(void){
    func_8023E00C(func_8023DBA4());
    func_8023DFF0(3);
}

void func_8023DBDC(void){
    func_8023E00C(func_8023DB74());
    func_8023DFF0(3);
}

void func_8023DC0C(void){
    func_80255C30();
    func_8023E00C(func_8023DBA4());
    func_8023E08C();
    func_8024BE30();
    func_80251308();
    D_8027BEF0 = D_8027A538;
    func_80254710();
    func_80254028();
    func_8025AFB0();
    func_8033EF58();
    func_8033BB84();
    func_8024F05C();
    func_80250C84();
    func_8023FB1C();
    func_8025425C();
    func_80257424();
    gctransition_reset();
    D_8027A130 = 0;
    D_80275618 = 0;
    func_8023DA9C(3);
}

void func_8023DCDC(void){
    D_80275618++;
}

void func_8023DCF4(void){
    D_80275618--;
}

extern s16 D_803A5D00[];

// void func_8023DD0C(void) {
//     s16 temp_t1;
//     s16 *temp_a0;
//     s32 phi_s3;
//     s32 s0_2;
//     s32 *s2;

//     if ((func_8023DB5C() & 0x7F) == 0x11) {
//         sns_write_payload_over_heap();
//     }
//     func_8023DA74();
//     if ((D_8027A130 != 3) || (getGameMode() != 4)) {
//         func_8023DCDC();
//     }
//     if (D_8027BEEC == 0) {
//         func_8024E7C8();
//     }
//     D_8027BEEC = 0;
//     func_80250C08();
//     if (mapSpecificFlags_validateCRC1() == 0) {
//         write_file_blocks(0, 0, 0x80397AD0, 0x40);
//     }
//     if (3 != D_8027A130) {
//         if (D_8027A130 == 4) {
//             func_802E35D8();
//         }
//     } else {
//         func_80255524();
//         func_80255ACC();
//         func_802C3A18();
//         if (func_802E4424() != 0) {
//             func_802E3F8C(0);
//         }
//         func_802C3A38();
//     }
//     if (D_80275610 != 0) {
//         func_8023DA9C(D_80275610 - 1);
//         D_80275610 = 0;
//     }
//     if ((func_8032056C() == 0) || (levelSpecificFlags_validateCRC1() == 0) || (func_80320240() == 0)) {
//         for (phi_s3 = 30; phi_s3 < (D_8027658C - 30); phi_s3++) {
//             s32 s2 = ((phi_s3 >> 3) & 0x1f) << 0x6;
//             s32 tmp2 = phi_s3 * phi_s3;
//             for (s0_2 = 20; s0_2 < 235; s0_2++) {
//                 s32 tmp = func_8023DB5C();
//                 temp_a0 = &((u8*)D_803A5D00)[(((D_80276588 - 0xFF) / 2) + s0_2 + (phi_s3 * D_80276588))];
//                 // s0 = s0 + 1;
//                 temp_t1 = ((((s32) ((tmp * 8) + tmp2 + (s0_2 * s0_2)) >> 3) & 0x1F)) | ((s0_2 >> 3) << 0xb) | (s2) | 1;
//                 // temp_t1 = GPACK_RGBA5551(s0_2, phi_s3, tmp * 8 + s0_2 * s0_2 + phi_s3 * phi_s3, 1);
//                 temp_a0[0] = temp_t1;
//                 temp_a0[63072] = temp_t1;
//             }
//         }
//     }
// }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/code_0/func_8023DD0C.s")

void func_8023DF9C(void *arg0){ 
    func_8023DC0C();
    sns_write_payload_over_heap();
    while(1){ //main loop
        func_8023DD0C();
    }
}

void func_8023DFF0(s32 arg0){
    D_80275610 = arg0 + 1;
}

s32 func_8023E000(void){
    return D_8027A130;
}

void func_8023E00C(s32 arg0){
    D_8027BEE8 = arg0;
}

void func_8023E018(void){
    // 5th argument should be a pointer to the end of an array, but the start is unknown
    // D_8027A538 is not the right symbol, but the end of the array is the important port and this is the closest symbol currently
    osCreateThread(&D_8027BD38, 6, func_8023DF9C, NULL, ((u8*)&D_8027A538) + 0x1800, 0x14);
}

OSThread *func_8023E060(void){
    return &D_8027BD38;
}

void func_8023E06C(void){
    D_8027BEEC = 1;
}