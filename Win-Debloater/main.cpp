#include "service.h"
#include <Windows.h>

//int main()
//{
//	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, DEFENDER_REGISTER_PATH, DEFENDER_NAME, 1);
//	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Real-Time Protection", "DisableRealtimeMonitoring", 1);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Features", "TamperProtection", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Spynet", "SpyNetReporting", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Spynet", "SubmitSamplesConsent", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\DomainProfile", "EnableFirewall", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\PublicProfile", "EnableFirewall", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\ControlSet001\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\StandardProfile", "EnableFirewall", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\DomainProfile", "EnableFirewall", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\PublicProfile", "EnableFirewall", 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Services\\SharedAccess\\Parameters\\FirewallPolicy\\StandardProfile", "EnableFirewall", 0);
//	//
//	////hklm / SOFTWARE / Microsoft / Windows Defender / Real - Time Protection / DisableRealtimeMonitoring
//	//
//	////hklm / SOFTWARE / Microsoft / Windows Defender / Features / TamperProtection: 0
//	//
//	////hklm / SOFTWARE / Microsoft / Windows Defender / Spynet / SpyNetReporting : 0
//	//
//	////hklm / SOFTWARE / Microsoft / Windows Defender / Spynet / SubmitSamplesConsent : 0
//	//
//	////hklm / SYSTEM / ControlSet001 / Services / SharedAccess / Parameters / FirewallPolicy / DomainProfile / EnableFirewall : 0
//	///// PublicProfile / EnableFirewall : 0
//	///// StandardProfile / EnableFirewall : 0
//	//
//	////hklm / SYSTEM / CurrentControlSet / Services / SharedAccess / Parameters / FirewallPolicy / DomainProfile / EnableFirewall : 0
//	////PublicProfile / EnableFirewall : 0
//	////StandardProfile / EnableFirewall : 0
//	//
//	//// Local machine \ Software \ Microsoft \ Windows Defender \ Features \ Tamper protection
//	////reg::security::gain_permission(HKEY_LOCAL_MACHINE, DEFENDER_REGISTER_PATH);
//	// reg::remove::value(HKEY_LOCAL_MACHINE, DEFENDER_ICON_PATH, DEFENDER_ICON);
//	ChangeRegistryNumber(HKEY_CURRENT_USER, EXPLORER_REGISTER_PATH, EXPLORER_THISPC, 1);
//	ChangeRegistryNumber(HKEY_CURRENT_USER, EXPLORER_REGISTER_PATH, TASKBAR_NOGROUP, 2);
//	ChangeRegistryNumber(HKEY_CURRENT_USER, EXPLORER_REGISTER_PATH, MULTIMONITOR_TASKBAR_NOGROUP, 2);
//	ChangeRegistryNumber(HKEY_CURRENT_USER, EXPLORER_REGISTER_PATH, HIDE_FOLDERS, 1);
//	ChangeRegistryNumber(HKEY_CURRENT_USER, EXPLORER_REGISTER_PATH, HIDE_EXTENSIONS, 0);
//	ChangeRegistryNumber(HKEY_CURRENT_USER, EXPLORER_REGISTER_PATH, TASKVIEW_BUTTON, 0);
//	ChangeRegistryString(HKEY_CURRENT_USER, DATETIME_PATH, DATETIME_NAME1, "1");
//	ChangeRegistryString(HKEY_CURRENT_USER, DATETIME_PATH, DATETIME_NAME2, "-");
//	ChangeRegistryString(HKEY_CURRENT_USER, DATETIME_PATH, DATETIME_NAME3, "ddd d-MMM/MM-yyyy");
//	ChangeRegistryNumber(HKEY_CURRENT_USER, SEARCH_BAR_PATH, SEARCH_BAR, 0);
//	ChangeRegistryNumber(HKEY_CURRENT_USER, EXPLORER_REGISTER_PATH, TASKBARSPEED_NAME, 75);
//	ChangeRegistryString(HKEY_CLASSES_ROOT, NOTEPAD_ADDON, "", NOTEPAD_EXEC);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, TELEMETRY_REGISTER_PATH, TELEMETRY_NAME, 0);
//	// svc::self_closing_registry_key manager(svc::OpenServiceManager());
//	// svc::self_closing_registry_key handle(svc::Open(*manager, SERVICE_TELEMETRY1));
//	// svc::DisableService(*manager, *handle);
//	//reg::remove::value(HKEY_CURRENT_USER, ONEDRIVE_NAME, ONEDRIVE_REGISTRY_PATH);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, ADS_REGISTER_PATH, ADS_NAME, 1);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, ADVERTISING_INFO_PATH, ADS_INFO_NAME, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, SOFTLANDING_PATH, SOFTLANDING_NAME, 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, CORTANA_REGISTER_PATH, CORTANA_NAME, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, SILENT_INSTALL_PATH, SILENT_NAME, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, SILENT_INSTALL_PATH, DELIVERY_NAME, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, PREINSTALLED_APPS_PATH, PREINSTALLED_NAME1, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, PREINSTALLED_APPS_PATH, PREINSTALLED_NAME2, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, PREINSTALLED_APPS_PATH, PREINSTALLED_NAME3, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, SUGGESTIONS_PATH, SUGGESTIONS_NAME, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, QUICKACCESS_PATH, QUICKACCESS_NAME, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, QUICKACCESS_PATH, FREQUENTS_NAME, 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, UAC_REGISTRY_PATH, UAC_NAME1, 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, UAC_REGISTRY_PATH, UAC_NAME2, 0);
//	// ChangeRegistryNumber(HKEY_CURRENT_USER, TRACKDOCS_PATH, TRACKDOCS_NAME, 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, FIREWALL_PATH1, FIREWALL_NAME, 0);
//	// ChangeRegistryNumber(HKEY_LOCAL_MACHINE, FIREWALL_PATH2, FIREWALL_NAME, 0);
//	//
//	// system(BUILDER3D);
//	// system(GETOFFICE);
//	// system(GETSKYPE);
//	// system(GROOVEMUSIC);
//	// system(MAPS_WIN);
//	// system(SOLITAIRE);
//	// system(VIDEO);
//	// system(PEOPLE);
//	// ////system(STORE);
//	// system(RECORDER);
//	// system(WEATHER);
//	// //system(XBOX_APP);
//	// system(NEWS_APP);
//	// system(MAIL_APP);
//	// system(CANDY_CRUSH);
//	// system(SKETCHBOOK);
//	// system(FEEDBACKHUB);
//	// system(VIEWER3D);
//
//	system("pause");
//}

