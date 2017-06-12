#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QtWidgets>
#include <qsizepolicy.h>


class Calculator : public QMainWindow
{
    Q_OBJECT
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    QGridLayout *layout_buttons, *layout_engineering;
    QVBoxLayout *fullUsualCalculator;
    QHBoxLayout *fullEngineeringCalculator;

    QLineEdit *le;

    QPushButton **digits;
    QPushButton *point, *plus, *minus, *mult, *div, *sign, *clear, *mc, *mr, *ms, *backspace, *compute;
    QPushButton *x_2, *x_3, *x_n, *root2_x, *x_10, *rootn_x;
    QPushButton *ln, *pi, *lg, *factorial, *exponent, *percent;
    QPushButton *x_minus1, *sin_x, *cos_x, *tg_x, *ctg_x, *mod;

    QSizePolicy *policy;

    QWidget *usualCalculator, *engineeringCalculator;

    QString digits_zero_to_nine[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    bool isPoint;
    bool isSign;
    bool isPlus, isMinus, isMult, isDiv;
    bool isCompute;
    bool isX_n, isRootn_x, isMod, isPercent;

    double n, n2;

    QString memory;

    void delZero(QString &str);

    double factorialInt(double a);

    double factorialDouble(double a);

public slots:
    void clickedDigits();
    void clickedPoint();
    void clickedBackspace();
    void clickedClear();
    void clickedSign();
    void clickedPlus();
    void clickedCompute();
    void clickedMinus();
    void clickedMult();
    void clickedDiv();
    void clickedMs();
    void clickedMr();
    void clickedMc();

    void clickedX_2();
    void clickedX_3();
    void clickedX_n();
    void clickedRoot2_x();
    void clickedRootn_x();
    void clickedX_10();
    void clickedLn();
    void clickedPi();
    void clickedLg();
    void clickedFactorial();
    void clickedExponent();
    void clickedPercent();
    void clickedX_minus1();
    void clickedSin();
    void clickedCos();
    void clickedTg();
    void clickedCtg();
    void clickedMod();
};

#endif // CALCULATOR_H
