#BasicMenu Library


		______           _     ___  ___                 
		| ___ \         (_)    |  \/  |                 
		| |_/ / __ _ ___ _  ___| .  . | ___ _ __  _   _ 
		| ___ \/ _` / __| |/ __| |\/| |/ _ \ '_ \| | | |
		| |_/ / (_| \__ \ | (__| |  | |  __/ | | | |_| |
		\____/ \__,_|___/_|\___\_|  |_/\___|_| |_|\__,_|                                             
                                               


[Basicmenu](http://cyounes.com/projects/basicmenu) is a an open source library coded in C, allows the programmer to create and display a menu easily in his/her console application on linux and mac os x, works with C/C++ programs.

### Example of program uses basicmenu library
![BasicMenu Library](http://cyounes.com/portail_files/Screen-Shot-2012-09-26-at-01.27.19.png)


##Installation:

There is no installation required, you need just to download the basicmenu.h file, include it in your code then start use the libray :)

	#include "basicmenu.h"

##Essential functions:

To use this library , you have just to learn about some basic functions

### 1. Start the basic menu library :

First you need to tell the program that you will use the library 
to do this, invoke `startBasicMenu()` function in the beginning of the main.

 
### 2. Create and initialize a new menu:

To create a new menu you need to declare it with its type: 
	custom_Menu* mymenu; 
To initialize it with the `init_new_menu()` function: 
	init_new_menu (&mymenu);

### 3. Add a new item to the menu:

Any menu , need to have at least tow items, to add a new item to the menu use the `addNewItem()` function: 
	addNewItem (&mymenu , "Choice number one!");
	addNewItem (&mymenu , "Choice number tow!");
You can add unlimited number of items, but be careful to don't exceed the console size :) 
> see the TODO list.

### 4. Put and display a menu into the program:

To display the menu you need to invoke the `put_menu()` function.
example: [Link](http://cyounes.com/basicmenu/doc/example1_8c-example.html)

## TODO:

+ Allow the programmer to add unlimited items to the menu.
+ Add a scroll menu option.
+ Add the maximum of items to shown on the menu.

## Useful functions:

- [item\_border\_ON()](http://cyounes.com/basicmenu/doc/basicmenu_8h.html#af25248c9cb3d0736be1409117da84682) & [item\_border\_OFF()](http://cyounes.com/basicmenu/doc/basicmenu_8h.html#a1c21c2b1ab331a2c67ef05a9284218da)
- [menu\_border\_ON()](http://cyounes.com/basicmenu/doc/basicmenu_8h.html#a704a37ae8f690f7a54186ee146309cb6) &  [menu\_border\_OFF()](http://cyounes.com/basicmenu/doc/basicmenu_8h.html#a0d9a10f8ced566cb797395039f35fb9d);
- [BG\_COLOR\_ON()](http://cyounes.com/basicmenu/doc/basicmenu_8h.html#ad089e1df4782b887c8eefe307bd42fd4) & [BG\_COLOR\_OFF()](http://cyounes.com/basicmenu/doc/basicmenu_8h.html#a538de9d0a829e45b7fe3d7930bc81a03)

>for more functions and examples please visit [this page](http://cyounes.com/basicmenu/doc/examples.html)


## Are you a developer? Fork me on GitHub

I'll be very happy to take pull requests from others, Go ahead and fork me.

### Documentation: 

for code documentation please visit  <http://cyounes.com/basicmenu/doc/index.html>

