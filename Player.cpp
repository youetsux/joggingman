#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "Weapon.h"
#include "TestScene.h"
#include "JointBall.h"


Player::Player(GameObject* parent)
	:GameObject(parent), hSilly(-1),hJogging(-1)
{
	//swordDirには、初期方向として、ローカルモデルの剣の根っこから
	//先端までのベクトルとして（0,1,0)を代入しておく
	//初期位置は原点
}

void Player::Initialize()
{
	hSilly = Model::Load("idle.fbx");
	hSilly = Model::Load("jogging.fbx");
	jogTr.scale_ = { 0.02,0.02,0.02 };
	jogTr.position_ = { 0, -2.0, 0 };

	//walk 165
	Model::SetAnimFrame(hSilly, 0, 156, 1.0);



	//XMVECTOR v1{ 0, 1, 0 };
	//XMVECTOR v2{ 1, 1, 0 };
	//XMVECTOR vn;
	//
	//v2 = XMVector3Normalize(v2);
	//vn = XMVector3Cross(v1, v2);
	//vn = XMVector3Normalize(vn);
	//float rotAngle = XMVectorGetX(XMVector3AngleBetweenVectors(v1, v2));
	//XMMATRIX rotMatrix = XMMatrixRotationAxis(vn, rotAngle);
	//XMMATRIX scrMatrix = XMMatrixIdentity();
	//XMMATRIX posMatrix = XMMatrixScaling( 0.05, 0.05, 0.05 );
	//pWep->SetTranslateMatrix(posMatrix);
	//pWep->SetRotateMatrix(rotMatrix);
	//pWep->SetScaleMatrix(scrMatrix);

}

void Player::Update()
{
	//transform_.rotate_.y +=1;
	
	//pWep->SetPosition(Model::GetAnimBonePosition(hSilly, "mixamorig6:RightHand"));
	//Transform tr1, tr2;
	//tr1.position_ = Model::GetAnimBonePosition(hSilly, "mixamorig:LeftHandThumb3");
	//tr2.position_ = Model::GetAnimBonePosition(hSilly, "mixamorig:RightHandPinky3");
	//XMVECTOR Vt1, Vt2, localUp{ 0,1,0 }, SwordDir;
	//Vt1 = XMLoadFloat3(&tr1.position_);
	//Vt2 = XMLoadFloat3(&tr2.position_);
	//XMMATRIX swRot;
	//if (XMVector3Equal({ Vt2 - Vt1 }, XMVectorZero())) {
	//	swRot = XMMatrixIdentity();
	//}
	//else {
	//	XMVECTOR rotAngle = XMVector3AngleBetweenVectors(localUp, XMVector3Normalize(Vt1 - Vt2) );
	//	XMVECTOR rotNormal = XMVector3Cross(localUp, XMVector3Normalize(Vt1 - Vt2));
	//	XMVECTOR rotVec = XMQuaternionRotationAxis(rotNormal, XMVectorGetX(rotAngle));
	//	swRot = XMMatrixRotationQuaternion(rotVec);
	//}
	//pWep->SetPosition(tr1.position_);
	//XMMATRIX swTr = XMMatrixTranslation(tr1.position_.x, tr1.position_.y, tr1.position_.z);
	//XMMATRIX swScale = XMMatrixScaling(0.05, 0.05, 0.05);
	//pWep->SetScaleMatrix(swScale);
	//pWep->SetTranslateMatrix(swTr);
	//pWep->SetRotateMatrix(swRot);
	//pWep->SetPosition({ 0, 0, 0 });
//	XMVECTOR v1{ 0, 1, 0 };
//	XMVECTOR v2{ 0, 1, 1 };
//	XMVECTOR vn;
//
//	v2 = XMVector3Normalize(v2);
//	vn = XMVector3Cross(v1, v2);
//	vn = XMVector3Normalize(vn);
//	float rotAngle = XMVectorGetX(XMVector3AngleBetweenVectors(v1, v2));
//	XMMATRIX rotMatrix = XMMatrixRotationAxis(vn, rotAngle);
//	XMMATRIX scrMatrix = XMMatrixIdentity();
//	XMMATRIX posMatrix = XMMatrixScaling(0.05, 0.05, 0.05);
//	pWep->SetTranslateMatrix(posMatrix);
//	pWep->SetRotateMatrix(rotMatrix);
//	pWep->SetScaleMatrix(scrMatrix);
}

void Player::Draw()
{

	Model::SetTransform(hSilly, jogTr);
	Model::Draw(hSilly);
}


void Player::Release()
{
}
