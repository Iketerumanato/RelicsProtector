#include "DxLib.h"
#include "math.h"
#include "stdlib.h"

const char TITLE[] = "学籍番号名前：タイトル";

const int WIN_WIDTH = 1920; //ウィンドウ横幅
const int WIN_HEIGHT = 1080;//ウィンドウ縦幅
//-やる事-//
//-BGMの捜索と選考-//
//タイトル
//説明
//ステージ選択
//ヨーロッパ(ステージ1)
//戦国(ステージ2)
//エジプト(ステージ3)
//クリア
//ゲームオーバー
//-SEの捜索と選考-//
//プレイヤーが歩く時の音
//エネミーが歩く時の音
//敵がプレイヤーを発見した時の音
//敵が警報を鳴らす音
//アイテムを獲得する時の音
//スキルを発動する時の音
//敵を殺す時の音>>画像のアニメーションの適所適所で再生
//敵を隠す時の音>>画像のアニメーションの適所適所で再生
//敵がプレイヤーを殺す時の音
//プレイヤーが力尽きる時の音
//画面が切り替わる時の音
//-画像の作成-//
//ゲームの背景の作成
//キャラクターの作成
//プレイヤー(アタッカー)
//プレイヤー(スピード)
//エネミー
//アイテムの作成
//マップの全体を表示するアイテム
//エネミーの動きを止めるアイテム
//マップ全体が見えるのを持続させるアイテム
//プレイヤーの周辺を照らす画像(明かり)
//各画像の読み込み
//ステージの作成
//ヨーロッパ(ステージ1)のデバック
//戦国(ステージ2)のデバック
//エジプト(ステージ3)のデバック
//ヨーロッパ(ステージ1)のマップチップ同士の衝突判定
//戦国(ステージ2)のマップチップ同士の衝突判定
//エジプト(ステージ3)のマップチップ同士の衝突判定
//敵の挙動設定
//プレイヤーの挙動設定

//現段階で思いつくタスクを書いたので各自確認して完了したら
//完了の所に[>>完了]と付けて切り取り&貼り付けして下さい

//-完了-//>>完了したら[>>完了]を付けてこの↓に

//-相談事や確認したい事-//>>何か確認事項等があったらこの↓に
//出来れば今回導入したいのが、キーの入力情報の判定を関数にして実装したい>>前に一回やろうとしたけど書き方がわからんかった

