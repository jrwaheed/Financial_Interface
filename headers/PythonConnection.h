#ifndef PYTHONCONNECTION_H
#define PYTHONCONNECTION_H

#include <Python.h>
#include <stdio.h>
#include <iostream>
#include <jsoncpp/json/json.h>

struct PythonConnection{
    PythonConnection();
    std::string call_Python_no_Param(const char* functionName);
    std::string call_Python_with_Param(const char* functionName, std::string currency);
    
};

#endif