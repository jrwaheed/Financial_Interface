#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Python.h>
#include <nlohmann/json.hpp>

#include "../headers/PythonConnection.h"
#include "../headers/JsonHelper.h"

using json = nlohmann::json;


JsonHelper::JsonHelper(){}

json JsonHelper::convertToJson(std::string simpleText){
    auto fullJson = nlohmann::json::parse(simpleText);

    return fullJson;
};


