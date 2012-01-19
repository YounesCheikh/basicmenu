
/**
 * \file basicmenu.h
 * \brief integrate a menu in your console application easily
 * \author Younes CHEIKH
 * \version 1.1
 * \date 14/12/11
 */


/*! \mainpage Documentation
 *
 * \section intro_sec Introduction
 *
 * The basicmenu.h is a library allow the programmer to create and display a menu easily in his console application. 
 *
 * \subsection ncurses_diff The difference between basic menu.h and menu.h
 *
 * The menu.h library is good, useful and more developed compared in basicmenu.h, but the problem is to use it, you need 
 * to master the most of ncurses functions, and when you use ncurses, you can't use the standard output and input functions 
 * as printf(), scanf() and system()...
 * \subsection SO So ?
 * with basicmenu.h you can integrate easily the menu and in the same time you can use all the standard functions normaly :)
 * \section install_sec Installation:
 * There is no installation required, you need just to download the <a href="download.html">basicmenu.h</a> file, include it in your code then start use the libray :)
 *
 * \section essential_functions essential functions: 
 * to use this library , you have just to learn about some basic functions
 * \subsection start_library 1/ Start the basic menu library :
 * first you need to tell the program that you will use the library <br />
 * to do this, invoke startBasicMenu() function in the beginning of the main. <br />
 * \subsection create_menu 2/ Create and initialize a new menu: 
 * to create a new menu you need to declare it with its type: custom_Menu* mymenu
 * then to initialize it with the init_new_menu() function: init_new_menu (&mymenu) ; 
 *
 * \subsection add_item 3/ Add a new item to the menu: 
 * any menu , need to have at least tow items. to add a new item to the menu use the addNewItem() function: <br />
 * addNewItem (&mymenu , "Choice number one!");<br />
 * addNewItem (&mymenu , "Choice number tow!");<br />
 * You can add unlimited number of items, but be careful to don't exceed the console size :)
 *
 * \subsection put_menu 4/ Put and display a menu into the program: 
 * to display the menu in the screen you need to invoke the put_menu() function.<br />
 * <b>example:</b> [ <a href="example1_8c-example.html">link</a> ]
 */


#ifndef _BASICMENU_H_
#define _BASICMENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


#define RIGHT_COLOR 0
/***********************************************/
/*                The Menu                     */
/***********************************************/

/**
 * \struct custom_Menu
 * \brief a strcuture for menu
 *
 * any item of the menu has:
 * string item[255],
 * the index number,
 * the adress of the pointer for the next item
 */

typedef struct custom_Menu {	
	char item[255]; /*!< string with max lenght 255 character. */
	int index; /*!< the index of the item */
	struct custom_Menu * last ; /*!< a pointer to the next item */
	
}custom_Menu;


/**
 * \fn void init_new_menu (custom_Menu** mymenu) 
 * \brief initialize the a new menu with a malloc
 *
 * \param mymenu The new menu that we want to initialize
 */
void init_new_menu (custom_Menu** mymenu);


/**
 * \fn int getch(void)
 * \brief get (or push back) characters from terminal keyboard
 * the program waits until the system passes text through to  the program.
 * 
 * \return The ascii code of the character passed by the keyboard.
 */
int getch(void) ;

/**
 * \fn int getTouch(void)
 * \brief the same function as int getch(void) but can distinct also the arrow keys
 * get (or push back) characters from terminal keyboard
 * the program waits until the system passes text through to  the program.
 * 
 * \return 300,301,302,303 for the (UP,DOWN,RIGHT,LEFT)keys else The ascii code of the character passed by the keyboard.
 */
int getTouch (void) ;

/*
 * Add new item the your menu
 */

/**
 * \fn void addNewItem (custom_Menu ** mymenu, char newItem[]) 
 * \brief add a new item to the menu
 *
 * \param mymenu The menu.
 * \param newItem[] the string of the new item.
 *
 */
void addNewItem (custom_Menu ** mymenu, char newItem[]) ;

/*
 * print the menu on the screen
 */

/**
 * \fn int put_menu (custom_Menu * mymenu, void (*before)(void), void (*after)(void))
 * \brief this function put the menu on the console
 * You can edit the before and the after functions as you like to be compatible with your program
 * \param mymenu the menu which you want to put
 * \param before the void function that print some thing before the menu in the screen
 * \param after the void function that print some thing after the menu in the screen
 * \return (int) the index of the item chosen by the user
 */
