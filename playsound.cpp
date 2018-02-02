#include <stdio.h>
#include <stdlib.h>
#include <string>

#if defined(__WIN32__) || defined(_WIN32)
#include <Windows.h>
#endif

using namespace std;

void shellCmd(const char *cmd);

#if defined(__WIN32__) || defined(_WIN32)
void shellCmd(const char *cmd) {
	printf("ShellCmd: %s\n", cmd);
}
#else
void shellCmd(const char *cmd) {
//	printf("ShellCmd: %s\n", cmd);
	FILE *pp;
	if ((pp = popen(cmd, "r")) == NULL) {
		return;
	}
	pclose(pp);
}
#endif

void playSound(const char *filename)
{
#if defined(__WIN32__) || defined(_WIN32)
	PlaySound(filename, NULL, SND_FILENAME);
#elif defined(__unix__) || defined(__unix)
	string cmd = "";
	cmd = cmd + "aplay " + filename + " &";
	shellCmd(cmd.c_str());
#elif defined(__APPLE__) || defined(__MACH__)
	//shellCmd("killall afplay");
	string cmd = "";
	cmd = cmd + "afplay " + filename + " &";
	shellCmd(cmd.c_str());
#endif
}
