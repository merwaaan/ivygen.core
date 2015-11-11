/**************************************************************************************
**
**  Copyright (C) 2006 Thomas Luft, University of Konstanz. All rights reserved.
**
**  This file is part of the Ivy Generator Tool.
**
**  This program is free software; you can redistribute it and/or modify it
**  under the terms of the GNU General Public License as published by the
**  Free Software Foundation; either version 2 of the License, or (at your
**  option) any later version.
**  This program is distributed in the hope that it will be useful, but
**  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
**  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
**  for more details.
**  You should have received a copy of the GNU General Public License along
**  with this program; if not, write to the Free Software Foundation,
**  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA 
**
***************************************************************************************/


#include <QApplication>
#include "ivygeneratorwindow.h"


int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else 
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        application.setStyleSheet(ts.readAll());
    }


    IvyGeneratorWindow ivyGenerator;

    ivyGenerator.show();
	
    application.connect(&application, SIGNAL(lastWindowClosed()), &application, SLOT(quit()));

    return application.exec();
}
