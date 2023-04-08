/*
*File: main.c
*Author: Nguyen Phi Hung
*Date: 18/03/2023
*Description: Shopping use bitmask
*/
#include<Shopping.h>

uint8_t GIO_HANG; 

int main()
{
    addToCart(&GIO_HANG,NHAN|AO|GIAY|TUI);
    displayCart(GIO_HANG);
    checkItems(GIO_HANG, NHAN|AO|VONG_TAY);
    removeFromCart(&GIO_HANG,AO);
    displayCart(GIO_HANG);
    checkItems(GIO_HANG, AO); 
    return 0;
}