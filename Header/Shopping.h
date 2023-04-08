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

/*
*Function: check_Name
*Desciption: check name of item or cart
*Input: 
    index: position in a 8 bit binary
*Output:
    Name of item
*/
char* check_Name(int index)
{
    switch (index)
    {
    case 0:
        return "AO";
        break;
    case 1:
        return "QUAN";
        break;
    case 2:
        return "VAY";
        break;
    case 3:
        return "DAM";
        break;
    case 4:
        return "NHAN";
        break;
    case 5:
        return "VONG_TAY";
        break;
    case 6:
        return "GIAY";
        break;
    case 7:
        return "TUI";
        break;    
    }
}
/*
*Function: addToCart
*Description: add item to cart
*Input:
    gio_hang: Pointer to a 8 bit binary
    ten_do_dung: item need add to cart
*Output: None
*/
void addToCart(uint8_t *gio_hang, uint8_t ten_do_dung)
{
    *gio_hang |= ten_do_dung;
}
/*
*Function: removeFromCart
*Description: remove item from cart
*Input:
    gio_hang: Pointer to a 8 bit binary
    ten_do_dung: item need to be added to cart
*Output: None
*/
void removeFromCart(uint8_t *gio_hang, uint8_t ten_do_dung)
{
    *gio_hang &= ~ten_do_dung;
}
/*
*Function: convertToBinary
*Description: value of items is decimal so need to be converted to binary to compare
*Param: 
    ten_do_dung (input): value of items need to be converted
    arr (output): String binary code 8 bit
*/
void convertToBinary(uint8_t ten_do_dung,char* arr)  
{ 
    int i = 0;
    while(ten_do_dung > 0)
    {
        *(arr + i) = ten_do_dung%2;             
        i++;
        ten_do_dung = ten_do_dung/2;
    }
    for(int k = i+1;k<7;k++)
    {
        *(arr + k) = 0;
    }
}
/*
*Function: checkItems
*Description: Check if items are in cart or not
*Input: 
    gio_hang: String binay 8 bit
    ten_do_dung: items need to be checked
*Output:
    inform items are in cart or not
*/
void checkItems(uint8_t gio_hang, uint8_t ten_do_dung)
{
    /*String save binary code of items need to bed checked*/
    char binaryItems[8];
    /*String save binary code of Cart*/
    char binaryCart[8];
    convertToBinary(ten_do_dung,binaryItems);                             
    convertToBinary(gio_hang, binaryCart); 
    /*Compare two binary code between items and cart*/                                     
    for(int i =0; i<8;i++)
    {
        if(binaryItems[i]==1)                                                     
        {
            if(binaryCart[i] ==1 )printf("%s co trong gio hang\n",check_Name(i));
            else printf("%s khong co trong gio hang\n",check_Name(i));
        }
    }
}
/*
*Function: displayCart
*Discription: display items in cart
*Input: 
    gio_hang: String binary 8 bit save items added
*Ouput: 
    Name of items in cart 
*/
void displayCart(uint8_t gio_hang)
{
    char binaryCart[8];
    if(gio_hang ==0)printf("Gio hang trong\n");
    else
    {
        int STT =0;
        printf("---------------------------------\n");
        printf("Gio hang gom co:\n");
        printf("STT\t TEN\n");
        convertToBinary(gio_hang, binaryCart);
        for(int i =0; i<8;i++)
        {
            if(binaryCart[i]==1)
            {
                STT += 1;
                printf("%d\t %s\n",STT,check_Name(i));
            }
        }
    }  
}

#endif
