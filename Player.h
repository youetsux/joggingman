#pragma once
#include "Engine/GameObject.h"


class Player :
    public GameObject
{

	enum PLAYER_STATE
	{
		IDLE, JOGGING, PUNCH, JUMP, MAXSTATE
	};
	int hSilly;
	int hJogging;
	int hLPunch, hRPunch;
	int hJump;
	XMVECTOR front;
	PLAYER_STATE pState;
	bool isRightP;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	XMFLOAT3 GetHeadPos();

};

