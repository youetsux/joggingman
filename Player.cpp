#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "Engine/Input.h"
#include "TestScene.h"
#include "Engine/Camera.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"), hSilly(-1), hJogging(-1),
	front({ 0, 0,-1, 0 }), pState(IDLE), hRPunch(-1),hLPunch(-1),isRightP(true)
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
	hJump = Model::Load("runjump.fbx");
	//transform_.scale_ = { 0.001,0.001,0.001 };
	transform_.scale_ = { 0.1, 0.1, 0.1 };
	transform_.position_ = { 0.0, 0.0, 0.0 };
	//front = { 0, 0, -1, 0 };
	pState = IDLE;
	isRightP = true;

	//idle 156
	//jog 165
	Model::SetAnimFrame(hSilly, 1, 836, 1.0);
	Model::SetAnimFrame(hJogging, 1, 42, 1.0);
	Model::SetAnimFrame(hRPunch, 1, 66, 1.0);
	Model::SetAnimFrame(hLPunch, 1, 66, 1.0);
	Model::SetAnimFrame(hJump, 1, 52, 1.0);
}
	

void Player::Update()
{
	//transform_.rotate_.y +=1;
	static bool punch = false;
	static float dt = 0;
	//static PLAYER_STATE lastState = IDLE;
	if (Input::IsKey(DIK_SPACE))
	{
		if (pState == IDLE)
		{
			pState = JOGGING;
			Model::SetAnimFrame(hJogging, 1, 42, 1.0);
		}
	}
	if (Input::IsKeyUp(DIK_SPACE))
	{
		if (pState == JOGGING)
		{
			pState = IDLE;
			Model::SetAnimFrame(hSilly, 1, 836, 1.0);
		}
	}
	if (Input::IsKeyDown(DIK_B))
	{
		if (punch == false) {
			//lastState = pState;
			dt = 0;
			punch = true;
			pState = PUNCH;
			if (isRightP)
			{
				Model::SetAnimFrame(hRPunch, 1, 66, 1.0);
				isRightP = false;
			}
			else
			{
				Model::SetAnimFrame(hLPunch, 1, 66, 1.0);
				isRightP = true;
			}
		}
	}
	
	if (punch) {
		if (dt > 66) {
			punch = false;
			pState = IDLE;
		}
		else {
			dt = dt + 1;
		}
		
	}
	if (pState == JUMP)
	{
		if (dt > 48) {
			pState = IDLE;
		}
		else {
			dt = dt + 1;
		}
	}
	if (Input::IsKeyDown(DIK_N))
	{
		if (!punch &&  pState !=JUMP)
		{
			Model::SetAnimFrame(hJump, 1, 52, 1.0);
			pState = JUMP;
			dt = 0;
		}
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
	else if (pState == PUNCH)
	{
		if (isRightP) {
			Model::SetTransform(hLPunch, transform_);
			Model::Draw(hLPunch);
		}
		else
		{
			Model::SetTransform(hRPunch, transform_);
			Model::Draw(hRPunch);
		}
	}
	else if (pState == JUMP)
	{
		Model::SetTransform(hJump, transform_);
		Model::Draw(hJump);
	}
}


void Player::Release()
{
}

XMFLOAT3 Player::GetHeadPos()
{
	XMFLOAT3 res = { 0,0,0 };
	//res = Model::GetAnimBonePosition(hJogging, "mixamorig:Head");
	if(pState == IDLE)
		res = Model::GetAnimBonePosition(hSilly, "mixamorig:Head");
	else if(pState == JOGGING)
  		res = Model::GetAnimBonePosition(hJogging, "mixamorig:Head");
	else if (pState == PUNCH)
	{
		if(isRightP)
			res = Model::GetAnimBonePosition(hSilly, "mixamorig:Head");
		else
			res = Model::GetAnimBonePosition(hSilly, "mixamorig:Head");
	}
	else if (pState == JUMP)
	{
		res = Model::GetAnimBonePosition(hJump, "mixamorig:Head");
	}
	return res;
}
