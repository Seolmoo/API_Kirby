#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleIntro.h"
#include "TitleBackGround.h"
#include <GameEngine/GameEngineRenderer.h>

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}

void TitleLevel::Loading()
{
	// Actor�� ������ֱ�

	// CreateActor<TitleBackGround>(0);

	CreateActor<TitleIntro>(1);
	
}

void TitleLevel::Update()
{
	// GameEngine::GlobalEngine().ChangeLevel("Play");
}