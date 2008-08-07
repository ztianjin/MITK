#include "QmitkRegisterClasses.h"
#include "Step8.h"

#include "mitkDataStorage.h"

#include <QApplication>
#include <itksys/SystemTools.hxx>

int main(int argc, char* argv[])
{
  QApplication qtapplication( argc, argv );

  if(argc<2)
  {
    fprintf( stderr, "Usage:   %s [filename1] [filename2] ...\n\n", itksys::SystemTools::GetFilenameName(argv[0]).c_str() );
    return 1;
  }

  // Register Qmitk-dependent global instances
  QmitkRegisterClasses();
  
  Step8 mainWidget(argc, argv, NULL);
  mainWidget.Initialize();
  mainWidget.show();

  // for testing
  #include "QtTesting.h"
  if(strcmp(argv[argc-1], "-testing")!=0)
    return qtapplication.exec();
  else
    return QtTesting();

  // Release all resources used by the data storage and
  // the datatree
  mitk::DataStorage::ShutdownSingleton();
}

/**
\example Step8main.cpp
*/
