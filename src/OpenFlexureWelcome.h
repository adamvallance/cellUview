#ifndef OPENFLEXURE_WELCOME_H
#define OPENFLEXURE_WELCOME_H
#include <stdlib.h>
#include <stdio.h>
#include "iostream"

class OpenFlexureWelcome {
    public:
        

        static void welcomeMessage() {
            printf(" _______ _______ _______ _       _______ _       _______                 _______ _______ _    \n"
		   "(  ___  (  ____ (  ____ ( (    /(  ____ ( \\     (  ____ |\\     /|\\     /(  ____ (  ____ ( )   \n"
		   "| (   ) | (    )| (    \\|  \\  ( | (    \\| (     | (    \\( \\   / | )   ( | (    )| (    \\| |   \n"
		   "| |   | | (____)| (__   |   \\ | | (__   | |     | (__    \\ (_) /| |   | | (____)| (__ __| |__ \n" 
		   "| |   | |  _____|  __)  | (\\ \\) |  __)  | |     |  __)    ) _ ( | |   | |     __|  __(__   __) \n"
		   "| |   | | (     | (     | | \\   | (     | |     | (      / ( ) \\| |   | | (\\ (  | (     | |   \n"
		   "| (___) | )     | (____/| )  \\  | )     | (____/| (____/( /   \\ | (___) | ) \\ \\_| (____/| |   \n"
		   "(_______|/      (_______|/    )_|/      (_______(_______|/     \\(_______|/   \\__(_______(_)   \n"
                   "\nWelcome to OpenFlexure, how many swimmers do you think you have?");
        }//note that the \ have been replaced with \\ to escape them. To regenerate go to https://patorjk.com/software/taag/#p=display&h=3&v=2&f=Epic&t=OpenFlexure%2B
};


#endif //OPENFLEXURE_WELCOME_H