int put_menu (custom_Menu * mymenu, void (*before)(void), void (*after)(void)) ;


/**
 * \fn int put_menu_with (custom_Menu * mymenu )
 * \brief this function put the menu on the console with a specified paramaters
 * This function is the same as put_menu() function, but without the before and after functions as paramters
 * you can add a paramters to this function , then edit the code into function, where commented to add functions and 
 * procedures before the menu and after the menu
 * \param mymenu the menu which you want to put
 * \return (int) the index of the item chosen by the user
 */
//int put_menu_with (custom_Menu * mymenu /* , int a, char b, int liste[]... */ );


/**
 * \fn void startBasicMenu(void) 
 * \brief You must put this function in the begining of the main inorder to use this library correctly
 */
void startBasicMenu(void) ;

/*
 * this will be used to clear the console
 */
static void toPosition() ;

/***********************************************/
/*                  COLORS                     */
/***********************************************/

/**
 * \enum _COLOR_
 * \brief a liste of the colors avilable
 * 
 * With this enum , you can use a liste of colors as displayed
 * also you can use the index of each color as figured as param in the
 * BG_COLOR_ON() and FG_COLOR_ON() functions
 */
//typedef enum _COLOR_ _COLOR_;
typedef enum {
	BLACK,	/*!< number 0 */
	RED,	/*!< number 1 */
	GREEN,	/*!< number 2 */
	YELLOW,	/*!< number 3 */
	BLUE,	/*!< number 4 */
	MAGENTA,/*!< number 5 */
	CYAN,	/*!< number 6 */
	WHITE	/*!< number 7 */
}
_COLOR_ ;


/**
 * \enum BOOLEAN
 * \brief With this enum you don't must to include the stdbool.h to use false and true
 * Remark: with this enum you need to write <i>FALSE</i> and <i>TRUE</i> as <b>uppercase letters</b>
 */
typedef enum { 
	FALSE, /*!< Can be the integer 0 */
	TRUE  /*!< Can be the integer 1 */
} 
BOOLEAN;


static BOOLEAN _DYNAMIC_MENU = FALSE; /*!< this will be TRUE when you call the dynamic_menu_ON() function */
static int _WINDOW_LARGE = 0; /*!< The large of the window of terminal */

static int _MENU_PADDING = 0; /*!< You can set this with the set_menu_padding() function */

static BOOLEAN _SHOW_BOLD_TEXT =FALSE;

static int FGCOLOR, /*!< The forground chosed by the programer */
	BGCOLOR; /*!< The background chosed by the programer */


static BOOLEAN _CHANGE_FGCOLOR=FALSE, /*!< this will be set TRUE if you call the FG_COLOR_ON() function */
		_CHANGE_BGCOLOR=FALSE; /*!< this will be set TRUE if you call the FG_COLOR_ON() function */

static int _MAX_ITEMS ; /*!< The the number of items to display */

/** 
 * \fn void BG_COLOR_ON(_COLOR_ COLOR)
 * \brief activate the background for the selected item in the menu
 * this will display the selected item with diffrent background color
 * \param COLOR type _COLOR_ { 	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE } <br />
 * <b>Remark</b> : you can use numbers between [0,7] <br /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 * but if you use another the background color shouldn't be activated
 */
void BG_COLOR_ON(_COLOR_ COLOR);

/** 
 * \fn void FG_COLOR_ON(_COLOR_ COLOR)
 * \brief activate the forground for the selected item in the menu
 * this will display the selected item with diffrent forground color
 * \param COLOR type _COLOR_ { 	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE } <br />
 * <b>Remark</b> : you can use numbers between [0,7] <br /> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 * but if you use another the forground color shouldn't be activated
 */
void FG_COLOR_ON(_COLOR_ COLOR);

/** 
 * \fn void BG_COLOR_OFF()
 * \brief desactivate the background color for the selected item in the menu
 *
 */
void BG_COLOR_OFF();

/** 
 * \fn void FG_COLOR_OFF()
 * \brief desactivate the forground color for the selected item in the menu
 *
 */
void FG_COLOR_OFF();

/** 
 * \fn BOLD_TEXT_ON()
 * \brief show the selected item in bold
 *
 */
void BOLD_TEXT_ON();

/** 
 * \fn BOLD_TEXT_OFF()
 * \brief don't show the selected item in bold
 *
 */
void BOLD_TEXT_OFF();


