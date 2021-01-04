#include "dialog.h"
#include <QLayout>
#include <QLabel>
#include <QFontDatabase>
#include <QTimer>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , m_generalFont(QFontDatabase::systemFont(QFontDatabase::GeneralFont))
    , m_fixedFont(QFontDatabase::systemFont(QFontDatabase::FixedFont))
    , m_generalFontLabel(new QLabel(tr("标准字体 Qt/FontName")))
    , m_fixedFontLabel(new QLabel(tr("等宽字体 Qt/MonoFontName")))
    , m_layout(new QVBoxLayout(this))
{
    m_layout->addWidget(m_generalFontLabel);
    m_layout->addWidget(m_fixedFontLabel);

    m_generalFontLabel->setFont(m_generalFont);
    m_fixedFontLabel->setFont(m_fixedFont);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Dialog::updateFonts);
    timer->setInterval(100);
    timer->setSingleShot(false);
    timer->start();
}

Dialog::~Dialog()
{

}

void Dialog::updateFonts()
{
    QFont font = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
    if(font != m_generalFont)
    {
        setGeneralFont(font);
    }

    font = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    if(font != m_fixedFont)
    {
        setFixedFont(font);
    }
}

void Dialog::setGeneralFont(const QFont& font)
{
    m_generalFont = font;
    m_generalFontLabel->setFont(m_generalFont);
}

void Dialog::setFixedFont(const QFont& font)
{
    m_fixedFont = font;
    m_fixedFontLabel->setFont(m_fixedFont);
}
