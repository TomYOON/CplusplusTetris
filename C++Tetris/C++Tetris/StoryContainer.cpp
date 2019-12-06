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
	cout << "������������������������������������������������������������" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "���������������                                                                                        ��" << endl;
	cout << "��                        ��                                                                                        ��" << endl;
	cout << "������������������������������������������������������������" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "��                                                                                                                  ��" << endl;
	cout << "������������������������������������������������������������" << endl;
}

void StoryContainer::showRS()
{
	showScreen();
	setColor(RED);
	gotoxy(28, 11);
	cout << "       ����    ����      ��      ���     ��    ��          ";
	gotoxy(28, 12);
	cout << "      ��   ��   ��         ���     ��  ��    ��  ��            ";
	gotoxy(28, 13);
	cout << "     ����    ����    ��  ��    ��   ��    ���              ";
	gotoxy(28, 14);
	cout << "    ��   ��   ��       �����   ��   ��     ��                ";
	gotoxy(28, 15);
	cout << "   ��    ��  ����  ��      ��  ����      ��     ��  ��  ��  ";
	Sleep(3000);
	setColor(BLUE);
	gotoxy(28, 11);
	cout << "    ����  �����      ��      ����    �����  ��  ��  ��";
	gotoxy(28, 12);
	cout << "  ��          ��        ���     ��   ��      ��     ��  ��  �� ";
	gotoxy(28, 13);
	cout << "   ���      ��       ��  ��    ����       ��     ��  ��  ��  ";
	gotoxy(28, 14);
	cout << "      ��    ��      �����   ��   ��      ��                  ";
	gotoxy(28, 15);
	cout << "����     ��     ��      ��  ��    ��     ��     ��  ��  ��    ";
	Sleep(2000);
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

void StoryContainer::showStory1() //1�ܰ� ������
{
	bp.play("humor");
	showScreen();
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("�� �̸��� �農��(������������ ��).", GRAY,
		"���̴� 30��. �����.", GRAY,
		"", GRAY);
	showChar(character[7]);
	printScript("��� �λ��� �̸� ���� �귯���ٰ� �ߴ���.", GRAY,
		"���� ���ϴ� ���̶��� �и����� ���̴�.", GRAY,
		"�׷��� ������ �ɸ��� �ֳ�.", GRAY);
	showChar(character[2]);
	printScript("������ �и����� �ϳ���ŭ�� Ȯ���� �ڽ��ִ�.", GRAY,
		"��â���� 12�⵿�� �������� ����� �׻� �� �������� �����̴�...", GRAY,
		"", GRAY);
	showChar(character[1]);
	printScript("������ �������� ����Ʈ�� '��ƴ���� �˲� �������' �̴�.", GRAY,
		"��ƴ�� ������ ��谡 �ν��� ���� �����ذ��� �ʱ� �����̴�.", GRAY,
		"", GRAY);
	printScript("���õ� �� �� ���� ���� �츮�� ���������� ��� ���� ������.", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
	bp.stop();
}

void StoryContainer::showStory1_1() //1�ܰ� ����
{
	showScreen();
	showChar(character[11]);
	printName("      �� �� ��");
	printScript("������ �и����Ÿ����� ����� ���ϴ� ���̴�.", GRAY,
		"���� �ƹ� ¦���� ���� ���� ����ΰɱ�...?", GRAY,
		"", GRAY);
	printScript("�׷��� ������ ��� ������ ���������̳� ���� ��Ȱ�� �ݺ��Ǿ���...", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory2()
{
	showScreen();
	showChar(character[2]);
	printName("      �� �� ��");
	printScript("(���� �� �Ƿ��� �����ϱ�.)", BLUE,
		"", BLUE,
		"", GRAY);
	showChar(character[4]);
	printScript("�׶� �������뿡 ���� ���� �ɰ����� ���� ���´�.", GRAY,
		"", GRAY,
		"", GRAY);
	printName("  �� �� �� �� ��");
	printScript("<ä�����>", GREEN,
		"NASA(���װ����ֱ��̶�� ��)���� ���־����� ó������� �����մϴ�.", GREEN,
		"�������� ���� ���� �ٶ��ϴ�.", GREEN);
	printScript("*����� ���*", GREEN,
		"", GRAY,
		"", GRAY);
	printName("      �� �� ��");
	showChar(character[5]);
	printScript("�ƴ� �̰� ����?", GRAY,
		"NASA�� �ϸ�, ���� �ְ��� �����ڵ��� ���ִٴ� �װ�,", GRAY,
		"�׸��� �������ϸ� �ٷ� �� �農�� �ƴѰ�...?!", GRAY);
	showChar(character[6]);
	printScript("�̰Ŵ�! �̰� �ϴ��� �ֽ� ��ȸ��!", GRAY,
		"��Ӵ�, ���� ���� ������ ������ ���� �� �־��!", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("");
	printScript("", GREEN,
		"                                          <������ �и����� ó����>", GREEN,
		"", GRAY);
	printName("      �� �� ��");
	showChar(character[9]);
	printScript("(����... ���⼭ ����� ���� ������ NASA�� �����Ѵ�!)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[2]);
	printScript("Ȥ�� �̼��� ����� ��ʴϱ�?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      �� �� ��");
	printScript("��? ����, �ڳ״� ������?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      �� �� ��");
	printScript("��, ���� �農���̶�� �մϴ�. �̰����� ���ϰ� �; ã�ƿԽ��ϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      �� �� ��");
	printScript("��... ��ħ ������ǰ ó����� �� �ڸ��� ����ֱ� �ѵ�... ���� �ڽ��� �ֳ�?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[9]);
	printName("      �� �� ��");
	printScript("��! �ðܸ� �ֽʽÿ�!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("����, �׷� �ϴ� �ϴ��� ì�����״� ���� �Ϸ� ���غ���,", GRAY,
		"���� ä���� �� ���Ŀ� �����ϰڳ�.", GRAY,
		"", GRAY);
	showChar(character[3]);
	printName("      �� �� ��");
	printScript("�����մϴ�!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("������ǰ�� ���簢�� ��� ���鸸 ó���ϸ� �Ǵϱ�, ������ ��Һ��� �� ���� ���� �־�.", GRAY,
		"ó���̶�� �������� ���� ��� �ѹ� ���غ���.", GRAY,
		"", GRAY);
	showChar(character[9]);
	printScript("(����, �̹� ��ȸ�� �� ��ġ�� �����س��� �ž�!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory2_1()
{
	showScreen();
	showChar(character[10]);
	printName("      �� �� ��");
	printScript("(...�����ߴ��� ��û���� �Ǽ��ع��ȴ�.)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      �� �� ��");
	printScript("�農�� ��, �̾������� �ڳ״� �Ǽ��� �ʹ� ����.", GRAY,
		"�̷��� �ؼ��� �츮�� ���ϱ� ��ưڱ���.", GRAY,
		"�ڳ� �������� �ȸ´� ���ѵ�, �ٸ� ���� �˾ƺ��� �� ���?", GRAY);
	showChar(character[5]);
	printName("      �� �� ��");
	printScript("�ȵ˴ϴ�! ���� �� �� ���� �ؾ� �Ѵٱ���!", GRAY,
		"�Ϸ縸 �� ��ȸ�� �ֽʽÿ�!", GRAY,
		"(NASA�� �����Ѵٱ���...)", BLUE);
	showChar(character[19]);
	printName("      �� �� ��");
	printScript("��... ��¿ ���� ������... �� �Ϸ縸�̾�.", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory3()
{
	showScreen();
	showChar(character[21]);
	printName("      �� �� ��");
	printScript("�ƴ�, �ڳ� ó��ġ��� ���� �Ǹ��ϱ���!", GRAY,
		"����, ���Ϻ��� �ٷ� ����ϵ��� �ϰ�.", GRAY,
		"", GRAY);
	showChar(character[3]);
	printName("      �� �� ��");
	printScript("�����մϴ�! ������ �ϰڽ��ϴ�!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("������ ������ǰ ����̶� �γ�������,", GRAY,
		"���Ϻ��� �Ƿ� �����⸦ ó���ؾ� �ϱ� ������ �� ��������ž�.", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("�Ƿ� �����Ⱑ �̸��� ���� ������������", GRAY,
		"�پ��� �� ��� ������ ó���ϴ� �� �׸� �������� �ʾƼ� �׸��δ� �����鵵 ����...", GRAY,
		"�� ���� �����Ǿ� �ְ���?", GRAY);
	printName("      �� �� ��");
	showChar(character[9]);
	printScript("��, �����Դϴ�!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("��... ������ ������ ��±�.", GRAY,
		"����, �׷� �� ��Ź�ϰڳ�.", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory3_1()
{
	showScreen();
	showChar(character[11]);
	printName("      �� �� ��");
	printScript("(...�̷��� ���� �۾��� ó���̾�...)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      �� �� ��");
	printScript("�� ���� �׷��°�... ���� ���� �Ŷ�� ������ �ʾҴ°�...", GRAY,
		"ó���̴� �׷� �� �־�. �� �ͼ������ž�.", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("(�׷�...�ٽ� �� �� �غ���!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory4()
{
	showScreen();
	showChar(character[21]);
	printName("      �� �� ��");
	printScript("�ڳ� ���� ����ϱ���! �̷��� ���� ���� ���ٴ�.", GRAY,
		"���� ���ݲ� �����ĺ� ������ �� �ܿ� �ְ��!", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      �� �� ��");
	printScript("�����մϴ�. ����Բ��� �� �������ֽ� �����Դϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("����, �ڳ����� �Ŵ� ��밡 �ſ� ũ��. �����ε� ���� ���� ����ϰھ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("(�׷��� 1���� ������. �׵��� ���� �и����� ��ų�� ��������Ͽ���,", BLUE,
		"���� Ȱ�࿡ ���Ծ� ������ �и����� ó������ ���� ������ �˷�����.)", BLUE,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("�農�� ��, ���� �׵����� ������ �����޾�", GRAY,
		"�̹��� ����� �и����� ó������ �������� �����ϰ� �Ǿ��ٳ�.", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      �� �� ��");
	printScript("�̾�~ ���� ���ϵ帳�ϴ�, �����.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("���� �� �� ���� �ְڳ�? �� �ڳ� ��������.", GRAY,
		"�׷��� ���̾�... ����ÿ����� �ڳ׿� �Բ� ���ϰ� ������ ���?", GRAY,
		"", GRAY);
	showChar(character[4]);
	printName("      �� �� ��");
	printScript("(����� �и����� ó���Ҷ�� ������ ���� ��ٴ� ������ ó��������� ��� ���δٴ� �װ�...?)", BLUE,
		"", BLUE,
		"", GRAY);
	showChar(character[10]);
	printScript("���� �׷� ���� ������ ���� �� �������...?", GRAY,
		"", BLUE,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("���� �Ҹ���? �ڳ׶�� ���ϰ� �����ɼ�. �, �Բ� ���ڳ�?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[3]);
	printName("      �� �� ��");
	printScript("��! ���� �����Դϴ�!", GRAY,
		"(NASA�� ���� ���ؼ� �翬�� �ѱ� �ְ� ������ �Ǿ���ϰ���...)", BLUE,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", GREEN,
		"                                          <����� �и����� ó����>", GREEN,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("������ ù ����̱���...", GRAY,
		"����� ó���Ҵ� �ƹ����� �������� ���� �Ը� ū ���̴� ����", GRAY,
		"�������忡�� ���� ŭ��ŭ���� ���� ������� ���� ���´ٳ�.", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("�ʺ��ڿ��� ���� �۾��� �ƴϰ�����", GRAY,
		"�ڳ�ó�� �⺻�Ⱑ źź�� ����̶�� ���� �����ž�.", GRAY,
		"�ڳ� �Ƿ��� �������� �����ְԳ�!", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("(������ ù ���.... �� �� �ִ�, �農��!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory4_1()
{
	showScreen();
	showChar(character[10]);
	printName("      �� �� ��");
	printScript("(���� ���� �ְ��� ���� ������... �ٵ� �̷� �� �ƹ����� �ʰ� �س��ٴ�...)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      �� �� ��");
	printScript("�農�� ��, �ڳ׿��� ������ ���� ���� ���̾�. ", GRAY,
		"�������� ���� ������ �ּ��� ���ϰ�. �� �ڳ׸� �Ͼ�.", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("(������� ������ �����ϱ� ���ؼ��� �ٽ� �� �� �غ���!)", BLUE,
		"", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory5()
{
	showScreen();
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("(��ħ�� �س´�. ���� �ѱ��� �и����ŷ� �� ����� �ڴ� ����.)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("�ڳװ� �ݹ� ������ ���̶��� ����������,", GRAY,
		"�̷��� ���� ���� �ְ��� �и����� ����� �� ���̾�...", GRAY,
		"�� ��ó�� ��ڱ���.", GRAY);
	showChar(character[2]);
	printName("      �� �� ��");
	printScript("�����մϴ�. ���� �����ֽ� �����Դϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("����, �����̳� ����������.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("��... �����, �帱 ������ �ֽ��ϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[18]);
	printName("      �� �� ��");
	printScript("��? �� ���� ����?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("�� �̹��ޱ����� �ϰ� �׸��ΰڽ��ϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[21]);
	printName("      �� �� ��");
	printScript("�װ� ���� ���̾�? ���� ���� �ְ��� �ڸ��� �ö��µ� �׸��дٴ�!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("���� �̷�� ���� ��ǥ�� �ֽ��ϴ�. ", GRAY,
		"NASA���� ���־����⸦ ó���ϴ� ���Դϴ�!", GRAY,
		"", GRAY);
	showChar(character[17]);
	printName("      �� �� ��");
	printScript("��? NASA? �����ϰ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("��?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      �� �� ��");
	printScript("�ڳ׸� �����Ϸ��� �� �ƴϾ�. �и� ����� �־�. ������ �װ� �ѱ������� ����", GRAY,
		"�ű⿡ ���� �������� ������ �����ؾ� �Ѵٱ�... �ڳ״� �»��� ����.", GRAY,
		"�ѱ��� ���� �ְ��� �ڸ����� ���ϰ� ���� �� �ִµ� �� �� ��ȸ�� �����ϴ°ǰ�?", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("���� �� �� �ֽ��ϴ�! �� �׷� ������ �����Ͻô� �̴ϱ�?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[20]);
	printName("      �� �� ��");
	printScript("������ ������ ���� ������ �Ĵٵ� ���� ���� �׷���.", GRAY,
		"�ڳװ� �����ϰ� ���ο��ϴ� ���� ���� ���� �ʾƼ� �ϴ� ���̾�.", GRAY,
		"�ڱ� �м��� �´� ���� �����!", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("������ ����ġ�ó׿�. ���� ����԰� ���ϰ� ���� �ʽ��ϴ�.", GRAY,
		"�ƹ�ư ���� �̹��ޱ����� ���ϰڽ��ϴ�.", GRAY,
		"", GRAY);
	showChar(character[19]);
	printName("      �� �� ��");
	printScript("��¿ �� ������, ��ȸ�� �ɼ�...", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("(�׷��� ������ ������.)", BLUE,
		"", GRAY,
		"", GRAY);
	printScript("(NASA�� ������ �ְ� �Ѵ� �ڿ� ������ �Դ�.)", BLUE,
		"", GRAY,
		"", GRAY);
	printName("  �� �� �� �� ��");
	printScript("<1�� �հ� ������>", GREEN,
		"�農�� ���� 1�� ���� ���� �հ��� ���ϵ帳�ϴ�.", GREEN,
		"2�� ������ �̱� NASA ���ο��� ����� �����Դϴ�.", GREEN);
	showChar(character[4]);
	printName("      �� �� ��");
	printScript("(�ƴ�! ���� 2���� ����ϸ� ��!)", BLUE,
		"", GRAY,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                               <�̱� NASA ����>", GREEN,
		"", GRAY);
	showChar(character[4]);
	printName("      �� �� ��");
	printScript("(�̰��� NASA... ���� �Դ�...!)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[23]);
	printName("        ???");
	printScript("�̽��� Ŵ����..?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("���ϴٸ�.... ��������?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("��, ���� ���� �����Դϴ�. �̹� ���־����� ó����� ������Ʈ�� ����ϰ� �ֽ��ϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[4]);
	printName("      �� �� ��");
	printScript("��, �ݰ����ϴ�. �ѱ����� ����� ���Ͻó׿�...", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("NASA �����ڿ��� �� ������ �⺻������. �̽��� ���� �ҽ��� ���� ������.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[4]);
	printName("      �� �� ��");
	printScript("���� �ƽʴϱ�?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("����������. �ѱ����� ����� ����̾��� �̼��� ���忡�Լ� ��õ���� ���� �� ����ͼ� ", GRAY,
		"�츮 ������ ���̿��� �� �����մϴ�.", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("(��... �������...?)", BLUE,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("�ִϿ���, ��õ�� ������ �հ��� ���� �ƴϿ���.", GRAY,
		"������ ���� ���븸���ε� ������Ʈ�ϴ�����. ", GRAY,
		"", GRAY);
	printScript("������ Ȯ���ؾ� �� �͵� �ְ�, Ʈ���̴��� �ʿ��� �κе� �ֱ⿡ 2�� ������ �ʿ��մϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("��, ������ �Ǿ��ֽ��ϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("���ƿ�. ���ֿ� ������ �Ƹ� �������� �� �� ������ ������ ��������� ���� �̴ϴ�.", GRAY,
		"���� �������� ������ ���ּ�, �ΰ��������� ������Դϴ�.", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("�� ���� ��������� �� ����� �ƴ϶� ������ ���·� �����Ѵٴ� �ǹ̿���.", GRAY,
		"�츮�� �׷� ������� ��Ʈ���� �� �ִ� ����� ã�� �־��.", GRAY,
		"�׷� �ٷ� �����غ����?", GRAY);
	showChar(character[9]);
	printName("      �� �� ��");
	printScript("��, �����ϴ�!", GRAY,
		"", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory5_1()
{
	showScreen();
	showChar(character[26]);
	printName("  �� �� �� �� ��");
	printScript("�̽��� ��, �Ǹ��� �۾� �ɷ��̾����� ��Ʋ�� �ƽ��� �κ��� �־����.", GRAY,
		"���� ���忡 �����ϱ⿣ ������ �� ������.", GRAY,
		"", GRAY);
	showChar(character[10]);
	printName("      �� �� ��");
	printScript("�׷����ϱ�...?", GRAY,
		"", GRAY,
		"(�̷��� Ż���Ǵ� �ǰ�?)", BLUE);
	showChar(character[23]);
	printName("  �� �� �� �� ��");
	printScript("���� ���ο��� �Ʒ��� �� �޵��� �ؿ�. �ٽ� �׽�Ʈ�� �����ؼ�", GRAY,
		"����ϸ� ���忡 �����ϵ��� ������.", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("��! ������ �Ʒ��ϰڽ��ϴ�.", GRAY,
		"", GRAY,
		"(�����̴�...)", BLUE);
	showRS();
}

void StoryContainer::showStory6()
{
	showScreen();
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("����Ʈ, ����Ʈ!! �Ǹ��ؿ�. �츮�� ã�� �ٷ� �׷� ���翡��.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[2]);
	printName("      �� �� ��");
	printScript("�����մϴ�!", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("�ٷ� ���忡 �����ص� ���� �� ������. �� �� �Ŀ� ���ַ� ������ �̴ϴ�.", GRAY,
		"�⺻���� �Ʒ��� ��� �޵��� �ϼ���.", GRAY,
		"", GRAY);
	showChar(character[26]);
	printScript("���� ���־����� ������ �ſ� �ɰ��ϴ� ���� �˰� �ְ���?", GRAY,
		"�̴�� ���ٰ��� ���� Ž���� �̷��� ���� �������� ū ���Ⱑ �� �̴ϴ�.", GRAY,
		"", GRAY);
	showChar(character[23]);
	printScript("����μ� �̽��� ���� ������ ����̿���.", GRAY,
		"�������� õ���а迡�� ����� Ȱ���� ����ϰ� �ֽ��ϴ�. ���� �� �ְ���?", GRAY,
		"", GRAY);
	showChar(character[8]);
	printName("      �� �� ��");
	printScript("��, �ðܸ� �ֽʽÿ�!", GRAY,
		"", GRAY,
		"", BLUE);
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                                  (�� �� ��)", GREEN,
		"", GRAY);
	printScript("", BLUE,
		"                                          <����� �и����� ó����>", GREEN,
		"", GRAY);
	printName("        T  V");
	printScript("���� �����Դϴ�. ���� ������ ���־����� ó��������� ���ߵ� �農�� ����", GREEN,
		"���� ���ַ� �����ϴ�. �������� �̸��� ���ߵǰ� �ֽ��ϴ�.", GREEN,
		"", GRAY);
	showChar(character[17]);
	printName("      �� �� ��");
	printScript("�ᱹ �س��� ����... �׷��� ���� �ڳ׸� ���Ѻôµ�", GRAY,
		"������ �ڳ׸� �ʹ� ������ �� ����. ������ ���ƿ���...", GRAY,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                        <�̱� NASA �ɳ׵� ���ּ���>", GREEN,
		"", GRAY);
	showChar(character[23]);
	printName("  �� �� �� �� ��");
	printScript("�̽��� ��, �ʹ� �������� ���ƿ�. ��� ���� �ߵ� �̴ϴ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      �� �� ��");
	printScript("(������ �ȵ� ���� ����.)", BLUE,
		"", GRAY,
		"", BLUE);
	eraseChar();
	printName("");
	printScript("", GREEN,
		"                                         3.....2......1.......�߻�", GREEN,
		"", GRAY);
	showChar(character[12]);
	printName("      �� �� ��");
	printScript("(������ ���ְ����� �����ߴ�.)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  �� �� �� �� ��");
	printScript("�̽��� ��, ��������� ���̽ó���?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[12]);
	printName("      �� �� ��");
	printScript("��, �� ���Դϴ�.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  �� �� �� �� ��");
	printScript("���� �������� ��Ÿ ���������� ���� ������ �۾��� ���ذ� �ɰſ���.", GRAY,
		"�װ� �˰� �ְ���?", GRAY,
		"", GRAY);
	showChar(character[12]);
	printName("      �� �� ��");
	printScript("��, �Ʒ� �߿� ������ϴ�.", GRAY,
		"�� ����������� �ѹ��� ������Ѽ� ó���ϸ� �Ǵ� �ɷ� �˰� �ֽ��ϴ�.", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("Ŀ��Ʈ. ���ݱ����ʹ� �ٸ� ��������� �⺻�Ⱑ źź�ϴٸ� ���� ���� �ſ���.", GRAY,
		"�׷� ���ݺ��� �۾� ��������.", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory6_1()
{
	showScreen();
	showChar(character[15]);
	printName("      �� �� ��");
	printScript("(ū�ϳ���. ��ֹ� ������ �������� ������ �� ���������̾�...)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  �� �� �� �� ��");
	printScript("�̽��� ��, ��Ȳ���� ������.", GRAY,
		"�������� �׾ư��� ���� �ذ�å�� ���� �̴ϴ�.", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      �� �� ��");
	printScript("��... �˰ڽ��ϴ�.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[26]);
	printName("  �� �� �� �� ��");
	printScript("�̹� ���ַ� ���� �̻�, �̹� ��ȸ�� �ִ��� �ذ��ؾ� �ؿ�.", GRAY,
		"��� �� ����� �տ� �޷��ֽ��ϴ�.", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory7()
{
	showScreen();
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("���ƿ�, �̽��� ��. ���� �����ο� ����̿���.", GRAY,
		"�̴�ζ�� ��ǥ���� �ݹ� ä��ڽ��ϴ�.", GRAY,
		"", GRAY);
	eraseChar();
	printName("      �� �� ��");
	printScript("", GRAY,
		"                       (����----- ����----- ����----- ����----- ����----- ����-----)", RED,
		"", BLUE);
	showChar(character[16]);
	printName("      �� �� ��");
	printScript("��.. �̰� ���� �Ҹ��ϱ�?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  �� �� �� �� ��");
	printScript("�̷� ����.... ū���Դϴ�. �̽��� ��! ��������� ������ �߷±� �ȿ� ���鼭", GRAY,
		"�߷��� ������ �ޱ� �����߾��!", GRAY,
		"", GRAY);
	showChar(character[16]);
	printName("      �� �� ��");
	printScript("��.. �׷� ��� �Ǵµ���?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  �� �� �� �� ��");
	printScript("�߷� ���ӵ� ������ ��������� �̵��ӵ��� �ް��ϰ� ���� �̴ϴ�.", GRAY,
		"��������� ���� �߷¿� ������ ������������ ���� ��ġ���� �ؿ�!", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      �� �� ��");
	printScript("(�̰� �Ʒ� �߿��� ���� �� �� ���ݾ�....)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  �� �� �� �� ��");
	printScript("į �ٿ�! �̽��� ��, �̷� ���ϼ��� ħ���ؾ� �մϴ�.", GRAY,
		"�θ����ذ� �߻��� ���� �ִٱ���!", GRAY,
		"", GRAY);
	showChar(character[13]);
	printName("      �� �� ��");
	printScript("(ħ���϶��ž� �����ž�...)", BLUE,
		"", GRAY,
		"", BLUE);
	printName("      �� �� ��");
	printScript("(���ڱ� ������� ���δ�. ���� ���� �Ȱǰ�?)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[17]);
	printName("      �� �� ��");
	printScript("(���� ��, �ڱ� �ڽ��� �Ͼ�� �ϳ�!)", GREEN,
		"", GRAY,
		"", BLUE);
	showChar(character[13]);
	printName("      �� �� ��");
	printScript("(�ϴ� ������ ������.)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[26]);
	printName("  �� �� �� �� ��");
	printScript("���� �ð��� �ֽ��ϴ�. ������ �ذ��Ѵٸ� �ƹ� ���� ���� �ſ���.", GRAY,
		"�̽��� ��, ����� �ɷ��� �����ּ���!", GRAY,
		"", GRAY);
	showRS();
}

void StoryContainer::showStory7_1()
{
	showScreen();
	showChar(character[15]);
	printName("      �� �� ��");
	printScript("(�ɸ��� ����.... ������ ���غôµ� ��� �϶��ž�...!)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  �� �� �� �� ��");
	printScript("�̽��� ��, ������ �Ǽ��� �ؾ��������.", GRAY,
		"���� ó���ؾ� �� ��������� ���� ���ҽ��ϴ�!", GRAY,
		"", GRAY);
	showChar(character[14]);
	printName("      �� �� ��");
	printScript("(�׷�, ������ �� ���� �ӹ��� ��������!)", BLUE,
		"", GRAY,
		"", BLUE);
	showRS();
}

void StoryContainer::showStory8()
{
	showScreen();
	showChar(character[12]);
	printName("      �� �� ��");
	printScript("(��... �س´�....)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[24]);
	printName("  �� �� �� �� ��");
	printScript("�̽��� ��! ����� �س½��ϴ�! ����� ������ ��Ų �̴ϴ�!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[12]);
	printName("      �� �� ��");
	printScript("���� �� ���� �ǰ���...?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("��, �����߾��. ���� ������ ��ȯ�ϵ��� �սô�.", GRAY,
		"", GRAY,
		"", GRAY);
	eraseChar();
	printName("");
	printScript("", BLUE,
		"                                        <�̱� NASA �ɳ׵� ���ּ���>", GREEN,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("(���� ������ ���ƿԴ�.)", BLUE,
		"", GRAY,
		"", BLUE);
	printScript("(������ ���İ� �� �ݱ��.)", BLUE,
		"", GRAY,
		"", BLUE);
	eraseChar();
	printName("  �� �� �� �� ��");
	printScript("�農��! �農��! �農��! �農��! �農��! �農��!", GREEN,
		"", GRAY,
		"", GRAY);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("�̽��� ��, ��� ���ҽ��ϴ�. ���� ����� ������ ����ο���.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("�ڻ��, �� ����� ���� �� �ֽ��ϴ�.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("���ϱ�?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("�� ���� �̽��� ���̶�� �θ�����?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("����� ��Ʈ ������ Bong �ƴմϱ�?", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("Kim�Դϴ�.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[23]);
	printName("  �� �� �� �� ��");
	printScript(".....", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript(".....", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[26]);
	printName("  �� �� �� �� ��");
	printScript("�̾��մϴ�, �̽��� Ŵ.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("�ƴ�, �������ϴ�.", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[25]);
	printName("  �� �� �� �� ��");
	printScript("�װͺ���, �̽��� Ŵ�� ��ٸ��� ����� �־��. � �������� �ؿ�.", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[1]);
	printName("      �� �� ��");
	printScript("(������...?)", BLUE,
		"", GRAY,
		"", BLUE);
	showChar(character[4]);
	printScript("(�ƴ�.. �����?)", BLUE,
		"", GRAY,
		"", BLUE);
	printScript("�����, �̱����� ���..?", GRAY,
		"", GRAY,
		"", BLUE);
	showChar(character[19]);
	printName("      �� �� ��");
	printScript("�ڳװ� ���� ���ķ� ��ȸ ���� �߾���.", GRAY,
		"���� ���� �ʹ� �����ƴ� �� ���Ƽ� ���̾�.", GRAY,
		"", GRAY);
	printScript("���� �ڳ׸� �ʹ� �������ߴ���. �� ����ϰ� �;� ã�ƿԳ�", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[7]);
	printName("      �� �� ��");
	printScript("�ƴմϴ�, �����. ������� �ƴϾ��ٸ� ���� �� �ڸ����� ���� ������ �ſ���.", GRAY,
		"", GRAY,
		"", GRAY);
	printScript("���ֿ����� ���� ������ ������� ������ ���ö� ��⸦ ������ϴ�.", GRAY,
		"������� �� ����� �����̽ʴϴ�.", GRAY,
		"", GRAY);
	showChar(character[22]);
	printName("      �� �� ��");
	printScript("���� ��...!!", GRAY,
		"", GRAY,
		"", GRAY);
	showChar(character[11]);
	printName("      �� �� ��");
	printScript("�����...!!", GRAY,
		"", GRAY,
		"", BLUE);
	eraseChar();
	printName("");
	printScript("���� ������� ������ ���� ������ �� �農��.", GREEN,
		"", GREEN,
		"", GRAY);
	printScript("���� �̸��� ������ �и������ε鿡�� �θ� �˷�����,", GREEN,
		"", GREEN,
		"", GRAY);
	printScript("�׷��� �״� ������ ó������ ������ �Ǿ���.", GREEN,
		"", GREEN,
		"", GRAY);
	printScript("", BLUE,
		"                                                    - �� -", GREEN,
		"", GRAY);
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
