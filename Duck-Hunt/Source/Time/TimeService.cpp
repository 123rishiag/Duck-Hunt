#include "../../Header/Time/TimeService.h"

namespace Time {
	void TimeService::Initialize()
	{
		previousTime = std::chrono::steady_clock::now();
		deltaTime = 0;
	}

	void TimeService::Update()
	{
		UpdateDeltaTime();
	}

	void TimeService::UpdateDeltaTime()
	{
		deltaTime = CalculateDeltaTime();
		UpdatePreviousTime();
	}

	float TimeService::CalculateDeltaTime() const
	{
		// Calculate time difference in microseconds between the current and previous frame.
		int delta = std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::steady_clock::now() - previousTime).count();

		// The cast is used to convert delta time from microseconds into seconds.
		// We will learn about how this works in detail later.
		return static_cast<float>(delta) / static_cast<float>(1000000);
	}

	// Update previous_time to the current time
	void TimeService::UpdatePreviousTime()
	{
		previousTime = std::chrono::steady_clock::now();
	}

	float TimeService::GetDeltaTime() const
	{
		return deltaTime;
	}
}