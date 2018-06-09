//
//  checkSystemState.h
//  checkSystemState
//
//  Created by abhinash jain on 21/10/16.
//  Copyright © 2016 abhinash jain. All rights reserved.
//

#import <UIKit/UIKit.h>
int checkFileAccess(char* name);
int checkFileStat(char* name);
int spawnProcess();
int loadedLibraries();
int checkFileExistence(char* name);
int ttySerialPort();


//! Project version number for checkSystemState.
FOUNDATION_EXPORT double checkSystemStateVersionNumber;

//! Project version string for checkSystemState.
FOUNDATION_EXPORT const unsigned char checkSystemStateVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <checkSystemState/PublicHeader.h>