/***********************************************/
/*               OTHER PREFERENCES             */
/***********************************************/

/* 
 * make the menu dynamic

 */

/**
 * \fn void dynamic_menu_ON()
 * \brief make the menu dynamic
 * when you want to select the next item after the latest
 * the first one will be selected automaticly
 */
void dynamic_menu_ON();

/**
 * \fn void dynamic_menu_OFF()
 * \brief desactivate the dynamically 
 * this must invoked only if the dynamic_menu_ON() function was invoked previously
 */
void dynamic_menu_OFF();


/**
 * \fn void menu_in_middle_ON()
 * \brief display the menu in the middle of the screen
 * <b>Remark</b> : this can't be invoked in the same time with the set_menu_padding() function <br />
 * The latest invoked one will disactivate the previous
 */
void menu_in_middle_ON();

/**
 * \fn void menu_in_middle_OFF()
 * \brief desactivate the display of the menu in the middle of the screen
 */
void menu_in_middle_OFF();

/**
 * \fn void set_menu_padding(int padding)
 * \brief Set the padding left to display the menu in the screen with a padding specified
 * <b>Remark</b> : this can't be invoked in the same time with the menu_in_middle_ON() function <br />
 * The latest invoked one will disactivate the previous
 * \param padding the number of rows (the padding)
 */
void set_menu_padding(int padding);

/**
 *\fn void set_max_items(int number)
 *\brief Set the maximum number of items to display in the menu
 * <b>Remark</b> : let number =0 if you want to display all the items
 * \param number the number of items to display in the menu
*/
void set_max_items(int number);

/**
 *\fn int get_max_items(void)
 *\brief get the maximum number of items to display in the menu
 * \return the number of items to display in the menu
 */
int get_max_items(void);

/*
 * The borders;
 */

static BOOLEAN _MENU_BORDER = FALSE, /*!< Will be true if you want to activate de border to all the menu <br />
							   edit this using the menu_border_ON() and menu_border_OFF() functions.
							   */
		_ITEM_BORDER = FALSE; /*!< Will be true if you want to activate de border to each item in the menu <br />
							   edit this using the item_border_ON() and item_border_OFF() functions.
							   */

/**
 * \fn menu_border_ON()
 * \brief switch on the menu border
 * this function switch off the item border
 */
void menu_border_ON() { _MENU_BORDER = TRUE; _ITEM_BORDER = FALSE; }

/**
 * \fn menu_border_OFF()
 * \brief switch off the menu border
 */
void menu_border_OFF() { _MENU_BORDER = FALSE; }

/**
 * \fn item_border_ON()
 * \brief switch on the border for each item in the menu
 * this function switch off the menu border
 */
void item_border_ON() { _ITEM_BORDER = TRUE; _MENU_BORDER = FALSE; }

/**
 * \fn item_border_OFF()
 * \brief switch off the border for each item in the menu
 */
void item_border_OFF() { _ITEM_BORDER = FALSE; }




/***********************************************/
/*                  FUNCTIONS                  */
/***********************************************/

void init_new_menu (custom_Menu** mymenu) {
	*mymenu = malloc (sizeof(*mymenu));
}

int getch(void) {
	
	struct termios to, t;
	
    tcgetattr (1, &t);
    to = t;
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr (1, 0, &t);
    char c;
    c=getchar () ;
    tcsetattr (1, 0, &to);
	
	return c;
}

int getTouch (void) {
	int keyUp = 300;
	int keyDown = 301;
	int keyRight = 302;
	int keyLeft = 303;
	int retVal;
	int code1,code2,code3;
	
	code1 = getch(); if (code1!=27) return code1; // si la touche differente de les 4 touches de direction
	code2 = getch(); if (code2!=91) return code2;
	code3 = getch(); 
	switch (code3) {
		case 65: {
			retVal = keyUp;
			break;
		}
		case 66: {
			retVal = keyDown;
			break;
		}
		case 67: {
			retVal = keyRight;
			break;
		}
		case 68: {
			retVal = keyLeft;
			break;
		}
		default: {
			retVal = code3;
			break;
		}	
	}
	
	return retVal;
}


void addNewItem (custom_Menu ** mymenu, char newItem[]) {
	
	custom_Menu *newItemTmp = malloc(sizeof *newItemTmp);
	if (newItemTmp != NULL)
	{
		strcpy (newItemTmp->item , newItem);
		newItemTmp->index = (*mymenu)->index+1;
		newItemTmp->last = *mymenu;
		*mymenu = newItemTmp;
	}
}


