#include "calculator.h"
#include <cmath>

#define PI 3.14159265358979323846
#define E 2.71828182845904523536


Calculator::Calculator(QWidget *parent) : QMainWindow(parent, Qt::Window)
{
    policy = new QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    point     = new QPushButton("."  );
    plus      = new QPushButton("+"  );
    minus     = new QPushButton("-"  );
    mult      = new QPushButton("x"  );
    div       = new QPushButton("/"  );
    sign      = new QPushButton("+/-");
    clear     = new QPushButton("C"  );
    mc        = new QPushButton("MC" );
    mr        = new QPushButton("MR" );
    ms        = new QPushButton("MS" );
    backspace = new QPushButton(style()->standardIcon(QStyle::SP_ArrowLeft), "Backspace");
    compute   = new QPushButton("="  );
    x_2       = new QPushButton("x²" );
    x_3       = new QPushButton("x³" );
    x_n       = new QPushButton("x ͫ" );
    root2_x   = new QPushButton("√"  );
    x_10      = new QPushButton("10 ͯ");
    rootn_x   = new QPushButton(" ͫ√x");
    ln        = new QPushButton("ln" );
    pi        = new QPushButton("π"  );
    lg        = new QPushButton("lg" );
    factorial = new QPushButton("x!" );
    exponent  = new QPushButton("exp");
    percent   = new QPushButton("%"  );
    x_minus1  = new QPushButton("1/x");
    sin_x     = new QPushButton("sin");
    cos_x     = new QPushButton("cos");
    tg_x      = new QPushButton("tg" );
    ctg_x     = new QPushButton("ctg");
    mod       = new QPushButton("mod");

    digits   = new QPushButton*[10];
    le = new QLineEdit("0");
    for (int i = 0; i < 10; i++)
    {
        digits[i] = new QPushButton(digits_zero_to_nine[i]);
        digits[i]->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
        digits[i]->setStyleSheet(
            " QPushButton {                  "
            "     background-color: #585858; "
            " }                              "
            " QPushButton:pressed {          "
            "     background-color: #2E2E2E; "
            " }                              "
        );
    }

    // Set size policy.
    compute  ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    point    ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    plus     ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    minus    ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    mult     ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    div      ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    sign     ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    clear    ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    mc       ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    mr       ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    ms       ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    backspace->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    x_2      ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    x_3      ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    x_n      ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    root2_x  ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    x_10     ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    rootn_x  ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    ln       ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    pi       ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    lg       ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    factorial->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    exponent ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    percent  ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    x_minus1 ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    sin_x    ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    cos_x    ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    tg_x     ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    ctg_x    ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());
    mod      ->setSizePolicy(policy->verticalPolicy(), policy->horizontalPolicy());

    // Add widgets for usual calculator.
    layout_buttons = new QGridLayout;
    layout_buttons->setSpacing(0);
    layout_buttons->addWidget(mc        , 0, 3        );
    layout_buttons->addWidget(mr        , 0, 4        );
    layout_buttons->addWidget(ms        , 0, 5        );
    layout_buttons->addWidget(clear     , 0, 6        );
    layout_buttons->addWidget(sign      , 1, 3        );
    layout_buttons->addWidget(div       , 1, 4        );
    layout_buttons->addWidget(mult      , 1, 5        );
    layout_buttons->addWidget(backspace , 1, 6        );
    layout_buttons->addWidget(digits[7] , 2, 3        );
    layout_buttons->addWidget(digits[8] , 2, 4        );
    layout_buttons->addWidget(digits[9] , 2, 5        );
    layout_buttons->addWidget(minus     , 2, 6        );
    layout_buttons->addWidget(digits[4] , 3, 3        );
    layout_buttons->addWidget(digits[5] , 3, 4        );
    layout_buttons->addWidget(digits[6] , 3, 5        );
    layout_buttons->addWidget(plus      , 3, 6        );
    layout_buttons->addWidget(digits[1] , 4, 3        );
    layout_buttons->addWidget(digits[2] , 4, 4        );
    layout_buttons->addWidget(digits[3] , 4, 5        );
    layout_buttons->addWidget(compute   , 4, 6, -1, -1);
    layout_buttons->addWidget(digits[0] , 5, 3,  1,  2);
    layout_buttons->addWidget(point     , 5, 5        );
    layout_buttons->addWidget(x_minus1  , 0, 0        );
    layout_buttons->addWidget(ln        , 0, 1        );
    layout_buttons->addWidget(x_2       , 0, 2        );
    layout_buttons->addWidget(sin_x     , 1, 0        );
    layout_buttons->addWidget(lg        , 1, 1        );
    layout_buttons->addWidget(x_3       , 1, 2        );
    layout_buttons->addWidget(cos_x     , 2, 0        );
    layout_buttons->addWidget(pi        , 2, 1        );
    layout_buttons->addWidget(x_n       , 2, 2        );
    layout_buttons->addWidget(tg_x      , 3, 0        );
    layout_buttons->addWidget(factorial , 3, 1        );
    layout_buttons->addWidget(root2_x   , 3, 2        );
    layout_buttons->addWidget(ctg_x     , 4, 0        );
    layout_buttons->addWidget(exponent  , 4, 1        );
    layout_buttons->addWidget(rootn_x   , 4, 2        );
    layout_buttons->addWidget(mod       , 5, 0        );
    layout_buttons->addWidget(percent   , 5, 1        );
    layout_buttons->addWidget(x_10      , 5, 2        );

    fullUsualCalculator = new QVBoxLayout;
    fullUsualCalculator->addWidget(le);
    fullUsualCalculator->addLayout(layout_buttons);

    // Set style for widgets.
    this->setFixedSize(560, 490);
    this->setStyleSheet(
        " QLineEdit {                         "
        "     min-height: 60px;               "
        "     font-size: 35px;                "
        "     background-color: LemonChiffon; "
        " }                                   "
        " QPushButton {                       "
        "     border: 1px solid Black;        "
        "     font-size: 16px;                "
        "     color: White;                   "
        " }                                   "
        " QMainWindow {                       "
        "     background-color: Silver;       "
        " }                                   "
    );
    compute->setStyleSheet(
        " QPushButton {                  "
        "     background-color: #FF8000; "
        " }                              "
        " QPushButton:pressed {          "
        "     background-color: #AF5A05; "
        " }                              "
    );
    point->setStyleSheet(
        " QPushButton {                  "
        "     background-color: #585858; "
        " }                              "
        " QPushButton:pressed {          "
        "     background-color: #2E2E2E; "
        " }                              "
    );
    QString styleForSignButtons(
        " QPushButton {                  "
        "     background-color: #756758; "
        " }                              "
        " QPushButton:pressed {          "
        "     background-color: #2E2E2E; "
        " }                              "
    );
    QString styleForMemory(
        " QPushButton {                  "
        "     background-color: #6F6F6F; "
        " }                              "
        " QPushButton:pressed {          "
        "     background-color: #2E2E2E; "
        " }                              "
    );

    plus ->setStyleSheet(styleForSignButtons);
    minus->setStyleSheet(styleForSignButtons);
    mult ->setStyleSheet(styleForSignButtons);
    div  ->setStyleSheet(styleForSignButtons);
    backspace->setStyleSheet(styleForSignButtons);
    backspace->setStyleSheet("QPushButton { font-size: 12px; }"+styleForSignButtons);
    sign->setStyleSheet(styleForSignButtons);

    ms->setStyleSheet(styleForMemory);
    mc->setStyleSheet(styleForMemory);
    mr->setStyleSheet(styleForMemory);

    clear->setStyleSheet(
        " QPushButton {                    "
        "     background-color: FireBrick; "
        " }                                "
        " QPushButton:pressed {            "
        "     background-color: DarkRed;   "
        " }                                "
    );

    x_2       -> setStyleSheet(styleForMemory);
    x_3       -> setStyleSheet(styleForMemory);
    x_n       -> setStyleSheet(styleForMemory);
    root2_x   -> setStyleSheet(styleForMemory);
    x_10      -> setStyleSheet(styleForMemory);
    rootn_x   -> setStyleSheet(styleForMemory);
    ln        -> setStyleSheet(styleForMemory);
    pi        -> setStyleSheet(styleForMemory);
    lg        -> setStyleSheet(styleForMemory);
    factorial -> setStyleSheet(styleForMemory);
    exponent  -> setStyleSheet(styleForMemory);
    percent   -> setStyleSheet(styleForMemory);
    x_minus1  -> setStyleSheet(styleForMemory);
    sin_x     -> setStyleSheet(styleForMemory);
    cos_x     -> setStyleSheet(styleForMemory);
    tg_x      -> setStyleSheet(styleForMemory);
    ctg_x     -> setStyleSheet(styleForMemory);
    mod       -> setStyleSheet(styleForMemory);

    le->setReadOnly(true);

    // Usual calculator.
    usualCalculator = new QWidget;
    usualCalculator->setLayout(fullUsualCalculator);
    setCentralWidget(usualCalculator);

    // Set keyboard shortcuts.
    digits[0]->setShortcut(QKeySequence(Qt::Key_0)        );
    digits[1]->setShortcut(QKeySequence(Qt::Key_1)        );
    digits[2]->setShortcut(QKeySequence(Qt::Key_2)        );
    digits[3]->setShortcut(QKeySequence(Qt::Key_3)        );
    digits[4]->setShortcut(QKeySequence(Qt::Key_4)        );
    digits[5]->setShortcut(QKeySequence(Qt::Key_5)        );
    digits[6]->setShortcut(QKeySequence(Qt::Key_6)        );
    digits[7]->setShortcut(QKeySequence(Qt::Key_7)        );
    digits[8]->setShortcut(QKeySequence(Qt::Key_8)        );
    digits[9]->setShortcut(QKeySequence(Qt::Key_9)        );
    point    ->setShortcut(QKeySequence(Qt::Key_Period)   );
    clear    ->setShortcut(QKeySequence(Qt::Key_Escape)   );
    backspace->setShortcut(QKeySequence(Qt::Key_Backspace));
    plus     ->setShortcut(QKeySequence(Qt::Key_Plus)     );
    minus    ->setShortcut(QKeySequence(Qt::Key_Minus)    );
    mult     ->setShortcut(QKeySequence(Qt::Key_Asterisk) );
    div      ->setShortcut(QKeySequence(Qt::Key_Slash)    );
    compute  ->setShortcut(QKeySequence(Qt::Key_Return)   );
    sin_x    ->setShortcut(QKeySequence(Qt::Key_S)        );
    cos_x    ->setShortcut(QKeySequence(Qt::Key_C)        );
    tg_x     ->setShortcut(QKeySequence(Qt::Key_T)        );
    ctg_x    ->setShortcut(QKeySequence(Qt::Key_O)        );
    factorial->setShortcut(QKeySequence(Qt::Key_Exclam)   );
    pi       ->setShortcut(QKeySequence(Qt::Key_P)        );
    lg       ->setShortcut(QKeySequence(Qt::Key_L)        );
    ln       ->setShortcut(QKeySequence(Qt::Key_N)        );
    x_2      ->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_2));
    mod      ->setShortcut(QKeySequence(Qt::Key_M)        );
    exponent ->setShortcut(QKeySequence(Qt::Key_E)        );
    sign     ->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_Minus));
    percent  ->setShortcut(QKeySequence(Qt::Key_Percent)  );
    x_n      ->setShortcut(QKeySequence(Qt::Key_AsciiCircum));
    x_3      ->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_3));
    root2_x  ->setShortcut(QKeySequence(Qt::Key_Q)        );

    // Initialize of variables.
    isPoint   = false;
    isSign    = false;
    isPlus    = false;
    isMinus   = false;
    isMult    = false;
    isDiv     = false;
    isCompute = false;
    isX_n     = false;
    isRootn_x = false;
    isMod     = false;
    isPercent = false;
    n  = 0.0;
    n2 = 0.0;
    memory = "0";

    // Connect: SIGNAL-SLOT.
    for (int i = 0; i < 10; i++)
    {
        connect(digits[i], &QPushButton::clicked, this, &Calculator::clickedDigits);
    }
    connect(point    , &QPushButton::clicked, this, &Calculator::clickedPoint    );
    connect(backspace, &QPushButton::clicked, this, &Calculator::clickedBackspace);
    connect(clear    , &QPushButton::clicked, this, &Calculator::clickedClear    );
    connect(sign     , &QPushButton::clicked, this, &Calculator::clickedSign     );
    connect(plus     , &QPushButton::clicked, this, &Calculator::clickedPlus     );
    connect(compute  , &QPushButton::clicked, this, &Calculator::clickedCompute  );
    connect(minus    , &QPushButton::clicked, this, &Calculator::clickedMinus    );
    connect(mult     , &QPushButton::clicked, this, &Calculator::clickedMult     );
    connect(div      , &QPushButton::clicked, this, &Calculator::clickedDiv      );
    connect(ms       , &QPushButton::clicked, this, &Calculator::clickedMs       );
    connect(mr       , &QPushButton::clicked, this, &Calculator::clickedMr       );
    connect(mc       , &QPushButton::clicked, this, &Calculator::clickedMc       );
    connect(x_2      , &QPushButton::clicked, this, &Calculator::clickedX_2      );
    connect(x_3      , &QPushButton::clicked, this, &Calculator::clickedX_3      );
    connect(x_n      , &QPushButton::clicked, this, &Calculator::clickedX_n      );
    connect(root2_x  , &QPushButton::clicked, this, &Calculator::clickedRoot2_x  );
    connect(rootn_x  , &QPushButton::clicked, this, &Calculator::clickedRootn_x  );
    connect(x_10     , &QPushButton::clicked, this, &Calculator::clickedX_10     );
    connect(ln       , &QPushButton::clicked, this, &Calculator::clickedLn       );
    connect(pi       , &QPushButton::clicked, this, &Calculator::clickedPi      );
    connect(lg       , &QPushButton::clicked, this, &Calculator::clickedLg       );
    connect(factorial, &QPushButton::clicked, this, &Calculator::clickedFactorial);
    connect(exponent , &QPushButton::clicked, this, &Calculator::clickedExponent );
    connect(percent  , &QPushButton::clicked, this, &Calculator::clickedPercent  );
    connect(x_minus1 , &QPushButton::clicked, this, &Calculator::clickedX_minus1 );
    connect(sin_x    , &QPushButton::clicked, this, &Calculator::clickedSin      );
    connect(cos_x    , &QPushButton::clicked, this, &Calculator::clickedCos      );
    connect(tg_x     , &QPushButton::clicked, this, &Calculator::clickedTg       );
    connect(ctg_x    , &QPushButton::clicked, this, &Calculator::clickedCtg      );
    connect(mod      , &QPushButton::clicked, this, &Calculator::clickedMod      );
}


