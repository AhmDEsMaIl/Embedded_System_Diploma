/*
 * Array_Service.h
 *
 * Created: 10/10/2023 9:11:16 PM
 *  Author: ahmed
 */ 


#ifndef ARRAY_SERVICE_H_
#define ARRAY_SERVICE_H_
#include "StdTypes.h"

void Array_countSort_mono(u16*arr,u16 size);
void Array_selectionSort_1(u16*arr,u16 size);
void Array_swap_Two_element (u16* px, u16* py);
u16 Array_findmax(u16*arr,u16 size);
u16  Array_max_min(u16 *arr,u16 s,u16*x, u16*y);
void Array_selectionSort_2(u16*arr,u16 size);
void Array_BubbleSort(u16*arr,u16 size);
u16 Array_mostRepeated_Frequency_array(u16*arr,u16 size,u16*pnum);
u16 Array_repeated_number(u16 *arr,u16 s);
u16 Array_count_given_number_in_array(u16 *ar,u16 s,u16 numb);
u16 Array_mostRepeated_sorted(u16 *arr,u16 size,u16 *pnum);
u16 array_binarySearch(u16*arr,u16 size,u16 num);
void Array_revse(u16 *arr,u16 s);
void  Array_Two_array_swap_With_Small_Size (u16 *arr,u16 *ar,u16 s1, u16 s2);
u16 Array_longest_consecutive_in_given_array (u16 *arr ,u16 s,u16*p1);
u16 Array_merging_Two_Array_With_Big_Array (u16 *arr,u16 s1,u16 *ar,u16 s2, u16 *a,u16 s3);





#endif /* ARRAY_SERVICE_H_ */