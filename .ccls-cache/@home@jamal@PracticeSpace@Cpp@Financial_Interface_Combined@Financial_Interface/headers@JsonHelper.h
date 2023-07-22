#ifndef JSONHELPER_H
#define JSONHELPER_H

#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;


struct JsonHelper{
    JsonHelper();
    nlohmann::json convertToJson(std::string simpleText);
};

#endif