Calculator::~Calculator()
{
}


void Calculator::delZero(QString &str)
{
    if (str != "0")
    {
        if (!isPoint)
        {
            while (str[0] == '0')
            {
                str.remove(0, 1);
            }
        }
    }

    if (str == "")
    {
        str = "0";
    }
}


void Calculator::clickedDigits()
{
    if (isSign)
    {
        le->setText("");
    }

    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        if (digits[i] == sender())
            break;
        else
            count++;
    }

    QString str = le->text();

    str += digits_zero_to_nine[count];
    delZero(str);
    le->setText(str);
    isSign = false;
}


void Calculator::clickedPoint()
{
    if (!isPoint)
    {
        QString str = le->text();

        str += ".";
        le->setText(str);
        isPoint = true;
    }
}


void Calculator::clickedBackspace()
{
    QString str = le->text();

    if (!str.isEmpty())
    {
        if (str[str.length()-1] == '.')
        {
            isPoint = false;
        }

        str.remove(str.length()-1, 1);
    }

    le->setText(!str.isEmpty() ? str : "0");
}


void Calculator::clickedClear()
{
    le->setText("0");
    isPoint = false;
    isCompute = false;
    isPlus = false;
    isMinus = false;
    isMult = false;
    isDiv = false;
    isSign = false;
    isX_n = false;
    isRootn_x = false;
    n = 0.0;
    n2 = 0.0;
}


