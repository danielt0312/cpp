#ifndef TEXTDIALOG
#define TEXTDIALOG

class TextDialog : public QDialog {
public:
    TextDialog(QWidget *parent = nullptr) : QDialog(parent) {
        setWindowTitle("Text Dialog");

        QVBoxLayout *layout = new QVBoxLayout(this);
        QLabel *label = new QLabel(this);
        label->setText("Indexing the vertices\n"
                       "while (i < N) // i=0, N=len(points), k=len(H)\n"
                       "while ((k>=2)&&!ccw(H[k-2],H[k-1],P[i])) --k\n"
                       "H[k++] = P[i++]\n"
                       "while (i >= 0) // i = N - 2, t = k + 1\n"
                       "while ((k>=t)&&!ccw(H[k-2],H[k-1],P[i])) --k\n"
                       "H[k++] = P[i--]");

        layout->addWidget(label);
    }
};

#endif
