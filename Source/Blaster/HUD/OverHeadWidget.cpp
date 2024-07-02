// Fill out your copyright notice in the Description page of Project Settings.

#include "OverHeadWidget.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerState.h"

void UOverHeadWidget::SetDisplayText(FString TextToDisplay)
{
    if (DisplayText)
    {
        DisplayText->SetText(FText::FromString(TextToDisplay));
    }
}

void UOverHeadWidget::ShowPlayerNetRole(APawn *InPawn)
{
    ENetRole RemoteRole = InPawn->GetRemoteRole();
    FString Role;
    switch (RemoteRole)
    {
    case ENetRole::ROLE_Authority:
        Role = FString("Authority");
        break;
    case ENetRole::ROLE_AutonomousProxy:
        Role = FString("Autonomous Proxy");
        break;
    case ENetRole::ROLE_SimulatedProxy:
        Role = FString("Simulated Proxy");
        break;
    case ENetRole::ROLE_None:
        Role = FString("None");
        break;
    }
    FString RemoteRoleString = FString::Printf(TEXT("Remote Role : %s"), *Role);
    SetDisplayText(RemoteRoleString);
}

void UOverHeadWidget::ShowPlayerName(APawn* InPawn)
{
    APlayerState *PlayerState = InPawn->GetPlayerState();
    if(PlayerState)
    {
        FString PlayerName = PlayerState->GetPlayerName();
        SetDisplayText(PlayerName);
    }
}

void UOverHeadWidget::NativeDestruct()
{
    RemoveFromParent();
    Super::NativeDestruct();
}