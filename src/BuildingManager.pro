QT += core gui widgets charts

CONFIG += c++17

SOURCES += \
    Model/BrightnessSensor.cpp \
    Model/Building.cpp \
    Model/Converter/JsonConverter.cpp \
    Model/NoiseSensor.cpp \
    Model/Sensor.cpp \
    Model/TemperatureSensor.cpp \
    View/BuildingMenuBar.cpp \
    View/Dialogs/AddSensorDialog.cpp \
    View/BuildingWindow.cpp \
    View/Dialogs/EditSensor/EditBrightnessSensorDialog.cpp \
    View/Dialogs/EditSensor/EditNoiseSensorDialog.cpp \
    View/Dialogs/EditSensor/EditSensorDialogInterface.cpp \
    View/Dialogs/EditSensor/EditTemperatureSensorDialog.cpp \
    View/SearchPanel.cpp \
    View/Visitors/SensorEditVisitor.cpp \
    View/Visitors/SensorInfoVisitor.cpp \
    View/SensorItem.cpp \
    Model/Converter/SensorJsonVisitor.cpp \
    View/SensorsListPanel.cpp \
    View/SensorsPanel.cpp \
    View/SimulationPanel.cpp \
    main.cpp \
    View/MainWindow.cpp

HEADERS += \
    Model/BrightnessSensor.h \
    Model/Building.h \
    Model/BuildingObserverInterface.h \
    Model/Converter/JsonConverter.h \
    Model/NoiseSensor.h \
    Model/Sensor.h \
    Model/SensorConstVisitorInterface.h \
    Model/SensorVisitorInterface.h \
    Model/TemperatureSensor.h \
    View/BuildingMenuBar.h \
    View/Dialogs/AddSensorDialog.h \
    View/BuildingWindow.h \
    View/Dialogs/EditSensor/EditBrightnessSensorDialog.h \
    View/Dialogs/EditSensor/EditNoiseSensorDialog.h \
    View/Dialogs/EditSensor/EditSensorDialogInterface.h \
    View/Dialogs/EditSensor/EditTemperatureSensorDialog.h \
    View/MainWindow.h \
    View/SearchPanel.h \
    View/Visitors/SensorEditVisitor.h \
    View/Visitors/SensorInfoVisitor.h \
    View/SensorItem.h \
    Model/Converter/SensorJsonVisitor.h \
    View/SensorsListPanel.h \
    View/SensorsPanel.h \
    View/SimulationPanel.h

RESOURCES += \
    resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