int put_menu (custom_Menu * mymenu, void (*before)(void), void (*after)(void)) {
	/* The longest string (item) */
	int THE_LONGEST_ITEM = 0;
	
	int listeSize = mymenu->index;
	
	/* A Finir pour la prochaine version */
	/*
	if (get_max_items() > listeSize ) {
		printf("error!");
		exit(-2);
	}
	*/
	char *liste[listeSize];
	int i,j; 
	for (i=0;i<listeSize;i++) {
		liste[i]= malloc(sizeof(mymenu->item));
	}
	
	custom_Menu * menuTmp = malloc(sizeof(*menuTmp));
	
	*menuTmp = *mymenu;
	
	while (menuTmp->last!=NULL) {
		//printf("[%d] %s\n",menuTmp->index, menuTmp->item);
		strcpy (liste[menuTmp->index-1], menuTmp->item);
		if(strlen(liste[menuTmp->index-1]) >THE_LONGEST_ITEM)
			THE_LONGEST_ITEM = strlen(liste[menuTmp->index-1]);
		menuTmp = menuTmp->last;
	}
	int retVal;
	BOOLEAN outOf = FALSE;
	int currentItem=1;
	int userChoice;
	do {
		toPosition();
		before();
		if (_MENU_BORDER==TRUE || _ITEM_BORDER==TRUE) {
			for (j=0; j<_MENU_PADDING; j++ )
				printf(" ");
			printf("+");
			for(j=_MENU_PADDING; j<_MENU_PADDING+THE_LONGEST_ITEM+6; j++)
				printf("-");
			printf("+\n");
		}
		for (i=0; i<listeSize; i++) {
			if (_WINDOW_LARGE != 0) {
				int row;
				for (row = 0 ; row < _WINDOW_LARGE-(strlen(liste[i]))/2 ; row++)
					printf(" ");
			}
			else if (_MENU_PADDING !=0) {
				int row;
				for (row = 0 ; row < _MENU_PADDING ; row++)
					printf(" ");
			}
			if (currentItem==i+1)
			{
				if (_MENU_BORDER || _ITEM_BORDER) printf("| ");
				if (_CHANGE_BGCOLOR) printf("\033[%dm",BGCOLOR);
				if (_CHANGE_FGCOLOR) printf("\033[%dm",FGCOLOR);
				if (_SHOW_BOLD_TEXT) printf("\033[1m");
				printf("[*] %s",liste[i]);
				if (_SHOW_BOLD_TEXT) printf("\033[0m");
				if (_CHANGE_FGCOLOR) printf("\033[0m");
				if (_CHANGE_BGCOLOR) printf("\033[0m");
				
				if (_MENU_BORDER || _ITEM_BORDER) {
					for(j=_MENU_PADDING+strlen(liste[i])+4; j<_MENU_PADDING+THE_LONGEST_ITEM+4;j++ )
						printf(" ");
					printf(" |\n");
				}
				else printf("\n");
			}
			else
			{	
				if (_MENU_BORDER || _ITEM_BORDER) {
					printf("| [ ] %s",liste[i]);
					for(j=_MENU_PADDING+strlen(liste[i])+4; j<_MENU_PADDING+THE_LONGEST_ITEM+4;j++ )
						printf(" ");
					printf(" |\n");
				}
				else 
					printf("[ ] %s\n",liste[i]);
			}
			if (_ITEM_BORDER) {
				for (j=0; j<_MENU_PADDING; j++ )
					printf(" ");
				printf("+");
				for(j=_MENU_PADDING; j<_MENU_PADDING+THE_LONGEST_ITEM+6; j++)
					printf("-");
				printf("+\n");
			}
		} // end of for
		if (_MENU_BORDER) {
			for (j=0; j<_MENU_PADDING; j++ )
				printf(" ");
			printf("+");
			for(j=_MENU_PADDING; j<_MENU_PADDING+THE_LONGEST_ITEM+6; j++)
				printf("-");
			printf("+\n");
		}
		
		
		after();
		userChoice = getTouch();
		switch(userChoice) {
			case 300: {
				if (currentItem>1)
					currentItem--;
				else {
					if (_DYNAMIC_MENU == TRUE) 
						currentItem= listeSize;
				}
				break;
			}
			case 301: {
				if (currentItem<listeSize) 
					currentItem++;
				else {
					if (_DYNAMIC_MENU==TRUE)
						currentItem=1;
				}
				break;
			}
			default : {
				if (userChoice == '\n' || userChoice=='\r') {
					retVal = currentItem;
					outOf = TRUE;
				}
				break;
			}
		}
	}while (!outOf);
	
	return(retVal);
}