void Calculator::clickedSign()
{
    QString str = le->text();

    if (str != "0")
    {
        if (str[0] != '-')
            str = "-" + str;
        else
            str.remove(0, 1);
    }

    le->setText(str);
}

void Calculator::clickedPlus()
{
    if (!isSign)
    {
        if (isMinus)
            clickedMinus();
        else if (isMult)
            clickedMult();
        else if (isDiv)
            clickedDiv();
        else if (isX_n)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isRootn_x)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, 1/n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isMod)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = fmod(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isPercent)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = n * n2 / 100;
            str = QString::number(n);
            le->setText(str);
        }
        else if (!isCompute)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n += n2;
            str = QString::number(n);
            le->setText(str);
        }

        isPlus = true;
        isMinus = false;
        isMult = false;
        isDiv = false;
        isSign = true;
        isCompute = false;
        isPoint = false;
        isX_n = false;
        isRootn_x = false;
        isMod = false;
        isPercent = false;
    }
}


void Calculator::clickedCompute()
{
    QString str;

    if (!isCompute)
    {
        str = le->text();
        n2 = str.toDouble();
    }

    if (isPlus)
        n += n2;
    else if (isMinus)
        n -= n2;
    else if (isMult)
        n *= n2;
    else if (isDiv)
    {
        try
        {
            n2 == 0 ? throw "Error!" : n /= n2;
        }
        catch(const char *what)
        {
            le->setText(what);
            return;
        }
    }

    if (isX_n)
        n = pow(n, n2);
    else if (isRootn_x)
        n = pow(n, 1/n2);
    else if (isMod)
        n = fmod(n, n2);
    else if (isPercent)
        n = n * n2 / 100;

    str = QString::number(n);
    le->setText(str);
    isCompute = true;
}


