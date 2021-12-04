// Fill out your copyright notice in the Description page of Project Settings.


#include "ARExplosiveBarrel.h"

// Sets default values
AARExplosiveBarrel::AARExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	MeshComp->SetSimulatePhysics(true);
	MeshComp->OnComponentHit.AddDynamic(this, &AARExplosiveBarrel::OnCompHit);
	
	RootComponent = MeshComp;

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("Radial Force");
	RadialForceComp->Radius = 650.0f;
	RadialForceComp->ImpulseStrength = 2000.0f;
	RadialForceComp->bImpulseVelChange = true;

}

// Called when the game starts or when spawned
void AARExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AARExplosiveBarrel::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		RadialForceComp->FireImpulse();
	}
}