int main()
{
	// Disable windows defender, firewall, smart screen, tamper protection, and reporting
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows Defender", "DisableAntiSpyware", 1);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows Defender", "DisableRoutinelyTakingAction", 1);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Real-Time Protection", "DisableRealtimeMonitoring", 1);
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer", "SmartScreenEnabled", "Off");
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppHost", "EnableWebContentEvaluation", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AppHost", "PreventOverride", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\System", "EnableSmartScreen", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Features", "TamperProtection", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Spynet", "SpyNetReporting", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows Defender\\Spynet", "SubmitSamplesConsent", 2);
	Delete_RegistryValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", "SecurityHealth");
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\DomainProfile", "EnableFirewall", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\WindowsFirewall\\StandardProfile", "EnableFirewall", 0);

	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "ConsentPromptBehaviorAdmin", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", "PromptOnSecureDesktop", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\Zones\\3", "1806", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Attachments", "SaveZoneInformation", 1);

	// Performance
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\PriorityControl", "Win32PrioritySeparation", 0x26);
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer", "Max Cached Icons", "4096");

	// Advertising
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\AdvertisingInfo", "Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "ShowSyncProviderNotifications", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\UserProfileEngagement", "ScoobeSystemSettingEnabled", 0);
	// > Telemetry
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "Software\\Policies\\Microsoft\\Windows NT\\CurrentVersion\\Software Protection Platform", "NoGenTicket", 1);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\AppV\\CEIP", "CEIPEnable", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\SQMClient\\Windows", "CEIPEnable", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\Diagnostics\\Performance", "DisableDiagnosticTracing", 1);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\InputPersonalization", "RestrictImplicitInkCollection", 1);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\InputPersonalization", "RestrictImplicitTextCollection", 1);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\InputPersonalization\\TrainedDataStore", "HarvestContacts", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Personalization\\Settings", "AcceptedPrivacyPolicy", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\TabletPC", "PreventHandwritingDataSharing", 1);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\HandwritingErrorReports", "PreventHandwritingErrorReports", 1);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Input\\Settings", "InsightsEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Input\\TIPC", "Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Diagnostics\\DiagTrack", "ShowedToastAtLevel", 1);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection", "AllowTelemetry", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection", "MaxTelemetryAllowed", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Policies\\DataCollection", "AllowTelemetry", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Speech", "AllowSpeechModelUpdate", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Privacy", "TailoredExperiencesWithDiagnosticDataEnabled", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\CloudContent", "DisableTailoredExperiencesWithDiagnosticData", 1);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting", "Disabled", 1);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\PCHealth\\ErrorReporting", "DoReport", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Error Reporting", "Disabled", 1);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\System", "UploadUserActivities", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\System", "PublishUserActivities", 0);

	// Bloat
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "ContentDeliveryAllowed", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "OemPreInstalledAppsEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "PreInstalledAppsEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "PreInstalledAppsEverEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SilentInstalledAppsEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SubscribedContent-310093Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SubscribedContent-338393Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SubscribedContent-353694Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SubscribedContent-353696Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SubscribedContent-338387Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "RotatingLockScreenOverlayEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SubscribedContent-338388Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SystemPaneSuggestionsEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SubscribedContent-338389Enabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SoftLandingEnabled", 0);

	// Loggers
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\CloudExperienceHostOobe", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\DefenderApiLogger", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\DefenderAuditLogger", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Diagtrack-Listener", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\Diaglog", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\NetCore", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\NtfsLog", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\RadioMgr", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\RdrLog", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\ReadyBoot", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\SpoolerLogger", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\UBPM", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WdiContextLog", "Start", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SYSTEM\\CurrentControlSet\\Control\\WMI\\Autologger\\WiFiSession", "Start", 0);


	// Experimentation
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\PolicyManager\\default\\System\\AllowExperimentation", "Value", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\PreviewBuilds", "AllowBuildPreview", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\PreviewBuilds", "EnableConfigFlighting", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\PreviewBuilds", "EnableExperimentation", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Visibility", "HideInsiderPage", 1);

	// Quality of life
	// Do not track recently used documents
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "Start_TrackDocs", 0);
	// Open to "This PC"
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "LaunchTo", 1);
	// Show hidden files and extensions
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "Hidden", 1);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "HideFileExt", 0);
	// Taskbar no group and quick preview
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "TaskbarGlomLevel", 2);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "MMTaskbarGlomLevel", 2);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "ExtendedUIHoverTime", 75);
	// Remove Feed, Meet and Task view
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "ShowTaskViewButton", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Feeds", "ShellFeedsTaskbarViewMode", 2);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer", "HideSCAMeetNow", 1);
	// Superior date-time
	ChangeRegistryString(HKEY_CURRENT_USER, "Control Panel\\International", "iDate", "1");
	ChangeRegistryString(HKEY_CURRENT_USER, "Control Panel\\International", "sDate", " - ");
	ChangeRegistryString(HKEY_CURRENT_USER, "Control Panel\\International", "sShortDate", "ddd d-MMM/MM-yyyy");
	// Add open with notepad
	ChangeRegistryString(HKEY_CLASSES_ROOT, "*\\shell\\Open with Notepad\\command", "", "notepad.exe %1\0");

	// Do not show suggestions in start menu
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\ContentDeliveryManager", "SystemPaneSuggestionsEnabled", 0);
	// In File Explorer, do not show recent or frequently used files
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", "ShowRecent", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", "ShowFrequent", 0);
	// Disable stupid shortcuts
	ChangeRegistryString(HKEY_CURRENT_USER, "Control Panel\\Accessibility\\StickyKeys", "Flags", "506");
	ChangeRegistryString(HKEY_CURRENT_USER, "Control Panel\\Accessibility\\ToggleKeys", "Flags", "58");
	// Always show more details on transfers (shows graph progress bar)
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\OperationStatusManager", "EnthusiastMode", 1);
#pragma region Hide folders from "This PC"
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{31C0DD25-9439-4F12-BF41-7FF4EDA38722}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{31C0DD25-9439-4F12-BF41-7FF4EDA38722}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{a0c69a99-21c8-4671-8703-7934162fcf1d}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{a0c69a99-21c8-4671-8703-7934162fcf1d}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{7d83ee9b-2244-4e70-b1f5-5393042af1e4}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{7d83ee9b-2244-4e70-b1f5-5393042af1e4}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{0ddd015d-b06c-45d5-8c4c-f59713854639}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{0ddd015d-b06c-45d5-8c4c-f59713854639}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{35286a68-3c57-41a1-bbb1-0eae73d76c95}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{35286a68-3c57-41a1-bbb1-0eae73d76c95}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{f42ee2d3-909f-4907-8871-4c22fc0bf756}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{f42ee2d3-909f-4907-8871-4c22fc0bf756}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}\\PropertyBag", "ThisPCPolicy", "Hide");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Explorer\\FolderDescriptions\\{B4BFCC3A-DB2C-424C-B029-7FE99A87C641}\\PropertyBag", "ThisPCPolicy", "Hide");
#pragma endregion
	// Always show full context menu
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer", "MultipleInvokePromptMinimum", 100);
	// Minimize mouse hover time
	ChangeRegistryString(HKEY_CURRENT_USER, "Control Panel\\Desktop", "MouseHoverTime", "20");
	// Alt tab open windows (to fix individual edge tabs)
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced", "MultiTaskingAltTabFilter", 3);

	// Context menu
	// Remove "Troubleshooting Compatibility"
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Blocked", "{1d27f844-3a1f-4410-85ac-14651078412d}", "");
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions", "{1d27f844-3a1f-4410-85ac-14651078412d}", "");

	// Windows Search
	// disable online search
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Search", "BingSearchEnabled", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search", "ConnectedSearchUseWeb", 0);
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search", "DisableWebSearch", 1);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\SearchSettings", "IsMSACloudSearchEnabled", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\SearchSettings", "SafeSearchMode", 0);
	ChangeRegistryNumber(HKEY_CURRENT_USER, "SOFTWARE\\Policies\\Microsoft\\Windows\\Explorer", "DisableSearchBoxSuggestions", 0);
	// Do not show an icon for search
	ChangeRegistryNumber(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Search", "SearchboxTaskbarMode", 0);

	// ##Important##
	// Can potentially reset settings if not turned off
	ChangeRegistryNumber(HKEY_LOCAL_MACHINE, "SOFTWARE\\Policies\\Microsoft\\Windows\\OOBE", "DisablePrivacyExperience", 1);
	ChangeRegistryString(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\PowerShell\\1\\ShellIds\\Microsoft.PowerShell", "ExecutionPolicy", "Unrestricted");
	system("pause");
}
