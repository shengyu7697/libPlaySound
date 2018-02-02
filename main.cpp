#include <stdio.h>
#include "playsound.h"

int main(int argc, const char *argv[])
{
	printf("begin\n");

	for (int i = 0; i < 5; i++) {
		printf("play\n");
		playSound("shutter.wav");
	}

    printf("end\n");

    return 0;
}
