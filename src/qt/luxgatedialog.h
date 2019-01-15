#ifndef __LUXGATE_DIALOG_H__
#define __LUXGATE_DIALOG_H__

#include <QWidget>
#include <QObject>
#include <QTableWidget>
#include <stdint.h>
#include "ui_luxgatedialog.h"
#include "clientmodel.h"
#include "walletmodel.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include "qcustomplot.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>
#include <QMainWindow>


namespace Ui {
    class LuxgateDialog;
}
class WalletModel;
class QDockWidget;


class LuxgateDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit LuxgateDialog(QWidget *parent = 0);
    ~LuxgateDialog();

    void setModel(WalletModel *model);


private:
    Ui::LuxgateDialog *ui;
    WalletModel *model;
    void moveWidgetsToDocks();
    QDockWidget* createDock(QWidget* widget, const QString& title);

private slots:
    void slotClickAddConfiguration();
    void slotClickRemoveConfiguration();
    void slotClickResetConfiguration();
    void slotClickChangeConfig();
    void slotConfigDataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles);
};

#endif //__LUXGATE_DIALOG_H__