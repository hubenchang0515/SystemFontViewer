#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QBoxLayout>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void updateFonts();

private:
    QFont m_generalFont;
    QFont m_fixedFont;
    QLabel* m_generalFontLabel;
    QLabel* m_fixedFontLabel;
    QVBoxLayout* m_layout;

    void setGeneralFont(const QFont& font);
    void setFixedFont(const QFont& font);
};

#endif // DIALOG_H
