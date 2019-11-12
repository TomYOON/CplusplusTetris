#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>

//*********************************
//상수 선언
//*********************************

#define EXT_KEY         0xffffffe0   //확장키 인식값 
#define KEY_LEFT      0x4b
#define KEY_RIGHT      0x4d
#define KEY_UP         0x48
#define KEY_DOWN      0x50

//*********************************
//구조체 선언
//*********************************
struct STAGE {      //각 스테이지마다의 난이도 설정
	int   speed;   //숫자가 낮을수록 속도가 빠르다
	int stick_rate;      //막대가 나오는 확률 0~99 , 99면 막대기만 나옴
	int clear_line; // 목표 줄 제거수 
};

enum {
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VOILET,      /* 13 : 보라 */
	YELLOW,      /* 14 : 노랑 */
	WHITE,      /* 15 : 하양 */
};

//*********************************
//전역변수선언
//*********************************
int level; //현재 레벨
int ab_x, ab_y;   //화면중 블럭이 나타나는 좌표의 절대위치
int block_shape, block_angle, block_x, block_y; // 블록 모양 각도 좌표
int next_block_shape; // 다음 블록 모양
int score; // 현재 점수
int lines; // 제거한 라인 개수
char total_block[21][14];      //화면에 표시되는 블럭들
struct STAGE stage_data[10]; // 스테이저 정보 구조체 배열

// 7개 모양으로 4개 각도 4X4 표현
char block[7][4][4][4] = {
	//막대모양 1
	1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

	//네모모양 ㅁ
	1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

	//'ㅓ' 모양
	0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

	//'ㄱ'모양
	1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,   0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

	//'ㄴ' 모양
	1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,   1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,   1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

	//'Z' 모양
	1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

	//'S' 모양
	0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0

};
//*********************************
//함수 선언
//*********************************
int gotoxy(int x, int y);   //커서옮기기
void SetColor(int color);   //색표현
int init();               //스테이지 정보 각종변수 초기화 
int show_cur_block(int shape, int angle, int x, int y);   //진행중인 블럭을 화면에 표시한다
int erase_cur_block(int shape, int angle, int x, int y);   //블럭 진행의 잔상을 지우기 위한 함수
int show_total_block();   //쌓여져있는 블럭을 화면에 표시한다.
int show_next_block(int shape); // 다음 블록이 무엇인지 표시
int make_new_block();   //return값으로 block의 모양번호를 알려줌
int strike_check(int shape, int angle, int x, int y);   //블럭이 화면 맨 아래에 부닥쳤는지 검사 부닥치면 1을리턴 아니면 0리턴
int merge_block(int shape, int angle, int x, int y);   //블럭이 바닥에 닿았을때 진행중인 블럭과 쌓아진 블럭을 합침
int block_start(int shape, int* angle, int* x, int* y);   //블럭이 처음 나올때 위치와 모양을 알려줌
int move_block(int* shape, int* angle, int* x, int* y, int* next_shape);   //게임오버는 1을 리턴 바닥에 블럭이 닿으면 2를 리턴
int rotate_block(int shape, int* angle, int* x, int* y);
int show_gameover();
int show_gamestat(); // 스테이지, 레벨, 점수 출력
int show_logo();
int input_data(); // 난이도 선택
int check_full_line(); // 한 줄 채워 졌는지 검사, 사라지는 모션 출력 


