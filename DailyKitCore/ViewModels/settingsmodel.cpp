#include "settingsmodel.h"
#include <QDebug>

const QString SettingsModel::WEIGHT_ACCURACY = "WEIGHT ACCURACY";
const QString SettingsModel::PRINTING_TIME = "PRINTING TIME";
const QString SettingsModel::SIMULATOR = "SIMULATOR";
const QString SettingsModel::MANUAL_ENTRY = "MANUAL ENTRY";
const QString SettingsModel::PRINTER_TEST = "PRINTER TEST";

SettingsModel::SettingsModel(QObject *parent) :
    QObject(parent),
    m_accuracy(0.0),
    m_printingTime(0),
    m_simulatorSetting(false),
    m_manualEntry(false),
    m_printerTesting(false)
{
    loadSettings();
}

SettingsModel::~SettingsModel()
{
}

double SettingsModel::weightAccuracy() const
{
    return m_accuracy;
}

void SettingsModel::setWeightAccuracy(double accuracy)
{
    m_accuracy = accuracy;

    emit weightAccuracyChanged();
}

int SettingsModel::printingTime() const
{
    return m_printingTime;
}

void SettingsModel::setPrintingTime(int time)
{
    m_printingTime = time;
    emit printingTimeChanged();
}

bool SettingsModel::simulator() const
{
    return  m_simulatorSetting;
}

void SettingsModel::setSimulator(bool simulatorValue)
{
    m_simulatorSetting = simulatorValue;
    simulatorChanged();
}

bool SettingsModel::manualEntry() const
{
    return m_manualEntry;
}

void SettingsModel::setManualEntry(bool manualEntry)
{
    m_manualEntry = manualEntry;
    emit manualEntryChanged();
}

bool SettingsModel::printerTest() const
{
    return m_printerTesting;
}

void SettingsModel::setPrinterTest(bool printerTest)
{
    m_printerTesting = printerTest;
    emit printerTestChanged();
}

void SettingsModel::loadSettings()
{
    setWeightAccuracy(m_settings.value(WEIGHT_ACCURACY).toDouble());
    setPrintingTime(m_settings.value(PRINTING_TIME).toInt());
    setManualEntry(m_settings.value(MANUAL_ENTRY).toBool());
    setSimulator(m_settings.value(SIMULATOR).toBool());
    setPrinterTest(m_settings.value(PRINTER_TEST).toBool());
}

void SettingsModel::saveSettings()
{
     m_settings.setValue(WEIGHT_ACCURACY, weightAccuracy());
     m_settings.setValue(PRINTER_TEST, printerTest());
     m_settings.setValue(MANUAL_ENTRY, manualEntry());
     m_settings.setValue(SIMULATOR, simulator());
     m_settings.setValue(PRINTING_TIME, printingTime());

     loadSettings();
}
