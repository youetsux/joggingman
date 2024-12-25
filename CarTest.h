#pragma once
#include "Engine\\GameObject.h"
class CarTest :
    public GameObject
{
	int hModel;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CarTest(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