//-途中の事や現段階で取り組んでいる事-//
//今取り組んでいる事を[>>自分の名前(進行度合い EX:6割り)]と書いてこの↓に


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);						//ウィンドウモードに設定
	//ウィンドウサイズを手動では変更できず、かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// タイトルを変更
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//画面サイズの最大サイズ、カラービット数を設定（モニターの解像度に合わせる）
	SetWindowSizeExtendRate(1.0);				//画面サイズを設定（解像度との比率で設定）
	SetBackgroundColor(0x00, 0x00, 0x00);		// 画面の背景色を設定する

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) { return -1; }

	//（ダブルバッファ）描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像などのリソースデータの変数宣言と読み込み
	//-背景
	int TitleG = LoadGraph("TITLE.png");//タイトル画像
	int ExplanationG = LoadGraph(".png");//説明画像
	int ChoiseG = LoadGraph("SELECTGRAPH2.png");//ステージ選択画像
	int EuropeG = LoadGraph("GEMA_BACKGROUND1.png");//ステージ1>>19世紀ヨーロッパ画像
	int SengokuG = LoadGraph("GEMA_BACKGROUND.png");//ステージ2>>戦国時代画像
	int EgyptG = LoadGraph("GEMA_BACKGROUND1.png");//ステージ3>>古代エジプト画像
	int ClearG = LoadGraph("CLEARGRAPH.png");//クリア画像
	int GameOverG = LoadGraph("GAMEOVERGRAPH.png");//ゲームオーバー画像
	int GemeSceneG = LoadGraph("GEMA_BACKROUND1.png");//ゲームシーンの背景(後ろ)画像
	int GameScene2G = LoadGraph("GameSceneGrap@h1-1.png");//ゲームシーン手前の画像

	//-プレイヤー
	//-方向別
	//-上ver.
	int Player_Front = LoadGraph("Player_Live(2).png");//プレイヤー(アタッカー)の通常画像
	//-下ver.
	int Player_Back = LoadGraph("Player_Live.png");
	//-右ver.
	int Player_Right = LoadGraph("Player_Live(4).png");
	//-左ver.
	int Player_Left = LoadGraph("Player_Live(3)");

	//-エネミー
	//-方向別
	//-上ver.
	int EnemyUpG = LoadGraph("SENGOKU_ENEMY2.png");//エネミーの通常画像
	//-下ver.
	int EnemyDownG = LoadGraph("SENGOKU_ENEMY.png");
	//-右ver.
	int EnemyRightG = LoadGraph("SENGOKU_ENEMY3.png");
	//-左ver.
	int EnemyLeftG = LoadGraph("SENGOKU_ENEMY4.png");

	//ブロックの画像
	int Block1 = LoadGraph("Stage1_Block.png");//紺色のブロックの画像を読み込む
	int Block2 = LoadGraph("Stage1_Block2.png");//黄色のブロックの画像を読み込む
	int Block3 = LoadGraph("Stage1_Block3.png");//白色のブロックの画像を読み込む

	int RED = GetColor(255, 0, 0);

	//落ちてるアイテムの画像
	int StanGun = LoadGraph("StanGun.png");//使うと相手の動きを止める
	int StanGunBullet_0 = LoadGraph("StanGunBullet_0.png");//上向き用の弾の画像
	int StanGunBullet_1 = LoadGraph("StanGunBullet_1.png");//左向き用の弾の画像
	int StanGunBullet_2 = LoadGraph("StanGunBullet_2.png");//下向き用の弾の画像
	int StanGunBullet_3 = LoadGraph("StanGunBullet_3.png");//右向き用の弾の画像

	//敵の（方向別）画像
	int Enemy_Front = LoadGraph("EOUROP_ENEMY2-2.png");//前向き
	int Enemy_Back = LoadGraph("EOUROP_ENEMY.png");//後向き
	int Enemy_Right = LoadGraph("EOUROP_ENEMY3.png");//右向き
	int Enemy_Left = LoadGraph("EOUROP_ENEMY4.png");//左向き

	int Battery = LoadGraph("Battery.png");//触れると制限時間を増やす
	int Bread = LoadGraph("Bread.png");//プレイヤーのHP回復
	int Sunflower = LoadGraph("SunFlower.png");//目標物(取ったらゴール)

	const int BlockSize = 64;//１つのブロックの大きさ(この大きさでキャラクターやアイテムの大きさも合わせる)

	//-宝
	//ステージ1>>19世紀ヨーロッパ
	int EuropTre = LoadGraph("SunFlower.png");//ステージ1の宝画像
	//EuropTre>>EuropeTreasureの略>>ステージ1の宝の事を指す

	//ステージ2>>戦国時代
	int SengokuTre = LoadGraph("KATANA_GRAPH.png");//ステージ2の宝画像
	//SengokuTreasureの略>>ステージ2の宝の事を指す

	//ステージ3>>古代エジプト
	int EgyptTre = LoadGraph(".png");//ステージ3の宝画像
	//EgyptTreasyreの略>>ステージ3の宝画像の事を指す

	//-アイテム

	//-HUD
	int HUDGRAPH = LoadGraph("GameSceneGraph1-1.png");
	//HUD(タイマーとHP,マップ表示メーターを除いたHUDの画像)
	//>>プログラムの上から順にゲームシーン背景、ステージ、HUD画像の順で
	//上から書くといいと思う

	//-アイテムのアイコンが選択可能状態にある事を示す赤枠の画像(左)
	int AICONLEFT = LoadGraph("AICON(L).png");

	//-アイテムのアイコンが選択可能状態にある事を示す赤枠の画像(真ん中)
	int AICONSENTER = LoadGraph("AICON(S).png");

	//-アイテムのアイコンが選択可能状態にある事を示す赤枠の画像(右)
	int AICONRIGHT = LoadGraph("AICON(R).png");

	//-プレイヤーのHPの画像
	//-FULLver.
	int FULLHP = LoadGraph("HP(FULL)-HUD.png");//HPがフル状態の画像

	//-2段階目
	int SECONDHP = LoadGraph("HP(2)-HUD.png");//HPが二段階目の状態の画像

	//-1段階目
	int FIRSTHP = LoadGraph("HP(1)-HUD.png");//HPが一段階目の状態の画像

	//-マップ全体表示時間を表すメーターの画像
	//-FULLver.
	int FULLMETTER = LoadGraph("MAPMATTER(FULL).png");
	//マップ全体表示のメーターの残り時間がフル状態の画像

	//-二段階目
	int SECONDMETTER = LoadGraph("MAPMATTER(2).png");
	//マップ全体表示のメーターの残り時間が二段階目の状態の画像

	//-一段階目
	int FIRSTMETTER = LoadGraph("MAPMATTER(1).png");
	//マップ全体表示のメーターの残り時間が一段階目の状態の画像

	//-タイマーの時間を描いた画像
	//-5分
	int TIMERFIVE = LoadGraph("Timer(5minits).png");//05:00

	//-4分
	int TIMEFOUR = LoadGraph("Timer(4minits).png");//04:00

	//-3分
	int TIMETHREE = LoadGraph("Timer(3minits).png");//03:00

	//-2分
	int TIMETWO = LoadGraph("Timer(2minits).png");//02:00

	//-1分
	int TIMEONE = LoadGraph("Timer(1minits).png");//01:00

	//-0分
	int TIMEZERO = LoadGraph("Timer(0minits).png");//00:00

	//-UI
	int STAGEAICONLEFT = LoadGraph("LEFT_STAGE.png");
	//ステージ選択時にどのステージが選択されているかを理解させる為に
	//選択時に描画する枠の画像(左)

	int STAGEAICONSENTER = LoadGraph("SENTER_STAGE.png");
	//ステージ選択時にどのステージが選択されているかを理解させる為に
	//選択時に描画する枠の画像(真ん中)

	int STAGEAICONRIGHT = LoadGraph("RIGHT_STAGE.png");
	//ステージ選択時にどのステージが選択されているかを理解させる為に
	//選択時に描画する枠の画像(右)

	int blind = LoadGraph("blind.png");

	//-マップチップの画像-//
	//-道
	int MITIBLOCK = LoadGraph("MITIGRAPH.png");//道のりのマップチップの画像
	//-壁
	int KABEBLOCK = LoadGraph("KABEGRAPH.png");//壁のマップチップの画像

	//-BGMの読み込み-//
	//タイトル
	int TitleBGM = LoadSoundMem(".mp3");//タイトルシーンで再生するBGM
	//説明
	int ExplanationBGM = LoadSoundMem(".mp3");//説明シーンで再生するBGM
	//ステージ選択
	int ChoiseBGM = LoadSoundMem(".mp3");//ステージ選択シーンで再生するBGM
	//ステージ1>>19世紀ヨーロッパ
	int EuropeBGM = LoadSoundMem(".mp3");//19世紀ヨーロッパ>>ステージ1で再生するBGM
	//ステージ2>>戦国時代
	int SengokuBGM = LoadSoundMem(".mp3");//戦国時代>>ステージ2で再生するBGM
	//ステージ3>>古代エジプト
	int EgyptBGM = LoadSoundMem(".mp3");//古代エジプト>>ステージ3で再生するBGM
	//クリア
	int ClearBGM = LoadSoundMem(".mp3");//クリアシーンで再生するBGM
	//ゲームオーバー
	int GameOvaeaBGM = LoadSoundMem(".mp3");//ゲームオーバーシーンで再生するBGM
	//スキル発動中
	int SkillBGM = LoadSoundMem(".mp3");//スキル発動中に再生するBGM

	//-SE-//
	//ボタン入力時のSE
	int InputSE = LoadSoundMem(".mp3");//ボタンの入力があった時に再生するSE
	//Input>>入力の意味
	//スキル発動時のSE
	int SkillSE = LoadSoundMem(".mp3");//スキルを発動するボタンの入力があった時に再生するSE
	//時間切れを知らせるSE
	int TimeUpSE = LoadSoundMem(".mp3");//時間切れの時に流すSE
	//警報を鳴らすSE
	int EneAlarmSE = LoadSoundMem(".mp3");//エネミーが警報を鳴らすSE


	//ゲームループで使う変数の宣言
	char keys[256] = { 0 }; //最新のキーボード情報用
	char oldkeys[256] = { 0 };//1ループ（フレーム）前のキーボード情報

	//シーン分け用の変数の設定
	enum SceneNo
	{
		TITLE,//タイトル
		EXPLANATION,//説明シーン
		CHOISE,//ステージ選択
		EUROPE,//ステージ1>>19世紀ヨーロッパ
		SENGOKU,//ステージ2>>戦国時代
		EGYPT,//ステージ3>>古代エジプト
		CLEAR,//クリアシーン
		GAMEOVER,//ゲームオーバーシーン
	};

	SceneNo GameScene = TITLE;//最初のシーンをタイトルに指定

	enum
	{
		OFF,//0の値が変数OFFに入る
		ON,//1の値が変数ONに入る
	};

	//-ステージの設定用の変数の設定-//
	int MapX = 0;//X方向
	int MapY = 0;//Y方向

	//-ゲームシステムの設定-// >> <(*)は注意事項の意味>
	//-プレイヤー(アタッカー)
	int PlayerAX = 0;//X座標
	int PlayerAY = 0;//Y座標
	int PlayerAR = 32;//半径
	int PlayAVel = 2;//移動量
	//PlaterAVelocity>>プレイヤー(アタッカー)の移動の速さ
	int PlayerAliveF = 1;//プレイヤーの生存を管理するフラグ
	//PlayerAliveF>>PlayerAliveFlagの略
	//>>アタッカーとスピードの両方に共通させる変数とする(*)

	int c1 = 0, c2=0, c3=0, c4=0;
	int OldPlayerX;
	int OldPlayerY;

	//-プレイヤー(スピード)
	int PlayerSX = 0;//X座標
	int PlayerSY = 0;//Y座標
	int PlayerSR = 0;//半径
	int PleySVel = 0;//移動量
	//PlaterSVelocity>>プレイヤー(スピード)の移動の速さ

	//-エネミー
	int EnemyX = 0;//X座標
	int EnemyY = 0;//Y座標
	int EnemyR = 32;//半径
	int EnemyVel = 2;//移動量
	//EnemyVelocity>>エネミーの移動の速さ
	int EneAlarmT = 0;//初期値は0で値を増加させてカウントする>> 50フレームで1秒間
	//>>エネミーがプレイヤーを発見してから警報を鳴らすまでの
	//時間をカウントする変数
	//EneAlarmT>>EnemyAlarmTimerの略>>警報を鳴らすまでの時間をカウントする時に使用
	int EneAliveF = 1;//エネミーの生存を管理するフラグ
	//EneAliveF>>EnemyAliveFlagの略

	//-宝
	//絵画
	int PaintingX = 0;//X座標
	int PaintingY = 0;//Y座標
	int PaintingR = 0;//半径

	//刀
	int KatanaX = 0;//X座標
	int KatanaY = 0;//Y座標
	int KatanaR = 32;//半径

	//ペンダント
	int PendantX = 0;//X座標
	int PendantY = 0;//Y座標
	int PendantR = 0;//半径

	//-アイテム
	//エネミーを止めるアイテム
	int EneStopX = 0;//X座標
	int EneStopY = 0;//Y座標
	int EneStopR = 0;//半径
	int EneStopF = 0;//アイテム獲得管理用変数>>獲得前=0(OFF),獲得後=1(ON)
	//EneStopF>>EnemyStopFlagの略
	int EneStopC = 0;//スキルの発動時間をカウントする変数
	//初期値は0で値を増加させてカウントする>>50フレームで1秒間
	//EneStopC>>EnemyStopCountの略

	//マップ全体を表示するアイテム
	int FullMapX = 0;//X座標
	int FullMapY = 0;//Y座標
	int FullMapR = 0;//半径
	int FullMapF = 0;//アイテム獲得管理用変数>>獲得前=0(OFF),獲得後=1(ON)
	//FullMapF>>FullMapFlagの略
	int FullMapC = 0;//マップ全体を表示する時間をカウントする変数
	//初期値は0で値を増加させてカウントする>>50フレームで1秒間

	//マップ全体の表示時間を延ばすアイテム
	int FMTimeX = 0;//X座標
	int FMTimeY = 0;//Y座標
	int FMTimeR = 0;//半径
	//FMTime>>FullMapTimeの略
	int FMTimeF = 0;//アイテム獲得管理用変数>>獲得前=0(OFF),獲得後=1(ON)
	//FMTimeF>>FullMapTimeFlagの略


	//プレイヤーのHPを回復するアイテム
	int HPUpX = 0;//X座標
	int HPUpY = 0;//Y座標
	int HPUpR = 0;//半径
	int HPUpF = 0;//アイテム獲得管理用変数>>獲得前=0(OFF),獲得後=1(ON)

	//-プレイヤーの上下左右の画像をキー入力情報に合わせて
	//同じ向きの画像を描画する為の描画番号を設定
	int PlayerDrawNum = 3;//最初は右側を向いている
	//0の時>>上/1の時>>下/2の時>>左/3の時>>右

	//敵の方向別の画像を描画を管理する変数の設定
	int EnemyDrawNum = 0;
	//0の時>>上/1の時>>下/2の時>>左/3の時>>右

	//-敵の座標設定
	//-敵1
	int EnemyX1 = 192;
	int EnemyY1 = 704;
	//int EnemyR = 32;//半径は皆共通
	//-敵2
	int EnemyX2 = 704;
	int EnemyY2 = 1472;

	//-敵の移動量
	int EnemyVelX = 3;//横方向の移動量
	int EnemyVelY = 3;//縦方向の移動量
	//-敵の描画方向を管理する変数の設定
	int EnemyDrawNum1 = 0;//上下
	int EnemyDrawNum2 = 1;//左右

	int PlayerX = 128;//プレイヤーの初期座標
	int PlayerY = 320;
	//プレイヤーの向きを番号で割り振る(０が上、１が左、２が下、３が右)
	int PlayerVel = 3;//プレイヤーの移動速度
	//プレイヤーの座標を確保するための変数
	int Empty = 0;
	//0はダメージなし１は一回ダメージを受けている２は二回ダメージを受けている
	int damage = 0;
	//ダメージを受けた時のフラグ
	int DamageFlag = 0;

	//敵に使う変数
	//敵の下向き用の座標
	int EnemyX_0 = 576;
	int EnemyY_0 = 256;

	//敵の左向き用の座標
	int EnemyX_1 = 1344;
	int EnemyY_1 = 1344;

	//敵の前向き用の座標
	int EnemyX_2 = 576;
	int EnemyY_2 = 960;

	//敵の右向き用の座標
	int EnemyX_3 = 192;
	int EnemyY_3 = 1344;

	//int EnemyR = 32;//敵の半径
	//int EnemyVelX = 2;//敵の横の移動速度
	//int EnemyVelY = 2;//敵の縦の移動速度
	//int EnemyDrawNum1 = 0;//敵の方向を番号で割り振る(上下)
	//int EnemyDrawNum2 = 1;//敵の方向を番号で割り振る(左右)

	//アイテムに使う変数
	int HP = 3;//プレイヤーのHP
	const int HpSize = 64;//食べ物の大きさ
	//0はダメージなし１は一回ダメージを受けている２は二回ダメージを受けている
	int HpFlag = 1;//フラグが立つと回復できる
	const int GoalSize = 64;
	//弾の座標
	int GunFlag = 0;//スタンガンに触れたら使えるようにするためのフラグ
	//上方向に弾を移動するための座標
	int bulX_0 = -32;
	int bulY_0 = -32;
	//左方向に弾を移動するための座標
	int bulX_1 = -32;
	int bulY_1 = -32;
	//下方向に弾を移動するための座標
	int bulX_2 = -32;
	int bulY_2 = -32;
	//右方向に弾を移動するための座標
	int bulX_3 = -32;
	int bulY_3 = -32;

	int bulR = 32;//弾の半径
	int isBulletFlag = 0;//0の時は発射前で利用可能、１は発射後
	const int ItemSize = 64;//スタンガンなどの大きさ

	enum Stage1 {//番号ではなく文字でわかりやすく指定

		KUUHAKU,//0に描画(空白)
		NAVYBLUE,//1に描画(紺色のブロック)
		YELLOW,//2に描画(黄色のブロック)
		WHITE,//3に描画(白のブロック)
		BATTERY,//4に描画(バッテリー)
		STANGUN,//5に描画(武器)
		BREAD,//6に描画(HP回復アイテム)
		SUNFLOWER//7に描画(目標物)
	};

	//マップの本体（ゲーム中の画面の大きさに合わせなきゃダメ）
	//１つ６４の大きさのブロックが 縦２５こ 横５０こ の大きさ
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

	int Stage1Height = sizeof(Stage1Map) / sizeof(Stage1Map[0]);//縦画面ステージの縦の大きさを割り出す
	int Stage1Width = sizeof(Stage1Map[0]) / sizeof(Stage1Map[0][0]);//縦画面ステージの横の大きさを割り出す

	//スクロールが始まる始点の座標
	int WorldposX = 0;
	int WorldposY = 0;
	//-戦国時代のステージの設定-//
	//ステージで使用するブロックの条件の設定
	enum StageBlock
	{
		MICHI,//0
		KABE,//1
		KAMON,//2
		TAKARA,//3
		BUTTELY,//4>>バッテリー
		SUTANGAN,//5>>スタンガン
		CARE,//6>>回復アイテム
	};

	//ステージマップ(迷路)の描画
	//1つのブロックサイズが64のブロックが縦35,横32個分の大きさのマップ
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

	//ステージの縦の配列の個数を求める
	int StageHight = sizeof(StageMap) / sizeof(StageMap[0]);

	//ステージの横の配列の個数を求める
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

	int MapSize = 64; //見るために半分にしてる

	enum Map {
		none,
		block
	};

	//スクロールを開始する為のフラグの設定
	int ScrollFlag = 0;

	//スクロールを開始する点(始点)の座標を設定
	int WorldPosX = 0;//X座標
	//WorldPositionXの略
	int WorldPosY = 0;//Y座標
	//スクロールする速さの設定
	int ScrollSpeed = 3;
	//マップチップ内でのプレイヤーのX座標を求める
	int PlayerIdX = (PlayerAX + WorldPosX) / BlockSize;
	//マップチップ内でのプレイヤーのY座標を求める
	int PlayerIdY = (PlayerAY + WorldPosY) / BlockSize;

	// ゲームループ
	while (1)
	{
		//最新のキーボード情報だったものは１フレーム前のキーボード情報として保存

		//最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		//画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		//更新処理
		switch (GameScene)
		{
		case TITLE://タイトル

			//タイトル画面の描画
			DrawGraph(0, 0, TitleG, TRUE);//画像を描画する
			//タイトル画像を縮小して描画する
			//DrawExtendGraph(0, 0, 1920, 1080, TitleG, TRUE);//縮小描画処理

			//-BGMの再生処理-//
			//BGMが再生されているかを判別する
			//>>タイトルシーンで再生するBGMが再生されていないか
			if (CheckSoundMem(TitleBGM) == 0)//再生されていない時
			{
				//再生されていない時にこのブロック内の処理を行う

				//-BGMの再生-//
				//>>タイトルシーンで再生するBGMを再生
				PlaySoundMem(TitleBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンドで再生する
			}

			//-次のシーンに移動する為のBGMの停止・ボタン入力時のSEの再生・シーン変更の処理-//
			//シーン移動のモーション>>ボタン入力があったかを判定する
			//スペースキーが押されているか
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//押された時(Tridder)
			{
				//スペースキーが押された時にこのブロック内の処理を行う

				//-BGMの停止処理-//
				//>>BGMが再生されているかを判別する
				//>>タイトルシーンで再生するBGMが再生されているか
				if (CheckSoundMem(TitleBGM) == 1)//再生されている時
				{
					//再生されている時にこのブロック内の処理を行う
					//-BGMの停止-//
					StopSoundMem(TitleBGM);//BGMの再生を停止する

					//-SEの再生処理-//
					//SEを再生
					//>>この時SEの再生の判別は要らない
					//>>ボタン入力があった時のみ1回だけ再生すればいい為
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SEをノーマル再生する
				}

				//-シーン変更処理-//
				//シーンをタイトルシーンから説明シーンに変更する
				GameScene = EXPLANATION;//説明シーンへシーン変更する
			}

			break;

		case EXPLANATION://説明

			//説明画面の描画
			DrawGraph(0, 0, ExplanationG, TRUE);//画像を描画する
			//説明画面の画像を縮小して描画する
			//DrawExtendGraph(0, 0, 1541, 881, ExplanationG, TRUE);//縮小描画処理

			//-BGMの再生処理-//
			//BGMが再生されているかを判別する
			//>>説明シーンで再生するBGMが再生されていないか
			if (CheckSoundMem(ExplanationBGM) == 0)//再生されていない時
			{
				//再生されていない時にこのブロック内の処理を行う

				//-BGMの再生-//
				//>>説明シーンで再生するBGMを再生
				PlaySoundMem(ExplanationBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンドで再生する
			}

			//-次のシーンに移動する為のBGMの停止・ボタン入力時のSEの再生・シーン変更の処理-//
			//シーン移動のモーション>>ボタン入力があったかを判定する
			//スペースキーが押されているか
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//押された時(Tridder)
			{
				//スペースキーが押された時にこのブロック内の処理を行う

				//-BGMの停止処理-//
				//>>BGMが再生されているかを判別する
				//>>説明シーンで再生するBGMが再生されているか
				if (CheckSoundMem(ExplanationBGM) == 1)//再生されている時
				{
					//再生されている時にこのブロック内の処理を行う
					//-BGMの停止-//
					StopSoundMem(ExplanationBGM);//BGMの再生を停止する

					//-SEの再生処理-//
					//SEを再生
					//>>この時SEの再生の判別は要らない
					//>>ボタン入力があった時のみ1回だけ再生すればいい為
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SEをノーマル再生する
				}

				//-シーン変更処理-//
				//シーンを説明シーンからステージ選択シーンに変更する
				GameScene = CHOISE;//ステージ選択シーンへシーン変更する

			}

			break;

		case CHOISE://ステージ選択

			//ステージ選択画像の描画処理//
			DrawGraph(0, 0, ChoiseG, TRUE);//画像を描画
			//ステージ選択画像を縮小して描画する
			//DrawExtendGraph(0, 0, 1541, 881, ChoiseG, TRUE);//縮小描画処理

			//-次のシーンに移動する為のBGMの停止・ボタン入力時のSEの再生・シーン変更の処理-//
			//シーン移動のモーション>>ボタン入力があったかを判定する
			//スペースキーが押されているか
			//if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//押された時(Tridder)
			//{
			//	//-シーン変更処理-//
			//	//シーンを説明シーンからステージ選択シーンに変更する
			//	GameScene = SENGOKU;//ステージ2(戦国時代)シーンへシーン変更する
			//}

			//エジプトステージへ
			if (keys[KEY_INPUT_1] == ON && oldkeys[KEY_INPUT_1] == OFF)
			{
				GameScene = EGYPT;
			}

			//戦国ステージへ
			if (keys[KEY_INPUT_2] == ON && oldkeys[KEY_INPUT_2] == OFF)
			{
				GameScene = SENGOKU;
			}

			//ヨーロッパステージへ
			if (keys[KEY_INPUT_3] == ON && oldkeys[KEY_INPUT_3] == OFF)
			{
				GameScene = EUROPE;
			}

			break;

		case EUROPE://ステージ1>>19世紀ヨーロッパ

			OldPlayerX = PlayerX;
			OldPlayerY = PlayerY;
			//ゲーム背景の画面を描画
			DrawGraph(0, 0, EuropeG, TRUE);//画像を描画する

			//-BGMの再生処理-//
			//BGMが再生されているかを判別する
			//>>ステージ1(19世紀ヨーロッパ)シーンで再生するBGMが再生されていないか
			if (CheckSoundMem(EuropeBGM) == 0)//再生されていない時
			{
				//再生されていない時にこのブロック内の処理を行う

				//-BGMの再生-//
				//>>ステージ1(19世紀ヨーロッパ)シーンで再生するBGMを再生
				PlaySoundMem(EuropeBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンドで再生する
			}

			//-プレイヤー(アタッカーとスピード)の移動処理(特殊コマンド含む)とスキル発動システム処理-//
			//-プレイヤーの移動処理(アタッカー)-//
			//移動キーのボタン入力が有ったかを判定する
			//Wキーか↑キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//Y軸(上)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのY座標から移動量の値を入力が有る度に引いていく
				PlayerY -= PlayAVel;//毎ループプレイヤーのY座標から移動量の値を引く
				//PlayerAY = PlayerAY - PlayAVel;と同じ処理
			}

			//Sキーか↓キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//Y軸(下)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのY座標に移動量の値を足していく
				PlayerY += PlayAVel;//毎ループプレイヤーのY座標に移動量の値を足す
				//PlayerAY = PlayerAY + PlayAVel;と同じ処理
			}

			//Aキーか←キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//押され時
			{
				//押された時このブロック内の処理を行う
				//X軸(左)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのX座標から移動量の値を入力が有る度に引いていく
				PlayerX -= PlayAVel;//毎ループプレイヤーのX座標から移動量の値を引いていく
				//PlayerAX = PlayerAX - PlayAVel;と同じ処理
			}

			//Dキーか→キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//X軸(右)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのX座標に移動量の値を入力が有る度に足していく
				PlayerX += PlayAVel;//毎ループプレイヤーのX座標に移動量の値を足す
				//PlayerAX = PlayerAX + PlayAVel;と同じ処理
			}

			

			//-特殊コマンド(ダッシュ)処理-//
			//SHIFTキーが押されたかつWキーか↑キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//押された時
			//{
			//	//押された時にこのブロック内の処理を行う
			//	//Y軸(上)方向にプレイヤーの移動量の値を引いていく
			//	//>>プレイヤーのY座標から移動量の値を入力がある度に引いていく
			//	PlayerY -= PlayAVel + PlayAVel;//毎ループプレイヤーのY座標から移動量の値を引く
			//	//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
			//	//>>デバック後にゲームバランスを調節する際に確定する
			//	//PlayerAY -= PlayAVel + PlayAVel;>>PlayerAY = PlayerAY - (PlayAVel + PlayAVel);と同じ処理
			//}

			////SHIFTキーが押されたかつSキーか↓キーが押されたか
			////>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//押された時
			//{
			//	//押された時にこのブロック内の処理を行う
			//	//Y軸(下)方向にプレイヤーの移動量の値を足していく
			//	//>>プレイヤーのY座標に移動量の値を入力がある度に足していく
			//	PlayerY += PlayAVel + PlayAVel;//毎ループプレイヤーのY座標に移動量の値を足す
			//	//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
			//	//>>デバック後にゲームバランスを調節する際に確定する
			//	//PlayerAY += PlayAVel + PlayAVel;>>PlayerAY = PlayerAY + (PlayAVel + PlayAVel);と同じ処理
			//}

			////SHIFTキーが押されたかつAキーか←キーが押されたか
			////>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//押された時
			//{
			//	//押された時にこのブロック内の処理を行う
			//	//X軸(左)方向にプレイヤーの移動量の値を引いていく
			//	//>>プレイヤーのX座標から移動量の値を入力がある度に引いていく
			//	PlayerX -= PlayAVel + PlayAVel;//毎ループプレイヤーのX座標から移動量の値を引く
			//	//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
			//	//>>デバック後にゲームバランスを調節する際に確定する
			//	//PlayerAX -= PlayAVel + PlayAVel;>>PlayerAX = PlayerAX - (PlayAVel + PlayAVel);と同じ処理
			//}

			////SHIFTキーが押されたかつDキーか→キーが押されたか
			////>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			//if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
			//	|| keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//押された時
			//{
			//	//押された時にこのブロック内の処理を行う
			//	//X軸(右)方向にプレイヤーの移動量の値を足していく
			//	//>>プレイヤーのX座標に移動量の値を入力がある度に足していく
			//	PlayerX += PlayAVel + PlayAVel;//毎ループプレイヤーのX座標に移動量の値を足す
			//	//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
			//	//>>デバック後にゲームバランスを調節する際に確定する
			//	//PlayerAX += PlayAVel + PlayAVel;>>PlayerAX = PlayerAX + (PlayAVel + PlayAVel);と同じ処理
			//}

			//-スキル発動処理-//
			//エネミーの動きを止めるスキル
			//Cキーが押されたか
			//>>判定の仕方はTriggerである
			if (keys[KEY_INPUT_C] == ON && oldkeys[KEY_INPUT_C] == OFF)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//エネミーの動きを止めるアイテムを取得しているかを判別する
				//エネミーの動きを止めるアイテムを持っているか
				if (EneStopF == ON)//持っている時
				{
					//-SEを再生する処理-//
					//SEが再生されているかの判別は必要ない
					//>>ボタン入力があった時のみ1回だけ再生すればいい為
					//SEを再生する
					PlaySoundMem(SkillSE, DX_PLAYTYPE_NORMAL);//SEをノーマル再生する

					//持っている時にこのブロック内の処理を行う
					//-エネミーの動きを停止させる処理-//
					EnemyVel = 0;//移動量
					//EnemyVelocity>>エネミーの移動の速さ
					//>>エネミーの移動は各座標に移動量を増減している為
					//>>移動量の値を0にする事で移動を停止する事が可能となる

					//スキルの持続時間をカウントする
					//カウントする変数の値を一定値まで増加させる
					//カウント数が0か
					if (EneStopC == 0)//カウント数が0の時
					{
						//-スキルの発動時間を伝えるBGM>>スキル発動中に再生するBGMの再生処理-//
						//スキル発動中に再生するBGMが再生されていないか
						if (CheckSoundMem(SkillBGM) == 0)//再生されていない時
						{
							//再生されていない時にこのブロック内の処理を行う
							PlaySoundMem(SkillBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンド再生する
						}

						//0の時にこのブロック内の処理を行う
						EneStopC += 1;//毎ループカウント数を1ずつ増加させる

						//カウント数が250(5秒後)か
						if (EneStopC == 250)//カウント数が250(5秒後)の時
						{
							//250(5秒後)の時にこのブロック内の処理を行う
							EneStopC = 250;//値を250で固定する

							//スキル発動を停止する
							//>>スキル発動アイテムの獲得フラグをOFF(未獲得)に変更する
							EneStopF = OFF;//フラグをOFFに変更
							//>>エネミーの移動が再開する

							//-スキルの発動時間を伝えるBGM>>スキル発動中に再生するBGMの停止処理-//
							//スキル発動中に再生するBGMが再生されているか
							if (CheckSoundMem(SkillBGM) == 0)//再生されている時
							{
								//再生されている時にこのブロック内の処理を行う
								StopSoundMem(SkillBGM);//BGMの再生を停止する
							}
						}
					}
				}
			}

			//-エネミーを殺すモーションの処理-//
			//Xキーが押されたか
			//>>判定の仕方はTriggerである
			if (keys[KEY_INPUT_X] == ON && oldkeys[KEY_INPUT_X] == OFF)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//エネミーがプレイヤーを発見してから警報を鳴らすまでの
				//時間をカウントする変数が0以外かを判別する
				//時間をカウントする変数が0以外か
				if (EneAlarmT != 0)//0以外の時
				{
					//0以外の時にこのブロック内の処理を行う
					//-エネミーの生存を管理するフラグをOFF(死亡)に変更する処理-//
					//エネミーの生存フラグがON(生存)か
					if (EneAliveF == 1)//フラグがON(生存)の時
					{
						//フラグがONの時にこのブロック内の処理を行う
						//エネミーの生存フラグをOFF(死亡)に変更する
						EneAliveF = 0;//生存フラグをOFF(死亡)に変更

						//エネミーを殺して死体を隠蔽するアニメーション画像を描画する

					}
				}

				//-ゲームオーバーシーンへのシーン移動処理-//
				//時間をカウントする変数が0か
				else if (EneAlarmT == 0)//時間をカウントする変数が0の時
				{
					//変数の値が0の時にこのブロック内の処理を行う
					//SEを再生する
					PlaySoundMem(DX_PLAYTYPE_BACK, EneAlarmSE);//SEをバックグラウンド再生する

					//プレイヤーが死ぬアニメーション画像を描画する

					//ゲームシーンのBGMが再生されているか
					if (CheckSoundMem(EuropeBGM) == 1)//再生されている時
					{
						//ゲームシーンのBGMが再生されている時にこのブロック内の処理を行う
						//BGMを停止する
						StopSoundMem(EuropeBGM);//BGMを停止する
						//シーンをステージ1(19世紀ヨーロッパ)からゲームオーバーシーンへシーン変更する
						GameScene = GAMEOVER;//ゲームオーバーシーンへシーン変更する
					}
				}

			}

			//描画処理
			for (int y = 0; y < Stage1Height; y++)//ステージの縦端まで繰り返す
			{
				for (int x = 0; x < Stage1Width; x++)//ステージの横端まで繰り返す
				{
					//０の場所は空白
					if (Stage1Map[y][x] == NAVYBLUE) {//マップチップの1の場所に紺色のブロックを描画
						if (abs(PlayerX + 32 - (x * BlockSize - WorldposX + 32)) < 64 && abs(PlayerY + 32 - (y * BlockSize + 32)) < 64) {
							PlayerX = OldPlayerX;
							PlayerY = OldPlayerY;
						}
						DrawGraph((x * BlockSize) - WorldposX, (y * BlockSize) - WorldposY, Block1, TRUE);
					}

					if (Stage1Map[y][x] == YELLOW) {//マップチップの2の場所に黄色のブロックを描画
						DrawGraph((x * BlockSize) - WorldposX, (y * BlockSize) - WorldposY, Block2, TRUE);
					}

					if (Stage1Map[y][x] == WHITE) {//マップチップの3の場所に白色のブロックを描画
						DrawGraph((x * BlockSize) - WorldposX, (y * BlockSize) - WorldposY, Block3, TRUE);
					}

					if (Stage1Map[y][x] == BATTERY) {//マップチップの4の場所にバッテリーを描画
						if (abs(PlayerX - (x * HpSize - WorldposX + 32)) < 80 && abs(PlayerY - (y * HpSize + 64)) < 112) {
							Stage1Map[y][x] = 0;
						}
						DrawGraph((x * ItemSize) - WorldposX, (y * ItemSize) - WorldposY, Battery, TRUE);
					}

					if (Stage1Map[y][x] == STANGUN) {//マップチップの5の場所にスタンガンを描画
						if (abs(PlayerX - (x * ItemSize - WorldposX + 32)) < 80 && abs(PlayerY - (y * ItemSize + 64)) < 112) {
							Stage1Map[y][x] = 0;
							GunFlag = 1;//1の時のフラグの処理へ
						}
						DrawGraph((x * ItemSize) - WorldposX, (y * ItemSize) - WorldposY, StanGun, TRUE);
					}

					if (Stage1Map[y][x] == BREAD) {//マップチップの6の場所にパンを描画
						//プレイヤーとパンの判定
						if (HpFlag == 1) {
							if (abs(PlayerX - (x * HpSize - WorldposX + 32)) < 80 && abs(PlayerY - (y * HpSize + 64)) < 112) {
								Stage1Map[y][x] = 0;
								HpFlag = 0;//0の時のフラグの処理へ
							}
						}
						DrawGraph((x * HpSize) - WorldposX, (y * HpSize) - WorldposY, Bread, TRUE);
					}

					if (Stage1Map[y][x] == SUNFLOWER) {//マップチップの7の場所に目標物を描画
						DrawGraph((x * GoalSize) - WorldposX, (y * GoalSize) - WorldposY, Sunflower, TRUE);
						if (abs(PlayerX + 32 - (x * BlockSize - WorldposX + 32)) < 64 && abs(PlayerY + 32 - (y * BlockSize + 32)) < 64) {
							GameScene = CLEAR;
						}
						//クリアシーンへ
						//GameScene = CLEAR;
					}

				}
			}

			//スタンガンを取った時の処理
			if (GunFlag == 1) {
				//弾の発射
				if (keys[KEY_INPUT_SPACE] == 1 && isBulletFlag == 0) {
					//上向きの場合
					if (PlayerDrawNum == 0) {
						bulX_0 = PlayerX;
						bulY_0 = PlayerY;
						isBulletFlag = 1;
					}
					//左向きの場合
					if (PlayerDrawNum == 1) {
						bulX_1 = PlayerX;
						bulY_1 = PlayerY;
						isBulletFlag = 1;
					}
					//下向きの場合
					if (PlayerDrawNum == 2) {
						bulX_2 = PlayerX;
						bulY_2 = PlayerY;
						isBulletFlag = 1;
					}
					//右向きの場合
					if (PlayerDrawNum == 3) {
						bulX_3 = PlayerX;
						bulY_3 = PlayerY;
						isBulletFlag = 1;
					}
				}

				//発射後の状態(向きによって打つ方向を変える)
				if (isBulletFlag == 1) {

					if (PlayerDrawNum == 0) {
						//上方向に弾を飛ばす
						bulY_0 = bulY_0 - 20;
						if (bulY_0 < 64) {
							isBulletFlag = 0;
						}
					}

					if (PlayerDrawNum == 1) {
						//左方向に弾を飛ばす
						bulX_1 = bulX_1 - 20;
						if (bulX_1 < 64) {
							isBulletFlag = 0;
						}
					}

					if (PlayerDrawNum == 2) {
						//下方向に弾を飛ばす
						bulY_2 = bulY_2 + 20;
						if (bulY_2 < 64) {
							isBulletFlag = 0;
						}
					}

					if (PlayerDrawNum == 3) {
						//右方向に弾を飛ばす
						bulX_3 = bulX_3 + 20;
						if (bulX_3 < 64) {
							isBulletFlag = 0;
						}
					}
				}
			}

			//敵の移動処理
			//敵の上下移動
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
			//敵の描画(上下)
			if (EnemyDrawNum1 == 0)
			{
				DrawGraph(EnemyX_0, EnemyY_0, Enemy_Back, TRUE);
			}

			if (EnemyDrawNum1 == 2)
			{
				DrawGraph(EnemyX_2, EnemyY_2, Enemy_Front, TRUE);
			}

			//敵の左右移動
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
			//敵の描画(左右)
			if (EnemyDrawNum2 == 1)
			{
				DrawGraph(EnemyX_1, EnemyY_1, Enemy_Left, TRUE);
			}

			if (EnemyDrawNum2 == 3)
			{
				DrawGraph(EnemyX_3, EnemyY_3, Enemy_Right, TRUE);
			}

			//２セット目の移動処理と描画
			//２セット目の新しい座標(上下)
			 EnemyX_0 = 1920;
			 EnemyY_0 = 64;
			 EnemyX_2 = 1920;
			 EnemyY_2 = 960;

			//２セット目の敵の上下移動
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
			//２セット目の敵の描画(上下)
			if (EnemyDrawNum1 == 0)
			{
				DrawGraph(EnemyX_0, EnemyY_0, Enemy_Back, TRUE);
			}
			if (EnemyDrawNum1 == 2)
			{
				DrawGraph(EnemyX_2, EnemyY_2, Enemy_Front, TRUE);
			}

			//２セット目の新しい敵の座標(左右)
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
			//２セット目の敵の描画(左右)
			if (EnemyDrawNum2 == 1)
			{
				DrawGraph(EnemyX_1, EnemyY_1, Enemy_Left, TRUE);
			}

			if (EnemyDrawNum2 == 3)
			{
				DrawGraph(EnemyX_3, EnemyY_3, Enemy_Right, TRUE);
			}

			//敵と弾の判定(当てると敵の動きが止まる)
			if (EnemyDrawNum1 == 0)
			{
				//2点間の距離
				float length = sqrtf((EnemyX_0 - bulX_0) * (EnemyX_0 - bulX_0) + (EnemyY_0 - bulY_0 - bulR) * (EnemyY_0 - bulY_0 - bulR));
				//衝突
				if (length <= EnemyR + bulR)
				{
					isBulletFlag = 0;
					bulX_0 = -32;
					bulY_0 = -32;
					EnemyVelY = 0;
				}
			}

			//スタンガンの弾の描画
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

			//食べ物に触れるとHPを回復
			if (HpFlag == 0) {
				HP = HP + 1;
				//触れて得点が増え続けるのを防ぐ
				HpFlag = 1;
			}

			//プレイヤーの描画
			if (PlayerDrawNum == 0) {//０の時に上方向
				DrawGraph(PlayerX, PlayerY, Player_Front, TRUE);
			}
			if (PlayerDrawNum == 1) {//１の時に左方向
				DrawGraph(PlayerX, PlayerY, Player_Left, TRUE);
			}
			if (PlayerDrawNum == 2) {//２の時に下方向
				DrawGraph(PlayerX, PlayerY, Player_Back, TRUE);
			}
			if (PlayerDrawNum == 3) {//３の時に右方向
				DrawGraph(PlayerX, PlayerY, Player_Right, TRUE);
			}

			DrawExtendGraph(PlayerX - 2033, PlayerY - 2033, PlayerX + 2096, PlayerY + 2096, blind, TRUE);

			//ゲームシーン背景手前の画像
			DrawExtendGraph(0, 0, 1541, 881, GameScene2G, TRUE);//縮小描画処理
			DrawGraph(0, 0, GameScene2G, TRUE);

			DrawFormatString(0, 0, RED, "%d", c1);
			DrawFormatString(5, 0, RED, "%d", c2);
			DrawFormatString(10, 0, RED, "%d", c3);
			DrawFormatString(15, 0, RED, "%d", c4);
			break;

		case SENGOKU://ステージ2>>戦国時代

			//ゲーム背景の画面を描画>>1番後ろに描画する背景画像
			DrawGraph(0, 0, GemeSceneG, TRUE);//画像を描画する

			//-BGMの再生処理-//
			//BGMが再生されているかを判別する
			//>>ステージ2(戦国時代)シーンで再生するBGMが再生されていないか
			if (CheckSoundMem(SengokuBGM) == 0)//再生されていない時
			{
				//再生されていない時にこのブロック内の処理を行う

				//-BGMの再生-//
				//>>ステージ2(戦国時代)シーンで再生するBGMを再生
				PlaySoundMem(SengokuBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンドで再生する
			}

			//-プレイヤー(アタッカーとスピード)の移動処理(特殊コマンド含む)とスキル発動システム処理-//
			//-プレイヤーの移動処理(アタッカー)-//
			//移動キーのボタン入力が有ったかを判定する
			//Wキーか↑キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//Y軸(上)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのY座標から移動量の値を入力が有る度に引いていく
				PlayerAY -= PlayAVel;//毎ループプレイヤーのY座標から移動量の値を引く
				//PlayerAY = PlayerAY - PlayAVel;と同じ処理
				//プレイヤーが↑方向を向いている画像を描画する
				PlayerDrawNum = 0;//フラグを0(上方向)に設定
			}

			//Sキーか↓キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//Y軸(下)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのY座標に移動量の値を足していく
				PlayerAX += PlayAVel;//毎ループプレイヤーのY座標に移動量の値を足す
				//PlayerAY = PlayerAY + PlayAVel;と同じ処理
				//プレイヤーが↓方向を向いている画像を描画する
				PlayerDrawNum = 1;//フラグを1(下方向)に設定
			}

			//Aキーか←キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//押され時
			{
				//押された時このブロック内の処理を行う
				//X軸(左)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのX座標から移動量の値を入力が有る度に引いていく
				PlayerAX -= PlayAVel;//毎ループプレイヤーのX座標から移動量の値を引いていく
				//PlayerAX = PlayerAX - PlayAVel;と同じ処理
				//プレイヤーが←方向を向いている画像を描画する
				PlayerDrawNum = 2;//フラグを2(左方向)に設定
			}

			//Dキーか→キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//X軸(右)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのX座標に移動量の値を入力が有る度に足していく
				PlayerAX -= PlayAVel;//毎ループプレイヤーのX座標に移動量の値を足す
				//PlayerAX = PlayerAX + PlayAVel;と同じ処理
				//プレイヤーが→方向を向いている画像を描画する
				PlayerDrawNum = 3;//フラグを3(右方向)に設定
			}

			//-特殊コマンド(ダッシュ)処理-//
			//SHIFTキーが押されたかつWキーか↑キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//Y軸(上)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのY座標から移動量の値を入力がある度に引いていく
				PlayerAY -= PlayAVel + PlayAVel;//毎ループプレイヤーのY座標から移動量の値を引く
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAY -= PlayAVel + PlayAVel;>>PlayerAY = PlayerAY - (PlayAVel + PlayAVel);と同じ処理
				//プレイヤーが↑方向を向いている画像を描画する
				PlayerDrawNum = 0;//フラグを0(上方向)に設定
			}

			//SHIFTキーが押されたかつSキーか↓キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//Y軸(下)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのY座標に移動量の値を入力がある度に足していく
				PlayerAY += PlayAVel + PlayAVel;//毎ループプレイヤーのY座標に移動量の値を足す
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAY += PlayAVel + PlayAVel;>>PlayerAY = PlayerAY + (PlayAVel + PlayAVel);と同じ処理
				//プレイヤーが↓方向を向いている画像を描画する
				PlayerDrawNum = 1;//フラグを1(下方向)に設定
			}

			//SHIFTキーが押されたかつAキーか←キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//X軸(左)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのX座標から移動量の値を入力がある度に引いていく
				PlayerAX -= PlayAVel + PlayAVel;//毎ループプレイヤーのX座標から移動量の値を引く
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAX -= PlayAVel + PlayAVel;>>PlayerAX = PlayerAX - (PlayAVel + PlayAVel);と同じ処理
				//プレイヤーが←方向を向いている画像を描画する
				PlayerDrawNum = 2;//フラグを2(左方向)に設定
			}

			//SHIFTキーが押されたかつDキーか→キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//X軸(右)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのX座標に移動量の値を入力がある度に足していく
				PlayerAX += PlayAVel + PlayAVel;//毎ループプレイヤーのX座標に移動量の値を足す
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAX += PlayAVel + PlayAVel;>>PlayerAX = PlayerAX + (PlayAVel + PlayAVel);と同じ処理
				//プレイヤーが→方向を向いている画像を描画する
				PlayerDrawNum = 3;//フラグを3(右方向)に設定
			}

			//-スキル発動処理-//
			//エネミーの動きを止めるスキル
			//Cキーが押されたか
			//>>判定の仕方はTriggerである
			if (keys[KEY_INPUT_C] == ON && oldkeys[KEY_INPUT_C] == OFF)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//エネミーの動きを止めるアイテムを取得しているかを判別する
				//エネミーの動きを止めるアイテムを持っているか
				if (EneStopF == ON)//持っている時
				{
					//-SEを再生する処理-//
					//SEが再生されているかの判別は必要ない
					//>>ボタン入力があった時のみ1回だけ再生すればいい為
					//SEを再生する
					PlaySoundMem(SkillSE, DX_PLAYTYPE_NORMAL);//SEをノーマル再生する

					//持っている時にこのブロック内の処理を行う
					//-エネミーの動きを停止させる処理-//
					EnemyVel = 0;//移動量
					//EnemyVelocity>>エネミーの移動の速さ
					//>>エネミーの移動は各座標に移動量を増減している為
					//>>移動量の値を0にする事で移動を停止する事が可能となる

					//スキルの持続時間をカウントする
					//カウントする変数の値を一定値まで増加させる
					//カウント数が0か
					if (EneStopC == 0)//カウント数が0の時
					{
						//-スキルの発動時間を伝えるBGM>>スキル発動中に再生するBGMの再生処理-//
						//スキル発動中に再生するBGMが再生されていないか
						if (CheckSoundMem(SkillBGM) == 0)//再生されていない時
						{
							//再生されていない時にこのブロック内の処理を行う
							PlaySoundMem(SkillBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンド再生する
						}

						//0の時にこのブロック内の処理を行う
						EneStopC += 1;//毎ループカウント数を1ずつ増加させる

						//カウント数が250(5秒後)か
						if (EneStopC == 250)//カウント数が250(5秒後)の時
						{
							//250(5秒後)の時にこのブロック内の処理を行う
							EneStopC = 250;//値を250で固定する

							//スキル発動を停止する
							//>>スキル発動アイテムの獲得フラグをOFF(未獲得)に変更する
							EneStopF = OFF;//フラグをOFFに変更
							//>>エネミーの移動が再開する

							//-スキルの発動時間を伝えるBGM>>スキル発動中に再生するBGMの停止処理-//
							//スキル発動中に再生するBGMが再生されているか
							if (CheckSoundMem(SkillBGM) == 0)//再生されている時
							{
								//再生されている時にこのブロック内の処理を行う
								StopSoundMem(SkillBGM);//BGMの再生を停止する
							}
						}
					}
				}
			}

			//-エネミーを殺すモーションの処理-//
			//Xキーが押されたか
			//>>判定の仕方はTriggerである
			if (keys[KEY_INPUT_X] == ON && oldkeys[KEY_INPUT_X] == OFF)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//エネミーがプレイヤーを発見してから警報を鳴らすまでの
				//時間をカウントする変数が0以外かを判別する
				//時間をカウントする変数が0以外か
				if (EneAlarmT != 0)//0以外の時
				{
					//0以外の時にこのブロック内の処理を行う
					//-エネミーの生存を管理するフラグをOFF(死亡)に変更する処理-//
					//エネミーの生存フラグがON(生存)か
					if (EneAliveF == 1)//フラグがON(生存)の時
					{
						//フラグがONの時にこのブロック内の処理を行う
						//エネミーの生存フラグをOFF(死亡)に変更する
						EneAliveF = 0;//生存フラグをOFF(死亡)に変更

						//エネミーを殺して死体を隠蔽するアニメーション画像を描画する

					}
				}

				//-ゲームオーバーシーンへのシーン移動処理-//
				//時間をカウントする変数が0か
				else if (EneAlarmT == 0)//時間をカウントする変数が0の時
				{
					//変数の値が0の時にこのブロック内の処理を行う
					//SEを再生する
					PlaySoundMem(DX_PLAYTYPE_BACK, EneAlarmSE);//SEをバックグラウンド再生する

					//プレイヤーが死ぬアニメーション画像を描画する

					//ゲームシーンのBGMが再生されているか
					if (CheckSoundMem(SengokuBGM) == 1)//再生されている時
					{
						//ゲームシーンのBGMが再生されている時にこのブロック内の処理を行う
						//BGMを停止する
						StopSoundMem(SengokuBGM);//BGMを停止する
						//シーンをステージ2(戦国時代)からゲームオーバーシーンへシーン変更する
						GameScene = GAMEOVER;//ゲームオーバーシーンへシーン変更する
					}
				}

			}

			//-スクロール処理-//
			//-マップチップのブロック同士の当たり判定
			//マップチップのブロック一つ一つの四つ角に当たっているかを
			//判定する用の変数の設定
			/*int C1 = StageMap[(PlayerAY - 31) / BlockSize][(PlayerAX - 31) / BlockSize];
			int C2 = StageMap[(PlayerAY - 31) / BlockSize][(PlayerAX + 32) / BlockSize];
			int C3 = StageMap[(PlayerAY + 32) / BlockSize][(PlayerAX - 31) / BlockSize];
			int C4 = StageMap[(PlayerAY + 32) / BlockSize][(PlayerAX + 32) / BlockSize];*/

			//-描画処理-//
			//ステージの縦端まで繰り返す
			for (int Y = 0; Y < StageHight; Y++)
			{
				//ステージの横端まで繰り返す
				for (int X = 0; X < StageWidth; X++)
				{
					//値が0のマス目は道
					if (StageMap[Y][X] == MICHI)
					{
						//マップチップの場所が0の時は道ブロックを描画
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, MITIBLOCK, TRUE);
					}

					//値が1のマス目は壁
					if (StageMap[Y][X] == KABE)
					{
						//マップチップの場所が1の時は壁ブロックを描画
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, KABEBLOCK, TRUE);
					}

					//値が2のマス目は赤ブロック
					if (StageMap[Y][X] == KAMON)
					{
						//マップチップの場所が2の時は赤ブロックを描画
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, RED, TRUE);
					}

					//値が3のマス目はお宝(村雨)
					if (StageMap[Y][X] == TAKARA)
					{
						//マップチップの場所が3の時はお宝ブロックを描画
						DrawGraph((X * BlockSize) - WorldPosX, (Y * BlockSize) - WorldPosY, RED, TRUE);

						//クリアシーンへ
						//GameScene = CLEAR;
					}

					//値が4のマス目はバッテリーを描画
					if (StageMap[Y][X] == BUTTELY)
					{
						//マップチップの場所が4の時はバッテリーを描画
						//DrawGraph((X* BlockSize)-WorldPosX, (Y* BlockSize)-WorldPosY, ButtelyG, TRUE);
					}

					//値が5のマス目はスタンガンを描画
					if (StageMap[Y][X] == SUTANGAN)
					{
						//マップチップの場所が5の時はスタンガンを描画
						//DrawGraph((X* BlockSize)-WorldPosX, (Y* BlockSize)-WorldPosY, SutanganG, TRUE);
					}

					//値が6のマス目は回復アイテムを描画
					if (StageMap[Y][X] == CARE)
					{
						//マップチップの場所が6の時は回復アイテムを描画
						//DrawGraph((X* BlockSize)-WorldPosX, (Y* BlockSize)-WorldPosY, CareItemG, TRUE);
					}
				}
			}

			//敵の移動処理//>>上下左右
			//-敵の上下移動処理
			if (EnemyDrawNum == 1)//描画番号が上下の番号(1)の時//下向き
			{
				//敵の下方向への移動処理
				EnemyY2 = EnemyY2 + EnemyVelY;

				//敵2のY座標が1792より大きくなったか
				if (EnemyY2 >= 1792)
				{
					EnemyDrawNum = 0;//上方向を向いている画像描画番号へ変更
					//Y座標を固定
					EnemyY2 = 1792;
				}
			}

			if (EnemyDrawNum == 0)//描画番号が上下の番号(0)の時//上向き
			{
				//敵の上方向への移動処理
				EnemyY2 = EnemyY2 - EnemyVelY;

				//敵2のY座標が1472より小さくなったか
				if (EnemyY2 <= 1472)
				{
					EnemyDrawNum = 1;//下方向を向いている画像描画番号へ変更
					//Y座標を固定
					EnemyY2 = 1472;
				}
			}

			//-敵の描画
			//-上下
			if (EnemyDrawNum == 0)//上方向を向いてる
			{
				//画像を描画
				DrawGraph(EnemyX2, EnemyY2, EnemyUpG, TRUE);
			}

			if (EnemyDrawNum == 1)//下方向を向いてる
			{
				//画像を描画
				DrawGraph(EnemyX2, EnemyY2, EnemyDownG, TRUE);
			}

			//-敵の左右移動処理
			if (EnemyDrawNum == 2)//描画番号が左右の番号(2)の時//左向き
			{
				//敵の左方向への移動処理
				EnemyX1 = EnemyX1 + EnemyVelX;

				//敵2のX座標が512より大きくなったか
				if (EnemyX1 >= 512)
				{
					EnemyDrawNum = 3;//右方向を向いている画像描画番号へ変更
					//X座標を固定
					EnemyX1 = 512;
				}
			}

			if (EnemyDrawNum == 3)//描画番号が左右の番号(3)の時//右向き
			{
				//敵の右方向への移動処理
				EnemyX1 = EnemyX1 - EnemyVelX;

				//敵2のX座標が192より小さくなったか
				if (EnemyX1 >= 192)
				{
					EnemyDrawNum = 2;//左方向を向いている画像描画番号へ変更
					//X座標を固定
					EnemyX1 = 192;
				}
			}

			//-敵の描画
			//-左右
			if (EnemyDrawNum == 2)//左方向を向いてる
			{
				//画像を描画
				DrawGraph(EnemyX2, EnemyY2, EnemyLeftG, TRUE);
			}

			if (EnemyDrawNum == 3)//右方向を向いてる
			{
				//画像を描画
				DrawGraph(EnemyX2, EnemyY2, EnemyRightG, TRUE);
			}

			DrawExtendGraph(PlayerX - 512, PlayerY - 512, PlayerX + 511, PlayerY + 511, blind, TRUE);

			//ゲームシーン背景手前の画像
			//DrawExtendGraph(0, 0, 1541, 881, GameScene2G, TRUE);//縮小描画処理
			DrawGraph(0, 0, GameScene2G, TRUE);

			break;

		case EGYPT://ステージ3>>古代エジプト

			//ゲーム背景の画面を描画
			DrawGraph(0, 0, EgyptG, TRUE);//画像を描画する

			//-BGMの再生処理-//
			//BGMが再生されているかを判別する
			//>>ステージ3(古代エジプト)シーンで再生するBGMが再生されていないか
			if (CheckSoundMem(EgyptBGM) == 0)//再生されていない時
			{
				//再生されていない時にこのブロック内の処理を行う

				//-BGMの再生-//
				//>>ステージ3(古代エジプト)シーンで再生するBGMを再生
				PlaySoundMem(EgyptBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンドで再生する
			}

			//-プレイヤー(アタッカーとスピード)の移動処理(特殊コマンド含む)とスキル発動システム処理-//
			//-プレイヤーの移動処理(アタッカー)-//
			//移動キーのボタン入力が有ったかを判定する
			//Wキーか↑キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//Y軸(上)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのY座標から移動量の値を入力が有る度に引いていく
				PlayerAY -= PlayAVel;//毎ループプレイヤーのY座標から移動量の値を引く
				//PlayerAY = PlayerAY - PlayAVel;と同じ処理
			}

			//Sキーか↓キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//Y軸(下)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのY座標に移動量の値を足していく
				PlayerAX += PlayAVel;//毎ループプレイヤーのY座標に移動量の値を足す
				//PlayerAY = PlayerAY + PlayAVel;と同じ処理
			}

			//Aキーか←キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//押され時
			{
				//押された時このブロック内の処理を行う
				//X軸(左)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのX座標から移動量の値を入力が有る度に引いていく
				PlayerAX -= PlayAVel;//毎ループプレイヤーのX座標から移動量の値を引いていく
				//PlayerAX = PlayerAX - PlayAVel;と同じ処理
			}

			//Dキーか→キーが押されたか>>判定の仕方は「または(OR)」となる
			if (keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//押された時
			{
				//押された時このブロック内の処理を行う
				//X軸(右)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのX座標に移動量の値を入力が有る度に足していく
				PlayerAX -= PlayAVel;//毎ループプレイヤーのX座標に移動量の値を足す
				//PlayerAX = PlayerAX + PlayAVel;と同じ処理
			}

			//-特殊コマンド(ダッシュ)処理-//
			//SHIFTキーが押されたかつWキーか↑キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_W] == ON || keys[KEY_INPUT_UP] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//Y軸(上)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのY座標から移動量の値を入力がある度に引いていく
				PlayerAY -= PlayAVel + PlayAVel;//毎ループプレイヤーのY座標から移動量の値を引く
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAY -= PlayAVel + PlayAVel;>>PlayerAY = PlayerAY - (PlayAVel + PlayAVel);と同じ処理
			}

			//SHIFTキーが押されたかつSキーか↓キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_S] == ON || keys[KEY_INPUT_DOWN] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//Y軸(下)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのY座標に移動量の値を入力がある度に足していく
				PlayerAY += PlayAVel + PlayAVel;//毎ループプレイヤーのY座標に移動量の値を足す
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAY += PlayAVel + PlayAVel;>>PlayerAY = PlayerAY + (PlayAVel + PlayAVel);と同じ処理
			}

			//SHIFTキーが押されたかつAキーか←キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_A] == ON || keys[KEY_INPUT_LEFT] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//X軸(左)方向にプレイヤーの移動量の値を引いていく
				//>>プレイヤーのX座標から移動量の値を入力がある度に引いていく
				PlayerAX -= PlayAVel + PlayAVel;//毎ループプレイヤーのX座標から移動量の値を引く
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAX -= PlayAVel + PlayAVel;>>PlayerAX = PlayerAX - (PlayAVel + PlayAVel);と同じ処理
			}

			//SHIFTキーが押されたかつDキーか→キーが押されたか
			//>>判定の仕方は「かつ(AND)」と「または(OR)」となる
			if (keys[KEY_INPUT_LSHIFT] == ON && oldkeys[KEY_INPUT_LSHIFT] == ON
				|| keys[KEY_INPUT_D] == ON || keys[KEY_INPUT_RIGHT] == ON)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//X軸(右)方向にプレイヤーの移動量の値を足していく
				//>>プレイヤーのX座標に移動量の値を入力がある度に足していく
				PlayerAX += PlayAVel + PlayAVel;//毎ループプレイヤーのX座標に移動量の値を足す
				//>>ダッシュは通常移動の時の移動量の2倍の値を増減させる(仮)
				//>>デバック後にゲームバランスを調節する際に確定する
				//PlayerAX += PlayAVel + PlayAVel;>>PlayerAX = PlayerAX + (PlayAVel + PlayAVel);と同じ処理
			}

			//-スキル発動処理-//
			//エネミーの動きを止めるスキル
			//Cキーが押されたか
			//>>判定の仕方はTriggerである
			if (keys[KEY_INPUT_C] == ON && oldkeys[KEY_INPUT_C] == OFF)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//エネミーの動きを止めるアイテムを取得しているかを判別する
				//エネミーの動きを止めるアイテムを持っているか
				if (EneStopF == ON)//持っている時
				{
					//-SEを再生する処理-//
					//SEが再生されているかの判別は必要ない
					//>>ボタン入力があった時のみ1回だけ再生すればいい為
					//SEを再生する
					PlaySoundMem(SkillSE, DX_PLAYTYPE_NORMAL);//SEをノーマル再生する

					//持っている時にこのブロック内の処理を行う
					//-エネミーの動きを停止させる処理-//
					EnemyVel = 0;//移動量
					//EnemyVelocity>>エネミーの移動の速さ
					//>>エネミーの移動は各座標に移動量を増減している為
					//>>移動量の値を0にする事で移動を停止する事が可能となる

					//スキルの持続時間をカウントする
					//カウントする変数の値を一定値まで増加させる
					//カウント数が0か
					if (EneStopC == 0)//カウント数が0の時
					{
						//-スキルの発動時間を伝えるBGM>>スキル発動中に再生するBGMの再生処理-//
						//スキル発動中に再生するBGMが再生されていないか
						if (CheckSoundMem(SkillBGM) == 0)//再生されていない時
						{
							//再生されていない時にこのブロック内の処理を行う
							PlaySoundMem(SkillBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンド再生する
						}

						//0の時にこのブロック内の処理を行う
						EneStopC += 1;//毎ループカウント数を1ずつ増加させる

						//カウント数が250(5秒後)か
						if (EneStopC == 250)//カウント数が250(5秒後)の時
						{
							//250(5秒後)の時にこのブロック内の処理を行う
							EneStopC = 250;//値を250で固定する

							//スキル発動を停止する
							//>>スキル発動アイテムの獲得フラグをOFF(未獲得)に変更する
							EneStopF = OFF;//フラグをOFFに変更
							//>>エネミーの移動が再開する

							//-スキルの発動時間を伝えるBGM>>スキル発動中に再生するBGMの停止処理-//
							//スキル発動中に再生するBGMが再生されているか
							if (CheckSoundMem(SkillBGM) == 0)//再生されている時
							{
								//再生されている時にこのブロック内の処理を行う
								StopSoundMem(SkillBGM);//BGMの再生を停止する
							}
						}
					}
				}
			}

			//-エネミーを殺すモーションの処理-//
			//Xキーが押されたか
			//>>判定の仕方はTriggerである
			if (keys[KEY_INPUT_X] == ON && oldkeys[KEY_INPUT_X] == OFF)//押された時
			{
				//押された時にこのブロック内の処理を行う
				//エネミーがプレイヤーを発見してから警報を鳴らすまでの
				//時間をカウントする変数が0以外かを判別する
				//時間をカウントする変数が0以外か
				if (EneAlarmT != 0)//0以外の時
				{
					//0以外の時にこのブロック内の処理を行う
					//-エネミーの生存を管理するフラグをOFF(死亡)に変更する処理-//
					//エネミーの生存フラグがON(生存)か
					if (EneAliveF == 1)//フラグがON(生存)の時
					{
						//フラグがONの時にこのブロック内の処理を行う
						//エネミーの生存フラグをOFF(死亡)に変更する
						EneAliveF = 0;//生存フラグをOFF(死亡)に変更

						//エネミーを殺して死体を隠蔽するアニメーション画像を描画する

					}
				}

				//-ゲームオーバーシーンへのシーン移動処理-//
				//時間をカウントする変数が0か
				else if (EneAlarmT == 0)//時間をカウントする変数が0の時
				{
					//変数の値が0の時にこのブロック内の処理を行う
					//SEを再生する
					PlaySoundMem(DX_PLAYTYPE_BACK, EneAlarmSE);//SEをバックグラウンド再生する

					//プレイヤーが死ぬアニメーション画像を描画する

					//ゲームシーンのBGMが再生されているか
					if (CheckSoundMem(EgyptBGM) == 1)//再生されている時
					{
						//ゲームシーンのBGMが再生されている時にこのブロック内の処理を行う
						//BGMを停止する
						StopSoundMem(EgyptBGM);//BGMを停止する
						//シーンをステージ3(古代エジプト)からゲームオーバーシーンへシーン変更する
						GameScene = GAMEOVER;//ゲームオーバーシーンへシーン変更する
					}
				}

			}

			for (int i = 0; i < MapY; i++) {
				for (int j = 0; j < MapX; j++) {
					if (Map[i][j] == block) {
						DrawBox(j * MapSize, i * MapSize, j * MapSize + MapSize, i * MapSize + MapSize, GetColor(255, 255, 255), TRUE);
					}

					//値が3のマス目はお宝(スフィンクス)
					if (StageMap[i][j] == TAKARA)
					{
						//マップチップの場所が3の時はお宝ブロックを描画
						DrawGraph((j * MapSize) - MapSize, (i * MapSize) - MapSize, EgyptTre, TRUE);
						//WorldPosY,WorldPosX

						//クリアシーンへ
						GameScene = CLEAR;
					}
				}
			}

			DrawExtendGraph(PlayerX - 512, PlayerY - 512, PlayerX + 511, PlayerY + 511, blind, TRUE);

			//ゲームシーン背景手前の画像
			//DrawExtendGraph(0, 0, 1541, 881, GameScene2G, TRUE);//縮小描画処理
			DrawGraph(0, 0, GameScene2G, TRUE);

			break;

		case CLEAR://クリア

			//クリア画面の描画
			DrawGraph(0, 0, ClearG, TRUE);//画像を描画する
			//クリア画面の画像を縮小して描画する
			//DrawExtendGraph(0, 0, 1541, 881, ClearG, TRUE);//縮小描画処理

			//-BGMの再生処理-//
			//BGMが再生されているかを判別する
			//>>クリアシーンで再生するBGMが再生されていないか
			if (CheckSoundMem(ClearBGM) == 0)//再生されていない時
			{
				//再生されていない時にこのブロック内の処理を行う

				//-BGMの再生-//
				//>>クリアシーンで再生するBGMを再生
				PlaySoundMem(ClearBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンドで再生する
			}

			//-次のシーンに移動する為のBGMの停止・ボタン入力時のSEの再生・シーン変更の処理-//
			//シーン移動のモーション>>ボタン入力があったかを判定する
			//スペースキーが押されているか
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//押された時(Tridder)
			{
				//スペースキーが押された時にこのブロック内の処理を行う

				//-BGMの停止処理-//
				//>>BGMが再生されているかを判別する
				//>>クリアシーンで再生するBGMが再生されているか
				if (CheckSoundMem(ClearBGM) == 1)//再生されている時
				{
					//再生されている時にこのブロック内の処理を行う
					//-BGMの停止-//
					StopSoundMem(ClearBGM);//BGMの再生を停止する

					//-SEの再生処理-//
					//SEを再生
					//>>この時SEの再生の判別は要らない
					//>>ボタン入力があった時のみ1回だけ再生すればいい為
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SEをノーマル再生する
				}

				//-シーン変更処理-//
				//>>タイトルシーンに戻る処理とステージ選択に戻る処理に分ける

				//-ステージ選択シーンへのシーン移動-//
				//ステージ選択画面に戻るボタンが押されたかの判別をする
				//>>Sキーが押されたか
				if (keys[KEY_INPUT_S] == ON && oldkeys[KEY_INPUT_S] == OFF)//押された
				{
					//押された時にこのブロック内の処理を行う

					//シーンをクリアシーンからステージ選択シーンに変更する
					GameScene = EXPLANATION;//ステージ選択シーンへシーン変更する
				}

				//-タイトルシーンへのシーン移動-//
				//タイトルシーンに戻るボタンが押されたかの判別をする
				//>>Tキーが押されたか
				if (keys[KEY_INPUT_T] == ON && oldkeys[KEY_INPUT_T] == OFF)//押された
				{
					//押された時にこのブロック内の処理を行う

					//シーンをクリアシーンからタイトルシーンに変更する
					GameScene = TITLE;//タイトルシーンへシーン変更する
				}
			}

			break;

		case GAMEOVER://ゲームオーバー

			//ゲームオーバー画面の描画
			DrawGraph(0, 0, GameOverG, TRUE);//画像を描画する
			//ゲームオーバー画面の画像を縮小して描画する
			//DrawExtendGraph(0, 0, 1541, 881, GameOverG, TRUE);//縮小描画処理

			//-BGMの再生処理-//
			//BGMが再生されているかを判別する
			//>>ゲームオーバーシーンで再生するBGMが再生されていないか
			if (CheckSoundMem(GameOvaeaBGM) == 0)//再生されていない時
			{
				//再生されていない時にこのブロック内の処理を行う

				//-BGMの再生-//
				//>>ゲームオーバーシーンで再生するBGMを再生
				PlaySoundMem(GameOvaeaBGM, DX_PLAYTYPE_BACK);//BGMをバックグラウンドで再生する
			}

			//-次のシーンに移動する為のBGMの停止・ボタン入力時のSEの再生・シーン変更の処理-//
			//シーン移動のモーション>>ボタン入力があったかを判定する
			//スペースキーが押されているか
			if (keys[KEY_INPUT_SPACE] == ON && oldkeys[KEY_INPUT_SPACE] == OFF)//押された時(Tridder)
			{
				//スペースキーが押された時にこのブロック内の処理を行う

				//-BGMの停止処理-//
				//>>BGMが再生されているかを判別する
				//>>ゲームオーバーシーンで再生するBGMが再生されているか
				if (CheckSoundMem(GameOvaeaBGM) == 1)//再生されている時
				{
					//再生されている時にこのブロック内の処理を行う
					//-BGMの停止-//
					StopSoundMem(GameOvaeaBGM);//BGMの再生を停止する

					//-SEの再生処理-//
					//SEを再生
					//>>この時SEの再生の判別は要らない
					//>>ボタン入力があった時のみ1回だけ再生すればいい為
					PlaySoundMem(InputSE, DX_PLAYTYPE_NORMAL);//SEをノーマル再生する
				}

				//-シーン変更処理-//
				//>>タイトルシーンに戻る処理とステージ選択に戻る処理に分ける

				//-ステージ選択シーンへのシーン移動-//
				//ステージ選択画面に戻るボタンが押されたかの判別をする
				//>>Sキーが押されたか
				if (keys[KEY_INPUT_S] == ON && oldkeys[KEY_INPUT_S] == OFF)//押された
				{
					//押された時にこのブロック内の処理を行う

					//シーンをゲームオーバーシーンからステージ選択シーンに変更する
					GameScene = EXPLANATION;//ステージ選択シーンへシーン変更する
				}

				//-タイトルシーンへのシーン移動-//
				//タイトルシーンに戻るボタンが押されたかの判別をする
				//>>Tキーが押されたか
				if (keys[KEY_INPUT_T] == ON && oldkeys[KEY_INPUT_T] == OFF)//押された
				{
					//押された時にこのブロック内の処理を行う

					//シーンをゲームオーバーシーンからタイトルシーンに変更する
					GameScene = TITLE;//タイトルシーンへシーン変更する
				}
			}

			break;

		default:
			break;
		}




		




		//---------  ここまでにプログラムを記述  ---------//
		ScreenFlip();//（ダブルバッファ）裏面
		// 20ミリ秒待機（疑似60FPS）
		WaitTimer(20);
		// Windows システムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}
		// ＥＳＣキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	//Dxライブラリ終了処理
	DxLib_End();

	return 0;
}