int main(int argc, char* argv[])
{
	int i;
	int is_gameover = 0;
	char keytemp;
	init();
	show_logo();
	while (1)
	{
		input_data(); // 난이도 입력
		show_total_block(); // 인터페이스 형성
		block_shape = make_new_block(); // 블록 모양 생성
		next_block_shape = make_new_block(); // 다음 블록 모양 생성
		show_next_block(next_block_shape); // 다음 블록 모양 출력
		block_start(block_shape, &block_angle, &block_x, &block_y);
		show_gamestat(); // 스테이지, 레벨, 점수 출력
		for (i = 1; 1; i++)
		{
			if (_kbhit())		//키 입력이 일어나면
			{
				keytemp = _getche();		//무슨키인지 변수에 넣음
				if (keytemp == EXT_KEY)		//키 입력 범위 확인
				{
					keytemp = _getche();
					switch (keytemp)
					{
					case KEY_UP:      //회전하기

						if (strike_check(block_shape, (block_angle + 1) % 4, block_x, block_y) == 0) //충돌이 없을 경우에만 가능하게
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);	//현재 블럭을 지우고
							block_angle = (block_angle + 1) % 4;							//블럭의 앵글을 변경
							show_cur_block(block_shape, block_angle, block_x, block_y);		//변경된 블럭 출력
						}
						break;
					case KEY_LEFT:      //왼쪽으로 이동
						if (block_x > 1)  //벽이랑 충돌 안할 경우만
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);	//현재 블럭지우고
							block_x--;														// x좌표 이동
							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)  //블럭이랑 충돌할 경우 원상태로 x++
								block_x++;

							show_cur_block(block_shape, block_angle, block_x, block_y);		//수정된 블럭 보여줌
						}
						break;
					case KEY_RIGHT:      //오른쪽으로 이동

						if (block_x < 14)														//오른쪽 벽이랑 충돌 안할 경우만
						{
							erase_cur_block(block_shape, block_angle, block_x, block_y);		// 현재 블럭지움
							block_x++;															// x좌표 이동
							if (strike_check(block_shape, block_angle, block_x, block_y) == 1)	//블럭이랑 충돌시
								block_x--;														//원상태
							show_cur_block(block_shape, block_angle, block_x, block_y);			//수정된 블럭 보여줌
						}
						break;
					case KEY_DOWN:      //아래로 이동
						is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);	//game_over판단 1==over, 0==not over
						show_cur_block(block_shape, block_angle, block_x, block_y);					//수정된 블럭보여줌
						break;
					}
				}
				if (keytemp == 32)   //스페이스바를 눌렀을때
				{
					while (is_gameover == 0)
					{
						is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);	//game_over 판단
					}
					show_cur_block(block_shape, block_angle, block_x, block_y);
				}
			}
			if (i % stage_data[level].speed == 0)			//satge_data에 저장된level의 speed에 따라 블럭의 내려가는 속도를 조절. speed값이 클수록 느리게 떨어짐
			{
				is_gameover = move_block(&block_shape, &block_angle, &block_x, &block_y, &next_block_shape);

				show_cur_block(block_shape, block_angle, block_x, block_y);
			}

			if (stage_data[level].clear_line <= lines)   //클리어 스테이지, 각 레벨별 라인과 부순 라인이 같으면 클리어라고 판단
			{
				level++;
				lines = 0;
				show_total_block();						//스테이지에 대한 출력변화를 바로 보여주기위해 추가
				show_gamestat();
			}
			if (is_gameover == 1)			//게임 오버
			{
				is_gameover = 0;
				show_gameover();		//게임오버 메세지 출력
				SetColor(GRAY);
				break;					//인게임 루프탈출
			}

			gotoxy(77, 23);
			Sleep(15);			//루프의 속도를 조절하기 위해서
			gotoxy(77, 23);
		}
		init();					//게임오버에서 탈출시 다시 초기화
	}
	return 0;
}

int gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void SetColor(int color)

{
	static HANDLE std_output_handle;
	std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color);

}

int init()
{
	int i, j;

	srand((unsigned)time(NULL));

	// 화면 초기화
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if ((j == 0) || (j == 13))
			{
				total_block[i][j] = 1;
			}
			else {
				total_block[i][j] = 0;
			}
		}
	}

	//화면의 제일 밑의 줄은 1로 채운다.
	for (j = 0; j < 14; j++)
		total_block[20][j] = 1;

	//전역변수 초기화
	level = 0;
	lines = 0;
	ab_x = 5;
	ab_y = 1;

	stage_data[0].speed = 40;
	stage_data[0].stick_rate = 20;
	stage_data[0].clear_line = 2;
	stage_data[1].speed = 38;
	stage_data[1].stick_rate = 18;
	stage_data[1].clear_line = 20;
	stage_data[2].speed = 35;
	stage_data[2].stick_rate = 18;
	stage_data[2].clear_line = 20;
	stage_data[3].speed = 30;
	stage_data[3].stick_rate = 17;
	stage_data[3].clear_line = 20;
	stage_data[4].speed = 25;
	stage_data[4].stick_rate = 16;
	stage_data[4].clear_line = 20;
	stage_data[5].speed = 20;
	stage_data[5].stick_rate = 14;
	stage_data[5].clear_line = 20;
	stage_data[6].speed = 15;
	stage_data[6].stick_rate = 14;
	stage_data[6].clear_line = 20;
	stage_data[7].speed = 10;
	stage_data[7].stick_rate = 13;
	stage_data[7].clear_line = 20;
	stage_data[8].speed = 6;
	stage_data[8].stick_rate = 12;
	stage_data[8].clear_line = 20;
	stage_data[9].speed = 4;
	stage_data[9].stick_rate = 11;
	stage_data[9].clear_line = 99999;
	return 0;
}

