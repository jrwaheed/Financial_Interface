#include <Python.h>
#include <stdio.h>
#include <iostream>
#include "../headers/PythonConnection.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>

PythonConnection::PythonConnection(){}

std::string PythonConnection::call_Python_no_Param(const char* functionName){
    Py_Initialize(); 
    
    PyObject *name, *load_module, *func, *callfunc, *args;

    name = PyUnicode_FromString("PythonScript");
    load_module = PyImport_Import(name);
    func = PyObject_GetAttrString(load_module,functionName);
    callfunc = PyObject_CallObject(func, NULL);
    std::string result = _PyUnicode_AsString(callfunc);
   
    return result;
    

    Py_Finalize();    
};

std::string PythonConnection::call_Python_with_Param(const char* functionName, std::string currency){
    Py_Initialize(); 
    
    PyObject *name, *load_module, *func, *callfunc, *args;

    name = PyUnicode_FromString("PythonScript");
    load_module = PyImport_Import(name);
    func = PyObject_GetAttrString(load_module,functionName);
    args = PyTuple_Pack(1, PyUnicode_FromString(currency.c_str()));
    callfunc = PyObject_CallObject(func, args);
    std::string result = _PyUnicode_AsString(callfunc);
   
    return result;
    
    Py_Finalize();    
}