int put_menu_with (custom_Menu * mymenu /* , int a, char b, int liste[]... */ ) {
	/* The longest string (item) */
	int THE_LONGEST_ITEM = 0;
	
	int listeSize = mymenu->index;
	//printf("%d\n",listeSize);
	char *liste[listeSize];
	int i,j; 
	for (i=0;i<listeSize;i++) {
		liste[i]= malloc(sizeof(mymenu->item));
	}
	
	custom_Menu * menuTmp = malloc(sizeof(*menuTmp));
	
	*menuTmp = *mymenu;
	
	while (menuTmp->last!=NULL) {
		strcpy (liste[menuTmp->index-1], menuTmp->item);
		if(strlen(liste[menuTmp->index-1]) >THE_LONGEST_ITEM)
			THE_LONGEST_ITEM = strlen(liste[menuTmp->index-1]);
		menuTmp = menuTmp->last;
	}
	int retVal;
	BOOLEAN outOf = FALSE;
	int currentItem=1;
	int userChoice;
	do {
		toPosition();
		/**************************************/
			// put your code here to display
			// any thing before the menu
		/**************************************/
		
		if (_MENU_BORDER==TRUE || _ITEM_BORDER==TRUE) { // If the border is activated
			// put the border
			for (j=0; j<_MENU_PADDING; j++ )
				printf(" ");
			printf("+");
			for(j=_MENU_PADDING; j<_MENU_PADDING+THE_LONGEST_ITEM+6; j++)
				printf("-");
			printf("+\n");
		}
		for (i=0; i<listeSize; i++) {
			if (_WINDOW_LARGE != 0) {
				int row;
				for (row = 0 ; row < _WINDOW_LARGE-(strlen(liste[i]))/2 ; row++)
					printf(" ");
			} // end of if _WINDOW_LARGE != 0
			else if (_MENU_PADDING !=0) {
				int row;
				for (row = 0 ; row < _MENU_PADDING ; row++)
					printf(" ");
			} // end of elseif _MENU_PADDING != 0
			if (currentItem==i+1)
			{
				if (_MENU_BORDER || _ITEM_BORDER) printf("| ");
				if (_CHANGE_BGCOLOR) printf("\033[%dm",BGCOLOR);
				if (_CHANGE_FGCOLOR) printf("\033[%dm",FGCOLOR);
				if (_SHOW_BOLD_TEXT) printf("\033[1m");
				printf("[*] %s",liste[i]);
				if (_SHOW_BOLD_TEXT) printf("\033[0m");
				if (_CHANGE_FGCOLOR) printf("\033[0m");
				if (_CHANGE_BGCOLOR) printf("\033[0m");
				if (_MENU_BORDER || _ITEM_BORDER) {
					for(j=_MENU_PADDING+strlen(liste[i])+4; j<_MENU_PADDING+THE_LONGEST_ITEM+4;j++ )
						printf(" ");
					printf(" |\n");
				}
				else printf("\n");
			}
			else
			{	
				if (_MENU_BORDER || _ITEM_BORDER) {
					printf("| [ ] %s",liste[i]);
					for(j=_MENU_PADDING+strlen(liste[i])+4; j<_MENU_PADDING+THE_LONGEST_ITEM+4;j++ )
						printf(" ");
					printf(" |\n");
				}
				else 
					printf("[ ] %s\n",liste[i]);
			}
			if (_ITEM_BORDER) {
				for (j=0; j<_MENU_PADDING; j++ )
					printf(" ");
				printf("+");
				for(j=_MENU_PADDING; j<_MENU_PADDING+THE_LONGEST_ITEM+6; j++)
					printf("-");
				printf("+\n");
			}
		} // end of for
		if (_MENU_BORDER) {
			for (j=0; j<_MENU_PADDING; j++ )
				printf(" ");
			printf("+");
			for(j=_MENU_PADDING; j<_MENU_PADDING+THE_LONGEST_ITEM+6; j++)
				printf("-");
			printf("+\n");
		}
		
		
		/**************************************/
		// put your code here to display
		// any thing after the menu
		/**************************************/
		
		
		userChoice = getTouch();
		switch(userChoice) {
			case 300: {
				if (currentItem>1)
					currentItem--;
				else {
					if (_DYNAMIC_MENU == TRUE) 
						currentItem= listeSize;
				}
				break;
			}
			case 301: {
				if (currentItem<listeSize) 
					currentItem++;
				else {
					if (_DYNAMIC_MENU==TRUE)
						currentItem=1;
				}
				break;
			}
			default : {
				if (userChoice == '\n' || userChoice=='\r') {
					retVal = currentItem;
					outOf = TRUE;
				}
				break;
			}
		}
	}while (!outOf);
	
	return(retVal);
}



