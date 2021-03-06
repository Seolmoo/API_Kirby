#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineUpdateObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include "GameEngineEnum.h"
#include <list>

// 설명 :
class GameEngineRenderer;
class GameEngineLevel;
class GameEngineActor : public GameEngineNameObject, public GameEngineUpdateObject
{
	//// ActorBase
public:
	friend GameEngineLevel;

	// constrcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	inline GameEngineLevel* GetLevel()
	{
		return Level_;
	}

	inline float4 GetPosition()
	{
		return Position_;
	}
	inline float4 GetScale()
	{
		return Scale_;
	}


	inline void SetMove(float4 _Value)
	{
		Position_ += _Value;
	}

	inline void SetPosition(float4 _Value)
	{
		Position_ = _Value;
	}
	inline void SetScale(float4 _Value)
	{
		Scale_ = _Value;
	}


protected:
	// 시작할때 뭔가를 하고 싶은데 생성자에서는 절대로 못할 부분들을 처리한다.
	virtual void Start() = 0;

	// 지속적으로 게임이 실행될때 호출된다.
	virtual void Update() {}
	virtual void Render() {}

	void DebugRectRender();

private:
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;

	// 나를 만들어준 레벨이라는것을 알려줌
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}


	/////////////////////////////////////////////////// Render

public:
	// 벡터의 값
	// 디폴트 인자는 선언에서만 지정 가능
	GameEngineRenderer* CreateRenderer(const std::string& _Image, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	GameEngineRenderer* CreateRendererToScale(const std::string& _Image, const float4& _Scale, RenderPivot _PivotType = RenderPivot::CENTER, const float4& _PivotPos = { 0,0 });

	void Renderering();

private:
	// 이터레이터
	std::list<GameEngineRenderer*>::iterator StartRenderIter;
	std::list<GameEngineRenderer*>::iterator EndRenderIter;

	std::list<GameEngineRenderer*> RenderList_;
};


