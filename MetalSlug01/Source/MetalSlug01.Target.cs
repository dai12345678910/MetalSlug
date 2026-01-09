// Fill out your copyright notice in the Description page of Project Settings.
////
using UnrealBuildTool;
using System.Collections.Generic;

public class MetalSlug01Target : TargetRules
{
	public MetalSlug01Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "MetalSlug01" } );
	}
}