void Calculator::clickedMinus()
{
    if (!isSign)
    {
        if (isPlus)
            clickedPlus();
        else if (isMult)
            clickedMult();
        else if (isDiv)
            clickedDiv();
        else if (isX_n)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isRootn_x)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, 1/n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isMod)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = fmod(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isPercent)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = n * n2 / 100;
            str = QString::number(n);
            le->setText(str);
        }
        else if (!isCompute)
        {
            QString str = le->text();

            n2 = str.toDouble();

            n = isMinus ? n - n2 : n2;

            str = QString::number(n);
            le->setText(str);
        }

        isPlus = false;
        isMinus = true;
        isMult = false;
        isDiv = false;
        isSign = true;
        isCompute = false;
        isPoint = false;
        isX_n = false;
        isRootn_x = false;
        isMod = false;
        isPercent = false;
    }
}

void Calculator::clickedMult()
{
    if (!isSign)
    {
        if (isPlus)
            clickedPlus();
        else if (isMinus)
            clickedMinus();
        else if (isDiv)
            clickedDiv();
        else if (isX_n)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isRootn_x)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, 1/n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isMod)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = fmod(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isPercent)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = n * n2 / 100;
            str = QString::number(n);
            le->setText(str);
        }
        else if (!isCompute)
        {
            QString str = le->text();

            n2 = str.toDouble();

            n = isMult ? n * n2 : n2;

            str = QString::number(n);
            le->setText(str);
        }

        isPlus = false;
        isMinus = false;
        isMult = true;
        isDiv = false;
        isSign = true;
        isCompute = false;
        isPoint = false;
        isX_n = false;
        isRootn_x = false;
        isMod = false;
        isPercent = false;
    }
}


