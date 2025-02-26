#include <ultra64.h>
#include "functions.h"
#include "variables.h"

extern char D_80375810[];
extern f32 D_8037581C;
extern f32 D_80375820;
extern f32 D_80375824;
extern f32 D_80375828;
extern f32 D_8037582C;

extern f32 D_8037D400;
extern u8 D_8037D404;


enum bs_e func_802ADCD4(enum bs_e arg0);

void func_802AD6D0(void){
    func_8028A010(ANIM_BANJO_CROUCH, 0.5f);
    D_8037D404 = 4;
}

void func_802AD6FC(void){
    func_8028A180(ANIM_BANJO_CROUCH_NOINPUT, 2.0f);
    D_8037D404 = 2;
}

void func_802AD728(void){
    func_8028A1F4(ANIM_BANJO_CROUCH, 0.5f, 0.9999f);
    func_8029E3C0(2, 2.0f);
    D_8037D404 = 1;
}

void func_802AD768(AnimCtrl *aCtrl, f32 arg1){
    animctrl_setDuration(aCtrl, ml_map_f(arg1, 0.0f, 180.0f, 0.5, 0.2f));
}

void func_802AD7B0(AnimCtrl *aCtrl){
    func_8029AD28(0.41f, 4);
    func_8029AD28(0.91f, 3);
}

void bscrouch_init(void){
    AnimCtrl *aCtrl = player_getAnimCtrlPtr();
    f32 sp28[3];
    f32 sp24;
    f32 sp20;

    switch(bs_getPrevState()){
        case BS_EGG_HEAD:
        case BS_EGG_ASS:
        case BS_WONDERWING_ENTER:
            sp24 = 0.5357f;
            break;
        default:
            sp24 = 0.0f;
            break;
    }
    animctrl_reset(aCtrl);
    animctrl_setIndex(aCtrl, ANIM_BANJO_CROUCH_ENTER);
    animctrl_setDuration(aCtrl, 0.5f);
    animctrl_setPlaybackType(aCtrl,  ANIMCTRL_ONCE);
    func_8028774C(aCtrl, sp24);
    func_802875AC(aCtrl, "bscrouch.c", 0xa0);
    func_80289F10(1);
    func_802991A8(3);
    func_80299234(350.0f, 14.0f);
    func_8029957C(7);
    func_8029932C(8.0f);
    func_802978DC(3);
    func_8029E3C0(0, 0.7f);
    func_8029E3C0(1, 0.2f);
    _get_velocity(&sp28);
    D_8037D400 = gu_sqrtf(sp28[0]*sp28[0] + sp28[2]*sp28[2]);
    if(140.0f < D_8037D400)
        func_80299AAC();

    if(func_8025801C(sp28, &sp20))
        func_8029797C(sp20);

    D_8037D404 = 0;
}

void bscrouch_update(void){
    enum bs_e sp34 = 0;
    f32 sp30;
    AnimCtrl *aCtrl = player_getAnimCtrlPtr(); //sp2C
    f32 temp_f2;
    f32 pad;
    f32 sp20;

    func_8029E1A8(0);
    func_8029E1A8(1);
    
    sp30 = ml_map_f(func_8029E270(0), 0.0f, 0.3f, 0.0f, D_8037D400);
    func_80297970(sp30);
    if(220.0f < sp30)
        func_802929F8();
    if(160.0f < sp30)
        func_80299AAC();
    sp20 = yaw_getIdeal();
    temp_f2 = mlAbsF(mlDiffDegF(sp20, yaw_get()));
    
    switch(D_8037D404){
        case 0://802ADA64
            if(sp30 != 0.0f)
                break;
            func_8029E3C0(2, 2.0f);
            D_8037D404 = 1;
            break;

        case 1: //802ADA98
            if(temp_f2 != 0.0f){
                func_802AD6D0();
            }
            else{
                func_8029E1A8(2);
                if(func_8029E384(2))
                    func_802AD6FC();
            }
            break; 

        case 2: //802ADAE8
            if(temp_f2 != 0.0f){
                func_802AD6D0();
            }else{
                if(animctrl_isStopped(aCtrl))
                    func_802AD728();
            }
            break;

        case 4: //802ADB30
            func_802AD768(aCtrl,temp_f2);
            func_802AD7B0(aCtrl);

            if(temp_f2 != 0.0f)
                break;

            if((f64)func_802877D8(aCtrl) <= 0.5){
                animctrl_setSubRange(aCtrl, 0.0f, 0.5f);
            }else{
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
            }
            animctrl_setPlaybackType(aCtrl,1);
            D_8037D404 = 3;
            break;

        case 3://802ADBCC
            func_802AD768(aCtrl, temp_f2);
            func_802AD7B0(aCtrl);
            if(temp_f2 != 0.0f){
                animctrl_setSubRange(aCtrl, 0.0f, 1.0f);
                animctrl_setPlaybackType(aCtrl,  ANIMCTRL_LOOP);
                D_8037D404 = 4;
            }else{
                if(animctrl_isStopped(aCtrl)){
                    yaw_setIdeal(yaw_get());
                    func_802AD728();
                }
            }
            break;
    }//L802ADC50

    if(player_isSliding())
        sp34 = BS_SLIDE;

    if(func_8028B094())
        sp34 = BS_FALL;

    sp34 = func_802ADCD4(sp34);
    if(sp34 == BS_IDLE && func_8029E348(1))
        sp34 = 0;

    if(player_inWater())
        sp34 = BS_SWIM_IDLE;

    bs_setState(sp34);
}//*/

void bscrouch_end(void){}

enum bs_e func_802ADCD4(enum bs_e arg0){
    if(button_released(BUTTON_Z)){
        arg0 = BS_IDLE;
        
        if(button_pressed(BUTTON_B) && can_claw())
            arg0 = BS_CLAW;

        if(button_pressed(BUTTON_A))
            arg0 = func_8029C780();

    }else{
        if(should_wonderwing())
            func_80346C10(&arg0, -1, BS_WONDERWING_ENTER, ITEM_GOLD_FEATHER, 1);

        if(should_trot())
            arg0 = BS_BTROT_ENTER;

        if(should_poop_egg())
            func_80346C10(&arg0, -1, BS_EGG_ASS, ITEM_EGGS, 0);

        if(should_shoot_egg())
            func_80346C10(&arg0, -1, BS_EGG_HEAD, ITEM_EGGS, 0);

        if(should_flip())
            arg0 = BS_BFLIP;

        if(should_beak_barge())
            arg0 = BS_BBARGE;


    }
    return arg0;
}
