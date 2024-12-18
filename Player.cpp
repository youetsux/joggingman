#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "Engine/Input.h"
#include "TestScene.h"
#include "Engine/Camera.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"), hSilly(-1), hJogging(-1),
	front({ 0, 0,-1, 0 }), pState(IDLE), hRPunch(-1),hLPunch(-1)
{
	//swordDirには、初期方向として、ローカルモデルの剣の根っこから
	//先端までのベクトルとして（0,1,0)を代入しておく
	//初期位置は原点
}

void Player::Initialize()
{

	hSilly = Model::Load("idle.fbx");
	hJogging = Model::Load("running.fbx");
	hLPunch = Model::Load("LeftP.fbx");
	hRPunch = Model::Load("RightP.fbx");
	//transform_.scale_ = { 0.001,0.001,0.001 };
	transform_.scale_ = { 0.1, 0.1, 0.1 };
	transform_.position_ = { 0.0, 0.0, 0.0 };
	//front = { 0, 0, -1, 0 };
	pState = IDLE;
	


	//idle 156
	//jog 165
	Model::SetAnimFrame(hSilly, 1, 836, 1.0);
	Model::SetAnimFrame(hJogging, 1, 42, 1.0);
	Model::SetAnimFrame(hRPunch, 1, 66, 1.0);
	Model::SetAnimFrame(hLPunch, 1, 66, 1.0);
}

void Player::Update()
{
	//transform_.rotate_.y +=1;
	static bool punch = false;
	static float dt = 0;
	static PLAYER_STATE lastState = IDLE;
	if (Input::IsKey(DIK_SPACE))
	{
		if (pState == IDLE)
		{
			pState = JOGGING;
			Model::SetAnimFrame(hSilly, 1, 836, 1.0);
		}
	}
	if (Input::IsKeyUp(DIK_SPACE))
	{
		if (pState == JOGGING)
		{
			pState = IDLE;
			Model::SetAnimFrame(hJogging, 1, 42, 1.0);
		}
	}
	if (Input::IsKeyDown(DIK_P))
	{

	}
	


}

void Player::Draw()
{
	if (pState == IDLE) {
		Model::SetTransform(hSilly, transform_);
		Model::Draw(hSilly);
	}
	else if(pState == JOGGING)
	{
		Model::SetTransform(hJogging, transform_);
		Model::Draw(hJogging);
	}

}


void Player::Release()
{
}

XMFLOAT3 Player::GetHeadPos()
{
	XMFLOAT3 res = { 0,0,0 };
	if(pState == IDLE)
		res = Model::GetAnimBonePosition(hSilly, "mixamorig:Head");
	else if(pState == JOGGING)
		res = Model::GetAnimBonePosition(hJogging, "mixamorig:Head");
	return res;
}
