#include "DxLib.h"
#include "math.h"
#include "stdlib.h"

const char TITLE[] = "�w�Дԍ����O�F�^�C�g��";

const int WIN_WIDTH = 1920; //�E�B���h�E����
const int WIN_HEIGHT = 1080;//�E�B���h�E�c��
//-��鎖-//
//-BGM�̑{���ƑI�l-//
//�^�C�g��
//����
//�X�e�[�W�I��
//���[���b�p(�X�e�[�W1)
//�퍑(�X�e�[�W2)
//�G�W�v�g(�X�e�[�W3)
//�N���A
//�Q�[���I�[�o�[
//-SE�̑{���ƑI�l-//
//�v���C���[���������̉�
//�G�l�~�[���������̉�
//�G���v���C���[�𔭌��������̉�
//�G���x���炷��
//�A�C�e�����l�����鎞�̉�
//�X�L���𔭓����鎞�̉�
//�G���E�����̉�>>�摜�̃A�j���[�V�����̓K���K���ōĐ�
//�G���B�����̉�>>�摜�̃A�j���[�V�����̓K���K���ōĐ�
//�G���v���C���[���E�����̉�
//�v���C���[���͐s���鎞�̉�
//��ʂ��؂�ւ�鎞�̉�
//-�摜�̍쐬-//
//�Q�[���̔w�i�̍쐬
//�L�����N�^�[�̍쐬
//�v���C���[(�A�^�b�J�[)
//�v���C���[(�X�s�[�h)
//�G�l�~�[
//�A�C�e���̍쐬
//�}�b�v�̑S�̂�\������A�C�e��
//�G�l�~�[�̓������~�߂�A�C�e��
//�}�b�v�S�̂�������̂�����������A�C�e��
//�v���C���[�̎��ӂ��Ƃ炷�摜(������)
//�e�摜�̓ǂݍ���
//�X�e�[�W�̍쐬
//���[���b�p(�X�e�[�W1)�̃f�o�b�N
//�퍑(�X�e�[�W2)�̃f�o�b�N
//�G�W�v�g(�X�e�[�W3)�̃f�o�b�N
//���[���b�p(�X�e�[�W1)�̃}�b�v�`�b�v���m�̏Փ˔���
//�퍑(�X�e�[�W2)�̃}�b�v�`�b�v���m�̏Փ˔���
//�G�W�v�g(�X�e�[�W3)�̃}�b�v�`�b�v���m�̏Փ˔���
//�G�̋����ݒ�
//�v���C���[�̋����ݒ�

//���i�K�Ŏv�����^�X�N���������̂Ŋe���m�F���Ċ���������
//�����̏���[>>����]�ƕt���Đ؂���&�\��t�����ĉ�����

//-����-//>>����������[>>����]��t���Ă��́���

//-���k����m�F��������-//>>�����m�F���������������炱�́���
//�o����΍��񓱓��������̂��A�L�[�̓��͏��̔�����֐��ɂ��Ď���������>>�O�Ɉ���낤�Ƃ������Ǐ��������킩��񂩂���

