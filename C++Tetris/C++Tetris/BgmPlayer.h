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
		if(bgm == "humor") PlaySound(TEXT("./bgm/humor.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if(bgm == "급박") PlaySound(TEXT("./bgm/급박.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "엔딩") PlaySound(TEXT("./bgm/엔딩.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "일상") PlaySound(TEXT("./bgm/일상.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "허탈") PlaySound(TEXT("./bgm/허탈.wav"), NULL, SND_FILENAME | SND_ASYNC );
		if (bgm == "희망") PlaySound(TEXT("./bgm/희망.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "인게임") PlaySound(TEXT("./bgm/인게임.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "메인") PlaySound(TEXT("./bgm/메인.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "애절") PlaySound(TEXT("./bgm/애절.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	}
	void stop() {
		PlaySound(NULL, 0, 0);
	}
};