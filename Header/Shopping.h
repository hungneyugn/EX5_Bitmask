/*
*File: Shopping.h
*Author: Nguyen Phi Hung
*Date: 18/03/2023
*Description: File header for acting when shopping
*/
#ifndef __SHOPPING_H
#define __SHOPPING_H

#include<stdio.h>
#include<stdint.h>

/* enum uses bitmask to assign each item to a bit in the binary code 8 bit*/
typedef enum DO_DUNG_CA_NHAN{
    AO          = 1<<0,
    QUAN        = 1<<1,
    VAY         = 1<<2,
    DAM         = 1<<3,
    NHAN        = 1<<4,
    VONG_TAY    = 1<<5,
    GIAY        = 1<<6,
    TUI         = 1<<7
}DO_DUNG_CA_NHAN;

/*Function return name of item*/
char* check_Name(int index);

/*Function add item into Cart*/
void addToCart(uint8_t *gio_hang, uint8_t ten_do_dung);

/*Function remove item from cart*/
void removeFromCart(uint8_t *gio_hang, uint8_t ten_do_dung);

/*Function convert decimal to binary*/
void convertToBinary(uint8_t ten_do_dung,char* arr);

/*Function to check item in cart*/
void checkItems(uint8_t gio_hang, uint8_t ten_do_dung);

/*Function display items in cart*/
void displayCart(uint8_t gio_hang);

#endif
