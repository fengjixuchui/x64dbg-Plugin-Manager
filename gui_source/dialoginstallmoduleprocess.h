// Copyright (c) 2019 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef DIALOGINSTALLMODULEPROCESS_H
#define DIALOGINSTALLMODULEPROCESS_H

#include <QDialog>
#include <QThread>
#include <QTimer>
#include "../installmoduleprocess.h"
#include "../utils.h"

namespace Ui {
class DialogInstallModuleProcess;
}

class DialogInstallModuleProcess : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInstallModuleProcess(QWidget *parent, Utils::MDATA *pMData,QIODevice *pDevice);
    ~DialogInstallModuleProcess();

private slots:
    void on_pushButtonCancel_clicked();
    void onCompleted(qint64 nElapsed);
    void timerSlot();

signals:
    void errorMessage(QString sMessage);

private:
    Ui::DialogInstallModuleProcess *ui;
    Utils::MDATA *pMData;

    InstallModuleProcess *pInstallModuleProcess;
    QThread *pThread;
    bool bIsRun;
    QTimer *pTimer;
};

#endif // DIALOGINSTALLMODULEPROCESS_H