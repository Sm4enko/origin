// Zoom

using UnrealBuildTool;
using System.Collections.Generic;

public class CameraTarget : TargetRules
{
	public CameraTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Camera" } );
	}
}
