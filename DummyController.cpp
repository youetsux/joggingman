#include "DummyController.h"
#include "Engine/Input.h"

DummyController::DummyController(GameObject* parent)
	:GameObject(parent,"DummyController")
{
}

void DummyController::Initialize()
{
}

void DummyController::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 5;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 5;
	}

	if (Input::IsKey(DIK_SPACE))
	{
		transform_.Calclation();
		XMMATRIX mvec = transform_.matRotate_;
		XMVECTOR front{ 0, 0, -1, 0 };
		front = XMVector3Transform(front, mvec);
		XMVECTOR npos;
		npos = XMLoadFloat3(&transform_.position_); 
		npos = npos + 0.004 * front;
		XMStoreFloat3(&transform_.position_, npos);
	}
}

void DummyController::Draw()
{
}

void DummyController::Release()
{
}
