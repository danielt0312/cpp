#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialogButtonBox>

// Clase para personalizar el mensaje
class CustomInputDialog : public QDialog {
    Q_OBJECT
public:
    CustomInputDialog(QWidget *parent = nullptr);
    QStringList getInputs() const;

private:
    void setupUi();
    QLineEdit *input1;
    QLineEdit *input2;
    QLineEdit *input3;
};

