#include "StoryContainer.h"

StoryContainer::StoryContainer()
	:Container(), story_stage(1), retry(false)
{
}

StoryContainer::StoryContainer(const int& ab_x, const int& ab_y)
	: Container(ab_x, ab_y), story_stage(1), retry(false)
{
}

int StoryContainer::get_story_stage()
{
	return story_stage;
}

bool StoryContainer::is_retry()
{
	return retry;
}

void StoryContainer::set_story_stage(const int& ss)
{
	story_stage = ss;
}

void StoryContainer::set_retry(const bool& rt)
{
	retry = rt;
}

void StoryContainer::showScreen()
{
	setColor(DARK_GRAY);
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■■■■■■■■■■■■■■                                                                                        ■" << endl;
	cout << "■                        ■                                                                                        ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■                                                                                                                  ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}

void StoryContainer::showRS()
{
	showScreen();
	setColor(RED);
	gotoxy(28, 11);
	cout << "       ■■■    ■■■      ■      ■■     ■    ■          ";
	gotoxy(28, 12);
	cout << "      ■   ■   ■         ■■     ■  ■    ■  ■            ";
	gotoxy(28, 13);
	cout << "     ■■■    ■■■    ■  ■    ■   ■    ■■              ";
	gotoxy(28, 14);
	cout << "    ■   ■   ■       ■■■■   ■   ■     ■                ";
	gotoxy(28, 15);
	cout << "   ■    ■  ■■■  ■      ■  ■■■      ■     ■  ■  ■  ";
	Sleep(1500);
	setColor(BLUE);
	gotoxy(28, 11);
	cout << "    ■■■  ■■■■      ■      ■■■    ■■■■  ■  ■  ■";
	gotoxy(28, 12);
	cout << "  ■          ■        ■■     ■   ■      ■     ■  ■  ■ ";
	gotoxy(28, 13);
	cout << "   ■■      ■       ■  ■    ■■■       ■     ■  ■  ■  ";
	gotoxy(28, 14);
	cout << "      ■    ■      ■■■■   ■   ■      ■                  ";
	gotoxy(28, 15);
	cout << "■■■     ■     ■      ■  ■    ■     ■     ■  ■  ■    ";
	Sleep(1000);
	gotoxy(0, 0);
}

void StoryContainer::showChar(string characters[])
{
	setColor(GRAY);
	for (int i = 0; i < 24; i++) {
		gotoxy(40, 3 + i);
		cout << character[0][i];
	}
	for (int i = 0; i < 24; i++) {
		gotoxy(40, 3 + i);
		cout << characters[i];
	}
}

void StoryContainer::eraseChar()
{
	for (int i = 0; i < 24; i++) {
		gotoxy(40, 3 + i);
		cout << character[0][i];
	}
}

void StoryContainer::printName(string name)
{
	gotoxy(5, 28);
	cout << "                  ";
	gotoxy(5, 28);
	setColor(GREEN);
	cout << name;
}

void StoryContainer::printScript(string script1, const int& color1, string script2, const int& color2, string script3, const int& color3)
{
	gotoxy(5, 31);
	setColor(color1);
	cout << "                                                                                                         ";
	gotoxy(5, 31);
	cout << script1;

	gotoxy(5, 32);
	setColor(color2);
	cout << "                                                                                                         ";
	gotoxy(5, 32);
	cout << script2;

	gotoxy(5, 33);
	setColor(color3);
	cout << "                                                                                                         ";
	gotoxy(5, 33);
	cout << script3;

	gotoxy(110, 34);
	setColor(GRAY);
	cout << ">>>";
	system("pause > nul");
	gotoxy(0, 0);
}

void StoryContainer::showStory1() //1단계 시작전
{
	showScreen();

	bp.play("급박");
	printName("    프 롤 로 그");
	printScript("때는 바야흐로 2050년,", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("자신들의 편리함만을 좇는 인류의 이기심은 끝이 없었고,", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("지구의 쓰레기 문제는 날이 갈수록 심각해져만 갔다.", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("멈출 줄 모르고 쏟아져 나오는 쓰레기들은", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("지구의 땅, 바다, 그리고 나아가 우주를 뒤덮었다.", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("지구는 그야말로 '쓰레기 세상'이었다.", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("하지만 난세는 영웅을 낳는다고 했던가.", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("이곳 광진구의 한 아파트 방구석에서,", GREEN,
		"", GRAY,
		"", GRAY);
	printScript("지구를 구할 영웅이 태어나려 하고 있었으니...", GREEN,
		"", GRAY,
		"", GRAY);
	bp.stop();
	bp.play("humor");
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("내 이름은 김쓰봉(쓰레기봉투라는 뜻).", GRAY,
		"나이는 30세. 백수다.", GRAY,
		"", GRAY);
	showChar(character[7]);
	printScript("사람 인생은 이름 따라 흘러간다고 했던가.", GRAY,
		"내가 잘하는 것이라고는 분리수거 뿐이다.", GRAY,
		"그러니 취직이 될리가 있나.", GRAY);
	showChar(character[2]);
	printScript("하지만 분리수거 하나만큼은 확실히 자신있다.", GRAY,
		"학창시절 12년동안 쓰레기통 당번은 항상 내 차지였을 정도이니...", GRAY,
		"", GRAY);
	showChar(character[1]);
	printScript("쓰레기 버리기의 포인트는 '빈틈없이 꽉꽉 눌러담기' 이다.", GRAY,
		"빈틈이 있으면 기계가 인식을 못해 수거해가지 않기 때문이다.", GRAY,
		"", GRAY);
	printScript("오늘도 할 일 없는 나는 우리집 쓰레기통을 들고 길을 나선다.", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory1_1() //1단계 실패
{
	bp.play("허탈");
	showScreen();
	showChar(character[11]);
	printName("      김 쓰 봉");
	printScript("오늘은 분리수거마저도 제대로 못하는 날이다.", GRAY,
		"나는 아무 짝에도 쓸모 없는 사람인걸까...?", GRAY,
		"", GRAY);
	printScript("그렇게 집에서 놀고 먹으며 쓰레기통이나 비우는 생활이 반복되었다...", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory2()
{
	bp.play("일상");
	showScreen();
	showChar(character[2]);
	printName("      김 쓰 봉");
	printScript("(역시 내 실력은 여전하군.)", BLUE,
		"", BLUE,
		"", GRAY);
	showChar(character[4]);
	printScript("그때 쓰레기통에 붙은 종이 쪼가리가 눈에 들어온다.", GRAY,
		"", GRAY,
		"", GRAY);
	printName("  종 이 쪼 가 리");
	printScript("<채용공고>", GREEN,
		"NASA(미항공우주국이라는 뜻)에서 우주쓰레기 처리요원을 모집합니다.", GREEN,
		"여러분의 많은 지원 바랍니다.", GREEN);
	printScript("*경력자 우대*", GREEN,
		"", GRAY,
		"", GRAY);
	printName("      김 쓰 봉");
	showChar(character[5]);
	printScript("아니 이건 뭐지?", GRAY,
		"NASA라 하면, 세계 최고의 과학자들이 모여있다는 그곳,", GRAY,
		"그리고 쓰레기하면 바로 나 김쓰봉 아닌가...?!", GRAY);
	showChar(character[6]);
	printScript("이거다! 이건 하늘이 주신 기회야!", GRAY,
		"어머니, 저도 드디어 번듯한 직장을 가질 수 있어요!", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("");
	printScript("", GREEN,
		"                                          <광진구 분리수거 처리소>", GREEN,
		"", GRAY);
	printName("      김 쓰 봉");
	showChar(character[9]);
	printScript("(좋아... 여기서 경력을 쌓은 다음에 NASA에 취직한다!)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[2]);
	printScript("혹시 이수거 소장님 계십니까?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      소 장 님");
	printScript("음? 난데, 자네는 누군가?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      김 쓰 봉");
	printScript("아, 저는 김쓰봉이라고 합니다. 이곳에서 일하고 싶어서 찾아왔습니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      소 장 님");
	printScript("흠... 마침 가전제품 처리요원 한 자리가 비어있긴 한데... 잘할 자신은 있나?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[9]);
	printName("      김 쓰 봉");
	printScript("네! 맡겨만 주십시오!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("좋아, 그럼 일단 일당은 챙겨줄테니 오늘 하루 일해보고,", GRAY,
		"정식 채용은 그 이후에 결정하겠네.", GRAY,
		"", GRAY);
	showChar(character[3]);
	printName("      김 쓰 봉");
	printScript("감사합니다!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("가전제품은 직사각형 모양 블럭들만 처리하면 되니까, 오히려 평소보다 더 편할 수도 있어.", GRAY,
		"처음이라고 긴장하지 말고 어디 한번 잘해보라구.", GRAY,
		"", GRAY);
	showChar(character[9]);
	printScript("(좋아, 이번 기회에 내 가치를 증명해내는 거야!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory2_1()
{
	bp.play("허탈");
	showScreen();
	showChar(character[10]);
	printName("      김 쓰 봉");
	printScript("(...긴장했더니 엄청나게 실수해버렸다.)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      소 장 님");
	printScript("김쓰봉 군, 미안하지만 자네는 실수가 너무 많아.", GRAY,
		"이렇게 해서는 우리와 일하기 어렵겠구만.", GRAY,
		"자네 적성과는 안맞는 듯한데, 다른 일을 알아보는 건 어떤가?", GRAY);
	showChar(character[5]);
	printName("      김 쓰 봉");
	printScript("안됩니다! 저는 꼭 이 일을 해야 한다구요!", GRAY,
		"하루만 더 기회를 주십시오!", GRAY,
		"(NASA에 가야한다구요...)", BLUE);
	showChar(character[19]);
	printName("      소 장 님");
	printScript("흠... 어쩔 수가 없구만... 딱 하루만이야.", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory3()
{
	bp.play("희망");
	showScreen();
	showChar(character[21]);
	printName("      소 장 님");
	printScript("아니, 자네 처음치고는 아주 훌륭하구만!", GRAY,
		"좋아, 내일부터 바로 출근하도록 하게.", GRAY,
		"", GRAY);
	showChar(character[3]);
	printName("      김 쓰 봉");
	printScript("감사합니다! 열심히 하겠습니다!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("오늘은 가전제품 담당이라 널널했지만,", GRAY,
		"내일부턴 의류 쓰레기를 처리해야 하기 때문에 더 힘들어질거야.", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("의류 쓰레기가 이름만 들어서는 쉬워보이지만", GRAY,
		"다양한 옷 모양 블럭들을 처리하는 게 그리 쉽지만은 않아서 그만두는 직원들도 많아...", GRAY,
		"그 점은 각오되어 있겠지?", GRAY);
	printName("      김 쓰 봉");
	showChar(character[9]);
	printScript("네, 물론입니다!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("흠... 각오가 마음에 드는군.", GRAY,
		"좋아, 그럼 잘 부탁하겠네.", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory3_1()
{
	bp.play("허탈");
	showScreen();
	showChar(character[11]);
	printName("      김 쓰 봉");
	printScript("(...이렇게 힘든 작업은 처음이야...)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      소 장 님");
	printScript("내 뭐라 그랬는가... 쉽지 않을 거라고 말하지 않았는가...", GRAY,
		"처음이니 그럴 수 있어. 곧 익숙해질거야.", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("(그래...다시 한 번 해보자!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory4()
{
	bp.play("희망");
	showScreen();
	showChar(character[21]);
	printName("      소 장 님");
	printScript("자네 정말 대단하구만! 이렇게 빨리 일을 배우다니.", GRAY,
		"내가 지금껏 가르쳐본 직원들 중 단연 최고야!", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      김 쓰 봉");
	printScript("감사합니다. 소장님께서 잘 가르쳐주신 덕분입니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("하하, 자네한테 거는 기대가 매우 크네. 앞으로도 좋은 성과 기대하겠어.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("(그렇게 1년이 지났다. 그동안 나의 분리수거 스킬은 일취월장하였고,", BLUE,
		"나의 활약에 힘입어 광진구 분리수거 처리소의 명성은 전국에 알려졌다.)", BLUE,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("김쓰봉 군, 내가 그동안의 성과를 인정받아", GRAY,
		"이번에 서울시 분리수거 처리소의 소장으로 승진하게 되었다네.", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      김 쓰 봉");
	printScript("이야~ 정말 축하드립니다, 소장님.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("내가 한 게 뭐가 있겠나? 다 자네 덕분이지.", GRAY,
		"그래서 말이야... 서울시에서도 자네와 함께 일하고 싶은데 어떤가?", GRAY,
		"", GRAY);
	showChar(character[4]);
	printName("      김 쓰 봉");
	printScript("(서울시 분리수거 처리소라면 전국의 날고 긴다는 쓰레기 처리요원들이 모두 모인다는 그곳...?)", BLUE,
		"", BLUE,
		"", GRAY);
	showChar(character[10]);
	printScript("제가 그런 곳에 가서도 잘할 수 있을까요...?", GRAY,
		"", BLUE,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("무슨 소리야? 자네라면 잘하고도 남을걸세. 어때, 함께 가겠나?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[3]);
	printName("      김 쓰 봉");
	printScript("네! 저야 영광입니다!", GRAY,
		"(NASA에 가기 위해선 당연히 한국 최고 정도는 되어야하겠지...)", BLUE,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", GREEN,
		"                                          <서울시 분리수거 처리소>", GREEN,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("오늘이 첫 출근이구만...", GRAY,
		"서울시 처리소는 아무래도 국내에서 가장 규모가 큰 곳이다 보니", GRAY,
		"공사현장에서 나온 큼직큼직한 건축 자재들이 많이 들어온다네.", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("초보자에게 쉬운 작업은 아니겠지만", GRAY,
		"자네처럼 기본기가 탄탄한 사람이라면 문제 없을거야.", GRAY,
		"자네 실력을 유감없이 보여주게나!", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("(오늘이 첫 출근.... 할 수 있다, 김쓰봉!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory4_1()
{
	bp.play("허탈");
	showScreen();
	showChar(character[10]);
	printName("      김 쓰 봉");
	printScript("(역시 전국 최고의 벽은 높구나... 다들 이런 걸 아무렇지 않게 해낸다니...)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      소 장 님");
	printScript("김쓰봉 군, 자네에게 부족한 것은 경험 뿐이야. ", GRAY,
		"좌절하지 말고 끝까지 최선을 다하게. 난 자네를 믿어.", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("(소장님의 믿음에 보답하기 위해서라도 다시 한 번 해보자!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory5()
{
	bp.play("희망");
	showScreen();
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("(마침내 해냈다. 이제 한국에 분리수거로 날 따라올 자는 없다.)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("자네가 금방 적응할 것이라고는 생각했지만,", GRAY,
		"이렇게 빨리 전국 최고의 분리수거 요원이 될 줄이야...", GRAY,
		"내 일처럼 기쁘구만.", GRAY);
	showChar(character[2]);
	printName("      김 쓰 봉");
	printScript("감사합니다. 많이 도와주신 덕분입니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("허허, 점심이나 먹으러가지.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("저... 소장님, 드릴 말씀이 있습니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      소 장 님");
	printScript("응? 할 말이 뭔가?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	bp.stop();
	bp.play("애절");
	printName("      김 쓰 봉");
	printScript("저 이번달까지만 하고 그만두겠습니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[21]);
	printName("      소 장 님");
	printScript("그게 무슨 말이야? 드디어 전국 최고의 자리에 올랐는데 그만둔다니!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("저는 이루고 싶은 목표가 있습니다. ", GRAY,
		"NASA에서 우주쓰레기를 처리하는 것입니다!", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      소 장 님");
	printScript("뭐? NASA? 포기하게.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("네?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      소 장 님");
	printScript("자네를 무시하려는 건 아니야. 분명 재능이 있어. 하지만 그건 한국에서의 얘기야", GRAY,
		"거기에 가면 전세계의 인재들과 경쟁해야 한다구... 자네는 승산이 없어.", GRAY,
		"한국에 남아 최고의 자리에서 편하게 일할 수 있는데 왜 그 기회를 포기하는건가?", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("저는 할 수 있습니다! 왜 그런 식으로 말씀하시는 겁니까?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[20]);
	printName("      소 장 님");
	printScript("옛말에 오르지 못할 나무는 쳐다도 보지 말라 그랬어.", GRAY,
		"자네가 실패하고 괴로워하는 것을 보고 싶지 않아서 하는 말이야.", GRAY,
		"자기 분수에 맞는 꿈을 꿔야지!", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("말씀이 지나치시네요. 더는 소장님과 말하고 싶지 않습니다.", GRAY,
		"아무튼 저는 이번달까지만 일하겠습니다.", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      소 장 님");
	printScript("어쩔 수 없구만, 후회할 걸세...", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("(그렇게 직장을 떠났다.)", BLUE,
		"", GRAY,
		"", GRAY);
	bp.stop();
	bp.play("일상");
	printScript("(NASA에 원서를 넣고 한달 뒤에 답장이 왔다.)", BLUE,
		"", GRAY,
		"", GRAY);
	printName("  합 격 통 지 서");
	printScript("<1차 합격 통지서>", GREEN,
		"김쓰봉 님의 1차 서류 전형 합격을 축하드립니다.", GREEN,
		"2차 시험은 미국 NASA 본부에서 진행될 예정입니다.", GREEN);
	showChar(character[4]);
	printName("      김 쓰 봉");
	printScript("(됐다! 이제 2차만 통과하면 돼!)", BLUE,
		"", GRAY,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                               <미국 NASA 본부>", GREEN,
		"", GRAY);
	showChar(character[4]);
	printName("      김 쓰 봉");
	printScript("(이곳이 NASA... 드디어 왔다...!)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[23]);
	printName("        ???");
	printScript("미스터 킴스봉..?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("접니다만.... 누구시죠?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("아, 저는 닥터 브라운입니다. 이번 우주쓰레기 처리요원 프로젝트를 담당하고 있습니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[4]);
	printName("      김 쓰 봉");
	printScript("아, 반갑습니다. 한국말을 상당히 잘하시네요...", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("NASA 과학자에게 이 정도는 기본이지요. 미스터 봉의 소식은 많이 들었어요.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[4]);
	printName("      김 쓰 봉");
	printScript("저를 아십니까?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("물론이지요. 한국에서 당신의 상관이었던 이수거 소장에게서 추천서가 여러 장 날라와서 ", GRAY,
		"우리 직원들 사이에선 꽤 유명합니다.", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("(소... 소장님이...?)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("애니웨이, 추천서 때문에 합격한 것은 아니에요.", GRAY,
		"원서에 적힌 내용만으로도 엑설런트하더군요. ", GRAY,
		"", GRAY);
	printScript("하지만 확인해야 할 것도 있고, 트레이닝이 필요한 부분도 있기에 2차 시험이 필요합니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("네, 각오는 되어있습니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("좋아요. 우주에 나가면 아마 지구에선 볼 수 없었던 형태의 쓰레기들이 많을 겁니다.", GRAY,
		"우주 쓰레기의 상당수는 우주선, 인공위성들의 파편들입니다.", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("그 말은 쓰레기들이 한 덩어리가 아니라 조각난 형태로 존재한다는 의미에요.", GRAY,
		"우리는 그런 프라블럼을 컨트롤할 수 있는 사람을 찾고 있어요.", GRAY,
		"그럼 바로 시작해볼까요?", GRAY);
	showChar(character[9]);
	printName("      김 쓰 봉");
	printScript("네, 좋습니다!", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory5_1()
{
	bp.play("허탈");
	showScreen();
	showChar(character[26]);
	printName("  브 라 운 박 사");
	printScript("미스터 봉, 훌륭한 작업 능력이었지만 리틀빗 아쉬운 부분이 있었어요.", GRAY,
		"아직 현장에 투입하기엔 무리인 것 같군요.", GRAY,
		"", GRAY);
	showChar(character[10]);
	printName("      김 쓰 봉");
	printScript("그렇습니까...?", GRAY,
		"", GRAY,
		"(이렇게 탈락되는 건가?)", BLUE);
	showChar(character[23]);
	printName("  브 라 운 박 사");
	printScript("여기 본부에서 훈련을 더 받도록 해요. 다시 테스트를 시행해서", GRAY,
		"통과하면 현장에 투입하도록 하지요.", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("네! 열심히 훈련하겠습니다.", GRAY,
		"", GRAY,
		"(다행이다...)", BLUE);
	showRS();
	bp.stop();
}

void StoryContainer::showStory6()
{
	bp.play("희망");
	showScreen();
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("퍼펙트, 퍼펙트!! 훌륭해요. 우리가 찾던 바로 그런 인재에요.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      김 쓰 봉");
	printScript("감사합니다!", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("바로 현장에 투입해도 좋을 것 같군요. 한 달 후에 우주로 나가실 겁니다.", GRAY,
		"기본적인 훈련을 계속 받도록 하세요.", GRAY,
		"", GRAY);
	showChar(character[26]);
	printScript("현재 우주쓰레기 문제가 매우 심각하단 것은 알고 있겠죠?", GRAY,
		"이대로 가다가는 우주 탐사의 미래는 물론 지구에도 큰 위기가 될 겁니다.", GRAY,
		"", GRAY);
	showChar(character[23]);
	printScript("현재로선 미스터 봉이 지구의 희망이에요.", GRAY,
		"전세계의 천문학계에서 당신의 활약을 기대하고 있습니다. 잘할 수 있겠죠?", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      김 쓰 봉");
	printScript("네, 맡겨만 주십시오!", GRAY,
		"", GRAY,
		"", BLUE);
	bp.stop();

	bp.play("급박");
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                                  (한 달 후)", GREEN,
		"", GRAY);
	printScript("", BLUE,
		"                                          <서울시 분리수거 처리소>", GREEN,
		"", GRAY);
	printName("        T  V");
	printScript("다음 뉴스입니다. 세계 최초의 우주쓰레기 처리요원으로 선발된 김쓰봉 씨가", GREEN,
		"오늘 우주로 떠납니다. 전세계의 이목이 집중되고 있습니다.", GREEN,
		"", GRAY);
	showChar(character[17]);
	printName("      소 장 님");
	printScript("결국 해내는 구만... 그렇게 오래 자네를 지켜봤는데", GRAY,
		"아직도 자네를 너무 몰랐던 거 같군. 무사히 돌아오게...", GRAY,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                        <미국 NASA 케네디 우주센터>", GREEN,
		"", GRAY);
	showChar(character[23]);
	printName("  브 라 운 박 사");
	printScript("미스터 봉, 너무 긴장하지 말아요. 모든 것이 잘될 겁니다.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      김 쓰 봉");
	printScript("(긴장이 안될 수가 없다.)", BLUE,
		"", GRAY,
		"", BLUE);
	eraseChar();
	printName("");
	printScript("", GREEN,
		"                                         3.....2......1.......발사", GREEN,
		"", GRAY);
	showChar(character[12]);
	printName("      김 쓰 봉");
	printScript("(무사히 우주공간에 도착했다.)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  브 라 운 박 사");
	printScript("미스터 봉, 쓰레기들이 보이시나요?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[12]);
	printName("      김 쓰 봉");
	printScript("네, 잘 보입니다.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  브 라 운 박 사");
	printScript("우주 공간에는 기타 부유물들이 많기 때문에 작업에 방해가 될거에요.", GRAY,
		"그건 알고 있겠죠?", GRAY,
		"", GRAY);
	showChar(character[12]);
	printName("      김 쓰 봉");
	printScript("네, 훈련 중에 배웠습니다.", GRAY,
		"그 부유물들까지 한번에 압축시켜서 처리하면 되는 걸로 알고 있습니다.", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("커렉트. 지금까지와는 다른 방식이지만 기본기가 탄탄하다면 문제 없을 거에요.", GRAY,
		"그럼 지금부터 작업 시작하죠.", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory6_1()
{
	bp.play("허탈");
	showScreen();
	showChar(character[15]);
	printName("      김 쓰 봉");
	printScript("(큰일났다. 장애물 때문에 지구에서 연습한 게 무용지물이야...)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  브 라 운 박 사");
	printScript("미스터 봉, 당황하지 마세요.", GRAY,
		"차근차근 쌓아가다 보면 해결책이 보일 겁니다.", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      김 쓰 봉");
	printScript("네... 알겠습니다.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[26]);
	printName("  브 라 운 박 사");
	printScript("이미 우주로 나온 이상, 이번 기회에 최대한 해결해야 해요.", GRAY,
		"모든 게 당신의 손에 달려있습니다.", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory7()
{
	bp.play("급박");
	showScreen();
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("좋아요, 미스터 봉. 아주 순조로운 출발이에요.", GRAY,
		"이대로라면 목표량을 금방 채우겠습니다.", GRAY,
		"", GRAY);
	eraseChar();
	printName("      경 보 기");
	printScript("", GRAY,
		"                       (삐이----- 삐이----- 삐이----- 삐이----- 삐이----- 삐이-----)", RED,
		"", BLUE);
	showChar(character[16]);
	printName("      김 쓰 봉");
	printScript("이.. 이게 무슨 소립니까?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  브 라 운 박 사");
	printScript("이럴 수가.... 큰일입니다. 미스터 봉! 쓰레기들이 지구의 중력권 안에 들어가면서", GRAY,
		"중력의 영향을 받기 시작했어요!", GRAY,
		"", GRAY);
	showChar(character[16]);
	printName("      김 쓰 봉");
	printScript("그.. 그럼 어떻게 되는데요?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  브 라 운 박 사");
	printScript("중력 가속도 때문에 쓰레기들의 이동속도가 급격하게 변할 겁니다.", GRAY,
		"쓰레기들이 지구 중력에 완전히 끌려가버리기 전에 해치워야 해요!", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      김 쓰 봉");
	printScript("(이건 훈련 중에도 전혀 못 들어본 거잖아....)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  브 라 운 박 사");
	printScript("캄 다운! 미스터 봉, 이럴 때일수록 침착해야 합니다.", GRAY,
		"인명피해가 발생할 수도 있다구요!", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      김 쓰 봉");
	printScript("(침착하란거야 말란거야...)", BLUE,
		"", GRAY,
		"", BLUE);
	printName("      김 쓰 봉");
	printScript("(갑자기 소장님이 보인다. 죽을 때가 된건가?)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[17]);
	printName("      소 장 님");
	printScript("(쓰봉 군, 자기 자신을 믿어야 하네!)", GREEN,
		"", GRAY,
		"", BLUE);
	showChar(character[13]);
	printName("      김 쓰 봉");
	printScript("(일단 정신을 차리자.)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[26]);
	printName("  브 라 운 박 사");
	printScript("아직 시간은 있습니다. 빠르게 해결한다면 아무 문제 없을 거에요.", GRAY,
		"미스터 봉, 당신의 능력을 보여주세요!", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory7_1()
{
	bp.play("허탈");
	showScreen();
	showChar(character[15]);
	printName("      김 쓰 봉");
	printScript("(될리가 없지.... 연습도 못해봤는데 어떻게 하란거야...!)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  브 라 운 박 사");
	printScript("미스터 봉, 지나간 실수는 잊어버리세요.", GRAY,
		"아직 처리해야 할 쓰레기들이 많이 남았습니다!", GRAY,
		"", GRAY);
	showChar(character[14]);
	printName("      김 쓰 봉");
	printScript("(그래, 지금은 눈 앞의 임무에 집중하자!)", BLUE,
		"", GRAY,
		"", BLUE);
	showRS();
	bp.stop();
}

void StoryContainer::showStory8()
{
	bp.play("엔딩");
	showScreen();
	showChar(character[12]);
	printName("      김 쓰 봉");
	printScript("(해... 해냈다....)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  브 라 운 박 사");
	printScript("미스터 봉! 당신이 해냈습니다! 당신이 지구를 지킨 겁니다!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[12]);
	printName("      김 쓰 봉");
	printScript("이제 다 끝난 건가요...?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("네, 수고했어요. 이제 지구로 귀환하도록 합시다.", GRAY,
		"", GRAY,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                        <미국 NASA 케네디 우주센터>", GREEN,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("(드디어 지구에 돌아왔다.)", BLUE,
		"", GRAY,
		"", BLUE);
	printScript("(수많은 인파가 날 반긴다.)", BLUE,
		"", GRAY,
		"", BLUE);
	eraseChar();
	printName("  수 많 은 인 파");
	printScript("김쓰봉! 김쓰봉! 김쓰봉! 김쓰봉! 김쓰봉! 김쓰봉!", GREEN,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("미스터 봉, 고생 많았습니다. 이제 당신은 지구의 히어로에요.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("박사님, 저 물어보고 싶은 게 있습니다.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("뭡니까?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("왜 저를 미스터 봉이라고 부르시죠?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("당신의 라스트 네임이 Bong 아닙니까?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("Kim입니다.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  브 라 운 박 사");
	printScript(".....", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript(".....", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[26]);
	printName("  브 라 운 박 사");
	printScript("미안합니다, 미스터 킴.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("아뇨, 괜찮습니다.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  브 라 운 박 사");
	printScript("그것보다, 미스터 킴을 기다리는 사람이 있어요. 어서 가보도록 해요.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      김 쓰 봉");
	printScript("(누구지...?)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[4]);
	printScript("(아니.. 소장님?)", BLUE,
		"", GRAY,
		"", BLUE);
	printScript("소장님, 미국까지 어떻게..?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[19]);
	printName("      소 장 님");
	printScript("자네가 떠난 이후로 후회 많이 했었네.", GRAY,
		"내가 말이 너무 지나쳤던 것 같아서 말이야.", GRAY,
		"", GRAY);
	printScript("내가 자네를 너무 과소평가했더군. 꼭 사과하고 싶어 찾아왔네", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[7]);
	printName("      김 쓰 봉");
	printScript("아닙니다, 소장님. 소장님이 아니었다면 저는 이 자리까지 오지 못했을 거에요.", GRAY,
		"", GRAY,
		"", GRAY);
	printScript("우주에서도 위기 순간에 소장님의 말씀이 떠올라 용기를 얻었습니다.", GRAY,
		"소장님은 제 평생의 은인이십니다.", GRAY,
		"", GRAY);
	showChar(character[22]);
	printName("      소 장 님");
	printScript("쓰봉 군...!!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[11]);
	printName("      김 쓰 봉");
	printScript("소장님...!!", GRAY,
		"", GRAY,
		"", BLUE);
	eraseChar();
	printName("    에 필 로 그");
	printScript("동네 백수에서 지구를 구한 영웅이 된 김쓰봉.", GREEN,
		"", GREEN,
		"", GRAY);
	printScript("그의 이름은 전세계 분리수거인들에게 널리 알려졌고,", GREEN,
		"", GREEN,
		"", GRAY);
	printScript("그렇게 그는 쓰레기 처리계의 전설이 되었다.", GREEN,
		"", GREEN,
		"", GRAY);
	printScript("", BLUE,
		"                                                    - 끝 -", GREEN,
		"", GRAY);
	bp.stop();
}

void StoryContainer::startStory(int stage)
{
	switch (stage) {
	case 0:
		showStory1();
		break;
	case 1:
		showStory2();
		break;
	case 2:
		showStory3();
		break;
	case 3:
		showStory4();
		break;
	case 4:
		showStory5();
		break;
	case 5:
		showStory6();
		break;
	case 6:
		showStory7();
		break;
	case 7:
		showStory8();
		break;
	}

}

void StoryContainer::failedStory(int stage)
{
	switch (stage) {
	case 0:
		showStory1_1();
		break;
	case 1:
		showStory2_1();
		break;
	case 2:
		showStory3_1();
		break;
	case 3:
		showStory4_1();
		break;
	case 4:
		showStory5_1();
		break;
	case 5:
		showStory6_1();
		break;
	case 6:
		showStory7_1();
		break;
	}

}
