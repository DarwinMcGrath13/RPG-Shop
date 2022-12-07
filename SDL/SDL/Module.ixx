
public:static GameManager* Instance(); static void Release();

void Run(); void Update(); void LateUpdate(); void Render(); GameManager(); ~GameManager();


#include "GameManager.h"namespace SDLFramework {    GameManager * GameManager::sInstance = nullptr;    GameManager * GameManager::Instance()    {if (sInstance == nullptr) {            sInstance = new GameManager();        }return sInstance;    }}


void GameManager::Release() { delete sInstance; sInstance = nullptr; }


void GameManager::Run() {// main game loopwhile (!mQuit) {// event processing loopwhile (SDL_PollEvent(&mEvent)) {switch (mEvent.type) {case SDL_QUIT:                mQuit = true;break;            }        }        Update();        LateUpdate();        Render();    }}

	
		void GameManager::Update() {}void GameManager::LateUpdate() {}void GameManager::Render() { mGraphics->ClearBackBuffer();    mGraphics->Render(); }

	
		GameManager::GameManager() : mQuit(false) {// create Graphics singleton    mGraphics = Graphics::Instance();// verify Graphics module is readyif (!Graphics::Initialized()) {        mQuit = true;    }}

		
			GameManager::~GameManager() {// release modules    Graphics::Release();    mGraphics = nullptr;// Quit SDL subsystems    SDL_Quit();}

			
#include "GameManager.h"using SDLFramework::GameManager;int main(int argc, char * args[]){    GameManager * game = GameManager::Instance();    game->Run();    GameManager::Release();    game = nullptr;return 0;}

				
#ifndef __TIMER_H#define __TIMER_H#include <SDL.h>namespace SDLFramework {class Timer {private:static Timer * sInstance;    };}#endif

				
				unsigned int mStartTicks; unsigned int mElapsedTicks; float mDeltaTime; float mTimeScale;

			
public:static Timer* Instance(); static void Release();

			
				void Reset(); float DeltaTime(); void TimeScale(float ts); float TimeScale(); void Update();

			
private:    Timer();    ~Timer();

			
#include "Timer.h"namespace SDLFramework {    Timer * Timer::sInstance = nullptr;    Timer * Timer::Instance() {if (sInstance == nullptr) {            sInstance = new Timer();        }return sInstance;    }void Timer::Release() {delete sInstance;        sInstance = nullptr;    }}

				
				void Timer::Reset() { mStartTicks = SDL_GetTicks();    mElapsedTicks = 0;    mDeltaTime = 0.0f; }

			
				float Timer::DeltaTime() { return mDeltaTime; }void Timer::TimeScale(float ts) { mTimeScale = ts; }float Timer::TimeScale() { return mTimeScale; }

			
				void Timer::Update() {
				mElapsedTicks = SDL_GetTicks() - mStartTicks;    mDeltaTime = mElapsedTicks * 0.001f; // convert to seconds}

				
					Timer::Timer() { Reset();    mTimeScale = 1.0f; }Timer::~Timer() {}

				
                   #include "Timer.h"

					
					const int FRAME_RATE = 60;        Timer* mTimer;

				
					mTimer = Timer::Instance();

				
					Timer::Release();    mTimer = nullptr;

				
					mTimer->Update();


					if (mTimer->DeltaTime() >= 1.0f / FRAME_RATE) { Update();            LateUpdate();            Render();            mTimer->Reset(); }

