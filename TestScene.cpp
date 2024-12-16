#include "TestScene.h"
#include "Player.h"
#include "DummyController.h"
#include "TPCam.h"
#include "Ground.h"

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	Instantiate<Ground>(this);
	Instantiate <Player>(Instantiate<DummyController>(this));
	Instantiate <TPCam>(Instantiate<DummyController>(this));

}

//更新
void TestScene::Update()
{
}

//描画
void TestScene::Draw()
{
}

//開放
void TestScene::Release()
{
}
