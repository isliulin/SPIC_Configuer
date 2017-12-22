/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "masterthread.h"

#include <QtSerialPort/QSerialPort>

#include <QTime>
#include "common/xconvert.h"

QT_USE_NAMESPACE

MasterThread::MasterThread(QObject *parent)
    : QThread(parent), waitTimeout(0), quit(false)
{
}

//! [0]
MasterThread::~MasterThread()
{
    mutex.lock();
    quit = true;
    cond.wakeOne();
    mutex.unlock();
    wait();
}


void MasterThread::transaction(QSerialPort *pserialPort, int waitTimeout, const QList<QByteArray> &request)
{
    QMutexLocker locker(&mutex);

    this->pSerialPort=pserialPort;
    this->waitTimeout= waitTimeout;
    this->request=request;
    //this->quit=quit;

    if (!isRunning())
        start();
//    else
//        cond.wakeOne();

}



void MasterThread::run()
{

    QMutexLocker locker(&mutex);

    while (!quit) {

        if(pSerialPort->isOpen())
        {
            // write request

            //mutex.lock();


            int length=request.length();
            for(int i=0;i<length;i++)
            {


                QByteArray requestData = this->request[i];
                requestData[3]=i+1;
                Xconvert::LRC(requestData);


                pSerialPort->write(requestData);


                if (pSerialPort->waitForBytesWritten(waitTimeout)) {
                    //! [8] //! [10]
                    // read response

                    //waitTimeout  100

                    if (pSerialPort->waitForReadyRead(500)) {


                        QByteArray responseData= pSerialPort->readAll();

//                        //10???
                       while (pSerialPort->waitForReadyRead(10))
                       {
                            responseData += pSerialPort->readAll();
                       }

                       //! [12]
                        emit this->response(responseData);


                        //! [10] //! [11] //! [12]
                    } else {
                        emit timeout(tr("Wait read response timeout %1")
                                     .arg(QTime::currentTime().toString()));
                        return;

                    }






                    //! [9] //! [11]
                } else {
                    emit timeout(tr("Wait write request timeout %1")
                                 .arg(QTime::currentTime().toString()));
                    return;

                }

            }

            //finished!
            QString completestr=tr("发送完毕");
            emit complete(completestr);
            return;



            //mutex.unlock();


        }
        else
        {
            emit error(tr("串口未打开"));
            return;
        }

    }
    //! [13]
}
