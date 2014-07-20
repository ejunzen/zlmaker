#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "genorate.h"
#include <unistd.h>

static char* partnerName;

void printUsage(){
	fprintf(stdout,"zlmaker -p <channelName>\n");
	fprintf(stdout,"zlmaker -p jinjiang\n");
	exit(127);
}

int main(int argc ,char* argv[]){

	if(argc != 3){
		fprintf(stderr,"parameter error, please see usage!\n");
		printUsage();
	}

	char ch; 

    while ((ch = getopt(argc, argv, "vp:")) != EOF) {
        switch(ch){
            case 'v':
                printUsage();
                break;
            case 'p':
                partnerName = optarg;
                break;
            default:
                break;
        }   
    }   

	if(partnerName == NULL){
		printUsage();
	}	

	genorateRoomStatusSyncService(partnerName);

	return 0;
}
