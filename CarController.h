#pragma once
#include "Engine\\GameObject.h"


class CarController :
    public GameObject
{
public:
	XMFLOAT3 frontVec;
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	CarController(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

