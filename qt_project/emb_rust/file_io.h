#ifndef FILE_IO_H
#define FILE_IO_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QFileInfo>

#include <QDebug>
#include "config.h"



class file_io
{
public:
    file_io();
    QJsonArray jsonArray;
    enum parameter{POWER, FREQUENCY, RATE, RANGE};
    int get_value(int index, parameter p);    
    void save_recipes();
    void update_recipe(int index, int power, int frequency, int rate, int range);
private:
    void initial_recipes();

    bool is_valid(parameter p, int value);
    QString convert_parameter_tostring(parameter p);
    void get_Jsonfile();
};

#endif // FILE_IO_H
