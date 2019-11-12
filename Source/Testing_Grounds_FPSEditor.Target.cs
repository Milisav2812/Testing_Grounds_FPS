// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class Testing_Grounds_FPSEditorTarget : TargetRules
{
	public Testing_Grounds_FPSEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("Testing_Grounds_FPS");
	}
}