void Calculator::clickedDiv()
{
    if (!isSign)
    {
        if (isPlus)
            clickedPlus();
        else if (isMinus)
            clickedMinus();
        if (isMult)
            clickedMult();
        else if (isX_n)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isRootn_x)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = pow(n, 1/n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isMod)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = fmod(n, n2);
            str = QString::number(n);
            le->setText(str);
        }
        else if (isPercent)
        {
            QString str = le->text();

            n2 = str.toDouble();
            n = n * n2 / 100;
            str = QString::number(n);
            le->setText(str);
        }
        else if (!isCompute)
        {
            QString str = le->text();

            n2 = str.toDouble();

            if (isDiv)
            {
                try
                {
                    if (n2 == 0)
                        throw "Error!";

                    n /= n2;
                }
                catch (const char *what)
                {
                    le->setText(what);
                    return;
                }
            }
            else
            {
                n = n2;
            }

            str = QString::number(n);
            le->setText(str);
        }

        isPlus = false;
        isMinus = false;
        isMult = false;
        isDiv = true;
        isSign = true;
        isCompute = false;
        isPoint = false;
        isX_n = false;
        isRootn_x = false;
        isMod = false;
        isPercent = false;
    }
}


void Calculator::clickedMs()
{
    QString str = le->text();

    memory = str;
    ms->setStyleSheet(
        " QPushButton {                  "
        "     background-color: #6F6F6F; "
        "     color: #1AFF00;            "
        " }                              "
        " QPushButton:pressed {          "
        "     background-color: #2E2E2E; "
        " }                              "
    );
}