int show_cur_block(int shape, int angle, int x, int y)
{
	int i, j;

	// 해당 블록에 맞는 색깔을 출력
	switch (shape)
	{
	case 0: //막대모양 1
		SetColor(RED);
		break;
	case 1: //네모모양 ㅁ
		SetColor(BLUE);
		break;
	case 2: //'ㅓ' 모양
		SetColor(SKY_BLUE);
		break;
	case 3: //'ㄱ'모양
		SetColor(WHITE);
		break;
	case 4: //'ㄴ' 모양
		SetColor(YELLOW);
		break;
	case 5: //'Z' 모양
		SetColor(VOILET);
		break;
	case 6: //'S' 모양
		SetColor(GREEN);
		break;
	}
	// 좌표 x, y 에 대하여 4X4 칸 내에 블록을 출력
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			// 화면 밖을 나갈때는 출력을 생략한다.
			if ((j + y) < 0)
				continue;

			if (block[shape][angle][j][i] == 1)
			{
				gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
				printf("■");

			}
		}
	}
	// 다시 검정으로 바꾼후 커서 이동
	SetColor(BLACK);
	gotoxy(77, 23);
	return 0;
}

int erase_cur_block(int shape, int angle, int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (block[shape][angle][j][i] == 1)
			{
				gotoxy((i + x) * 2 + ab_x, j + y + ab_y);
				printf("  ");
				//break;

			}
		}
	}
	return 0;
}



int show_total_block()
{
	int i, j;
	SetColor(DARK_GRAY);
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 14; j++)
		{
			//레벨에 따라 외벽 색을 변경한다.
			if (j == 0 || j == 13 || i == 20)
			{
				SetColor((level % 6) + 1);

			}
			else { // 바닥에 앉은 블록은 회색으로 출력
				SetColor(DARK_GRAY);
			}
			gotoxy((j * 2) + ab_x, i + ab_y);
			// 블록이 앉은 자리는 출력을 한다.
			if (total_block[i][j] == 1)
			{
				printf("■");
			}
			else {
				printf("  ");
			}

		}
	}
	// 검은색으로 바꾼후 종료
	SetColor(BLACK);
	gotoxy(77, 23);
	return 0;
}

int make_new_block()
{
	int shape;
	int i;
	i = rand() % 100;
	if (i <= stage_data[level].stick_rate)      //막대기 나올확률 계산
		return 0;                     //막대기 모양으로 리턴

	shape = (rand() % 6) + 1;      //shape에는 1~6의 값이 들어감
	show_next_block(shape);
	return shape;
}


int strike_check(int shape, int angle, int x, int y)
{
	int i, j;
	int block_dat;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			int moved_x = x + j;
			int moved_y = y + i;
			if ((moved_x == 0) || (moved_x == 13))
				block_dat = 1;
			else if (moved_y >= 0 && moved_y < 21 && moved_x >= 0 && moved_x < 14)
				block_dat = total_block[moved_y][moved_x];
			else
				block_dat = 0;

			/*if ((moved_x == 0) || (moved_x == 13))
			   block_dat = 1;
			else
			   block_dat = total_block[y + i][x + j];*/


			if ((block_dat == 1) && (block[shape][angle][i][j] == 1))                                                                     //좌측벽의 좌표를 빼기위함
			{
				return 1;
			}
		}
	}
	return 0;
}

int merge_block(int shape, int angle, int x, int y)
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			total_block[y + i][x + j] |= block[shape][angle][i][j];
		}
	}
	check_full_line();
	show_total_block();

	return 0;
}

int block_start(int shape, int* angle, int* x, int* y)
{

	*x = 5;
	*y = -3;
	*angle = 0;
	return 0;
}

int show_gameover()
{
	SetColor(RED);
	gotoxy(15, 8);
	printf("┏━━━━━━━━━━━━━┓");
	gotoxy(15, 9);
	printf("┃**************************┃");
	gotoxy(15, 10);
	printf("┃*        GAME OVER       *┃");
	gotoxy(15, 11);
	printf("┃**************************┃");
	gotoxy(15, 12);
	printf("┗━━━━━━━━━━━━━┛");
	fflush(stdin);
	Sleep(1000);

	_getche();
	system("cls");

	return 0;
}

int move_block(int* shape, int* angle, int* x, int* y, int* next_shape)
{
	erase_cur_block(*shape, *angle, *x, *y);

	(*y)++;   //블럭을 한칸 아래로 내림
	if (strike_check(*shape, *angle, *x, *y) == 1)
	{
		if (*y <= 0)   //게임오버
		{

			return 1;
		}
		(*y)--;
		merge_block(*shape, *angle, *x, *y);
		*shape = *next_shape;
		*next_shape = make_new_block();

		block_start(*shape, angle, x, y);   //angle,x,y는 포인터임
		show_next_block(*next_shape);
		return 2;
	}
	return 0;
}

