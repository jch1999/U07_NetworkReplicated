using UnrealBuildTool;

public class OSS : ModuleRules
{
	public OSS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.Add(ModuleDirectory);

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"UMG",
			"OnlineSubsystem",
			"OnlineSubsystemSteam"
		});

		/*if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string SteamSDKPath = Path.Combine(ModuleDirectory, "../../Plugins/Steam/Steamworks");
			PublicIncludePaths.Add(Path.Combine(SteamSDKPath, "sdk/public"));
			PublicAdditionalLibraries.Add(Path.Combine(SteamSDKPath, "sdk/redistributable_bin/win64/steam_api64.lib"));
		}*/
	}
}
