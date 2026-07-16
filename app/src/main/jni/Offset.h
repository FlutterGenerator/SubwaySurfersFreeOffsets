lib l2cpp;
Address 
_GetCurrency, 
_GetGodHack, 
_GetGodHack2, 
_getMaxSpeed, 
_getMinSpeed, 
_getJumpHeight, 
_getJumpLimit, 
_ApplyGravity, 
_UpdateMovement, 
_getownsCoinDoubler, 
_IsAutoReviveEnabled, 
_getBaseMultiplierSum, 
_getLaneChangeDuration, 
_CameraFollow, 
_CameraStop;

void getAddress() {
l2cpp.name = "libil2cpp.so";
l2cpp.open();

//Normal Example 
Uclass WalletModelClass = l2cpp.getClass("SYBO.Subway.Meta", "WalletModel");
_GetCurrency = WalletModelClass.dump("GetCurrency", 1);

Uclass CharacterMotorClass = l2cpp.getClass("SYBO.RunnerCore.Character", "CharacterMotor");
_GetGodHack = CharacterMotorClass.dump("CheckFrontalImpact", 1);
_GetGodHack2 = CharacterMotorClass.dump("CheckSideImpact", 1);
_ApplyGravity = CharacterMotorClass.dump("ApplyGravity", 0);
_UpdateMovement = CharacterMotorClass.dump("UpdateMovement", 0);

Uclass CharacterMotorAbilitiesClass = l2cpp.getClass("SYBO.RunnerCore.Character", "CharacterMotorAbilities");
_getMaxSpeed = CharacterMotorAbilitiesClass.dump("get_MaxSpeed", 0);
_getMinSpeed = CharacterMotorAbilitiesClass.dump("get_MinSpeed", 0);
_getJumpHeight = CharacterMotorAbilitiesClass.dump("get_JumpHeight", 0);
_getJumpLimit = CharacterMotorAbilitiesClass.dump("get_JumpLimit", 0);
_getLaneChangeDuration = CharacterMotorAbilitiesClass.dump("get_LaneChangeDuration", 0);

Uclass EndRunCoinWidgetClass = l2cpp.getClass("SYBO.Subway", "EndRunCoinWidget");
_getownsCoinDoubler = EndRunCoinWidgetClass.dump("get_OwnsCoinDoubler", 0);

Uclass CharacterStumbleClass = l2cpp.getClass("SYBO.Subway", "CharacterStumble");
_IsAutoReviveEnabled = CharacterStumbleClass.dump("IsAutoReviveEnabled", 0);

Uclass ScoreMultiplierManagerClass = l2cpp.getClass("SYBO.Subway", "ScoreMultiplierManager");
_getBaseMultiplierSum = ScoreMultiplierManagerClass.dump("get_BaseMultiplierSum", 0);

Uclass CameraGroundedModifierClass = l2cpp.getClass("SYBO.Subway", "CameraGroundedModifier");
_CameraFollow = CameraGroundedModifierClass.dump("Apply", 1);

Uclass CameraOffsetModifierClass = l2cpp.getClass("SYBO.Subway", "CameraOffsetModifier");
_CameraStop = CameraOffsetModifierClass.dump("Apply", 1);

}
