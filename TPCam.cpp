#include "TPCam.h"
#include "DummyController.h"
#include "Engine/Camera.h"


TPCam::TPCam(GameObject* parent)
	:GameObject(parent, "TPCam")
{
	transform_.position_ = { 0,3,4 };
	target = { 0,2,0 };
}

void TPCam::Initialize()
{
	Camera::SetPosition(position);
	Camera::SetTarget(target);
}

void TPCam::Update()
{
	XMMATRIX wMat = GetParent()->GetWorldMatrix();
	XMFLOAT3 wpos = { transform_.position_.x + GetParent()->GetPosition().x,
					  transform_.position_.y + GetParent()->GetPosition().y,
					  transform_.position_.z + GetParent()->GetPosition().z };
	XMFLOAT3 wrot = { transform_.rotate_.x + GetParent()->GetRotate().x,
					  transform_.rotate_.y + GetParent()->GetRotate().y,
					  transform_.rotate_.z + GetParent()->GetRotate().z };

	XMFLOAT3 wscl = { transform_.scale_.x + GetParent()->GetScale().x,
				      transform_.scale_.y + GetParent()->GetScale().y,
				      transform_.scale_.z + GetParent()->GetScale().z };
	XMVECTOR wposV = XMLoadFloat3(&wpos);
	wposV = XMVector3TransformCoord(wposV, wMat);
	XMFLOAT3 campos;
	XMStoreFloat3(&campos, wposV);
	XMFLOAT3 tpos = GetParent()->GetPosition();
	Camera::SetPosition(campos);
	Camera::SetTarget(tpos);
}

void TPCam::Draw()
{
}

void TPCam::Release()
{
}