void Calculator::clickedMr()
{
    le->setText(memory);
}


void Calculator::clickedMc()
{
    memory = "0";
    ms->setStyleSheet(
        " QPushButton {                  "
        "     background-color: #6F6F6F; "
        "     color: White;              "
        " }                              "
        " QPushButton:pressed {          "
        "     background-color: #2E2E2E; "
        " }                              "
    );
}


void Calculator::clickedX_2()
{
    QString str = le->text();

    n = str.toDouble();
    n *= n;
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedX_3()
{
    QString str = le->text();

    n = str.toDouble();
    n *= n * n;
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedX_n()
{
    QString str = le->text();

    n = str.toDouble();
    isX_n = true;
    isSign = true;
}


void Calculator::clickedRoot2_x()
{
    QString str = le->text();

    n = str.toDouble();
    n = sqrt(n);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedRootn_x()
{
    QString str = le->text();

    n = str.toDouble();
    isRootn_x = true;
    isSign = true;
}


void Calculator::clickedX_10()
{
    QString str = le->text();

    n = str.toDouble();
    n = pow(10, n);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedLn()
{
    QString str = le->text();

    try
    {
        n = str.toDouble();

        if (n == 0)
            throw "Error";
    }
    catch(const char *what)
    {
        le->setText(what);
        return;
    }

    n = log(n);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedPi()
{
    le->setText("3.141593");
}


void Calculator::clickedLg()
{
    QString str = le->text();

    try
    {
        n = str.toDouble();

        if (n == 0)
            throw "Error";
    }
    catch(const char *what)
    {
        le->setText(what);
        return;
    }

    n = log10(n);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedFactorial()
{
    QString str = le->text();

    try
    {
        n = str.toDouble();

        if (n < 0)
            throw "Error!";
    }
    catch(const char *what)
    {
        le->setText(what);
        return;
    }

    n = tgamma(n + 1);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedExponent()
{
    QString str = le->text();

    n = str.toDouble();
    n = exp(n);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedPercent()
{
    QString str = le->text();

    n = str.toDouble();
    isPercent = true;
    isSign = true;
}


void Calculator::clickedX_minus1()
{
    QString str = le->text();

    n = str.toDouble();
    n = 1/n;
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedSin()
{
    QString str = le->text();

    n = str.toDouble();
    n = sin(n * PI / 180);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedCos()
{
    QString str = le->text();

    n = str.toDouble();
    n = cos(n * PI / 180);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedTg()
{
    QString str = le->text();

    try
    {
        n = str.toDouble();

        if (n == 0 || n == 180)
            throw 1;

        if (n == 90 || n == 270)
            throw "Error!";
    }
    catch(const int what)
    {
        le->setText("0");
        return;
    }
    catch(const char *what)
    {
        le->setText(what);
        return;
    }

    n = tan(n * PI / 180);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedCtg()
{
    QString str = le->text();

    try
    {
        n = str.toDouble();

        if (n == 90 || n == 270)
            throw 1;

        if (n == 0 || n == 180)
            throw "Error!";
    }
    catch(const int what)
    {
        le->setText("0");
        return;
    }
    catch(const char *what)
    {
        le->setText(what);
        return;
    }

    n = 1/tan(n * PI / 180);
    str = QString::number(n);
    le->setText(str);
}


void Calculator::clickedMod()
{
    QString str = le->text();

    n = str.toDouble();
    isMod = true;
    isSign = true;
}
