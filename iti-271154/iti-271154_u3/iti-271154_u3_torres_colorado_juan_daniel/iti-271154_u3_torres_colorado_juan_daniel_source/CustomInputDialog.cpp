#include "CustomInputDialog.h"

// Clase para personalizar el mensaje
CustomInputDialog::CustomInputDialog(QWidget *parent) : QDialog(parent) {
	setWindowTitle("Establecer caracteres en la transición");
	setFixedSize(350,110);
        setupUi();
}

QStringList CustomInputDialog::getInputs() const {
        return QStringList{input1->text(), input2->text(), input3->text()};
}

void CustomInputDialog::setupUi() {
        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *messageLabel = new QLabel("Espacio en blanco: '~'", this);        
        QLabel *messageLabel2 = new QLabel("Entrada a leer || Eliminar de Stack || Agregar en Stack", this);
        input1 = new QLineEdit(this);
        input2 = new QLineEdit(this);
        input3 = new QLineEdit(this);
        
        input1->setMaxLength(1);
        input2->setMaxLength(1);
        input3->setMaxLength(1);

        QHBoxLayout *inputLayout = new QHBoxLayout();
        inputLayout->addWidget(input1);
        inputLayout->addWidget(input2);
        inputLayout->addWidget(input3);

        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
        connect(buttonBox, &QDialogButtonBox::accepted, this, &CustomInputDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, this, &CustomInputDialog::reject);

        layout->addWidget(messageLabel);
        layout->addWidget(messageLabel2);
        layout->addLayout(inputLayout);
        layout->addWidget(buttonBox);
}

