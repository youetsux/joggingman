#include "DummyController.h"
#include "Engine/Input.h"
#include "Player.h"

DummyController::DummyController(GameObject* parent)
	:GameObject(parent,"DummyController")
{
}

void DummyController::Initialize()
{
	transform_.position_ = { 2, 0, 0 };
}

void DummyController::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 2;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 2;
	}

	if (Input::IsKey(DIK_SPACE))
	{
		transform_.Calclation();
		XMMATRIX mvec = transform_.matRotate_;
		XMVECTOR front{ 0, 0, -1, 0 };
		front = XMVector3Transform(front, mvec);
		XMVECTOR npos;
		npos = XMLoadFloat3(&transform_.position_); 
		npos = npos + 0.007 * front;
		XMStoreFloat3(&transform_.position_, npos);
	}
}

void DummyController::Draw()
{
}

void DummyController::Release()
{
}