int rotate_block(int shape, int* angle, int* x, int* y)
{
	return 0;
}

int check_full_line()
{
	int i, j, k;
	for (i = 0; i < 20; i++)
	{
		for (j = 1; j < 13; j++)
		{
			if (total_block[i][j] == 0)
				break;
		}
		if (j == 13)   //한줄이 다 채워졌음
		{
			lines++;
			show_total_block();
			SetColor(BLUE);
			gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				printf("□");
				Sleep(10);
			}
			gotoxy(1 * 2 + ab_x, i + ab_y);
			for (j = 1; j < 13; j++)
			{
				printf("  ");
				Sleep(10);
			}

			for (k = i; k > 0; k--)
			{
				for (j = 1; j < 13; j++)
					total_block[k][j] = total_block[k - 1][j];
			}
			for (j = 1; j < 13; j++)
				total_block[0][j] = 0;
			score += 100 + (level * 10) + (rand() % 10);
			show_gamestat();
		}
	}
	return 0;
}

int show_next_block(int shape)
{
	int i, j;
	// 레벨에 해당하는 색상으로 바꾼후
	SetColor((level + 1) % 6 + 1);
	for (i = 1; i < 7; i++)
	{
		// 다음 블록 출력 시작 위치로 이동후
		gotoxy(33, i);
		// 박스를 출력
		for (j = 0; j < 6; j++)
		{
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				printf("■");
			}
			else {
				printf("  ");
			}

		}
	}
	// 박스 안에 다음 블록의 모양을 출력
	show_cur_block(shape, 0, 15, 1);
	return 0;
}

int show_gamestat()
{
	static int printed_text = 0;
	SetColor(GRAY);
	if (printed_text == 0)
	{
		gotoxy(35, 7);
		printf("STAGE");

		gotoxy(35, 9);
		printf("SCORE");

		gotoxy(35, 12);
		printf("LINES");


	}
	gotoxy(41, 7);
	printf("%d", level + 1);
	gotoxy(35, 10);
	printf("%10d", score);
	gotoxy(35, 13);
	printf("%10d", stage_data[level].clear_line - lines);
	return 0;
}

int input_data()
{
	int i = 0;
	SetColor(GRAY);
	gotoxy(10, 7);
	printf("┏━━━━<GAME KEY>━━━━━┓");
	Sleep(10);
	gotoxy(10, 8);
	printf("┃ UP   : Rotate Block        ┃");
	Sleep(10);
	gotoxy(10, 9);
	printf("┃ DOWN : Move One-Step Down  ┃");
	Sleep(10);
	gotoxy(10, 10);
	printf("┃ SPACE: Move Bottom Down    ┃");
	Sleep(10);
	gotoxy(10, 11);
	printf("┃ LEFT : Move Left           ┃");
	Sleep(10);
	gotoxy(10, 12);
	printf("┃ RIGHT: Move Right          ┃");
	Sleep(10);
	gotoxy(10, 13);
	printf("┗━━━━━━━━━━━━━━┛");


	while (i < 1 || i>8)
	{
		gotoxy(10, 3);
		printf("Select Start level[1-8]:       \b\b\b\b\b\b\b");
		scanf_s("%d", &i);
	}


	level = i - 1;
	system("cls");
	return 0;
}

int show_logo()
{
	int i, j;
	gotoxy(13, 3);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━┓");
	Sleep(100);
	gotoxy(13, 4);
	printf("┃◆◆◆  ◆◆◆  ◆◆◆   ◆◆     ◆   ◆  ◆ ┃");
	Sleep(100);
	gotoxy(13, 5);
	printf("┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃");
	Sleep(100);
	gotoxy(13, 6);
	printf("┃  ◆    ◆◆◆    ◆     ◆◆     ◆     ◆   ┃");
	Sleep(100);
	gotoxy(13, 7);
	printf("┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃");
	Sleep(100);
	gotoxy(13, 8);
	printf("┃  ◆    ◆◆◆    ◆     ◆  ◆   ◆   ◆  ◆ ┃");
	Sleep(100);
	gotoxy(13, 9);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━┛");

	gotoxy(28, 20);
	printf("Please Press Any Key~!");

	for (i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{


			for (j = 0; j < 5; j++)
			{
				gotoxy(18, 14 + j);
				printf("                                                          ");


			}
			show_cur_block(rand() % 7, rand() % 4, 6, 14);
			show_cur_block(rand() % 7, rand() % 4, 12, 14);
			show_cur_block(rand() % 7, rand() % 4, 19, 14);
			show_cur_block(rand() % 7, rand() % 4, 24, 14);
		}
		if (_kbhit())
			break;
		Sleep(30);
	}

	_getche();
	system("cls");

	return 0;
}