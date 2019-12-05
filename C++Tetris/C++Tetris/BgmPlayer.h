#pragma once
#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <string>

using namespace std;

class BgmPlayer {
public:
	void play(const string& bgm) {
		if(bgm == "humor")
		PlaySound(TEXT("./bgm/humor.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	void stop() {
		PlaySound(NULL, 0, 0);
	}
};