//-�r���̎��⌻�i�K�Ŏ��g��ł��鎖-//
//�����g��ł��鎖��[>>�����̖��O(�i�s�x���� EX:6����)]�Ə����Ă��́���


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);						//�E�B���h�E���[�h�ɐݒ�
	//�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// �^�C�g����ύX
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�i���j�^�[�̉𑜓x�ɍ��킹��j
	SetWindowSizeExtendRate(1.0);				//��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
	SetBackgroundColor(0x00, 0x00, 0x00);		// ��ʂ̔w�i�F��ݒ肷��

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1) { return -1; }

	//�i�_�u���o�b�t�@�j�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	//-�w�i
	int TitleG = LoadGraph("TITLE.png");//�^�C�g���摜
	int ExplanationG = LoadGraph(".png");//�����摜
	int ChoiseG = LoadGraph("SELECTGRAPH2.png");//�X�e�[�W�I���摜
	int EuropeG = LoadGraph("GEMA_BACKGROUND1.png");//�X�e�[�W1>>19���I���[���b�p�摜
	int SengokuG = LoadGraph("GEMA_BACKGROUND.png");//�X�e�[�W2>>�퍑����摜
	int EgyptG = LoadGraph("GEMA_BACKGROUND1.png");//�X�e�[�W3>>�Ñ�G�W�v�g�摜
	int ClearG = LoadGraph("CLEARGRAPH.png");//�N���A�摜
	int GameOverG = LoadGraph("GAMEOVERGRAPH.png");//�Q�[���I�[�o�[�摜
	int GemeSceneG = LoadGraph("GEMA_BACKROUND1.png");//�Q�[���V�[���̔w�i(���)�摜
	int GameScene2G = LoadGraph("GameSceneGrap@h1-1.png");//�Q�[���V�[����O�̉摜

	//-�v���C���[
	//-������
	//-��ver.
	int Player_Front = LoadGraph("Player_Live(2).png");//�v���C���[(�A�^�b�J�[)�̒ʏ�摜
	//-��ver.
	int Player_Back = LoadGraph("Player_Live.png");
	//-�Ever.
	int Player_Right = LoadGraph("Player_Live(4).png");
	//-��ver.
	int Player_Left = LoadGraph("Player_Live(3)");

	//-�G�l�~�[
	//-������
	//-��ver.
	int EnemyUpG = LoadGraph("SENGOKU_ENEMY2.png");//�G�l�~�[�̒ʏ�摜
	//-��ver.
	int EnemyDownG = LoadGraph("SENGOKU_ENEMY.png");
	//-�Ever.
	int EnemyRightG = LoadGraph("SENGOKU_ENEMY3.png");
	//-��ver.
	int EnemyLeftG = LoadGraph("SENGOKU_ENEMY4.png");

	//�u���b�N�̉摜
	int Block1 = LoadGraph("Stage1_Block.png");//���F�̃u���b�N�̉摜��ǂݍ���
	int Block2 = LoadGraph("Stage1_Block2.png");//���F�̃u���b�N�̉摜��ǂݍ���
	int Block3 = LoadGraph("Stage1_Block3.png");//���F�̃u���b�N�̉摜��ǂݍ���

	int RED = GetColor(255, 0, 0);

	//�����Ă�A�C�e���̉摜
	int StanGun = LoadGraph("StanGun.png");//�g���Ƒ���̓������~�߂�
	int StanGunBullet_0 = LoadGraph("StanGunBullet_0.png");//������p�̒e�̉摜
	int StanGunBullet_1 = LoadGraph("StanGunBullet_1.png");//�������p�̒e�̉摜
	int StanGunBullet_2 = LoadGraph("StanGunBullet_2.png");//�������p�̒e�̉摜
	int StanGunBullet_3 = LoadGraph("StanGunBullet_3.png");//�E�����p�̒e�̉摜

	//�G�́i�����ʁj�摜
	int Enemy_Front = LoadGraph("EOUROP_ENEMY2-2.png");//�O����
	int Enemy_Back = LoadGraph("EOUROP_ENEMY.png");//�����
	int Enemy_Right = LoadGraph("EOUROP_ENEMY3.png");//�E����
	int Enemy_Left = LoadGraph("EOUROP_ENEMY4.png");//������

	int Battery = LoadGraph("Battery.png");//�G���Ɛ������Ԃ𑝂₷
	int Bread = LoadGraph("Bread.png");//�v���C���[��HP��
	int Sunflower = LoadGraph("SunFlower.png");//�ڕW��(�������S�[��)

	const int BlockSize = 64;//�P�̃u���b�N�̑傫��(���̑傫���ŃL�����N�^�[��A�C�e���̑傫�������킹��)

	//-��
	//�X�e�[�W1>>19���I���[���b�p
	int EuropTre = LoadGraph("SunFlower.png");//�X�e�[�W1�̕�摜
	//EuropTre>>EuropeTreasure�̗�>>�X�e�[�W1�̕�̎����w��

	//�X�e�[�W2>>�퍑����
	int SengokuTre = LoadGraph("KATANA_GRAPH.png");//�X�e�[�W2�̕�摜
	//SengokuTreasure�̗�>>�X�e�[�W2�̕�̎����w��

	//�X�e�[�W3>>�Ñ�G�W�v�g
	int EgyptTre = LoadGraph(".png");//�X�e�[�W3�̕�摜
	//EgyptTreasyre�̗�>>�X�e�[�W3�̕�摜�̎����w��

	//-�A�C�e��

	//-HUD
	int HUDGRAPH = LoadGraph("GameSceneGraph1-1.png");
	//HUD(�^�C�}�[��HP,�}�b�v�\�����[�^�[��������HUD�̉摜)
	//>>�v���O�����̏ォ�珇�ɃQ�[���V�[���w�i�A�X�e�[�W�AHUD�摜�̏���
	//�ォ�珑���Ƃ����Ǝv��

	//-�A�C�e���̃A�C�R�����I���\��Ԃɂ��鎖�������Ԙg�̉摜(��)
	int AICONLEFT = LoadGraph("AICON(L).png");

	//-�A�C�e���̃A�C�R�����I���\��Ԃɂ��鎖�������Ԙg�̉摜(�^��)
	int AICONSENTER = LoadGraph("AICON(S).png");

	//-�A�C�e���̃A�C�R�����I���\��Ԃɂ��鎖�������Ԙg�̉摜(�E)
	int AICONRIGHT = LoadGraph("AICON(R).png");

	//-�v���C���[��HP�̉摜
	//-FULLver.
	int FULLHP = LoadGraph("HP(FULL)-HUD.png");//HP���t����Ԃ̉摜

	//-2�i�K��
	int SECONDHP = LoadGraph("HP(2)-HUD.png");//HP����i�K�ڂ̏�Ԃ̉摜

	//-1�i�K��
	int FIRSTHP = LoadGraph("HP(1)-HUD.png");//HP����i�K�ڂ̏�Ԃ̉摜

	//-�}�b�v�S�̕\�����Ԃ�\�����[�^�[�̉摜
	//-FULLver.
	int FULLMETTER = LoadGraph("MAPMATTER(FULL).png");
	//�}�b�v�S�̕\���̃��[�^�[�̎c�莞�Ԃ��t����Ԃ̉摜

	//-��i�K��
	int SECONDMETTER = LoadGraph("MAPMATTER(2).png");
	//�}�b�v�S�̕\���̃��[�^�[�̎c�莞�Ԃ���i�K�ڂ̏�Ԃ̉摜

	//-��i�K��
	int FIRSTMETTER = LoadGraph("MAPMATTER(1).png");
	//�}�b�v�S�̕\���̃��[�^�[�̎c�莞�Ԃ���i�K�ڂ̏�Ԃ̉摜

	//-�^�C�}�[�̎��Ԃ�`�����摜
	//-5��
	int TIMERFIVE = LoadGraph("Timer(5minits).png");//05:00

	//-4��
	int TIMEFOUR = LoadGraph("Timer(4minits).png");//04:00

	//-3��
	int TIMETHREE = LoadGraph("Timer(3minits).png");//03:00

	//-2��
	int TIMETWO = LoadGraph("Timer(2minits).png");//02:00

	//-1��
	int TIMEONE = LoadGraph("Timer(1minits).png");//01:00

	//-0��
	int TIMEZERO = LoadGraph("Timer(0minits).png");//00:00

	//-UI
	int STAGEAICONLEFT = LoadGraph("LEFT_STAGE.png");
	//�X�e�[�W�I�����ɂǂ̃X�e�[�W���I������Ă��邩�𗝉�������ׂ�
	//�I�����ɕ`�悷��g�̉摜(��)

	int STAGEAICONSENTER = LoadGraph("SENTER_STAGE.png");
	//�X�e�[�W�I�����ɂǂ̃X�e�[�W���I������Ă��邩�𗝉�������ׂ�
	//�I�����ɕ`�悷��g�̉摜(�^��)

	int STAGEAICONRIGHT = LoadGraph("RIGHT_STAGE.png");
	//�X�e�[�W�I�����ɂǂ̃X�e�[�W���I������Ă��邩�𗝉�������ׂ�
	//�I�����ɕ`�悷��g�̉摜(�E)

	int blind = LoadGraph("blind.png");

	//-�}�b�v�`�b�v�̉摜-//
	//-��
	int MITIBLOCK = LoadGraph("MITIGRAPH.png");//���̂�̃}�b�v�`�b�v�̉摜
	//-��
	int KABEBLOCK = LoadGraph("KABEGRAPH.png");//�ǂ̃}�b�v�`�b�v�̉摜

	//-BGM�̓ǂݍ���-//
	//�^�C�g��
	int TitleBGM = LoadSoundMem(".mp3");//�^�C�g���V�[���ōĐ�����BGM
	//����
	int ExplanationBGM = LoadSoundMem(".mp3");//�����V�[���ōĐ�����BGM
	//�X�e�[�W�I��
	int ChoiseBGM = LoadSoundMem(".mp3");//�X�e�[�W�I���V�[���ōĐ�����BGM
	//�X�e�[�W1>>19���I���[���b�p
	int EuropeBGM = LoadSoundMem(".mp3");//19���I���[���b�p>>�X�e�[�W1�ōĐ�����BGM
	//�X�e�[�W2>>�퍑����
	int SengokuBGM = LoadSoundMem(".mp3");//�퍑����>>�X�e�[�W2�ōĐ�����BGM
	//�X�e�[�W3>>�Ñ�G�W�v�g
	int EgyptBGM = LoadSoundMem(".mp3");//�Ñ�G�W�v�g>>�X�e�[�W3�ōĐ�����BGM
	//�N���A
	int ClearBGM = LoadSoundMem(".mp3");//�N���A�V�[���ōĐ�����BGM
	//�Q�[���I�[�o�[
	int GameOvaeaBGM = LoadSoundMem(".mp3");//�Q�[���I�[�o�[�V�[���ōĐ�����BGM
	//�X�L��������
	int SkillBGM = LoadSoundMem(".mp3");//�X�L���������ɍĐ�����BGM

	//-SE-//
	//�{�^�����͎���SE
	int InputSE = LoadSoundMem(".mp3");//�{�^���̓��͂����������ɍĐ�����SE
	//Input>>���͂̈Ӗ�
	//�X�L����������SE
	int SkillSE = LoadSoundMem(".mp3");//�X�L���𔭓�����{�^���̓��͂����������ɍĐ�����SE
	//���Ԑ؂��m�点��SE
	int TimeUpSE = LoadSoundMem(".mp3");//���Ԑ؂�̎��ɗ���SE
	//�x���炷SE
	int EneAlarmSE = LoadSoundMem(".mp3");//�G�l�~�[���x���炷SE


	//�Q�[�����[�v�Ŏg���ϐ��̐錾
	char keys[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���

	//�V�[�������p�̕ϐ��̐ݒ�
	enum SceneNo
	{
		TITLE,//�^�C�g��
		EXPLANATION,//�����V�[��
		CHOISE,//�X�e�[�W�I��
		EUROPE,//�X�e�[�W1>>19���I���[���b�p
		SENGOKU,//�X�e�[�W2>>�퍑����
		EGYPT,//�X�e�[�W3>>�Ñ�G�W�v�g
		CLEAR,//�N���A�V�[��
		GAMEOVER,//�Q�[���I�[�o�[�V�[��
	};

	SceneNo GameScene = TITLE;//�ŏ��̃V�[�����^�C�g���Ɏw��

	enum
	{
		OFF,//0�̒l���ϐ�OFF�ɓ���
		ON,//1�̒l���ϐ�ON�ɓ���
	};

	//-�X�e�[�W�̐ݒ�p�̕ϐ��̐ݒ�-//
	int MapX = 0;//X����
	int MapY = 0;//Y����

	//-�Q�[���V�X�e���̐ݒ�-// >> <(*)�͒��ӎ����̈Ӗ�>
	//-�v���C���[(�A�^�b�J�[)
	int PlayerAX = 0;//X���W
	int PlayerAY = 0;//Y���W
	int PlayerAR = 32;//���a
	int PlayAVel = 2;//�ړ���
	//PlaterAVelocity>>�v���C���[(�A�^�b�J�[)�̈ړ��̑���
	int PlayerAliveF = 1;//�v���C���[�̐������Ǘ�����t���O
	//PlayerAliveF>>PlayerAliveFlag�̗�
	//>>�A�^�b�J�[�ƃX�s�[�h�̗����ɋ��ʂ�����ϐ��Ƃ���(*)

	int c1 = 0, c2=0, c3=0, c4=0;
	int OldPlayerX;
	int OldPlayerY;

	//-�v���C���[(�X�s�[�h)
	int PlayerSX = 0;//X���W
	int PlayerSY = 0;//Y���W
	int PlayerSR = 0;//���a
	int PleySVel = 0;//�ړ���
	//PlaterSVelocity>>�v���C���[(�X�s�[�h)�̈ړ��̑���

	//-�G�l�~�[
	int EnemyX = 0;//X���W
	int EnemyY = 0;//Y���W
	int EnemyR = 32;//���a
	int EnemyVel = 2;//�ړ���
	//EnemyVelocity>>�G�l�~�[�̈ړ��̑���
	int EneAlarmT = 0;//�����l��0�Œl�𑝉������ăJ�E���g����>> 50�t���[����1�b��
	//>>�G�l�~�[���v���C���[�𔭌����Ă���x���炷�܂ł�
	//���Ԃ��J�E���g����ϐ�
	//EneAlarmT>>EnemyAlarmTimer�̗�>>�x���炷�܂ł̎��Ԃ��J�E���g���鎞�Ɏg�p
	int EneAliveF = 1;//�G�l�~�[�̐������Ǘ�����t���O
	//EneAliveF>>EnemyAliveFlag�̗�

	//-��
	//�G��
	int PaintingX = 0;//X���W
	int PaintingY = 0;//Y���W
	int PaintingR = 0;//���a

	//��
	int KatanaX = 0;//X���W
	int KatanaY = 0;//Y���W
	int KatanaR = 32;//���a

	//�y���_���g
	int PendantX = 0;//X���W
	int PendantY = 0;//Y���W
	int PendantR = 0;//���a

	//-�A�C�e��
	//�G�l�~�[���~�߂�A�C�e��
	int EneStopX = 0;//X���W
	int EneStopY = 0;//Y���W
	int EneStopR = 0;//���a
	int EneStopF = 0;//�A�C�e���l���Ǘ��p�ϐ�>>�l���O=0(OFF),�l����=1(ON)
	//EneStopF>>EnemyStopFlag�̗�
	int EneStopC = 0;//�X�L���̔������Ԃ��J�E���g����ϐ�
	//�����l��0�Œl�𑝉������ăJ�E���g����>>50�t���[����1�b��
	//EneStopC>>EnemyStopCount�̗�

	//�}�b�v�S�̂�\������A�C�e��
	int FullMapX = 0;//X���W
	int FullMapY = 0;//Y���W
	int FullMapR = 0;//���a
	int FullMapF = 0;//�A�C�e���l���Ǘ��p�ϐ�>>�l���O=0(OFF),�l����=1(ON)
	//FullMapF>>FullMapFlag�̗�
	int FullMapC = 0;//�}�b�v�S�̂�\�����鎞�Ԃ��J�E���g����ϐ�
	//�����l��0�Œl�𑝉������ăJ�E���g����>>50�t���[����1�b��

	//�}�b�v�S�̂̕\�����Ԃ����΂��A�C�e��
	int FMTimeX = 0;//X���W
	int FMTimeY = 0;//Y���W
	int FMTimeR = 0;//���a
	//FMTime>>FullMapTime�̗�
	int FMTimeF = 0;//�A�C�e���l���Ǘ��p�ϐ�>>�l���O=0(OFF),�l����=1(ON)
	//FMTimeF>>FullMapTimeFlag�̗�


	//�v���C���[��HP���񕜂���A�C�e��
	int HPUpX = 0;//X���W
	int HPUpY = 0;//Y���W
	int HPUpR = 0;//���a
	int HPUpF = 0;//�A�C�e���l���Ǘ��p�ϐ�>>�l���O=0(OFF),�l����=1(ON)

	//-�v���C���[�̏㉺���E�̉摜���L�[���͏��ɍ��킹��
	//���������̉摜��`�悷��ׂ̕`��ԍ���ݒ�
	int PlayerDrawNum = 3;//�ŏ��͉E���������Ă���
	//0�̎�>>��/1�̎�>>��/2�̎�>>��/3�̎�>>�E

	//�G�̕����ʂ̉摜��`����Ǘ�����ϐ��̐ݒ�
	int EnemyDrawNum = 0;
	//0�̎�>>��/1�̎�>>��/2�̎�>>��/3�̎�>>�E

	//-�G�̍��W�ݒ�
	//-�G1
	int EnemyX1 = 192;
	int EnemyY1 = 704;
	//int EnemyR = 32;//���a�͊F����
	//-�G2
	int EnemyX2 = 704;
	int EnemyY2 = 1472;

	//-�G�̈ړ���
	int EnemyVelX = 3;//�������̈ړ���
	int EnemyVelY = 3;//�c�����̈ړ���
	//-�G�̕`��������Ǘ�����ϐ��̐ݒ�
	int EnemyDrawNum1 = 0;//�㉺
	int EnemyDrawNum2 = 1;//���E

	int PlayerX = 128;//�v���C���[�̏������W
	int PlayerY = 320;
	//�v���C���[�̌�����ԍ��Ŋ���U��(�O����A�P�����A�Q�����A�R���E)
	int PlayerVel = 3;//�v���C���[�̈ړ����x
	//�v���C���[�̍��W���m�ۂ��邽�߂̕ϐ�
	int Empty = 0;
	//0�̓_���[�W�Ȃ��P�͈��_���[�W���󂯂Ă���Q�͓��_���[�W���󂯂Ă���
	int damage = 0;
	//�_���[�W���󂯂����̃t���O
	int DamageFlag = 0;

	//�G�Ɏg���ϐ�
	//�G�̉������p�̍��W
	int EnemyX_0 = 576;
	int EnemyY_0 = 256;

	//�G�̍������p�̍��W
	int EnemyX_1 = 1344;
	int EnemyY_1 = 1344;

	//�G�̑O�����p�̍��W
	int EnemyX_2 = 576;
	int EnemyY_2 = 960;

	//�G�̉E�����p�̍��W
	int EnemyX_3 = 192;
	int EnemyY_3 = 1344;

	//int EnemyR = 32;//�G�̔��a
	//int EnemyVelX = 2;//�G�̉��̈ړ����x
	//int EnemyVelY = 2;//�G�̏c�̈ړ����x
	//int EnemyDrawNum1 = 0;//�G�̕�����ԍ��Ŋ���U��(�㉺)
	//int EnemyDrawNum2 = 1;//�G�̕�����ԍ��Ŋ���U��(���E)

	//�A�C�e���Ɏg���ϐ�
	int HP = 3;//�v���C���[��HP
	const int HpSize = 64;//�H�ו��̑傫��
	//0�̓_���[�W�Ȃ��P�͈��_���[�W���󂯂Ă���Q�͓��_���[�W���󂯂Ă���
	int HpFlag = 1;//�t���O�����Ɖ񕜂ł���
	const int GoalSize = 64;
	//�e�̍��W
	int GunFlag = 0;//�X�^���K���ɐG�ꂽ��g����悤�ɂ��邽�߂̃t���O
	//������ɒe���ړ����邽�߂̍��W
	int bulX_0 = -32;
	int bulY_0 = -32;
	//�������ɒe���ړ����邽�߂̍��W
	int bulX_1 = -32;
	int bulY_1 = -32;
	//�������ɒe���ړ����邽�߂̍��W
	int bulX_2 = -32;
	int bulY_2 = -32;
	//�E�����ɒe���ړ����邽�߂̍��W
	int bulX_3 = -32;
	int bulY_3 = -32;

	int bulR = 32;//�e�̔��a
	int isBulletFlag = 0;//0�̎��͔��ˑO�ŗ��p�\�A�P�͔��ˌ�
	const int ItemSize = 64;//�X�^���K���Ȃǂ̑傫��

	enum Stage1 {//�ԍ��ł͂Ȃ������ł킩��₷���w��

		KUUHAKU,//0�ɕ`��(��)
		NAVYBLUE,//1�ɕ`��(���F�̃u���b�N)
		YELLOW,//2�ɕ`��(���F�̃u���b�N)
		WHITE,//3�ɕ`��(���̃u���b�N)
		BATTERY,//4�ɕ`��(�o�b�e���[)
		STANGUN,//5�ɕ`��(����)
		BREAD,//6�ɕ`��(HP�񕜃A�C�e��)
		SUNFLOWER//7�ɕ`��(�ڕW��)
	};

	//�}�b�v�̖{�́i�Q�[�����̉�ʂ̑傫���ɍ��킹�Ȃ���_���j
	//�P�U�S�̑傫���̃u���b�N�� �c�Q�T�� ���T�O�� �̑傫��
	int Stage1Map[25][50] = {

		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1},
		{1,3,3,3,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,1},
		{1,3,2,3,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,2,0,1,1,1,1,0,1,1,0,2,1,1,2,2,2,2,2,1,1,1},
		{1,3,3,3,1,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,2,0,1,1,1,1,0,0,0,0,0,2,1,2,1,1,1,2,1,1,1},
		{1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,2,2,1,1,1,0,1,1,3,1,1,1,2,0,0,0,0,0,0,1,1,1,0,2,1,2,1,2,1,2,1,1,1},
		{1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,3,2,3,1,1,2,0,1,1,1,1,0,1,1,1,0,2,1,2,2,2,1,2,1,1,1},
		{1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,1,1,1,2,0,1,1,1,1,0,1,1,1,0,2,1,1,1,1,1,1,1,1,1},
		{1,5,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,2,0,1,1,1,1,0,1,1,1,0,2,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,0,1},
		{1,0,1,1,0,1,1,0,1,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,1,0,0,0,1,3,3,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,3,1,0,1,1,0,1},
		{1,0,1,1,0,0,1,1,0,0,0,3,2,2,3,0,4,0,0,0,0,0,0,7,1,1,1,1,1,0,0,1,1,1,1,0,0,1,1,1,1,0,3,2,3,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,0,0,0,3,2,2,3,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,2,2,1,0,1,3,1,0,0,0,0,1},
		{1,1,3,1,1,0,1,1,0,0,0,1,3,3,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,2,2,1,0,0,0,0,0,1,1,0,1},
		{1,3,2,3,1,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,0,0,0,1},
		{1,1,3,1,1,0,1,1,0,0,1,1,3,3,3,1,0,1,1,0,0,1,3,3,3,0,0,0,0,1,3,3,3,1,1,0,0,1,3,3,3,1,0,0,3,0,3,0,1,1},
		{1,0,0,1,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,3,1,0,0,0,0,0,1,1,3,1,0,0,0,0,0,1,1,3,3,0,0,0,0,0,1},
		{1,1,1,0,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,0,0,1,1,0,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1},
		{1,0,0,1,1,1,0,1,0,1,0,1,1,0,0,7,1,2,1,0,0,1,2,1,0,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,0,0,0,1,0,0,0,0,1},
		{1,1,0,0,1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
		{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,3,1,3,1,1,1,1,1,0,1,1,1,1,1},
		{1,0,0,0,0,1,1,1,1,0,3,3,1,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,3,1,1,1,0,1,1,0,1,0,0,7,1},
		{1,1,1,0,1,3,3,3,1,0,0,0,0,0,1,0,0,0,0,0,0,2,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,2,2,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};

	int Stage1Height = sizeof(Stage1Map) / sizeof(Stage1Map[0]);//�c��ʃX�e�[�W�̏c�̑傫��������o��
	int Stage1Width = sizeof(Stage1Map[0]) / sizeof(Stage1Map[0][0]);//�c��ʃX�e�[�W�̉��̑傫��������o��

	//�X�N���[�����n�܂�n�_�̍��W
	int WorldposX = 0;
	int WorldposY = 0;
	//-�퍑����̃X�e�[�W�̐ݒ�-//
	//�X�e�[�W�Ŏg�p����u���b�N�̏����̐ݒ�
	enum StageBlock
	{
		MICHI,//0
		KABE,//1
		KAMON,//2
		TAKARA,//3
		BUTTELY,//4>>�o�b�e���[
		SUTANGAN,//5>>�X�^���K��
		CARE,//6>>�񕜃A�C�e��
	};

	//�X�e�[�W�}�b�v(���H)�̕`��
	//1�̃u���b�N�T�C�Y��64�̃u���b�N���c35,��32���̑傫���̃}�b�v
	int StageMap[32][35] = {

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,1,0,0,1,0,0,0,0,0,0,0},
		{0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,1,0,0,0,0,0,0,1,0,0,2,2,2,0,0},
		{1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,1,0,0,0,0,0,1,1,0,1,2,2,2,0,0},
		{0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,1,1,0,0,1,0,0,2,2,2,1,0},
		{0,1,0,0,1,0,0,1,1,1,0,0,1,6,2,2,2,2,0,1,0,0,0,1,1,0,0,1,0,0,2,2,2,1,0},
		{0,1,0,0,1,0,0,0,1,0,0,0,1,0,2,2,2,2,0,1,0,1,1,1,1,0,0,1,1,0,2,2,2,1,0},
		{0,1,0,0,1,0,0,0,0,0,0,0,0,0,2,2,2,2,0,1,0,1,0,1,1,0,0,0,0,0,2,2,2,0,0},
		{0,0,0,0,1,0,0,0,0,0,1,1,1,1,2,2,2,2,0,0,0,1,0,1,1,1,0,0,0,0,2,2,2,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,1,1,0,0,0,1,0,0,0,0,1,1,2,2,2,0,0},
		{1,0,0,0,0,0,0,0,0,0,0,1,1,1,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,0,1},
		{1,1,1,0,0,0,0,0,0,0,0,0,1,0,2,2,2,2,0,0,0,1,1,0,0,1,1,0,0,0,2,2,2,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,1,0,0,1,1,1,1,1,0,2,2,2,0,1},
		{0,0,1,0,0,1,1,0,0,0,0,1,0,0,2,2,2,2,1,0,0,1,0,0,0,1,1,0,0,0,2,2,2,0,1},
		{1,0,1,0,0,1,0,0,1,0,1,1,1,0,2,2,2,2,1,0,0,1,1,0,0,1,1,0,0,0,2,2,2,0,0},
		{1,0,1,0,0,0,0,5,1,0,0,1,4,0,2,2,2,2,1,0,0,0,0,0,0,1,1,0,0,0,2,2,2,0,0},
		{0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
		{0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0},
		{0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0},
		{0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0},
		{1,0,2,2,2,0,0,0,1,6,0,0,0,0,2,2,2,2,6,0,1,0,0,0,1,1,4,0,1,1,0,0,0,0,0},
		{0,0,2,2,2,0,0,1,1,1,1,0,0,0,2,2,2,2,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
		{0,1,2,2,2,0,0,0,1,0,0,0,1,0,2,2,2,2,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0},
		{0,0,2,2,2,1,0,0,1,0,0,0,1,0,2,2,2,2,1,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0},
		{0,0,2,2,2,0,0,0,1,1,0,0,1,0,2,2,2,2,1,0,1,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
		{1,0,2,2,2,0,0,1,1,1,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
		{1,0,2,2,2,2,0,0,0,1,0,0,0,1,2,2,2,2,0,0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0},
		{0,0,2,2,2,1,1,1,0,1,0,0,0,1,2,2,2,2,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1},
		{0,0,2,2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,1,0,0,0,0,0,0,0,3,0,0,0,0,1},
		{0,1,2,2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
		{0,1,2,2,2,1,0,0,0,0,0,0,1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0},
		{0,1,2,2,2,1,0,0,0,1,0,0,1,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},

	};

	//�X�e�[�W�̏c�̔z��̌������߂�
	int StageHight = sizeof(StageMap) / sizeof(StageMap[0]);

	//�X�e�[�W�̉��̔z��̌������߂�
	int StageWidth = sizeof(StageMap[0]) / sizeof(StageMap[0][0]);


	int Map[30][53] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,1,0,0,0},
		{0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0},
		{1,1,0,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,0,1,0},
		{0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

	};

	/*int MapX = 53;
	int MapY = 30;*/

	int MapSize = 64; //���邽�߂ɔ����ɂ��Ă�

	enum Map {
		none,
		block
	};

	//�X�N���[�����J�n����ׂ̃t���O�̐ݒ�
	int ScrollFlag = 0;

	//�X�N���[�����J�n����_(�n�_)�̍��W��ݒ�
	int WorldPosX = 0;//X���W
	//WorldPositionX�̗�
	int WorldPosY = 0;//Y���W
	//�X�N���[�����鑬���̐ݒ�
	int ScrollSpeed = 3;
	//�}�b�v�`�b�v���ł̃v���C���[��X���W�����߂�
	int PlayerIdX = (PlayerAX + WorldPosX) / BlockSize;
	//�}�b�v�`�b�v���ł̃v���C���[��Y���W�����߂�
	int PlayerIdY = (PlayerAY + WorldPosY) / BlockSize;

	// �Q�[�����[�v
	while (1)
	{
		//�ŐV�̃L�[�{�[�h��񂾂������̂͂P�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�

		//�ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		//��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		//�X�V����
		switch (GameScene)
		{
		case TITLE://�^�C�g��

			//�^�C�g����ʂ̕`��
			DrawGraph(0, 0, TitleG, TRUE);//�摜��`�悷��
			//�^�C�g���摜���k�����ĕ`�悷��
			//DrawExtendGraph(0, 0, 1920, 1080, TitleG, TRUE);//�k���`�揈��

			//-BGM�̍Đ�����-//
			//BGM���Đ�����Ă��邩�𔻕ʂ���
			//>>�^�C�g���V�[���ōĐ�����BGM���Đ�����Ă��Ȃ���
			if (CheckSoundMem(TitleBGM) == 0)//�Đ�����Ă��Ȃ���
			{
				//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��

				//-BGM�̍Đ�-//
				//>>�^�C�g���V�[���ōĐ�����BGM���Đ�
				PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�ōĐ�����
			}

			//-���̃V�[���Ɉړ�����ׂ�BGM�̒�~�E�{�^�����͎���SE�̍Đ��E�V�[���ύX�̏���-//
			//�V�[���ړ��̃��[�V����>>�{�^�����͂����������𔻒肷��
			//�X�y�[�X�L�[��������Ă��邩
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//�����ꂽ��(Tridder)
			{
				//�X�y�[�X�L�[�������ꂽ���ɂ��̃u���b�N���̏������s��

				//-BGM�̒�~����-//
				//>>BGM���Đ�����Ă��邩�𔻕ʂ���
				//>>�^�C�g���V�[���ōĐ�����BGM���Đ�����Ă��邩
				if (CheckSoundMem(TitleBGM) == 1)//�Đ�����Ă��鎞
				{
					//�Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
					//-BGM�̒�~-//
					StopSoundMem(TitleBGM);//BGM�̍Đ����~����

					//-SE�̍Đ�����-//
					//SE���Đ�
					//>>���̎�SE�̍Đ��̔��ʂ͗v��Ȃ�
					//>>�{�^�����͂����������̂�1�񂾂��Đ�����΂�����
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SE���m�[�}���Đ�����
				}

				//-�V�[���ύX����-//
				//�V�[�����^�C�g���V�[����������V�[���ɕύX����
				GameScene = EXPLANATION;//�����V�[���փV�[���ύX����
			}

			break;

		case EXPLANATION://����

			//������ʂ̕`��
			DrawGraph(0, 0, ExplanationG, TRUE);//�摜��`�悷��
			//������ʂ̉摜���k�����ĕ`�悷��
			//DrawExtendGraph(0, 0, 1541, 881, ExplanationG, TRUE);//�k���`�揈��

			//-BGM�̍Đ�����-//
			//BGM���Đ�����Ă��邩�𔻕ʂ���
			//>>�����V�[���ōĐ�����BGM���Đ�����Ă��Ȃ���
			if (CheckSoundMem(ExplanationBGM) == 0)//�Đ�����Ă��Ȃ���
			{
				//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��

				//-BGM�̍Đ�-//
				//>>�����V�[���ōĐ�����BGM���Đ�
				PlaySoundMem(ExplanationBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�ōĐ�����
			}

			//-���̃V�[���Ɉړ�����ׂ�BGM�̒�~�E�{�^�����͎���SE�̍Đ��E�V�[���ύX�̏���-//
			//�V�[���ړ��̃��[�V����>>�{�^�����͂����������𔻒肷��
			//�X�y�[�X�L�[��������Ă��邩
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//�����ꂽ��(Tridder)
			{
				//�X�y�[�X�L�[�������ꂽ���ɂ��̃u���b�N���̏������s��

				//-BGM�̒�~����-//
				//>>BGM���Đ�����Ă��邩�𔻕ʂ���
				//>>�����V�[���ōĐ�����BGM���Đ�����Ă��邩
				if (CheckSoundMem(ExplanationBGM) == 1)//�Đ�����Ă��鎞
				{
					//�Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
					//-BGM�̒�~-//
					StopSoundMem(ExplanationBGM);//BGM�̍Đ����~����

					//-SE�̍Đ�����-//
					//SE���Đ�
					//>>���̎�SE�̍Đ��̔��ʂ͗v��Ȃ�
					//>>�{�^�����͂����������̂�1�񂾂��Đ�����΂�����
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SE���m�[�}���Đ�����
				}

				//-�V�[���ύX����-//
				//�V�[��������V�[������X�e�[�W�I���V�[���ɕύX����
				GameScene = CHOISE;//�X�e�[�W�I���V�[���փV�[���ύX����

			}

			break;

		case CHOISE://�X�e�[�W�I��

			//�X�e�[�W�I���摜�̕`�揈��//
			DrawGraph(0, 0, ChoiseG, TRUE);//�摜��`��
			//�X�e�[�W�I���摜���k�����ĕ`�悷��
			//DrawExtendGraph(0, 0, 1541, 881, ChoiseG, TRUE);//�k���`�揈��

			//-���̃V�[���Ɉړ�����ׂ�BGM�̒�~�E�{�^�����͎���SE�̍Đ��E�V�[���ύX�̏���-//
			//�V�[���ړ��̃��[�V����>>�{�^�����͂����������𔻒肷��
			//�X�y�[�X�L�[��������Ă��邩
			//if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//�����ꂽ��(Tridder)
			//{
			//	//-�V�[���ύX����-//
			//	//�V�[��������V�[������X�e�[�W�I���V�[���ɕύX����
			//	GameScene = SENGOKU;//�X�e�[�W2(�퍑����)�V�[���փV�[���ύX����
			//}

			//�G�W�v�g�X�e�[�W��
			if (keys[KEY_INPUT_1] == ON && oldkeys[KEY_INPUT_1] == OFF)
			{
				GameScene = EGYPT;
			}

			//�퍑�X�e�[�W��
			if (keys[KEY_INPUT_2] == ON && oldkeys[KEY_INPUT_2] == OFF)
			{
				GameScene = SENGOKU;
			}

			//���[���b�p�X�e�[�W��
			if (keys[KEY_INPUT_3] == ON && oldkeys[KEY_INPUT_3] == OFF)
			{
				GameScene = EUROPE;
			}

			break;

		case EUROPE://�X�e�[�W1>>19���I���[���b�p

			OldPlayerX = PlayerX;
			OldPlayerY = PlayerY;
			//�Q�[���w�i�̉�ʂ�`��
			DrawGraph(0, 0, EuropeG, TRUE);//�摜��`�悷��

			//-BGM�̍Đ�����-//
			//BGM���Đ�����Ă��邩�𔻕ʂ���
			//>>�X�e�[�W1(19���I���[���b�p)�V�[���ōĐ�����BGM���Đ�����Ă��Ȃ���
			if (CheckSoundMem(EuropeBGM) == 0)//�Đ�����Ă��Ȃ���
			{
				//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��

				//-BGM�̍Đ�-//
				//>>�X�e�[�W1(19���I���[���b�p)�V�[���ōĐ�����BGM���Đ�
				PlaySoundMem(EuropeBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�ōĐ�����
			}

			//-�v���C���[(�A�^�b�J�[�ƃX�s�[�h)�̈ړ�����(����R�}���h�܂�)�ƃX�L�������V�X�e������-//
			//-�v���C���[�̈ړ�����(�A�^�b�J�[)-//
			//�ړ��L�[�̃{�^�����͂��L�������𔻒肷��
			//W�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��Y���W����ړ��ʂ̒l����͂��L��x�Ɉ����Ă���
				PlayerY -= PlayAVel;//�����[�v�v���C���[��Y���W����ړ��ʂ̒l������
				//PlayerAY = PlayerAY - PlayAVel;�Ɠ�������
			}

			//S�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂��Ă���
				PlayerY += PlayAVel;//�����[�v�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂�
				//PlayerAY = PlayerAY + PlayAVel;�Ɠ�������
			}

			//A�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//�����ꎞ
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//X��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��X���W����ړ��ʂ̒l����͂��L��x�Ɉ����Ă���
				PlayerX -= PlayAVel;//�����[�v�v���C���[��X���W����ړ��ʂ̒l�������Ă���
				//PlayerAX = PlayerAX - PlayAVel;�Ɠ�������
			}

			//D�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//X��(�E)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��X���W�Ɉړ��ʂ̒l����͂��L��x�ɑ����Ă���
				PlayerX += PlayAVel;//�����[�v�v���C���[��X���W�Ɉړ��ʂ̒l�𑫂�
				//PlayerAX = PlayerAX + PlayAVel;�Ɠ�������
			}

			

			//-����R�}���h(�_�b�V��)����-//
			//SHIFT�L�[�������ꂽ����W�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//�����ꂽ��
			//{
			//	//�����ꂽ���ɂ��̃u���b�N���̏������s��
			//	//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
			//	//>>�v���C���[��Y���W����ړ��ʂ̒l����͂�����x�Ɉ����Ă���
			//	PlayerY -= PlayAVel + PlayAVel;//�����[�v�v���C���[��Y���W����ړ��ʂ̒l������
			//	//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
			//	//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
			//	//PlayerAY -= PlayAVel + PlayAVel;>>PlayerAY = PlayerAY - (PlayAVel + PlayAVel);�Ɠ�������
			//}

			////SHIFT�L�[�������ꂽ����S�L�[�����L�[�������ꂽ��
			////>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//�����ꂽ��
			//{
			//	//�����ꂽ���ɂ��̃u���b�N���̏������s��
			//	//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
			//	//>>�v���C���[��Y���W�Ɉړ��ʂ̒l����͂�����x�ɑ����Ă���
			//	PlayerY += PlayAVel + PlayAVel;//�����[�v�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂�
			//	//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
			//	//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
			//	//PlayerAY += PlayAVel + PlayAVel;>>PlayerAY = PlayerAY + (PlayAVel + PlayAVel);�Ɠ�������
			//}

			////SHIFT�L�[�������ꂽ����A�L�[�����L�[�������ꂽ��
			////>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//�����ꂽ��
			//{
			//	//�����ꂽ���ɂ��̃u���b�N���̏������s��
			//	//X��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
			//	//>>�v���C���[��X���W����ړ��ʂ̒l����͂�����x�Ɉ����Ă���
			//	PlayerX -= PlayAVel + PlayAVel;//�����[�v�v���C���[��X���W����ړ��ʂ̒l������
			//	//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
			//	//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
			//	//PlayerAX -= PlayAVel + PlayAVel;>>PlayerAX = PlayerAX - (PlayAVel + PlayAVel);�Ɠ�������
			//}

			////SHIFT�L�[�������ꂽ����D�L�[�����L�[�������ꂽ��
			////>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//�����ꂽ��
			//{
			//	//�����ꂽ���ɂ��̃u���b�N���̏������s��
			//	//X��(�E)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
			//	//>>�v���C���[��X���W�Ɉړ��ʂ̒l����͂�����x�ɑ����Ă���
			//	PlayerX += PlayAVel + PlayAVel;//�����[�v�v���C���[��X���W�Ɉړ��ʂ̒l�𑫂�
			//	//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
			//	//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
			//	//PlayerAX += PlayAVel + PlayAVel;>>PlayerAX = PlayerAX + (PlayAVel + PlayAVel);�Ɠ�������
			//}

			//-�X�L����������-//
			//�G�l�~�[�̓������~�߂�X�L��
			//C�L�[�������ꂽ��
			//>>����̎d����Trigger�ł���
			if (keys[KEY_INPUT_C] == ON && oldkeys[KEY_INPUT_C] == OFF)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//�G�l�~�[�̓������~�߂�A�C�e�����擾���Ă��邩�𔻕ʂ���
				//�G�l�~�[�̓������~�߂�A�C�e���������Ă��邩
				if (EneStopF == ON)//�����Ă��鎞
				{
					//-SE���Đ����鏈��-//
					//SE���Đ�����Ă��邩�̔��ʂ͕K�v�Ȃ�
					//>>�{�^�����͂����������̂�1�񂾂��Đ�����΂�����
					//SE���Đ�����
					PlaySoundMem(SkillSE, DX_PLAYTYPE_NORMAL);//SE���m�[�}���Đ�����

					//�����Ă��鎞�ɂ��̃u���b�N���̏������s��
					//-�G�l�~�[�̓������~�����鏈��-//
					EnemyVel = 0;//�ړ���
					//EnemyVelocity>>�G�l�~�[�̈ړ��̑���
					//>>�G�l�~�[�̈ړ��͊e���W�Ɉړ��ʂ𑝌����Ă����
					//>>�ړ��ʂ̒l��0�ɂ��鎖�ňړ����~���鎖���\�ƂȂ�

					//�X�L���̎������Ԃ��J�E���g����
					//�J�E���g����ϐ��̒l�����l�܂ő���������
					//�J�E���g����0��
					if (EneStopC == 0)//�J�E���g����0�̎�
					{
						//-�X�L���̔������Ԃ�`����BGM>>�X�L���������ɍĐ�����BGM�̍Đ�����-//
						//�X�L���������ɍĐ�����BGM���Đ�����Ă��Ȃ���
						if (CheckSoundMem(SkillBGM) == 0)//�Đ�����Ă��Ȃ���
						{
							//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��
							PlaySoundMem(SkillBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�Đ�����
						}

						//0�̎��ɂ��̃u���b�N���̏������s��
						EneStopC += 1;//�����[�v�J�E���g����1������������

						//�J�E���g����250(5�b��)��
						if (EneStopC == 250)//�J�E���g����250(5�b��)�̎�
						{
							//250(5�b��)�̎��ɂ��̃u���b�N���̏������s��
							EneStopC = 250;//�l��250�ŌŒ肷��

							//�X�L���������~����
							//>>�X�L�������A�C�e���̊l���t���O��OFF(���l��)�ɕύX����
							EneStopF = OFF;//�t���O��OFF�ɕύX
							//>>�G�l�~�[�̈ړ����ĊJ����

							//-�X�L���̔������Ԃ�`����BGM>>�X�L���������ɍĐ�����BGM�̒�~����-//
							//�X�L���������ɍĐ�����BGM���Đ�����Ă��邩
							if (CheckSoundMem(SkillBGM) == 0)//�Đ�����Ă��鎞
							{
								//�Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
								StopSoundMem(SkillBGM);//BGM�̍Đ����~����
							}
						}
					}
				}
			}

			//-�G�l�~�[���E�����[�V�����̏���-//
			//X�L�[�������ꂽ��
			//>>����̎d����Trigger�ł���
			if (keys[KEY_INPUT_X] == ON && oldkeys[KEY_INPUT_X] == OFF)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//�G�l�~�[���v���C���[�𔭌����Ă���x���炷�܂ł�
				//���Ԃ��J�E���g����ϐ���0�ȊO���𔻕ʂ���
				//���Ԃ��J�E���g����ϐ���0�ȊO��
				if (EneAlarmT != 0)//0�ȊO�̎�
				{
					//0�ȊO�̎��ɂ��̃u���b�N���̏������s��
					//-�G�l�~�[�̐������Ǘ�����t���O��OFF(���S)�ɕύX���鏈��-//
					//�G�l�~�[�̐����t���O��ON(����)��
					if (EneAliveF == 1)//�t���O��ON(����)�̎�
					{
						//�t���O��ON�̎��ɂ��̃u���b�N���̏������s��
						//�G�l�~�[�̐����t���O��OFF(���S)�ɕύX����
						EneAliveF = 0;//�����t���O��OFF(���S)�ɕύX

						//�G�l�~�[���E���Ď��̂��B������A�j���[�V�����摜��`�悷��

					}
				}

				//-�Q�[���I�[�o�[�V�[���ւ̃V�[���ړ�����-//
				//���Ԃ��J�E���g����ϐ���0��
				else if (EneAlarmT == 0)//���Ԃ��J�E���g����ϐ���0�̎�
				{
					//�ϐ��̒l��0�̎��ɂ��̃u���b�N���̏������s��
					//SE���Đ�����
					PlaySoundMem(DX_PLAYTYPE_BACK, EneAlarmSE);//SE���o�b�N�O���E���h�Đ�����

					//�v���C���[�����ʃA�j���[�V�����摜��`�悷��

					//�Q�[���V�[����BGM���Đ�����Ă��邩
					if (CheckSoundMem(EuropeBGM) == 1)//�Đ�����Ă��鎞
					{
						//�Q�[���V�[����BGM���Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
						//BGM���~����
						StopSoundMem(EuropeBGM);//BGM���~����
						//�V�[�����X�e�[�W1(19���I���[���b�p)����Q�[���I�[�o�[�V�[���փV�[���ύX����
						GameScene = GAMEOVER;//�Q�[���I�[�o�[�V�[���փV�[���ύX����
					}
				}

			}

			//�`�揈��
			for (int y = 0; y < Stage1Height; y++)//�X�e�[�W�̏c�[�܂ŌJ��Ԃ�
			{
				for (int x = 0; x < Stage1Width; x++)//�X�e�[�W�̉��[�܂ŌJ��Ԃ�
				{
					//�O�̏ꏊ�͋�
					if (Stage1Map[y][x] == NAVYBLUE) {//�}�b�v�`�b�v��1�̏ꏊ�ɍ��F�̃u���b�N��`��
						if (abs(PlayerX + 32 - (x * BlockSize - WorldposX + 32)) < 64 && abs(PlayerY + 32 - (y * BlockSize + 32)) < 64) {
							PlayerX = OldPlayerX;
							PlayerY = OldPlayerY;
						}
						DrawGraph((x * BlockSize) - WorldposX, (y * BlockSize) - WorldposY, Block1, TRUE);
					}

					if (Stage1Map[y][x] == YELLOW) {//�}�b�v�`�b�v��2�̏ꏊ�ɉ��F�̃u���b�N��`��
						DrawGraph((x * BlockSize) - WorldposX, (y * BlockSize) - WorldposY, Block2, TRUE);
					}

					if (Stage1Map[y][x] == WHITE) {//�}�b�v�`�b�v��3�̏ꏊ�ɔ��F�̃u���b�N��`��
						DrawGraph((x * BlockSize) - WorldposX, (y * BlockSize) - WorldposY, Block3, TRUE);
					}

					if (Stage1Map[y][x] == BATTERY) {//�}�b�v�`�b�v��4�̏ꏊ�Ƀo�b�e���[��`��
						if (abs(PlayerX - (x * HpSize - WorldposX + 32)) < 80 && abs(PlayerY - (y * HpSize + 64)) < 112) {
							Stage1Map[y][x] = 0;
						}
						DrawGraph((x * ItemSize) - WorldposX, (y * ItemSize) - WorldposY, Battery, TRUE);
					}

					if (Stage1Map[y][x] == STANGUN) {//�}�b�v�`�b�v��5�̏ꏊ�ɃX�^���K����`��
						if (abs(PlayerX - (x * ItemSize - WorldposX + 32)) < 80 && abs(PlayerY - (y * ItemSize + 64)) < 112) {
							Stage1Map[y][x] = 0;
							GunFlag = 1;//1�̎��̃t���O�̏�����
						}
						DrawGraph((x * ItemSize) - WorldposX, (y * ItemSize) - WorldposY, StanGun, TRUE);
					}

					if (Stage1Map[y][x] == BREAD) {//�}�b�v�`�b�v��6�̏ꏊ�Ƀp����`��
						//�v���C���[�ƃp���̔���
						if (HpFlag == 1) {
							if (abs(PlayerX - (x * HpSize - WorldposX + 32)) < 80 && abs(PlayerY - (y * HpSize + 64)) < 112) {
								Stage1Map[y][x] = 0;
								HpFlag = 0;//0�̎��̃t���O�̏�����
							}
						}
						DrawGraph((x * HpSize) - WorldposX, (y * HpSize) - WorldposY, Bread, TRUE);
					}

					if (Stage1Map[y][x] == SUNFLOWER) {//�}�b�v�`�b�v��7�̏ꏊ�ɖڕW����`��
						DrawGraph((x * GoalSize) - WorldposX, (y * GoalSize) - WorldposY, Sunflower, TRUE);
						if (abs(PlayerX + 32 - (x * BlockSize - WorldposX + 32)) < 64 && abs(PlayerY + 32 - (y * BlockSize + 32)) < 64) {
							GameScene = CLEAR;
						}
						//�N���A�V�[����
						//GameScene = CLEAR;
					}

				}
			}

			//�X�^���K������������̏���
			if (GunFlag == 1) {
				//�e�̔���
				if (keys[KEY_INPUT_SPACE] == 1 && isBulletFlag == 0) {
					//������̏ꍇ
					if (PlayerDrawNum == 0) {
						bulX_0 = PlayerX;
						bulY_0 = PlayerY;
						isBulletFlag = 1;
					}
					//�������̏ꍇ
					if (PlayerDrawNum == 1) {
						bulX_1 = PlayerX;
						bulY_1 = PlayerY;
						isBulletFlag = 1;
					}
					//�������̏ꍇ
					if (PlayerDrawNum == 2) {
						bulX_2 = PlayerX;
						bulY_2 = PlayerY;
						isBulletFlag = 1;
					}
					//�E�����̏ꍇ
					if (PlayerDrawNum == 3) {
						bulX_3 = PlayerX;
						bulY_3 = PlayerY;
						isBulletFlag = 1;
					}
				}

				//���ˌ�̏��(�����ɂ���đł�����ς���)
				if (isBulletFlag == 1) {

					if (PlayerDrawNum == 0) {
						//������ɒe���΂�
						bulY_0 = bulY_0 - 20;
						if (bulY_0 < 64) {
							isBulletFlag = 0;
						}
					}

					if (PlayerDrawNum == 1) {
						//�������ɒe���΂�
						bulX_1 = bulX_1 - 20;
						if (bulX_1 < 64) {
							isBulletFlag = 0;
						}
					}

					if (PlayerDrawNum == 2) {
						//�������ɒe���΂�
						bulY_2 = bulY_2 + 20;
						if (bulY_2 < 64) {
							isBulletFlag = 0;
						}
					}

					if (PlayerDrawNum == 3) {
						//�E�����ɒe���΂�
						bulX_3 = bulX_3 + 20;
						if (bulX_3 < 64) {
							isBulletFlag = 0;
						}
					}
				}
			}

			//�G�̈ړ�����
			//�G�̏㉺�ړ�
			if (EnemyDrawNum1 == 0) {
				EnemyY_0 = EnemyY_0 + EnemyVelY;

				if (EnemyY_0 >= 960)
				{
					EnemyDrawNum1 = 2;
					EnemyY_2 = 960;
				}
			}

			if (EnemyDrawNum1 == 2) {
				EnemyY_2 = EnemyY_2 - EnemyVelY;

				if (EnemyY_2 <= 256)
				{
					EnemyDrawNum1 = 0;
					EnemyY_0 = 256;
				}
			}
			//�G�̕`��(�㉺)
			if (EnemyDrawNum1 == 0)
			{
				DrawGraph(EnemyX_0, EnemyY_0, Enemy_Back, TRUE);
			}

			if (EnemyDrawNum1 == 2)
			{
				DrawGraph(EnemyX_2, EnemyY_2, Enemy_Front, TRUE);
			}

			//�G�̍��E�ړ�
			if (EnemyDrawNum2 == 1) {
				EnemyX_1 = EnemyX_1 - EnemyVelX;

				if (EnemyX_1 <= 192)
				{
					EnemyDrawNum2 = 3;
					EnemyX_3 = 192;
				}
			}

			if (EnemyDrawNum2 == 3) {
				EnemyX_3 = EnemyX_3 + EnemyVelX;

				if (EnemyX_3 >= 1344)
				{
					EnemyDrawNum2 = 1;
					EnemyX_1 = 1344;
				}
			}
			//�G�̕`��(���E)
			if (EnemyDrawNum2 == 1)
			{
				DrawGraph(EnemyX_1, EnemyY_1, Enemy_Left, TRUE);
			}

			if (EnemyDrawNum2 == 3)
			{
				DrawGraph(EnemyX_3, EnemyY_3, Enemy_Right, TRUE);
			}

			//�Q�Z�b�g�ڂ̈ړ������ƕ`��
			//�Q�Z�b�g�ڂ̐V�������W(�㉺)
			 EnemyX_0 = 1920;
			 EnemyY_0 = 64;
			 EnemyX_2 = 1920;
			 EnemyY_2 = 960;

			//�Q�Z�b�g�ڂ̓G�̏㉺�ړ�
			if (EnemyDrawNum1 == 0) {
				EnemyY_0 = EnemyY_0 + EnemyVelY;

				if (EnemyY_0 >= 960)
				{
					EnemyDrawNum1 = 2;
					EnemyY_2 = 960;
				}
			}
			if (EnemyDrawNum1 == 2) {
				EnemyY_2 = EnemyY_2 - EnemyVelY;

				if (EnemyY_2 <= 64)
				{
					EnemyDrawNum1 = 0;
					EnemyY_0 = 64;
				}
			}
			//�Q�Z�b�g�ڂ̓G�̕`��(�㉺)
			if (EnemyDrawNum1 == 0)
			{
				DrawGraph(EnemyX_0, EnemyY_0, Enemy_Back, TRUE);
			}
			if (EnemyDrawNum1 == 2)
			{
				DrawGraph(EnemyX_2, EnemyY_2, Enemy_Front, TRUE);
			}

			//�Q�Z�b�g�ڂ̐V�����G�̍��W(���E)
			 EnemyX_1 = 1344;
			 EnemyY_1 = 1216;
			 EnemyX_3 = 2280;
			 EnemyY_3 = 1216;

			if (EnemyDrawNum2 == 1) {
				EnemyX_1 = EnemyX_1 - EnemyVelX;

				if (EnemyX_1 <= 1344)
				{
					EnemyDrawNum2 = 3;
					EnemyX_3 = 1344;
				}
			}

			if (EnemyDrawNum2 == 3) {
				EnemyX_3 = EnemyX_3 + EnemyVelX;

				if (EnemyX_3 >= 2280)
				{
					EnemyDrawNum2 = 1;
					EnemyX_1 = 2280;
				}
			}
			//�Q�Z�b�g�ڂ̓G�̕`��(���E)
			if (EnemyDrawNum2 == 1)
			{
				DrawGraph(EnemyX_1, EnemyY_1, Enemy_Left, TRUE);
			}

			if (EnemyDrawNum2 == 3)
			{
				DrawGraph(EnemyX_3, EnemyY_3, Enemy_Right, TRUE);
			}

			//�G�ƒe�̔���(���Ă�ƓG�̓������~�܂�)
			if (EnemyDrawNum1 == 0)
			{
				//2�_�Ԃ̋���
				float length = sqrtf((EnemyX_0 - bulX_0) * (EnemyX_0 - bulX_0) + (EnemyY_0 - bulY_0 - bulR) * (EnemyY_0 - bulY_0 - bulR));
				//�Փ�
				if (length <= EnemyR + bulR)
				{
					isBulletFlag = 0;
					bulX_0 = -32;
					bulY_0 = -32;
					EnemyVelY = 0;
				}
			}

			//�X�^���K���̒e�̕`��
			if (isBulletFlag == 1) {
				if (PlayerDrawNum == 0) {
					DrawGraph(bulX_0, bulY_0 - bulR, StanGunBullet_0, TRUE);
				}
				if (PlayerDrawNum == 1) {
					DrawGraph(bulX_1, bulY_1 + bulR, StanGunBullet_1, TRUE);
				}
				if (PlayerDrawNum == 2) {
					DrawGraph(bulX_2, bulY_2 - bulR, StanGunBullet_2, TRUE);
				}
				if (PlayerDrawNum == 3) {
					DrawGraph(bulX_3 + bulR, bulY_3 + bulR, StanGunBullet_3, TRUE);
				}
			}

			//�H�ו��ɐG����HP����
			if (HpFlag == 0) {
				HP = HP + 1;
				//�G��ē��_������������̂�h��
				HpFlag = 1;
			}

			//�v���C���[�̕`��
			if (PlayerDrawNum == 0) {//�O�̎��ɏ����
				DrawGraph(PlayerX, PlayerY, Player_Front, TRUE);
			}
			if (PlayerDrawNum == 1) {//�P�̎��ɍ�����
				DrawGraph(PlayerX, PlayerY, Player_Left, TRUE);
			}
			if (PlayerDrawNum == 2) {//�Q�̎��ɉ�����
				DrawGraph(PlayerX, PlayerY, Player_Back, TRUE);
			}
			if (PlayerDrawNum == 3) {//�R�̎��ɉE����
				DrawGraph(PlayerX, PlayerY, Player_Right, TRUE);
			}

			DrawExtendGraph(PlayerX - 2033, PlayerY - 2033, PlayerX + 2096, PlayerY + 2096, blind, TRUE);

			//�Q�[���V�[���w�i��O�̉摜
			DrawExtendGraph(0, 0, 1541, 881, GameScene2G, TRUE);//�k���`�揈��
			DrawGraph(0, 0, GameScene2G, TRUE);

			DrawFormatString(0, 0, RED, "%d", c1);
			DrawFormatString(5, 0, RED, "%d", c2);
			DrawFormatString(10, 0, RED, "%d", c3);
			DrawFormatString(15, 0, RED, "%d", c4);
			break;

		case SENGOKU://�X�e�[�W2>>�퍑����

			//�Q�[���w�i�̉�ʂ�`��>>1�Ԍ��ɕ`�悷��w�i�摜
			DrawGraph(0, 0, GemeSceneG, TRUE);//�摜��`�悷��

			//-BGM�̍Đ�����-//
			//BGM���Đ�����Ă��邩�𔻕ʂ���
			//>>�X�e�[�W2(�퍑����)�V�[���ōĐ�����BGM���Đ�����Ă��Ȃ���
			if (CheckSoundMem(SengokuBGM) == 0)//�Đ�����Ă��Ȃ���
			{
				//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��

				//-BGM�̍Đ�-//
				//>>�X�e�[�W2(�퍑����)�V�[���ōĐ�����BGM���Đ�
				PlaySoundMem(SengokuBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�ōĐ�����
			}

			//-�v���C���[(�A�^�b�J�[�ƃX�s�[�h)�̈ړ�����(����R�}���h�܂�)�ƃX�L�������V�X�e������-//
			//-�v���C���[�̈ړ�����(�A�^�b�J�[)-//
			//�ړ��L�[�̃{�^�����͂��L�������𔻒肷��
			//W�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��Y���W����ړ��ʂ̒l����͂��L��x�Ɉ����Ă���
				PlayerAY -= PlayAVel;//�����[�v�v���C���[��Y���W����ړ��ʂ̒l������
				//PlayerAY = PlayerAY - PlayAVel;�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 0;//�t���O��0(�����)�ɐݒ�
			}

			//S�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂��Ă���
				PlayerAX += PlayAVel;//�����[�v�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂�
				//PlayerAY = PlayerAY + PlayAVel;�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 1;//�t���O��1(������)�ɐݒ�
			}

			//A�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//�����ꎞ
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//X��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��X���W����ړ��ʂ̒l����͂��L��x�Ɉ����Ă���
				PlayerAX -= PlayAVel;//�����[�v�v���C���[��X���W����ړ��ʂ̒l�������Ă���
				//PlayerAX = PlayerAX - PlayAVel;�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 2;//�t���O��2(������)�ɐݒ�
			}

			//D�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//X��(�E)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��X���W�Ɉړ��ʂ̒l����͂��L��x�ɑ����Ă���
				PlayerAX -= PlayAVel;//�����[�v�v���C���[��X���W�Ɉړ��ʂ̒l�𑫂�
				//PlayerAX = PlayerAX + PlayAVel;�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 3;//�t���O��3(�E����)�ɐݒ�
			}

			//-����R�}���h(�_�b�V��)����-//
			//SHIFT�L�[�������ꂽ����W�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��Y���W����ړ��ʂ̒l����͂�����x�Ɉ����Ă���
				PlayerAY -= PlayAVel + PlayAVel;//�����[�v�v���C���[��Y���W����ړ��ʂ̒l������
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAY -= PlayAVel + PlayAVel;>>PlayerAY = PlayerAY - (PlayAVel + PlayAVel);�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 0;//�t���O��0(�����)�ɐݒ�
			}

			//SHIFT�L�[�������ꂽ����S�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��Y���W�Ɉړ��ʂ̒l����͂�����x�ɑ����Ă���
				PlayerAY += PlayAVel + PlayAVel;//�����[�v�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂�
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAY += PlayAVel + PlayAVel;>>PlayerAY = PlayerAY + (PlayAVel + PlayAVel);�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 1;//�t���O��1(������)�ɐݒ�
			}

			//SHIFT�L�[�������ꂽ����A�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//X��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��X���W����ړ��ʂ̒l����͂�����x�Ɉ����Ă���
				PlayerAX -= PlayAVel + PlayAVel;//�����[�v�v���C���[��X���W����ړ��ʂ̒l������
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAX -= PlayAVel + PlayAVel;>>PlayerAX = PlayerAX - (PlayAVel + PlayAVel);�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 2;//�t���O��2(������)�ɐݒ�
			}

			//SHIFT�L�[�������ꂽ����D�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//X��(�E)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��X���W�Ɉړ��ʂ̒l����͂�����x�ɑ����Ă���
				PlayerAX += PlayAVel + PlayAVel;//�����[�v�v���C���[��X���W�Ɉړ��ʂ̒l�𑫂�
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAX += PlayAVel + PlayAVel;>>PlayerAX = PlayerAX + (PlayAVel + PlayAVel);�Ɠ�������
				//�v���C���[���������������Ă���摜��`�悷��
				PlayerDrawNum = 3;//�t���O��3(�E����)�ɐݒ�
			}

			//-�X�L����������-//
			//�G�l�~�[�̓������~�߂�X�L��
			//C�L�[�������ꂽ��
			//>>����̎d����Trigger�ł���
			if (keys[KEY_INPUT_C] == ON && oldkeys[KEY_INPUT_C] == OFF)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//�G�l�~�[�̓������~�߂�A�C�e�����擾���Ă��邩�𔻕ʂ���
				//�G�l�~�[�̓������~�߂�A�C�e���������Ă��邩
				if (EneStopF == ON)//�����Ă��鎞
				{
					//-SE���Đ����鏈��-//
					//SE���Đ�����Ă��邩�̔��ʂ͕K�v�Ȃ�
					//>>�{�^�����͂����������̂�1�񂾂��Đ�����΂�����
					//SE���Đ�����
					PlaySoundMem(SkillSE, DX_PLAYTYPE_NORMAL);//SE���m�[�}���Đ�����

					//�����Ă��鎞�ɂ��̃u���b�N���̏������s��
					//-�G�l�~�[�̓������~�����鏈��-//
					EnemyVel = 0;//�ړ���
					//EnemyVelocity>>�G�l�~�[�̈ړ��̑���
					//>>�G�l�~�[�̈ړ��͊e���W�Ɉړ��ʂ𑝌����Ă����
					//>>�ړ��ʂ̒l��0�ɂ��鎖�ňړ����~���鎖���\�ƂȂ�

					//�X�L���̎������Ԃ��J�E���g����
					//�J�E���g����ϐ��̒l�����l�܂ő���������
					//�J�E���g����0��
					if (EneStopC == 0)//�J�E���g����0�̎�
					{
						//-�X�L���̔������Ԃ�`����BGM>>�X�L���������ɍĐ�����BGM�̍Đ�����-//
						//�X�L���������ɍĐ�����BGM���Đ�����Ă��Ȃ���
						if (CheckSoundMem(SkillBGM) == 0)//�Đ�����Ă��Ȃ���
						{
							//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��
							PlaySoundMem(SkillBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�Đ�����
						}

						//0�̎��ɂ��̃u���b�N���̏������s��
						EneStopC += 1;//�����[�v�J�E���g����1������������

						//�J�E���g����250(5�b��)��
						if (EneStopC == 250)//�J�E���g����250(5�b��)�̎�
						{
							//250(5�b��)�̎��ɂ��̃u���b�N���̏������s��
							EneStopC = 250;//�l��250�ŌŒ肷��

							//�X�L���������~����
							//>>�X�L�������A�C�e���̊l���t���O��OFF(���l��)�ɕύX����
							EneStopF = OFF;//�t���O��OFF�ɕύX
							//>>�G�l�~�[�̈ړ����ĊJ����

							//-�X�L���̔������Ԃ�`����BGM>>�X�L���������ɍĐ�����BGM�̒�~����-//
							//�X�L���������ɍĐ�����BGM���Đ�����Ă��邩
							if (CheckSoundMem(SkillBGM) == 0)//�Đ�����Ă��鎞
							{
								//�Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
								StopSoundMem(SkillBGM);//BGM�̍Đ����~����
							}
						}
					}
				}
			}

			//-�G�l�~�[���E�����[�V�����̏���-//
			//X�L�[�������ꂽ��
			//>>����̎d����Trigger�ł���
			if (keys[KEY_INPUT_X] == ON && oldkeys[KEY_INPUT_X] == OFF)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//�G�l�~�[���v���C���[�𔭌����Ă���x���炷�܂ł�
				//���Ԃ��J�E���g����ϐ���0�ȊO���𔻕ʂ���
				//���Ԃ��J�E���g����ϐ���0�ȊO��
				if (EneAlarmT != 0)//0�ȊO�̎�
				{
					//0�ȊO�̎��ɂ��̃u���b�N���̏������s��
					//-�G�l�~�[�̐������Ǘ�����t���O��OFF(���S)�ɕύX���鏈��-//
					//�G�l�~�[�̐����t���O��ON(����)��
					if (EneAliveF == 1)//�t���O��ON(����)�̎�
					{
						//�t���O��ON�̎��ɂ��̃u���b�N���̏������s��
						//�G�l�~�[�̐����t���O��OFF(���S)�ɕύX����
						EneAliveF = 0;//�����t���O��OFF(���S)�ɕύX

						//�G�l�~�[���E���Ď��̂��B������A�j���[�V�����摜��`�悷��

					}
				}

				//-�Q�[���I�[�o�[�V�[���ւ̃V�[���ړ�����-//
				//���Ԃ��J�E���g����ϐ���0��
				else if (EneAlarmT == 0)//���Ԃ��J�E���g����ϐ���0�̎�
				{
					//�ϐ��̒l��0�̎��ɂ��̃u���b�N���̏������s��
					//SE���Đ�����
					PlaySoundMem(DX_PLAYTYPE_BACK, EneAlarmSE);//SE���o�b�N�O���E���h�Đ�����

					//�v���C���[�����ʃA�j���[�V�����摜��`�悷��

					//�Q�[���V�[����BGM���Đ�����Ă��邩
					if (CheckSoundMem(SengokuBGM) == 1)//�Đ�����Ă��鎞
					{
						//�Q�[���V�[����BGM���Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
						//BGM���~����
						StopSoundMem(SengokuBGM);//BGM���~����
						//�V�[�����X�e�[�W2(�퍑����)����Q�[���I�[�o�[�V�[���փV�[���ύX����
						GameScene = GAMEOVER;//�Q�[���I�[�o�[�V�[���փV�[���ύX����
					}
				}

			}

			//-�X�N���[������-//
			//-�}�b�v�`�b�v�̃u���b�N���m�̓����蔻��
			//�}�b�v�`�b�v�̃u���b�N���̎l�p�ɓ������Ă��邩��
			//���肷��p�̕ϐ��̐ݒ�
			/*int C1 = StageMap[(PlayerAY - 31) / BlockSize][(PlayerAX - 31) / BlockSize];
			int C2 = StageMap[(PlayerAY - 31) / BlockSize][(PlayerAX + 32) / BlockSize];
			int C3 = StageMap[(PlayerAY + 32) / BlockSize][(PlayerAX - 31) / BlockSize];
			int C4 = StageMap[(PlayerAY + 32) / BlockSize][(PlayerAX + 32) / BlockSize];*/

			//-�`�揈��-//
			//�X�e�[�W�̏c�[�܂ŌJ��Ԃ�
			for (int Y = 0; Y < StageHight; Y++)
			{
				//�X�e�[�W�̉��[�܂ŌJ��Ԃ�
				for (int X = 0; X < StageWidth; X++)
				{
					//�l��0�̃}�X�ڂ͓�
					if (StageMap[Y][X] == MICHI)
					{
						//�}�b�v�`�b�v�̏ꏊ��0�̎��͓��u���b�N��`��
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, MITIBLOCK, TRUE);
					}

					//�l��1�̃}�X�ڂ͕�
					if (StageMap[Y][X] == KABE)
					{
						//�}�b�v�`�b�v�̏ꏊ��1�̎��͕ǃu���b�N��`��
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, KABEBLOCK, TRUE);
					}

					//�l��2�̃}�X�ڂ͐ԃu���b�N
					if (StageMap[Y][X] == KAMON)
					{
						//�}�b�v�`�b�v�̏ꏊ��2�̎��͐ԃu���b�N��`��
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, RED, TRUE);
					}

					//�l��3�̃}�X�ڂ͂���(���J)
					if (StageMap[Y][X] == TAKARA)
					{
						//�}�b�v�`�b�v�̏ꏊ��3�̎��͂���u���b�N��`��
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, RED, TRUE);

						//�N���A�V�[����
						//GameScene = CLEAR;
					}

					//�l��4�̃}�X�ڂ̓o�b�e���[��`��
					if (StageMap[Y][X] == BUTTELY)
					{
						//�}�b�v�`�b�v�̏ꏊ��4�̎��̓o�b�e���[��`��
						//DrawGraph((X* BlockSize)-WorldPosX, (Y* BlockSize)-WorldPosY, ButtelyG, TRUE);
					}

					//�l��5�̃}�X�ڂ̓X�^���K����`��
					if (StageMap[Y][X] == SUTANGAN)
					{
						//�}�b�v�`�b�v�̏ꏊ��5�̎��̓X�^���K����`��
						//DrawGraph((X* BlockSize)-WorldPosX, (Y* BlockSize)-WorldPosY, SutanganG, TRUE);
					}

					//�l��6�̃}�X�ڂ͉񕜃A�C�e����`��
					if (StageMap[Y][X] == CARE)
					{
						//�}�b�v�`�b�v�̏ꏊ��6�̎��͉񕜃A�C�e����`��
						//DrawGraph((X* BlockSize)-WorldPosX, (Y* BlockSize)-WorldPosY, CareItemG, TRUE);
					}
				}
			}

			//�G�̈ړ�����//>>�㉺���E
			//-�G�̏㉺�ړ�����
			if (EnemyDrawNum == 1)//�`��ԍ����㉺�̔ԍ�(1)�̎�//������
			{
				//�G�̉������ւ̈ړ�����
				EnemyY2 = EnemyY2 + EnemyVelY;

				//�G2��Y���W��1792���傫���Ȃ�����
				if (EnemyY2 >= 1792)
				{
					EnemyDrawNum = 0;//������������Ă���摜�`��ԍ��֕ύX
					//Y���W���Œ�
					EnemyY2 = 1792;
				}
			}

			if (EnemyDrawNum == 0)//�`��ԍ����㉺�̔ԍ�(0)�̎�//�����
			{
				//�G�̏�����ւ̈ړ�����
				EnemyY2 = EnemyY2 - EnemyVelY;

				//�G2��Y���W��1472��菬�����Ȃ�����
				if (EnemyY2 <= 1472)
				{
					EnemyDrawNum = 1;//�������������Ă���摜�`��ԍ��֕ύX
					//Y���W���Œ�
					EnemyY2 = 1472;
				}
			}

			//-�G�̕`��
			//-�㉺
			if (EnemyDrawNum == 0)//������������Ă�
			{
				//�摜��`��
				DrawGraph(EnemyX2, EnemyY2, EnemyUpG, TRUE);
			}

			if (EnemyDrawNum == 1)//�������������Ă�
			{
				//�摜��`��
				DrawGraph(EnemyX2, EnemyY2, EnemyDownG, TRUE);
			}

			//-�G�̍��E�ړ�����
			if (EnemyDrawNum == 2)//�`��ԍ������E�̔ԍ�(2)�̎�//������
			{
				//�G�̍������ւ̈ړ�����
				EnemyX1 = EnemyX1 + EnemyVelX;

				//�G2��X���W��512���傫���Ȃ�����
				if (EnemyX1 >= 512)
				{
					EnemyDrawNum = 3;//�E�����������Ă���摜�`��ԍ��֕ύX
					//X���W���Œ�
					EnemyX1 = 512;
				}
			}

			if (EnemyDrawNum == 3)//�`��ԍ������E�̔ԍ�(3)�̎�//�E����
			{
				//�G�̉E�����ւ̈ړ�����
				EnemyX1 = EnemyX1 - EnemyVelX;

				//�G2��X���W��192��菬�����Ȃ�����
				if (EnemyX1 >= 192)
				{
					EnemyDrawNum = 2;//�������������Ă���摜�`��ԍ��֕ύX
					//X���W���Œ�
					EnemyX1 = 192;
				}
			}

			//-�G�̕`��
			//-���E
			if (EnemyDrawNum == 2)//�������������Ă�
			{
				//�摜��`��
				DrawGraph(EnemyX2, EnemyY2, EnemyLeftG, TRUE);
			}

			if (EnemyDrawNum == 3)//�E�����������Ă�
			{
				//�摜��`��
				DrawGraph(EnemyX2, EnemyY2, EnemyRightG, TRUE);
			}

			DrawExtendGraph(PlayerX - 512, PlayerY - 512, PlayerX + 511, PlayerY + 511, blind, TRUE);

			//�Q�[���V�[���w�i��O�̉摜
			//DrawExtendGraph(0, 0, 1541, 881, GameScene2G, TRUE);//�k���`�揈��
			DrawGraph(0, 0, GameScene2G, TRUE);

			break;

		case EGYPT://�X�e�[�W3>>�Ñ�G�W�v�g

			//�Q�[���w�i�̉�ʂ�`��
			DrawGraph(0, 0, EgyptG, TRUE);//�摜��`�悷��

			//-BGM�̍Đ�����-//
			//BGM���Đ�����Ă��邩�𔻕ʂ���
			//>>�X�e�[�W3(�Ñ�G�W�v�g)�V�[���ōĐ�����BGM���Đ�����Ă��Ȃ���
			if (CheckSoundMem(EgyptBGM) == 0)//�Đ�����Ă��Ȃ���
			{
				//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��

				//-BGM�̍Đ�-//
				//>>�X�e�[�W3(�Ñ�G�W�v�g)�V�[���ōĐ�����BGM���Đ�
				PlaySoundMem(EgyptBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�ōĐ�����
			}

			//-�v���C���[(�A�^�b�J�[�ƃX�s�[�h)�̈ړ�����(����R�}���h�܂�)�ƃX�L�������V�X�e������-//
			//-�v���C���[�̈ړ�����(�A�^�b�J�[)-//
			//�ړ��L�[�̃{�^�����͂��L�������𔻒肷��
			//W�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��Y���W����ړ��ʂ̒l����͂��L��x�Ɉ����Ă���
				PlayerAY -= PlayAVel;//�����[�v�v���C���[��Y���W����ړ��ʂ̒l������
				//PlayerAY = PlayerAY - PlayAVel;�Ɠ�������
			}

			//S�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂��Ă���
				PlayerAX += PlayAVel;//�����[�v�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂�
				//PlayerAY = PlayerAY + PlayAVel;�Ɠ�������
			}

			//A�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//�����ꎞ
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//X��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��X���W����ړ��ʂ̒l����͂��L��x�Ɉ����Ă���
				PlayerAX -= PlayAVel;//�����[�v�v���C���[��X���W����ړ��ʂ̒l�������Ă���
				//PlayerAX = PlayerAX - PlayAVel;�Ɠ�������
			}

			//D�L�[�����L�[�������ꂽ��>>����̎d���́u�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//�����ꂽ��
			{
				//�����ꂽ�����̃u���b�N���̏������s��
				//X��(�E)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��X���W�Ɉړ��ʂ̒l����͂��L��x�ɑ����Ă���
				PlayerAX -= PlayAVel;//�����[�v�v���C���[��X���W�Ɉړ��ʂ̒l�𑫂�
				//PlayerAX = PlayerAX + PlayAVel;�Ɠ�������
			}

			//-����R�}���h(�_�b�V��)����-//
			//SHIFT�L�[�������ꂽ����W�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��Y���W����ړ��ʂ̒l����͂�����x�Ɉ����Ă���
				PlayerAY -= PlayAVel + PlayAVel;//�����[�v�v���C���[��Y���W����ړ��ʂ̒l������
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAY -= PlayAVel + PlayAVel;>>PlayerAY = PlayerAY - (PlayAVel + PlayAVel);�Ɠ�������
			}

			//SHIFT�L�[�������ꂽ����S�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//Y��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��Y���W�Ɉړ��ʂ̒l����͂�����x�ɑ����Ă���
				PlayerAY += PlayAVel + PlayAVel;//�����[�v�v���C���[��Y���W�Ɉړ��ʂ̒l�𑫂�
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAY += PlayAVel + PlayAVel;>>PlayerAY = PlayerAY + (PlayAVel + PlayAVel);�Ɠ�������
			}

			//SHIFT�L�[�������ꂽ����A�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//X��(��)�����Ƀv���C���[�̈ړ��ʂ̒l�������Ă���
				//>>�v���C���[��X���W����ړ��ʂ̒l����͂�����x�Ɉ����Ă���
				PlayerAX -= PlayAVel + PlayAVel;//�����[�v�v���C���[��X���W����ړ��ʂ̒l������
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAX -= PlayAVel + PlayAVel;>>PlayerAX = PlayerAX - (PlayAVel + PlayAVel);�Ɠ�������
			}

			//SHIFT�L�[�������ꂽ����D�L�[�����L�[�������ꂽ��
			//>>����̎d���́u����(AND)�v�Ɓu�܂���(OR)�v�ƂȂ�
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//X��(�E)�����Ƀv���C���[�̈ړ��ʂ̒l�𑫂��Ă���
				//>>�v���C���[��X���W�Ɉړ��ʂ̒l����͂�����x�ɑ����Ă���
				PlayerAX += PlayAVel + PlayAVel;//�����[�v�v���C���[��X���W�Ɉړ��ʂ̒l�𑫂�
				//>>�_�b�V���͒ʏ�ړ��̎��̈ړ��ʂ�2�{�̒l�𑝌�������(��)
				//>>�f�o�b�N��ɃQ�[���o�����X�𒲐߂���ۂɊm�肷��
				//PlayerAX += PlayAVel + PlayAVel;>>PlayerAX = PlayerAX + (PlayAVel + PlayAVel);�Ɠ�������
			}

			//-�X�L����������-//
			//�G�l�~�[�̓������~�߂�X�L��
			//C�L�[�������ꂽ��
			//>>����̎d����Trigger�ł���
			if (keys[KEY_INPUT_C] == ON && oldkeys[KEY_INPUT_C] == OFF)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//�G�l�~�[�̓������~�߂�A�C�e�����擾���Ă��邩�𔻕ʂ���
				//�G�l�~�[�̓������~�߂�A�C�e���������Ă��邩
				if (EneStopF == ON)//�����Ă��鎞
				{
					//-SE���Đ����鏈��-//
					//SE���Đ�����Ă��邩�̔��ʂ͕K�v�Ȃ�
					//>>�{�^�����͂����������̂�1�񂾂��Đ�����΂�����
					//SE���Đ�����
					PlaySoundMem(SkillSE, DX_PLAYTYPE_NORMAL);//SE���m�[�}���Đ�����

					//�����Ă��鎞�ɂ��̃u���b�N���̏������s��
					//-�G�l�~�[�̓������~�����鏈��-//
					EnemyVel = 0;//�ړ���
					//EnemyVelocity>>�G�l�~�[�̈ړ��̑���
					//>>�G�l�~�[�̈ړ��͊e���W�Ɉړ��ʂ𑝌����Ă����
					//>>�ړ��ʂ̒l��0�ɂ��鎖�ňړ����~���鎖���\�ƂȂ�

					//�X�L���̎������Ԃ��J�E���g����
					//�J�E���g����ϐ��̒l�����l�܂ő���������
					//�J�E���g����0��
					if (EneStopC == 0)//�J�E���g����0�̎�
					{
						//-�X�L���̔������Ԃ�`����BGM>>�X�L���������ɍĐ�����BGM�̍Đ�����-//
						//�X�L���������ɍĐ�����BGM���Đ�����Ă��Ȃ���
						if (CheckSoundMem(SkillBGM) == 0)//�Đ�����Ă��Ȃ���
						{
							//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��
							PlaySoundMem(SkillBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�Đ�����
						}

						//0�̎��ɂ��̃u���b�N���̏������s��
						EneStopC += 1;//�����[�v�J�E���g����1������������

						//�J�E���g����250(5�b��)��
						if (EneStopC == 250)//�J�E���g����250(5�b��)�̎�
						{
							//250(5�b��)�̎��ɂ��̃u���b�N���̏������s��
							EneStopC = 250;//�l��250�ŌŒ肷��

							//�X�L���������~����
							//>>�X�L�������A�C�e���̊l���t���O��OFF(���l��)�ɕύX����
							EneStopF = OFF;//�t���O��OFF�ɕύX
							//>>�G�l�~�[�̈ړ����ĊJ����

							//-�X�L���̔������Ԃ�`����BGM>>�X�L���������ɍĐ�����BGM�̒�~����-//
							//�X�L���������ɍĐ�����BGM���Đ�����Ă��邩
							if (CheckSoundMem(SkillBGM) == 0)//�Đ�����Ă��鎞
							{
								//�Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
								StopSoundMem(SkillBGM);//BGM�̍Đ����~����
							}
						}
					}
				}
			}

			//-�G�l�~�[���E�����[�V�����̏���-//
			//X�L�[�������ꂽ��
			//>>����̎d����Trigger�ł���
			if (keys[KEY_INPUT_X] == ON && oldkeys[KEY_INPUT_X] == OFF)//�����ꂽ��
			{
				//�����ꂽ���ɂ��̃u���b�N���̏������s��
				//�G�l�~�[���v���C���[�𔭌����Ă���x���炷�܂ł�
				//���Ԃ��J�E���g����ϐ���0�ȊO���𔻕ʂ���
				//���Ԃ��J�E���g����ϐ���0�ȊO��
				if (EneAlarmT != 0)//0�ȊO�̎�
				{
					//0�ȊO�̎��ɂ��̃u���b�N���̏������s��
					//-�G�l�~�[�̐������Ǘ�����t���O��OFF(���S)�ɕύX���鏈��-//
					//�G�l�~�[�̐����t���O��ON(����)��
					if (EneAliveF == 1)//�t���O��ON(����)�̎�
					{
						//�t���O��ON�̎��ɂ��̃u���b�N���̏������s��
						//�G�l�~�[�̐����t���O��OFF(���S)�ɕύX����
						EneAliveF = 0;//�����t���O��OFF(���S)�ɕύX

						//�G�l�~�[���E���Ď��̂��B������A�j���[�V�����摜��`�悷��

					}
				}

				//-�Q�[���I�[�o�[�V�[���ւ̃V�[���ړ�����-//
				//���Ԃ��J�E���g����ϐ���0��
				else if (EneAlarmT == 0)//���Ԃ��J�E���g����ϐ���0�̎�
				{
					//�ϐ��̒l��0�̎��ɂ��̃u���b�N���̏������s��
					//SE���Đ�����
					PlaySoundMem(DX_PLAYTYPE_BACK, EneAlarmSE);//SE���o�b�N�O���E���h�Đ�����

					//�v���C���[�����ʃA�j���[�V�����摜��`�悷��

					//�Q�[���V�[����BGM���Đ�����Ă��邩
					if (CheckSoundMem(EgyptBGM) == 1)//�Đ�����Ă��鎞
					{
						//�Q�[���V�[����BGM���Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
						//BGM���~����
						StopSoundMem(EgyptBGM);//BGM���~����
						//�V�[�����X�e�[�W3(�Ñ�G�W�v�g)����Q�[���I�[�o�[�V�[���փV�[���ύX����
						GameScene = GAMEOVER;//�Q�[���I�[�o�[�V�[���փV�[���ύX����
					}
				}

			}

			for (int i = 0; i < MapY; i++) {
				for (int j = 0; j < MapX; j++) {
					if (Map[i][j] == block) {
						DrawBox(j * MapSize, i * MapSize, j * MapSize + MapSize, i * MapSize + MapSize, GetColor(255, 255, 255), TRUE);
					}

					//�l��3�̃}�X�ڂ͂���(�X�t�B���N�X)
					if (StageMap[i][j] == TAKARA)
					{
						//�}�b�v�`�b�v�̏ꏊ��3�̎��͂���u���b�N��`��
						DrawGraph((j * MapSize) - MapSize, (i * MapSize) - MapSize, EgyptTre, TRUE);
						//WorldPosY,WorldPosX

						//�N���A�V�[����
						GameScene = CLEAR;
					}
				}
			}

			DrawExtendGraph(PlayerX - 512, PlayerY - 512, PlayerX + 511, PlayerY + 511, blind, TRUE);

			//�Q�[���V�[���w�i��O�̉摜
			//DrawExtendGraph(0, 0, 1541, 881, GameScene2G, TRUE);//�k���`�揈��
			DrawGraph(0, 0, GameScene2G, TRUE);

			break;

		case CLEAR://�N���A

			//�N���A��ʂ̕`��
			DrawGraph(0, 0, ClearG, TRUE);//�摜��`�悷��
			//�N���A��ʂ̉摜���k�����ĕ`�悷��
			//DrawExtendGraph(0, 0, 1541, 881, ClearG, TRUE);//�k���`�揈��

			//-BGM�̍Đ�����-//
			//BGM���Đ�����Ă��邩�𔻕ʂ���
			//>>�N���A�V�[���ōĐ�����BGM���Đ�����Ă��Ȃ���
			if (CheckSoundMem(ClearBGM) == 0)//�Đ�����Ă��Ȃ���
			{
				//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��

				//-BGM�̍Đ�-//
				//>>�N���A�V�[���ōĐ�����BGM���Đ�
				PlaySoundMem(ClearBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�ōĐ�����
			}

			//-���̃V�[���Ɉړ�����ׂ�BGM�̒�~�E�{�^�����͎���SE�̍Đ��E�V�[���ύX�̏���-//
			//�V�[���ړ��̃��[�V����>>�{�^�����͂����������𔻒肷��
			//�X�y�[�X�L�[��������Ă��邩
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//�����ꂽ��(Tridder)
			{
				//�X�y�[�X�L�[�������ꂽ���ɂ��̃u���b�N���̏������s��

				//-BGM�̒�~����-//
				//>>BGM���Đ�����Ă��邩�𔻕ʂ���
				//>>�N���A�V�[���ōĐ�����BGM���Đ�����Ă��邩
				if (CheckSoundMem(ClearBGM) == 1)//�Đ�����Ă��鎞
				{
					//�Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
					//-BGM�̒�~-//
					StopSoundMem(ClearBGM);//BGM�̍Đ����~����

					//-SE�̍Đ�����-//
					//SE���Đ�
					//>>���̎�SE�̍Đ��̔��ʂ͗v��Ȃ�
					//>>�{�^�����͂����������̂�1�񂾂��Đ�����΂�����
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SE���m�[�}���Đ�����
				}

				//-�V�[���ύX����-//
				//>>�^�C�g���V�[���ɖ߂鏈���ƃX�e�[�W�I���ɖ߂鏈���ɕ�����

				//-�X�e�[�W�I���V�[���ւ̃V�[���ړ�-//
				//�X�e�[�W�I����ʂɖ߂�{�^���������ꂽ���̔��ʂ�����
				//>>S�L�[�������ꂽ��
				if (keys[KEY_INPUT_S] == ON && oldkeys[KEY_INPUT_S] == OFF)//�����ꂽ
				{
					//�����ꂽ���ɂ��̃u���b�N���̏������s��

					//�V�[�����N���A�V�[������X�e�[�W�I���V�[���ɕύX����
					GameScene = EXPLANATION;//�X�e�[�W�I���V�[���փV�[���ύX����
				}

				//-�^�C�g���V�[���ւ̃V�[���ړ�-//
				//�^�C�g���V�[���ɖ߂�{�^���������ꂽ���̔��ʂ�����
				//>>T�L�[�������ꂽ��
				if (keys[KEY_INPUT_T] == ON && oldkeys[KEY_INPUT_T] == OFF)//�����ꂽ
				{
					//�����ꂽ���ɂ��̃u���b�N���̏������s��

					//�V�[�����N���A�V�[������^�C�g���V�[���ɕύX����
					GameScene = TITLE;//�^�C�g���V�[���փV�[���ύX����
				}
			}

			break;

		case GAMEOVER://�Q�[���I�[�o�[

			//�Q�[���I�[�o�[��ʂ̕`��
			DrawGraph(0, 0, GameOverG, TRUE);//�摜��`�悷��
			//�Q�[���I�[�o�[��ʂ̉摜���k�����ĕ`�悷��
			//DrawExtendGraph(0, 0, 1541, 881, GameOverG, TRUE);//�k���`�揈��

			//-BGM�̍Đ�����-//
			//BGM���Đ�����Ă��邩�𔻕ʂ���
			//>>�Q�[���I�[�o�[�V�[���ōĐ�����BGM���Đ�����Ă��Ȃ���
			if (CheckSoundMem(GameOvaeaBGM) == 0)//�Đ�����Ă��Ȃ���
			{
				//�Đ�����Ă��Ȃ����ɂ��̃u���b�N���̏������s��

				//-BGM�̍Đ�-//
				//>>�Q�[���I�[�o�[�V�[���ōĐ�����BGM���Đ�
				PlaySoundMem(GameOvaeaBGM, DX_PLAYTYPE_BACK);//BGM���o�b�N�O���E���h�ōĐ�����
			}

			//-���̃V�[���Ɉړ�����ׂ�BGM�̒�~�E�{�^�����͎���SE�̍Đ��E�V�[���ύX�̏���-//
			//�V�[���ړ��̃��[�V����>>�{�^�����͂����������𔻒肷��
			//�X�y�[�X�L�[��������Ă��邩
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//�����ꂽ��(Tridder)
			{
				//�X�y�[�X�L�[�������ꂽ���ɂ��̃u���b�N���̏������s��

				//-BGM�̒�~����-//
				//>>BGM���Đ�����Ă��邩�𔻕ʂ���
				//>>�Q�[���I�[�o�[�V�[���ōĐ�����BGM���Đ�����Ă��邩
				if (CheckSoundMem(GameOvaeaBGM) == 1)//�Đ�����Ă��鎞
				{
					//�Đ�����Ă��鎞�ɂ��̃u���b�N���̏������s��
					//-BGM�̒�~-//
					StopSoundMem(GameOvaeaBGM);//BGM�̍Đ����~����

					//-SE�̍Đ�����-//
					//SE���Đ�
					//>>���̎�SE�̍Đ��̔��ʂ͗v��Ȃ�
					//>>�{�^�����͂����������̂�1�񂾂��Đ�����΂�����
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SE���m�[�}���Đ�����
				}

				//-�V�[���ύX����-//
				//>>�^�C�g���V�[���ɖ߂鏈���ƃX�e�[�W�I���ɖ߂鏈���ɕ�����

				//-�X�e�[�W�I���V�[���ւ̃V�[���ړ�-//
				//�X�e�[�W�I����ʂɖ߂�{�^���������ꂽ���̔��ʂ�����
				//>>S�L�[�������ꂽ��
				if (keys[KEY_INPUT_S] == ON && oldkeys[KEY_INPUT_S] == OFF)//�����ꂽ
				{
					//�����ꂽ���ɂ��̃u���b�N���̏������s��

					//�V�[�����Q�[���I�[�o�[�V�[������X�e�[�W�I���V�[���ɕύX����
					GameScene = EXPLANATION;//�X�e�[�W�I���V�[���փV�[���ύX����
				}

				//-�^�C�g���V�[���ւ̃V�[���ړ�-//
				//�^�C�g���V�[���ɖ߂�{�^���������ꂽ���̔��ʂ�����
				//>>T�L�[�������ꂽ��
				if (keys[KEY_INPUT_T] == ON && oldkeys[KEY_INPUT_T] == OFF)//�����ꂽ
				{
					//�����ꂽ���ɂ��̃u���b�N���̏������s��

					//�V�[�����Q�[���I�[�o�[�V�[������^�C�g���V�[���ɕύX����
					GameScene = TITLE;//�^�C�g���V�[���փV�[���ύX����
				}
			}

			break;

		default:
			break;
		}




		




		//---------  �����܂łɃv���O�������L�q  ---------//
		ScreenFlip();//�i�_�u���o�b�t�@�j����
		// 20�~���b�ҋ@�i�^��60FPS�j
		WaitTimer(20);
		// Windows �V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}
		// �d�r�b�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	//Dx���C�u�����I������
	DxLib_End();

	return 0;
}