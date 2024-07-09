/*
 * Math_Service.h
 *
 * Created: 10/10/2023 8:58:36 PM
 *  Author: ahmed
 */ 


#ifndef MATH_SERVICE_H_
#define MATH_SERVICE_H_
#include "StdTypes.h"

u8 Math_Is_number_baseof2_1(u16  n);
u8 Math_Is_number_baseof2_2(u16  n);
u8 Math_Is_number_baseof2_3(u16  n);
void Math_max_min_for_TWO_numbers_return_Two_pou16ers(u16 x,u16 y ,u16 *m,u16 *n );
u16 Math_Mul_by_addation (u16 x,u16 y);
u16 Math_remd_by_Mul_DivD(u16 x,u16 y);
u16 Math_power_By_Mul(u16 x,u16 y);
u16 Math_factorial (u16 x);
u8 Math_Is_Number_prime (u16 x);
u16 Math_Is_Number_prefectsquare (u16 x);
u8 Math_sum_of_digits_of_Number (u16 x);
u16 Math_revese_number (u16 x);
u16 Math_Is_Number_power_of_3(u16 x);





#endif /* MATH SERVICE_H_ */