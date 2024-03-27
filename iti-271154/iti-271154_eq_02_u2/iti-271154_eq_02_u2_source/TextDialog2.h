#ifndef TEXTDIALOG2
#define TEXTDIALOG2

class TextDialog2 : public QDialog {
public:
    TextDialog2(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Text Dialog");

        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel(this);
        label->setText("Indexing the vertices\n\n"
                               "push P[N-1], P[0], P[1] into stack S\n\n"
                               "while (i < N) // i = 2, N = size of P\n"
                               "  if (ccw(S[S.size()-2],S[S.size()-1],P[i])\n"
                               "    push P[i] into stack and increase i\n"
                               "  else pop from S\n\n"
                               "S is the result");

        layout->addWidget(label);
    }
};

#endif
