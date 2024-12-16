#pragma once
#include "Engine/GameObject.h"


class Player :
    public GameObject
{

	enum PLAYER_STATE
	{
		IDLE, JOGGING, MAXSTATE
	};
	int hSilly;
	int hJogging;
	XMVECTOR front;
	PLAYER_STATE pState;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	XMFLOAT3 GetHeadPos();
};

