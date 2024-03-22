/****************************************************************************
  **
  ** Copyright (C) 2016 The Qt Company Ltd.
  ** Contact: https://www.qt.io/licensing/
  **
  ** This file is part of the examples of the Qt Toolkit.
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

  #include <QtWidgets>

#include <iostream>
using namespace std;
  #include "finddialog.h"

  void FindDialog::setString (string X) {
        Caadena = X;
        std::cout<<"Find String "<<X<<"\n";
        lineEdit->setText(QString::fromStdString(Caadena) );
    }

    string FindDialog::getResultingString () {
        return (lineEdit->text().toStdString());
    }

    void FindDialog::AccionBotonDentroDialogo () {
        std::cout<<"Clickeaste Find Button "<<"\n";
        this->close();

    }


  FindDialog::FindDialog(QWidget *parent)
      : QDialog(parent)
  {
      label = new QLabel(tr("Find &what:"));
      lineEdit = new QLineEdit;
      //lineEdit->setText(QString::fromStdString(Caadena) );
      label->setBuddy(lineEdit);

      caseCheckBox = new QCheckBox(tr("Match &case"));
      fromStartCheckBox = new QCheckBox(tr("Search from &start"));
      fromStartCheckBox->setChecked(true);

      findButton = new QPushButton(tr("&Find"));
      findButton->setDefault(true);

      connect(findButton, &QPushButton::clicked, this, &FindDialog::AccionBotonDentroDialogo);

      moreButton = new QPushButton(tr("&More"));
      moreButton->setCheckable(true);
      moreButton->setAutoDefault(false);


      extension = new QWidget;

      wholeWordsCheckBox = new QCheckBox(tr("&Whole words"));
      backwardCheckBox = new QCheckBox(tr("Search &backward"));
      searchSelectionCheckBox = new QCheckBox(tr("Search se&lection"));

      buttonBox = new QDialogButtonBox(Qt::Vertical);
      buttonBox->addButton(findButton, QDialogButtonBox::ActionRole);
      buttonBox->addButton(moreButton, QDialogButtonBox::ActionRole);

      connect(moreButton, &QAbstractButton::toggled, extension, &QWidget::setVisible);

      QVBoxLayout *extensionLayout = new QVBoxLayout;
      extensionLayout->setMargin(0);
      extensionLayout->addWidget(wholeWordsCheckBox);
      extensionLayout->addWidget(backwardCheckBox);
      extensionLayout->addWidget(searchSelectionCheckBox);
      extension->setLayout(extensionLayout);

      QHBoxLayout *topLeftLayout = new QHBoxLayout;
      topLeftLayout->addWidget(label);
      topLeftLayout->addWidget(lineEdit);

      QVBoxLayout *leftLayout = new QVBoxLayout;
      leftLayout->addLayout(topLeftLayout);
      leftLayout->addWidget(caseCheckBox);
      leftLayout->addWidget(fromStartCheckBox);

      QGridLayout *mainLayout = new QGridLayout;
      mainLayout->setSizeConstraint(QLayout::SetFixedSize);
      mainLayout->addLayout(leftLayout, 0, 0);
      mainLayout->addWidget(buttonBox, 0, 1);
      mainLayout->addWidget(extension, 1, 0, 1, 2);
      mainLayout->setRowStretch(2, 1);

      setLayout(mainLayout);

      setWindowTitle(tr("Extension"));
      extension->hide();

      Variable = 10;

}
