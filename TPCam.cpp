#include "TPCam.h"
#include "DummyController.h"
#include "Engine/Camera.h"
#include "Player.h"

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

	XMFLOAT3 lpos = { 0.0f, 0.2f, 0.3f };//カメラのローカルポジション
	XMFLOAT3 ppos = GetParent()->GetWorldPosition();
	XMFLOAT3 wpos = { lpos.x ,  lpos.y , lpos.z  };
					  
	XMVECTOR wposV = XMLoadFloat3(&wpos);
	wposV = XMVector3Transform(wposV, wMat);
	XMFLOAT3 campos;

	XMStoreFloat3(&campos, wposV);
	XMFLOAT3 tpos = GetParent()->GetPosition();
	
	Player* pl = (Player*)FindObject("Player");
	
	Camera::SetPosition({ campos.x, campos.y, campos.z });
	Camera::SetTarget(pl->GetHeadPos());
}

void TPCam::Draw()
{
}

void TPCam::Release()
{
}
