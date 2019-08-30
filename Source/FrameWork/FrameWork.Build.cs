// Fill out your copyright notice in the Description page of Project Settings.
using System;
using System.IO;
using UnrealBuildTool;

public class FrameWork : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
    }

    public FrameWork(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PrivateDependencyModuleNames.AddRange(new string[] { "slua_unreal", "Slate", "SlateCore", "UMG" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "slua_unreal" });
        PublicIncludePathModuleNames.AddRange(new string[] { "slua_unreal" });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        //LoadLua(Target); // This functions loads Lua
    }

    private bool LoadLua(ReadOnlyTargetRules TargetRules)
    {
        bool isLibSupported = false;

        // Check if we are on Windows
        if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
        {
            isLibSupported = true;

            string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86"; // This string is either "x64" or "x86" so we can append it on the lib filename
            string BuildTypeString = (Target.Configuration == UnrealTargetConfiguration.Debug) ? "Debug" : "Release";
            string LibrariesPath = Path.Combine(ThirdPartyPath, "LuaIntegration", "libraries", PlatformString, BuildTypeString);

            PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "Lua5.1.5.lib"));

            PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "LuaIntegration", "includes"));
        }

        Definitions.Add(string.Format("WITH_LUA_BINDING={0}", isLibSupported ? 1 : 0));

        return isLibSupported;
    }
}
