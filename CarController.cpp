#include "CarController.h"
#include "player.h"

CarController::CarController(GameObject* parent)
	:GameObject(parent,"CarController"),frontVec({0,0, 1})
{
}

void CarController::Initialize()
{
	transform_.position_ = { -1, 0, 0 };
}

void CarController::Update()
{
	XMMATRIX mvec = transform_.matRotate_;
	XMVECTOR front{ frontVec.x, frontVec.y, frontVec.z };
	front = XMVector3Transform(front, mvec);
	
	XMFLOAT3 playerPos = ((Player *)FindObject("Player"))->GetWorldPosition();


	XMVECTOR targetVec = XMVector3Normalize({ playerPos.x - transform_.position_.x,
		                                      playerPos.y - transform_.position_.y, 
		                                      playerPos.z - transform_.position_.z });
	XMVECTOR angle = XMVector3AngleBetweenVectors (targetVec, front);
	XMVECTOR rotDir = XMVector3Cross(targetVec, front);


	float dig = XMConvertToDegrees(XMVectorGetX(angle));


	if (dig > 1) {
		if (XMVectorGetY(rotDir) > 0)
			transform_.rotate_.y += 0.5;
		else
			transform_.rotate_.y -= 0.5;
	}

	transform_.Calclation();
	mvec = transform_.matRotate_;
	front = { frontVec.x, frontVec.y, frontVec.z };
	XMVECTOR nextVec = XMVector3Transform(front, mvec);
	XMVECTOR npos;
	npos = XMLoadFloat3(&transform_.position_);
	npos = npos + 0.002 * targetVec;
	XMStoreFloat3(&transform_.position_, npos);
}

void CarController::Draw()
{
}

void CarController::Release()
{
}
