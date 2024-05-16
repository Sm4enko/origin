// Zoom

using UnrealBuildTool;
using System.Collections.Generic;

public class CameraEditorTarget : TargetRules
{
	public CameraEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Camera" } );
	}
}
