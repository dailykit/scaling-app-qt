#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QObject>
#include <QSettings>

class SettingsModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double weightAccuracy READ weightAccuracy WRITE setWeightAccuracy NOTIFY weightAccuracyChanged)
    Q_PROPERTY(int printingTime READ printingTime WRITE setPrintingTime NOTIFY printingTimeChanged)
    Q_PROPERTY(bool simulator READ simulator WRITE setSimulator NOTIFY simulatorChanged)
    Q_PROPERTY(bool manualEntry READ manualEntry WRITE setManualEntry NOTIFY manualEntryChanged)
    Q_PROPERTY(bool printerTest READ printerTest WRITE setPrinterTest NOTIFY printerTestChanged)

public:
    explicit SettingsModel(QObject *parent = nullptr);
    virtual ~SettingsModel();

    double weightAccuracy() const;
    void setWeightAccuracy(double accuracy);

    int printingTime() const;
    void setPrintingTime(int time);

    bool simulator() const;
    void setSimulator(bool simulatorValue);

    bool manualEntry() const;
    void setManualEntry(bool manualEntry);

    bool printerTest() const;
    void setPrinterTest(bool printerTest);

    Q_INVOKABLE void loadSettings();
    Q_INVOKABLE void saveSettings();

signals:
    void weightAccuracyChanged();
    void printingTimeChanged();
    void simulatorChanged();
    void manualEntryChanged();
    void printerTestChanged();

private:
    const static QString WEIGHT_ACCURACY;
    const static QString PRINTING_TIME;
    const static QString SIMULATOR;
    const static QString MANUAL_ENTRY;
    const static QString PRINTER_TEST;

    QSettings m_settings;

    double m_accuracy;
    int m_printingTime;
    bool m_simulatorSetting;
    bool m_manualEntry;
    bool m_printerTesting;
};

#endif // SETTINGSMODEL_H
