#include "Ground.h"
#include "Engine/Model.h"


Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"),hGround(-1)
{
}

void Ground::Initialize()
{
	hGround = Model::Load("ground.fbx");

}

void Ground::Update()
{

}

void Ground::Draw()
{
	transform_.scale_ = { 5.0, 5.0, 5.0 };
	Model::SetTransform(hGround, transform_);
	Model::Draw(hGround);
}

void Ground::Release()
{
}
