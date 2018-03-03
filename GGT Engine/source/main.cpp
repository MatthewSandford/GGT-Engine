#include <json/json.h>
#include <string>
#include "application.h"
#include "jsonhandler.h"
#include "modelmanager.h"
#include "texturemanager.h"

int main()
{
    Json::Value config = JsonHandler::LoadJsonFromFile("assets/window_config.json");
    Application app(config);
    app.Start();

    return 0;
}