void startBasicMenu(void) {
	system("clear");
	printf("\033[s");
}

void toPosition() {
	struct winsize w;
	printf("\033[u");
	ioctl(0, TIOCGWINSZ, &w);
	int line, column;
	for (line=0;line<w.ws_row;line++) {
		for (column=0;column<w.ws_col;column++) {
			printf(" ");
		}
	}
	printf("\033[u");
}


void BG_COLOR_ON(_COLOR_ COLOR) {
	
	switch (COLOR) {
		case (BLACK):
		{
			BGCOLOR = 40;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		case RED:
		{
			BGCOLOR = 41;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		case GREEN:
		{
			BGCOLOR = 42;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		case YELLOW:
		{
			BGCOLOR = 43;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		case BLUE:
		{
			BGCOLOR = 44;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		case MAGENTA:
		{
			BGCOLOR = 45;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		case CYAN:
		{
			BGCOLOR = 46;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		case WHITE:
		{
			BGCOLOR = 47;
			_CHANGE_BGCOLOR = 1;
			break;
		}
		default: 
		{ 
			break;
		}
	}
}

void FG_COLOR_ON(_COLOR_ COLOR) {
	
	switch (COLOR) {
		case BLACK:
		{
			FGCOLOR = 30;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		case RED:
		{
			FGCOLOR = 31;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		case GREEN:
		{
			FGCOLOR = 32;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		case YELLOW:
		{
			FGCOLOR =33;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		case BLUE:
		{
			FGCOLOR = 34;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		case MAGENTA:
		{
			FGCOLOR = 35;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		case CYAN:
		{
			FGCOLOR = 36;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		case WHITE:
		{
			FGCOLOR = 37;
			_CHANGE_FGCOLOR = 1;
			break;
		}
		default: 
		{
#undef RIGHT_COLOR
#define RIGHT_COLOR 0
			break;
		}
	}
}

void FG_COLOR_OFF() { _CHANGE_FGCOLOR = 0; }
void BG_COLOR_OFF() { _CHANGE_BGCOLOR = 0; }

void dynamic_menu_ON() { _DYNAMIC_MENU = TRUE; }
void dynamic_menu_OFF() { _DYNAMIC_MENU = FALSE; }

void menu_in_middle_ON() {
	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w); 
	_WINDOW_LARGE = w.ws_col/2 ;
}
void menu_in_middle_OFF() { _WINDOW_LARGE = 0; }

void set_menu_padding(int padding) { _MENU_PADDING = padding; }

void BOLD_TEXT_ON() {
	_SHOW_BOLD_TEXT = TRUE;
}

void BOLD_TEXT_OFF() {
	_SHOW_BOLD_TEXT = FALSE;
}


void set_max_items(int number) {
	_MAX_ITEMS = number;
}


int get_max_items() {
	return _MAX_ITEMS;
}

/*************************************/
/*          How to                   */
/*************************************/



/*! \page download Download
 * you can find here all the versions: <a href="https://sourceforge.net/projects/basicmenu/files/"> sourceforge </a>
 or choose a version below :
 \section sec_latest The latest version : 
 <a href="https://sourceforge.net/projects/basicmenu/files/1.0.0/"> basicmenu-1.0.0.tar.gz </a>
 \subsection Other Other versions:
 There is no previous versions!
 */

 /** 
  * \example example1.c 
  * \example show_bg_color.c
  * \example show_fg_color.c
  * \example show_bold_text.c
  * \example items_border.c
  * \example menu_border.c
  * \example menu_in_middle.c
  * \example set_menu_padding.c
  */

#if RIGHT_COLOR 
#warning error paramaters
#endif


#endif /* _BASICMENU_H_ */


