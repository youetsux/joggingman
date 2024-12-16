#pragma once
#include "Engine/GameObject.h"
#include "Weapon.h"


class Player :
    public GameObject
{

	enum PLAYER_STATE
	{
		IDLE, JOGGING, MAXSTATE
	};
	int hSilly;
	int hJogging;
	Transform idleTr, jogTr;
	XMVECTOR front;
	PLAYER_STATE pState;
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
};

