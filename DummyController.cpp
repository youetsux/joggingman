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
}

void DummyController::Draw()
{
}

void DummyController::Release()
{
}
