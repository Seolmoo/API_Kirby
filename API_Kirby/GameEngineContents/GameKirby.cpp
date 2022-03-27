#include "GameKirby.h"
#include "HUBWorld.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineBase/GameEngineFile.h>
#include <GameEngine/GameEngineImageManager.h>

GameKirby::GameKirby()
{
}

GameKirby::~GameKirby()
{
}

void GameKirby::GameInit()
{
	// ���������� * 3 
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 300, 10 }, { 768, 720 });

	// Ŀ��
	GameEngineDirectory ResourcesDir;
	ResourcesDir.MoveParent("API_Kirby");
	ResourcesDir.Move("Kirby_Resources");
	ResourcesDir.Move("Actor");
	ResourcesDir.Move("Kirby");

	// �����ȿ� ��� �̹��� ������ ã�´�.
	std::vector<GameEngineFile> AllImageFileList = ResourcesDir.GetAllFile("Bmp");

	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}

	// Level
	ResourcesDir.MoveParent("API_Kirby");
	ResourcesDir.Move("Kirby_Resources");
	ResourcesDir.Move("Level");

	AllImageFileList = ResourcesDir.GetAllFile("Bmp");
	for (size_t i = 0; i < AllImageFileList.size(); i++)
	{
		GameEngineImageManager::GetInst()->Load(AllImageFileList[i].GetFullPath());
	}


	GameEngineImage* KirbyImage = GameEngineImageManager::GetInst()->Find("Kirby_Idle_Right.bmp");
	KirbyImage->Cut({ 48, 48 });



	CreateLevel<TitleLevel>("Title");
	CreateLevel<HUBWorld>("HUBWorld");
	// CreateLevel<EndingLevel>("Ending");
	ChangeLevel("HUBWorld");
}

void GameKirby::GameLoop()
{
}

void GameKirby::GameEnd()
{
}
