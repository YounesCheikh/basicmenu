
/***
* example.c
* Author: Younes CHEIKH 
* Email: contact [at] cyounes [dot] com
*
* 25/09/2012
* This is un example show you how to use basicmenu library
***/

#include <stdio.h>
#include "basicmenu.h" // Don't forget to include the baiscmenu.h file

void displayBeforeMenu(void) {
        printf("This message will be displayed before the menu ! \n");
        printf("welcome to basimenu library\n");
        printf("the fatest way to insert menu in your console application\n\n\n" );
}


void displayAfterMenu(void) {
        printf("\n\nThis message will be displayed after the menu ! \n");
        printf("i hope this will help you :) \n");
}

int main(void) {
        // Start the basic menu
        startBasicMenu();
        // Creat a new menu
        custom_Menu* mymenu;
        // Initialize a menu
        init_new_menu (&mymenu);
        // Add some items to the menu
        addNewItem (&mymenu , "Choice number one!");
        addNewItem (&mymenu , "Choice number 2");
        addNewItem (&mymenu , "Choice number three");
        addNewItem (&mymenu , "The forth choice");
        addNewItem (&mymenu , "5th choice");
        addNewItem (&mymenu , "Choice 6");

        // menu preferences
        set_menu_padding(6);    // You can use menu_in_middle_ON() function 
        item_border_ON();       // enable border for each item
        BG_COLOR_ON(RED);       // The background color for the selected item
        FG_COLOR_ON(YELLOW);    // The forground color for the selected item
        BOLD_TEXT_ON();         // show bold text for the selected item
        // display the menu
        put_menu (mymenu,displayBeforeMenu,displayAfterMenu);

        // I prefer to disable all the preferences which i've enabled to display the menu
        BOLD_TEXT_OFF();
        FG_COLOR_OFF();
        BG_COLOR_OFF();
        item_border_OFF();
        set_menu_padding(0) ;   // set the padding 0

        return 0;
}

