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
		if(bgm == "�޹�") PlaySound(TEXT("./bgm/�޹�.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "����") PlaySound(TEXT("./bgm/����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "�ϻ�") PlaySound(TEXT("./bgm/�ϻ�.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "��Ż") PlaySound(TEXT("./bgm/��Ż.wav"), NULL, SND_FILENAME | SND_ASYNC );
		if (bgm == "���") PlaySound(TEXT("./bgm/���.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "�ΰ���") PlaySound(TEXT("./bgm/�ΰ���.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "����") PlaySound(TEXT("./bgm/����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		if (bgm == "����") PlaySound(TEXT("./bgm/����.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	}
	void stop() {
		PlaySound(NULL, 0, 0);
	}
};