#include "TestScene.h"
#include "Player.h"
//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	Instantiate <Player>(this);

}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}
