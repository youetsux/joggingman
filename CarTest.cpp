#include "CarTest.h"
#include "Engine\\Model.h"

CarTest::CarTest(GameObject* parent)
	:GameObject(parent,"Car"),hModel(-1)
{
}

void CarTest::Initialize()
{
	hModel = Model::Load("car.fbx");
	//transform_.position_ = { 1.0, 0, 1.0 };
	transform_.scale_ = { 0.1, 0.1, 0.1};
}

void CarTest::Update()
{
}

void CarTest::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void CarTest::Release()
{
}
