#pragma once
#include "RequestData.h"
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class CAppsflyerLauncherModule
{
public:
	// Initialize the AppsFlyer Connector with your api key and app id,
	void Init(const char *devkey, const char *appID);
	// Send first open/session request to AppsFlyer).
	void Start(bool skipFirst = false);
	// This method receives an event name and json object and sends an in-app event to AppsFlyer.
	void LogEvent(std::string event_name, json event_values);
	std::string GetAppsFlyerUID();
	bool IsInstallOlderThanDate(std::string datestring);

private:
	const char *devkey;
	const char *appID;
	friend CAppsflyerLauncherModule *AppsflyerLauncherModule();
	CAppsflyerLauncherModule();
};

const int FIRST_OPEN_REQUEST = 100;
const int SESSION_REQUEST = 101;
const int INAPP_EVENT_REQUEST = 102;

CAppsflyerLauncherModule *AppsflyerLauncherModule();