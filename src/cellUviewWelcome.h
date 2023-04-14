#ifndef CELLUVIEW_WELCOME_H
#define CELLUVIEW_WELCOME_H
#include <stdlib.h>
#include <stdio.h>
#include "iostream"

class cellUviewWelcome {
    public:
        

        static void welcomeMessage() {
            printf("     ______  _______  __       __       __    __  ____    ____  __   ___________    __    ____ \n");
            printf("    /      ||   ____||  |     |  |     |  |  |  | \\   \\  /   / |  | |   ____\\   \\  /  \\  /   / \n");
            printf("   |  ,----'|  |__   |  |     |  |     |  |  |  |  \\   \\/   /  |  | |  |__   \\   \\/    \\/   /  \n");
            printf("   |  |     |   __|  |  |     |  |     |  |  |  |   \\      /   |  | |   __|   \\            /   \n");
            printf("   |  `----.|  |____ |  `----.|  `----.|  `--'  |    \\    /    |  | |  |____   \\    /\\    /    \n");
            printf("    \\______||_______||_______||_______| \\______/      \\__/     |__| |_______|   \\__/  \\__/     \n");
                                                                                            
                   printf("Welcome to cellUview, a real time image processing and analysis suite for digital microscopy.\n");
        }//note that the \ have been replaced with \\ to escape them. To regenerate go to https://patorjk.com/software/taag/#p=display&h=3&v=2&f=Epic&t=cellUview%2B
};


#endif //CELLUVIEW_WELCOME_H
