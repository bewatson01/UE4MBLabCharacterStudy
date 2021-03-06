// © Ajit D'Monte 2019


#include "MirrorCharacterMovementComponent.h"

UMirrorCharacterMovementComponent::UMirrorCharacterMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RootMotionAxis = FVector(1.f, 1.f, 1.f);
}


void UMirrorCharacterMovementComponent::OnRegister()
{
	Super::OnRegister();	
}

FVector UMirrorCharacterMovementComponent::CalcAnimRootMotionVelocity(const FVector& RootMotionDeltaMove, float DeltaSeconds, const FVector& CurrentVelocity) const
{
	if (ensure(DeltaSeconds > 0.f))
	{
		FVector RootMotionVelocity = (RootMotionDeltaMove*RootMotionAxis) / DeltaSeconds;
		return RootMotionVelocity;
	}
	else
	{
		return CurrentVelocity;
	}
}

void UMirrorCharacterMovementComponent::PhysWalking(float DeltaTime, int32 Iterations)
{
	// let character do its thing for translation
	Super::PhysWalking(DeltaTime, Iterations);
}